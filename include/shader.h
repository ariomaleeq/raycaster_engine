#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>

#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include <math.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


//boilerplate shader class implementation
class Shader

{
    public:
        unsigned int ID;
        Shader();

        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader();
        void use();

        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;
        void setMatrix4(const std::string &name, glm::mat4 &projection);
        void setVector3(const std::string &name, glm::vec3 &value);
        };
#endif
