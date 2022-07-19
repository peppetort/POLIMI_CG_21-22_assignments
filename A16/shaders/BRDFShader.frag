#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragTexCoord;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D texSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir0;
	vec3 lightColor0;
	vec3 lightDir1;
	vec3 lightColor1;
	vec3 lightDir2;
	vec3 lightColor2;
	vec3 lightDir3;
	vec3 lightColor3;
	vec3 eyePos;
	vec4 selector;
} gubo;

/**** Modify from here *****/

// LAMBERT (diffuse reflection model)
// constant diffuse term
// each point of the object hit by a ray reflect it eith uniform probability in all directions
// N.B: the quantity of light is not costant but is proportional to the angle between the ray and the normal vector of the x point (depends on the reflecting surface)
vec3 Lambert_Diffuse_BRDF(vec3 L, vec3 N, vec3 V, vec3 C) {
	// Lambert Diffuse BRDF model
	// in all BRDF parameters are:
	// vec3 L : light direction
	// vec3 N : normal vector
	// vec3 V : view direction
	// vec3 C : main color (diffuse color, or specular color)
	
    // we wants only positive values => max()
	return C * max(dot(L, N), 0);
}


// OREN-NAYER (diffuse reflection model)
// used for materials charaterized by retroreflection
// requires the normal vector of point x, the direction of the light and the direction of the viewer
vec3 Oren_Nayar_Diffuse_BRDF(vec3 L, vec3 N, vec3 V, vec3 C, float sigma) {
	// Directional light direction
	// additional parameter:
	// float sigma : roughness of the materia
    
    // projection of light direction (L) to the plane perpendiculat to normal vector (N)
    vec3 v_i = normalize(L - dot(L,N)*N);
    // projection of viewer direction (V) to the plane perpendiculat to normal vector (N)
    vec3 v_r = normalize(V - dot(V,N)*N);
    
    float G = max(0, dot(v_i,v_r));
    vec3 LL = C * clamp(dot(L, N), 0, 1);
    float A = 1 - 0.5f * (pow(sigma, 2)/(pow(sigma, 2) + 0.33f));
    float B = 0.45f * (pow(sigma, 2)/(pow(sigma, 2) + 0.09f));
    
    float teta_i = cos(dot(L, N));
    float teta_r = cos(dot(L, V));
    float alpha = max(teta_i, teta_r);
    float beta = min(teta_i, teta_r);
    
	return LL*(A + B*G*sin(alpha)*tan(beta));
}

// PHONG (specular reflection model)
// specular reflection has same angle of incoming light ray w.r.t normal vector but oriented in opposite direction \|/
// also the sirection of the viewer is considered. In particular we are interested in the cosin of the angle between the direction of the viewer and the direction of the reflection.
// This parameter enstablish the intensity of the specular reflection ( max reflection when viewer aligned with reflection direction, zero when 90 degree)
vec3 Phong_Specular_BRDF(vec3 L, vec3 N, vec3 V, vec3 C, float gamma)  {
	// Phong Specular BRDF model
	// additional parameter:
	// float gamma : exponent of the cosine term
    
    // dot(.) - L id the vector from light direction vectori perpendicular to normal vector
    // if we double we have the reflection vector
    vec3 r = 2*N * dot(L, N) - L;
	
	return C * pow(clamp(dot(V, r), 0, 1), gamma);
}

// TOON (specular + diffusion reflection model)
// simplify output color range using only discrete values according to set of threshold
// 2 colors and 2 threshold to choose which color to use
vec3 Toon_Diffuse_BRDF(vec3 L, vec3 N, vec3 V, vec3 C, vec3 Cd, float thr) {
	// Toon Diffuse Brdf
	// additional parameters:
	// vec3 Cd : color to be used in dark areas
	// float thr : color
    
    // based on Lambert
    // angle between normal and light direction vector
    float x = dot(L, N);
    
    return x >= thr ? C : x > 0 ? Cd : vec3(0,0,0);
}

vec3 Toon_Specular_BRDF(vec3 L, vec3 N, vec3 V, vec3 C, float thr)  {
	// Directional light direction
	// additional parameter:
	// float thr : color threshold
    
    // based on Phong
    // reflection vector
    vec3 r = 2*N * dot(L, N) - L;
    // angle beteen reflection vectori and viewer vector
    float x = dot(V, r);
    
    // the white circle on top
    return x >= thr ? C : vec3(0,0,0);
}


/**** To here *****/




vec3 BRDF_D(vec3 L, vec3 N, vec3 V, vec3 C) {
	return gubo.selector.x * Lambert_Diffuse_BRDF(L, N, V, C) +
		   (1.0 - gubo.selector.x) * (1.0 - gubo.selector.y) * 
		   			Toon_Diffuse_BRDF(L, N, V, C, 0.2f * C, 0.5) +
		   (1.0 - gubo.selector.x) * (gubo.selector.y) * 
		   			Oren_Nayar_Diffuse_BRDF(L, N, V, C, 1.5);
}

vec3 BRDF_S(vec3 L, vec3 N, vec3 V, vec3 C) {
	return Phong_Specular_BRDF(L, N, V, C, 200.0f) * gubo.selector.z +
		   (1.0 - gubo.selector.x) * (1.0 - gubo.selector.y) * 
		   			Toon_Specular_BRDF(L, N, V, vec3(1,1,1), 0.97f);
}

void main() {
	vec3 Norm = normalize(fragNorm);
	vec3 EyeDir = normalize(gubo.eyePos.xyz - fragPos);
	
	float AmbFact = 0.025;
	
	vec3 DiffColor = texture(texSampler, fragTexCoord).rgb * gubo.selector.w + vec3(1,1,1) * (1-gubo.selector.w);
	vec3 Diffuse = vec3(0,0,0);
	
	Diffuse += BRDF_D(gubo.lightDir0, Norm, EyeDir, DiffColor) * gubo.lightColor0;
	Diffuse += BRDF_D(gubo.lightDir1, Norm, EyeDir, DiffColor) * gubo.lightColor1;
	Diffuse += BRDF_D(gubo.lightDir2, Norm, EyeDir, DiffColor) * gubo.lightColor2;
	Diffuse += BRDF_D(gubo.lightDir3, Norm, EyeDir, DiffColor) * gubo.lightColor3;
	
	vec3 Specular = vec3(0,0,0);
	Specular += BRDF_S(gubo.lightDir0, Norm, EyeDir, vec3(1,1,1)) * gubo.lightColor0;
	Specular += BRDF_S(gubo.lightDir1, Norm, EyeDir, vec3(1,1,1)) * gubo.lightColor1;
	Specular += BRDF_S(gubo.lightDir2, Norm, EyeDir, vec3(1,1,1)) * gubo.lightColor2;
	Specular += BRDF_S(gubo.lightDir3, Norm, EyeDir, vec3(1,1,1)) * gubo.lightColor3;

	vec3 Ambient = AmbFact * DiffColor;
	
	outColor = vec4(Diffuse + Specular + Ambient, 1.0f);	
}
