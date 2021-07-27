#pragma once
#define GLEW_STATIC
#include <GL/glew.h>

// Shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"uniform vec3 PlayerPosition;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position + PlayerPosition, 1.0);\n"
"}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"uniform vec4 colorU;\n"
"void main()\n"
"{\n"
"color = colorU;\n"
"}\n\0";


const GLchar* enemyShaderVerS = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 0) uniform vec3 EnemyPosition;\n"
"void main()\n"
"{\n"
"gl_Position = vec4(position + EnemyPosition, 1.0);\n"
"}\0";
const GLchar* enemyShaderFragS = "#version 330 core\n"
"out vec4 color;\n"
"uniform vec4 colorU;\n"
"void main()\n"
"{\n"
"color = colorU\n"
"}\n\0";