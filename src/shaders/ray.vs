#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aColor;

out vec3 outColor;

uniform mat4 projection;
uniform mat4 transform;
uniform vec3 color;

void main(){
gl_Position = projection*transform*vec4(aPos, 1.0);
outColor = color;
    }
