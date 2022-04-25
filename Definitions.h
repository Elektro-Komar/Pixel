#pragma once
#include <glm/vec2.hpp>

#define LEFT(x) -x
#define RIGHT(x) +x
#define UP(x) +x
#define DOWN(x) -x
#define CLICKED(button, action) action == GLFW_PRESS && action != GLFW_RELEASE && action != GLFW_REPEAT

#define Wall(PlayerPos, WALLUP, WALLLEFT, WALLDOWN, WALLRIGHT, length, PECSize, WallsColidedArrIndex, WallCol) \
DoCollisions(PlayerPos, WALLUP, length, PECSize, PECSize, &WallsColidedArrIndex[0], &WallCol[0]);\
DoCollisions(PlayerPos, WALLLEFT, length, PECSize, PECSize, &WallsColidedArrIndex[1], &WallCol[1]);\
DoCollisions(PlayerPos, WALLDOWN, length, PECSize, PECSize, &WallsColidedArrIndex[2], &WallCol[2]);\
DoCollisions(PlayerPos, WALLRIGHT, length, PECSize, PECSize, &WallsColidedArrIndex[3], &WallCol[3]);\
if (WallCol[0])\
PlayerPos.y -= 0.1f;\
if (WallCol[1])\
PlayerPos.x += 0.1f;\
if (WallCol[2])\
PlayerPos.y += 0.1f;\
if (WallCol[3])\
PlayerPos.x -= 0.1f