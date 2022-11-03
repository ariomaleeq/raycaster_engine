#version 330 core

layout (location=0) in vec3 aPos;
layout (location=1) in vec3 aColor;


uniform mat4 projection;
uniform mat4 transform;

void main(){
gl_Position = projection*transform*vec4(aPos, 1.0);
    }
