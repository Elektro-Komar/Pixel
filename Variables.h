#pragma once
#include <GL/glew.h>
#include "Definitions.h"
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
// Walls Positions
glm::vec2 WallLvl2[] = {
    glm::vec2(RIGHT(0.4f), UP(0.6f))
};


// Lvl's Lengths
#define LVL1_LENGTH 7
#define LVL2_LENGTH 10
#define LVL2_WALL_LENGTH 1

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
// Copy of TIMER_POSITIONS use when you want to reset TIMER_POSTITIONS
const glm::vec2 TIMER_POSITIONS_COPY[] = {
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