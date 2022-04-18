//Fragment shader

#version 450

layout(location = 0) out vec4 outColor;

layout(set = 0, binding = 1) uniform GlobalUniformBufferObject {
	float time;
} gubo;

void main() {
    float red = 1.f;
    float green = sin(gubo.time);
    float blue = cos(gubo.time);
    
    
	outColor = vec4(red, green, blue, 1.0f);
}
