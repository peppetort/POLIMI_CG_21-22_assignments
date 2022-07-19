#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragUV;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D diffuseColorSamplers;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;//the direction of the light.
	vec3 lightPos;//the position of the light.
	vec3 lightColor;//the basic color of the light.
	vec4 lightParams;//other
	vec3 eyePos;//the position of the viewer
} gubo;

/*lightParams.x -> a float component containing the cosine of the inner angle.
• lightParams.y -> a float component containing the cosine of the outer angle.
• lightParams.z -> a float component containing the denominator exponent b.
• lightParams.w -> a float component containing the basic distance g.*/

layout(binding = 3) uniform sampler2D specColorPowerSampler;



vec3 spot_light_dir(vec3 pos) {
	// Spot light direction= p-x/|p-x|
	//Same as point
	vec3 pMinusx = gubo.lightPos - pos;
	return normalize(pMinusx);
}

vec3 spot_light_color(vec3 pos) {
	// Spot light color
	vec3 pMinusx = gubo.lightPos - pos;
	float lenpMinusx =length(pMinusx);
	float bod= gubo.lightParams.w/lenpMinusx;
	float decay =pow(bod,gubo.lightParams.z);
	float dotProd = dot(normalize(pMinusx),gubo.lightDir);
	float clampPart = clamp((dotProd-gubo.lightParams.y)/(gubo.lightParams.x-gubo.lightParams.y),0.0, 1.0);
	return gubo.lightColor*dot(decay,clampPart);
}

vec3 Lambert_Diffuse_BRDF(vec3 L, vec3 N, vec3 V, vec3 C) {
	// Lambert Diffuse BRDF model
	// in all BRDF parameters are:
	// vec3 L : light direction
	// vec3 N : normal vector
	// vec3 V : view direction
	// vec3 C : main color (diffuse color, or specular color)

	return C *clamp(dot(L,N),0.0,1.0);
}

vec3 Phong_Specular_BRDF(vec3 L, vec3 N, vec3 V, vec3 C, float gamma)  {
	// Phong Specular BRDF model
	// additional parameter:
	// float gamma : exponent of the cosine term
	vec3 r = -reflect(L,N); // L-2*N*DOT
	float cosGammaAlpha = pow(clamp(dot(V,r),0.0,1.0),gamma);
	return C*cosGammaAlpha; //Todo green
}


void main() {

	//Spot light
	
	vec3 Norm = normalize(fragNorm);

	vec3 EyeDir = normalize(gubo.eyePos - fragPos);

	vec3 lD = spot_light_dir(fragPos);//Calculate vectors light model
	vec3 lC = spot_light_color(fragPos);

	vec3 diffuseColor = texture(diffuseColorSamplers, fragUV).rgb ;//Extract from sampler diffuse color
	vec4 texel = texture(specColorPowerSampler, fragUV);//Extract from sampler specular color and power

	vec3 lambertDiffuse = Lambert_Diffuse_BRDF(lD, Norm, EyeDir, diffuseColor) * lC;
	vec3 phongSpecular = Phong_Specular_BRDF(lD, Norm, EyeDir, texel.rgb,200.0f * texel.a) * lC;

	outColor = vec4(lambertDiffuse + phongSpecular, 1.0f);	

}