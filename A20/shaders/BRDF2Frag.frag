#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(location = 0) in vec3 fragPos;
layout(location = 1) in vec3 fragNorm;
layout(location = 2) in vec2 fragUV;

layout(location = 0) out vec4 outColor;

layout(binding = 1) uniform sampler2D ambientColorSampler;

layout(binding = 2) uniform GlobalUniformBufferObject {
	vec3 lightDir;//the direction of the light.
	vec3 lightColor;//the basic color of the light.
	vec3 eyePos;//the position of the viewer
} gubo;

layout(binding = 3) uniform sampler2D specColorPowerSampler;



vec3 direct_light_dir(vec3 pos) {
	// Directional light direction = constant
	return gubo.lightDir;
}

vec3 direct_light_color(vec3 pos) {
	// Directional light color = constant
	return gubo.lightColor;
}

vec3 blinn_specular(vec3 L, vec3 N, vec3 V, vec3 C, float gamma){
	// Blinn Specular BRDF model
	// additional parameter:
	// float gamma : exponent of the cosine term
	vec3 h = normalize(L +V);
	float cosGammaAlpha = pow(clamp(dot(N,h),0.0,1.0),gamma);
	return C*cosGammaAlpha;
}

void main() {

	//Spot light
	
	vec3 Norm = normalize(fragNorm);

	vec3 EyeDir = normalize(gubo.eyePos - fragPos);

	vec3 lD = direct_light_dir(fragPos);//Calculate vectors light model
	vec3 lC = direct_light_color(fragPos);

	vec3 ambientColor = texture(ambientColorSampler, fragUV).rgb ;//Extract from sampler ambient color
	vec4 texel = texture(specColorPowerSampler, fragUV);//Extract from sampler specular color and power

	vec3 blinnSpecular = blinn_specular(lD, Norm, EyeDir, texel.rgb,200.0f * texel.a) * lC;

	outColor = vec4(ambientColor + blinnSpecular, 1.0f);	

}