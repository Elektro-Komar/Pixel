#pragma once
#include <glm/vec2.hpp>

#define LEFT(x) -x
#define RIGHT(x) +x
#define UP(x) +x
#define DOWN(x) -x
#define CLICKED(button, action) action == GLFW_PRESS && action != GLFW_RELEASE && action != GLFW_REPEAT

//  Enemy Positions
glm::vec2 Lvl1[] = {  // Lvl 1 Enemies Positions
    glm::vec2(LEFT(0.2f), UP(0.2f)),
    glm::vec2(RIGHT(0.2f), UP(0.4f)),
    glm::vec2(RIGHT(0.4f), DOWN(0.2f)),
    glm::vec2(LEFT(0.8f), UP(0.1f)),
    glm::vec2(RIGHT(0.1f), DOWN(0.3f)),
    glm::vec2(LEFT(0.4f), DOWN(0.6f)),
    glm::vec2(LEFT(0.6f), DOWN(0.2f))
};
glm::vec2 Lvl2[] = {  // Lvl 1 Enemies Positions
    glm::vec2(LEFT(0.3f), UP(0.2f)),
    glm::vec2(RIGHT(0.1f), UP(0.4f)),
    glm::vec2(RIGHT(0.8f), DOWN(0.2f)),
    glm::vec2(LEFT(0.2f), UP(0.1f)),
    glm::vec2(RIGHT(0.4f), DOWN(0.3f)),
    glm::vec2(LEFT(0.6f), DOWN(0.6f)),
    glm::vec2(LEFT(0.8f), DOWN(0.2f)),
    ////////
    glm::vec2(RIGHT(0.4f), UP(0.3f)),
    glm::vec2(RIGHT(0.5f), DOWN(0.4f)),
    glm::vec2(LEFT(0.5f), DOWN(0.3f))
};
glm::vec2 WallLvl2[] = {
    glm::vec2(RIGHT(0.4f), UP(0.6f))
};
#define LVL1_LENGTH 7
#define LVL2_LENGTH 10


glm::vec2 WALLUP[] = {
    glm::vec2(LEFT(1.0f), UP(1.0f)),
    glm::vec2(LEFT(0.9f), UP(1.0f)),
    glm::vec2(LEFT(0.8f), UP(1.0f)),
    glm::vec2(LEFT(0.7f), UP(1.0f)),
    glm::vec2(LEFT(0.6f), UP(1.0f)),
    glm::vec2(LEFT(0.5f), UP(1.0f)),
    glm::vec2(LEFT(0.4f), UP(1.0f)),
    glm::vec2(LEFT(0.3f), UP(1.0f)),
    glm::vec2(LEFT(0.2f), UP(1.0f)),
    glm::vec2(LEFT(0.1f), UP(1.0f)),
    glm::vec2(0.0f, UP(1.0f)),
    glm::vec2(RIGHT(0.1f), UP(1.0f)),
    glm::vec2(RIGHT(0.2f), UP(1.0f)),
    glm::vec2(RIGHT(0.3f), UP(1.0f)),
    glm::vec2(RIGHT(0.4f), UP(1.0f)),
    glm::vec2(RIGHT(0.5f), UP(1.0f)),
    glm::vec2(RIGHT(0.6f), UP(1.0f)),
    glm::vec2(RIGHT(0.7f), UP(1.0f)),
    glm::vec2(RIGHT(0.8f), UP(1.0f)),
    glm::vec2(RIGHT(0.9f), UP(1.0f)),
    glm::vec2(RIGHT(1.0f), UP(1.0f))
};
glm::vec2 WALLLEFT[] = {
    glm::vec2(LEFT(1.0f), UP(0.0f)),
    glm::vec2(LEFT(1.0f), UP(0.9f)),
    glm::vec2(LEFT(1.0f), UP(0.8f)),
    glm::vec2(LEFT(1.0f), UP(0.7f)),
    glm::vec2(LEFT(1.0f), UP(0.6f)),
    glm::vec2(LEFT(1.0f), UP(0.5f)),
    glm::vec2(LEFT(1.0f), UP(0.4f)),
    glm::vec2(LEFT(1.0f), UP(0.3f)),
    glm::vec2(LEFT(1.0f), UP(0.2f)),
    glm::vec2(LEFT(1.0f), UP(0.1f)),
    glm::vec2(LEFT(1.0f), 0.0f),
    glm::vec2(LEFT(1.0f), DOWN(0.1f)),
    glm::vec2(LEFT(1.0f), DOWN(0.2f)),
    glm::vec2(LEFT(1.0f), DOWN(0.3f)),
    glm::vec2(LEFT(1.0f), DOWN(0.4f)),
    glm::vec2(LEFT(1.0f), DOWN(0.5f)),
    glm::vec2(LEFT(1.0f), DOWN(0.6f)),
    glm::vec2(LEFT(1.0f), DOWN(0.7f)),
    glm::vec2(LEFT(1.0f), DOWN(0.8f)),
    glm::vec2(LEFT(1.0f), DOWN(0.9f)),
    glm::vec2(LEFT(1.0f), DOWN(1.0f))
}; 
glm::vec2 WALLRIGHT[] = {
    glm::vec2(RIGHT(1.0f), UP(0.0f)),
    glm::vec2(RIGHT(1.0f), UP(0.9f)),
    glm::vec2(RIGHT(1.0f), UP(0.8f)),
    glm::vec2(RIGHT(1.0f), UP(0.7f)),
    glm::vec2(RIGHT(1.0f), UP(0.6f)),
    glm::vec2(RIGHT(1.0f), UP(0.5f)),
    glm::vec2(RIGHT(1.0f), UP(0.4f)),
    glm::vec2(RIGHT(1.0f), UP(0.3f)),
    glm::vec2(RIGHT(1.0f), UP(0.2f)),
    glm::vec2(RIGHT(1.0f), UP(0.1f)),
    glm::vec2(RIGHT(1.0f), 0.0f),
    glm::vec2(RIGHT(1.0f), DOWN(0.1f)),
    glm::vec2(RIGHT(1.0f), DOWN(0.2f)),
    glm::vec2(RIGHT(1.0f), DOWN(0.3f)),
    glm::vec2(RIGHT(1.0f), DOWN(0.4f)),
    glm::vec2(RIGHT(1.0f), DOWN(0.5f)),
    glm::vec2(RIGHT(1.0f), DOWN(0.6f)),
    glm::vec2(RIGHT(1.0f), DOWN(0.7f)),
    glm::vec2(RIGHT(1.0f), DOWN(0.8f)),
    glm::vec2(RIGHT(1.0f), DOWN(0.9f)),
    glm::vec2(RIGHT(1.0f), DOWN(1.0f))
};

