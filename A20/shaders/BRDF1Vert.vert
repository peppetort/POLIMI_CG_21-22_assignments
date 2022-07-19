#version 450
#extension GL_ARB_separate_shader_objects : enable

layout(binding = 0) uniform UniformBufferObject {
	mat4 mvpMat;//-> the World-View-Projection matrix to transform position in clipping space.
	mat4 mMat;// -> the World matrix to transform the position in World space.
	mat4 nMat;// -> the matrix to transform normal vector directions in World space.
} ubo;

layout(location = 0) in vec3 inPosition;//the position of the vertex in Local coordinates.
layout(location = 1) in vec3 inNormal;//the direction of the normal vector in Local space.
layout(location = 2) in vec2 inTexCoord;//the UV coordinates of the vertex.

layout(location = 0) out vec3 fragPos;
layout(location = 1) out vec3 fragNorm;
layout(location = 2) out vec2 fragUV;

void main() {
	gl_Position = ubo.mvpMat * vec4(inPosition, 1.0);//Computed clipping coord
	fragPos = (ubo.mMat * vec4(inPosition, 1.0)).xyz;//pixel pos world coord
	fragNorm = (ubo.nMat * vec4(inNormal, 0.0)).xyz;//normal world coord
	fragUV = inTexCoord;//uv
}