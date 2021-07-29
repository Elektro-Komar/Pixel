#include "Functions.h"


/*
    Draws one object
    @param Program - Shader Program
    @param VerArrayObj - Vertex Array Object
    @param vertices - vertices np. 6
    @param pos - Draw Position
    @param PositionLoc - Uniform Position Location
    @param color - color
    @param ColorLoc - Uniform Color Location
*/
void DrawObj(GLuint Program, GLuint VerArrayObj, GLint vertices, glm::vec2 pos, GLint PositionLoc, glm::vec3 color, GLint ColorLoc)
{
    glUseProgram(Program);
    glBindVertexArray(VerArrayObj);
    glUniform3f(PositionLoc, pos.x, pos.y, 0.0f);
    glUniform4f(ColorLoc, color.x, color.y, color.z, 0.0f);
    glDrawArrays(GL_TRIANGLES, 0, vertices);
}


// Draws objects
void DrawObjects(glm::vec2* Positions, int length, GLuint Program, GLuint VerArrayObj, GLint vertices, GLint PosLoc, glm::vec3 col, GLint ColorLoc)
{
    for (int i = 0; i < length; i++)
    {
        DrawObj(Program, VerArrayObj, vertices, Positions[i], PosLoc, col, ColorLoc);
    }
}

bool CheckCollision(glm::vec2 Obj1, glm::vec2 Obj2, glm::vec2 Obj1Size, glm::vec2 Obj2Size) // AABB - AABB collision
{
    if ((Obj1.x + Obj1Size.x) >= (Obj2.x) &&
        (Obj1.x) <= (Obj2.x + Obj2Size.x) &&
        (Obj1.y + Obj1Size.y) >= (Obj2.y) &&
        (Obj1.y) <= (Obj2.y + Obj2Size.y))
        return true;
    else
        return false;
}
void DoCollisions(glm::vec2 Obj1, glm::vec2* Obj2, int length, glm::vec2 Obj1Size, glm::vec2 Obj2Size, int* ColidedArrayIndex, bool* Colided)
{
    for (int i = 0; i < length; i++)
    {
        glm::vec2 CurrentEnemyLoc = Obj2[i];
        if (CheckCollision(Obj1, CurrentEnemyLoc, Obj1Size, Obj2Size))
        {
            *ColidedArrayIndex = i;
            *Colided = true;
            return;
        }
    }
    *Colided = false;
    return;
}


//TODO: Dokonczyc Sciane
void WallObject(glm::vec2 WallPosition, glm::vec2 WallSize, glm::vec2* PlayerPosition, glm::vec2 PlayerSize, glm::vec2 Kierunek)
{
    // X == -0.1f = Wejscie z prawej &PlayerPosition += 0.1f
    // X == 0.1f = Wejscie z lewej
    // Y == -0.1f = Wejscie od gory
    // Y == 0.1f = Wejscie od dolu
    // Sciana jest na levelu 2
    if (Kierunek.x == -0.1 && CheckCollision(WallPosition, *PlayerPosition, WallSize, PlayerSize)) //ERROR: Not works
        std::cout << Kierunek.x << std::endl;
}


void Menu(GameStatus status)
{
    //TODO: Dorobic menu dla - DEAD i PAUSE
    if (status == GameStatus::DEAD)
    {
        // ...
    }
    if (status == GameStatus::PAUSE)
    {
        // ...
    }
}