glm::vec2 WALLDOWN[] = {
    glm::vec2(LEFT(1.0f), DOWN(1.0f)),
    glm::vec2(LEFT(0.9f), DOWN(1.0f)),
    glm::vec2(LEFT(0.8f), DOWN(1.0f)),
    glm::vec2(LEFT(0.7f), DOWN(1.0f)),
    glm::vec2(LEFT(0.6f), DOWN(1.0f)),
    glm::vec2(LEFT(0.5f), DOWN(1.0f)),
    glm::vec2(LEFT(0.4f), DOWN(1.0f)),
    glm::vec2(LEFT(0.3f), DOWN(1.0f)),
    glm::vec2(LEFT(0.2f), DOWN(1.0f)),
    glm::vec2(LEFT(0.1f), DOWN(1.0f)),
    glm::vec2(0.0f, DOWN(1.0f)),
    glm::vec2(RIGHT(0.1f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.2f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.3f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.4f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.5f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.6f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.7f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.8f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.9f), DOWN(1.0f)),
    glm::vec2(RIGHT(1.0f), DOWN(1.0f))
};
glm::vec2 TIMER_POSITIONS[] = {
    glm::vec2(LEFT(1.0f), DOWN(1.0f)),
    glm::vec2(LEFT(0.9f), DOWN(1.0f)),
    glm::vec2(LEFT(0.8f), DOWN(1.0f)),
    glm::vec2(LEFT(0.7f), DOWN(1.0f)),
    glm::vec2(LEFT(0.6f), DOWN(1.0f)),
    glm::vec2(LEFT(0.5f), DOWN(1.0f)),
    glm::vec2(LEFT(0.4f), DOWN(1.0f)),
    glm::vec2(LEFT(0.3f), DOWN(1.0f)),
    glm::vec2(LEFT(0.2f), DOWN(1.0f)),
    glm::vec2(LEFT(0.1f), DOWN(1.0f)),
    glm::vec2(0.0f, DOWN(1.0f)),
    glm::vec2(RIGHT(0.1f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.2f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.3f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.4f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.5f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.6f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.7f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.8f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.9f), DOWN(1.0f)),
    glm::vec2(RIGHT(1.0f), DOWN(1.0f))
};
glm::vec2 TIMER_POSITIONS_COPY[] = {
    glm::vec2(LEFT(1.0f), DOWN(1.0f)),
    glm::vec2(LEFT(0.9f), DOWN(1.0f)),
    glm::vec2(LEFT(0.8f), DOWN(1.0f)),
    glm::vec2(LEFT(0.7f), DOWN(1.0f)),
    glm::vec2(LEFT(0.6f), DOWN(1.0f)),
    glm::vec2(LEFT(0.5f), DOWN(1.0f)),
    glm::vec2(LEFT(0.4f), DOWN(1.0f)),
    glm::vec2(LEFT(0.3f), DOWN(1.0f)),
    glm::vec2(LEFT(0.2f), DOWN(1.0f)),
    glm::vec2(LEFT(0.1f), DOWN(1.0f)),
    glm::vec2(0.0f, DOWN(1.0f)),
    glm::vec2(RIGHT(0.1f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.2f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.3f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.4f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.5f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.6f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.7f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.8f), DOWN(1.0f)),
    glm::vec2(RIGHT(0.9f), DOWN(1.0f)),
    glm::vec2(RIGHT(1.0f), DOWN(1.0f))
};


#define Wall(PlayerPos, WALLUP, WALLLEFT, WALLDOWN, WALLRIGHT, length, PECSize, WColidedArrIndex, WallCol) \
DoCollisions(PlayerPos, WALLUP, length, PECSize, PECSize, &WColidedArrIndex[0], &WallCol[0]);\
DoCollisions(PlayerPos, WALLLEFT, length, PECSize, PECSize, &WColidedArrIndex[1], &WallCol[1]);\
DoCollisions(PlayerPos, WALLDOWN, length, PECSize, PECSize, &WColidedArrIndex[2], &WallCol[2]);\
DoCollisions(PlayerPos, WALLRIGHT, length, PECSize, PECSize, &WColidedArrIndex[3], &WallCol[3]);\
if (WallCol[0])\
PlayerPos.y -= 0.1f;\
if (WallCol[1])\
PlayerPos.x += 0.1f;\
if (WallCol[2])\
PlayerPos.y += 0.1f;\
if (WallCol[3])\
PlayerPos.x -= 0.1f