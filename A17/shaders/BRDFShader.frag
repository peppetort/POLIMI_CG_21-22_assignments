#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	// Direct lights parameters (for diffuse and specular)
	vec3 lightDir0;
	vec3 lightColor0;
	vec3 lightDir1;
	vec3 lightColor1;
	vec3 lightDir2;
	vec3 lightColor2;
	vec3 lightDir3;
	vec3 lightColor3;

	// Ambient light parameters
	vec3 AmbColor;	// also Bottom color for Hemispheric light,
					//      Constant term for Spherical Harmonics light
	vec3 TopColor;	// also DyColor for Spherical Harmonics light
	vec3 DzColor;
	vec3 DxColor;
	
	// Other parameters (not relevant for the exercise)
	vec3 eyePos;
	vec4 selector;
} gubo;

/**** Modify from here *****/

layout(location = 2) in vec2 fragTexCoord;
layout(location = 1) in vec3 fragNorm;
layout(location = 0) in vec3 fragPos;

layout(location = 0) out vec4 outColor;


vec3 Case1_Color(vec3 N, vec3 V, vec3 Cd, vec3 Ca, float sigma) {
	// Oren Nayar Diffuse + Ambient
	// No Specular
	// One directional light (lightDir0 and lightColor0)
	//
	// Parameters are:
	//
	// vec3 N : normal vector
	// vec3 V : view direction
	// vec3 Cd : main color (diffuse color)
	// vec3 Ca : ambient color
	// float sigma : roughness of the material
    
    vec3 lx = gubo.lightDir0;
    
    // Oren Nayar Diffuse
    vec3 v_i = normalize(lx - dot(lx,N)*N);
    vec3 v_r = normalize(V - dot(V,N)*N);
    float G = max(0, dot(v_i,v_r));
    
    vec3 L = Cd * clamp(dot(lx, N), 0, 1);
    
    float A = 1 - 0.5f * (pow(sigma, 2)/(pow(sigma, 2) + 0.33f));
    float B = 0.45f * (pow(sigma, 2)/(pow(sigma, 2) + 0.09f));
    
    float teta_i = cos(dot(lx, N));
    float teta_r = cos(dot(lx, V));
    float alpha = max(teta_i, teta_r);
    float beta = min(teta_i, teta_r);
    
    vec3 F_diffuse = L*(A + B*G*sin(alpha)*tan(beta));
    
    //BRDF function
    vec3 F_BRDF = F_diffuse;
    
    //Ligt model
    vec3 L_model = gubo.lightColor0;
    
    //Ambient light model
    vec3 L_amb = gubo.AmbColor * Ca;
    
	return L_model * F_BRDF + L_amb;
}

vec3 Case2_Color(vec3 N, vec3 V, vec3 Cd, vec3 Ca) {
	// Lambert Diffuse + Hemispheric
	// No Specular
	// One directional light (lightDir0 and lightColor0)
	// Hemispheric light oriented along the y-axis
	//
	// Parameters are:
	//
	// vec3 N : normal vector
	// vec3 V : view direction
	// vec3 Cd : main color (diffuse color)
	// vec3 Ca : ambient color
    
    vec3 lx = gubo.lightDir0;
    vec3 l = gubo.lightColor0;
    
    //Lambert diffuse
    vec3 F_diffuse = Cd * max(dot(lx, N), 0);
    
    //BRDF function
    vec3 F_BDFR = F_diffuse;
    
    //Light model
    vec3 L_model = l;
    
    //Hemispheric light model
    vec3 ld = gubo.AmbColor;
    vec3 lu = gubo.TopColor;
	vec3 HemiDir = vec3(0.0f, 1.0f, 0.0f);
    
    vec3 L_amb = (((dot(N, HemiDir)+1)/2)*lu + ((1-dot(N,HemiDir))/2)*ld)*Ca;
    
	return L_model * F_BDFR + L_amb;
}

vec3 Case3_Color(vec3 N, vec3 V, vec3 Cs, vec3 Ca, float gamma)  {
	// Spherical Harmonics
	// Blinn Specular
	// Four directional lights (lightDir0 to lightDir3, and lightColor0 to lightColor3)
	//
	// Parameters are:
	//
	// vec3 N : normal vector
	// vec3 V : view direction
	// vec3 Cs : specular color
	// vec3 Ca : ambient color
	// float gamma : Blinn exponent
    
    //BRDF Blinn specular model
    vec3 blinn_0 = Cs * pow(clamp(dot(N, normalize(gubo.lightDir0 + V)), 0, 1), gamma);
    vec3 blinn_1 = Cs * pow(clamp(dot(N, normalize(gubo.lightDir1 + V)), 0, 1), gamma);
    vec3 blinn_2 = Cs * pow(clamp(dot(N, normalize(gubo.lightDir2 + V)), 0, 1), gamma);
    vec3 blinn_3 = Cs * pow(clamp(dot(N, normalize(gubo.lightDir3 + V)), 0, 1), gamma);
    
    //Light model
    vec3 dir_light_0 = gubo.lightColor0;
    vec3 dir_light_1 = gubo.lightColor1;
    vec3 dir_light_2 = gubo.lightColor2;
    vec3 dir_light_3 = gubo.lightColor3;
    
    //Harmonics model
    vec3 F_amb = gubo.AmbColor + N.x * gubo.DxColor + N.y * gubo.TopColor + N.z * gubo.DzColor;
    vec3 L_amb = Ca * F_amb;
    
    return (blinn_0 * dir_light_0 + blinn_1 * dir_light_1 + blinn_2 * dir_light_2 + blinn_3 * dir_light_3) + L_amb;
}




/**** To here *****/




void main() {
	vec3 Norm = normalize(fragNorm);
	vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);
	
	float AmbFact = 0.025;
	
	vec3 DifCol = texture(texSampler, fragTexCoord).rgb * gubo.selector.w +
				  vec3(1,1,1) * (1-gubo.selector.w);

	vec3 CompColor = gubo.selector.x *
						Case1_Color(Norm, EyeDir, DifCol, DifCol, 1.2f) +
					 gubo.selector.y *
						Case2_Color(Norm, EyeDir, DifCol, DifCol) +
					 gubo.selector.z *
						Case3_Color(Norm, EyeDir, vec3(1.0f,1.0f,1.0f), DifCol, 200.0f);
	
	outColor = vec4(CompColor, 1.0f);	
}
