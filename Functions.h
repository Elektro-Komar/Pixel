#pragma once
#include <iostream>
#include <GL/glew.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
enum class GameStatus {
    DEAD,
    PAUSE,
    PLAYING
};

void DrawObj(GLuint Program, GLuint VerArrayObj, GLint vertices, glm::vec2 pos, GLint PositionLoc, glm::vec3 color, GLint ColorLoc);
void DrawObjects(glm::vec2* Positions, int length, GLuint Program, GLuint VerArrayObj, GLint vertices, GLint PosLoc, glm::vec3 col, GLint ColorLoc);
bool CheckCollision(glm::vec2 Obj1, glm::vec2 Obj2, glm::vec2 Obj1Size, glm::vec2 Obj2Size);
void DoCollisions(glm::vec2 Obj1, glm::vec2* Obj2, int length, glm::vec2 Obj1Size, glm::vec2 Obj2Size, int* ColidedArrayIndex, bool* Colided);
void Menu(GameStatus status);