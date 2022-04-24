#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include "Shaders.h"
#include "Definitions.h"
#include "Functions.h"
#include "Variables.h"
#include <GLFW/glfw3.h>
#include <stb_image.h>
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 800;
glm::vec2 PlayerPos(LEFT(0.7f), UP(0.9f));
glm::vec2 PrevPPos = PlayerPos;
glm::vec2 PrevPPos2 = PlayerPos;
bool SetPos = false;
int lvl = 1;
bool Fullscreen;
bool pause = false;

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
    // Init GLFW
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); // Not Resizable
    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pixel", NULL, nullptr);
    int screenWidth, screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

    if (nullptr == window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(window);

    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Define the viewport dimensions
    glViewport(0, 0, screenWidth, screenHeight);
    glfwSetWindowPos(window, ((1920 / 2) / 2) - 25, ((1280 / 2) / 2) - 175);
    glfwSetKeyCallback(window, KeyCallback);
    ////////////////////////////////////////////////////////////////////////////////
    // Build and compile our shader program
    // Vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    // Check for compile time errors
    GLint success;
    GLchar infoLog[512];

    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // Check for compile time errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // Link shaders
    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if (!success)
    {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);


    // Set up vertex data (and buffer(s)) and attribute pointers
    GLfloat vertices[] =
    {
        0.05f, 0.05f, 0.0f, // top right
        0.05f, -0.05f, 0.0f, // bottom right
        -0.05f, 0.05f, 0.0f, // top left
        // second triangle
        0.05f, -0.05f, 0.0f, // bottom right
        -0.05f, -0.05f, 0.0f, // bottom left
        -0.05f, 0.05f, 0.0f // top left
    };

    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

    glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange



    glUseProgram(shaderProgram);

    int Color_Location = glGetUniformLocation(shaderProgram, "colorU");
    glUniform4f(Color_Location, 0.1f, 0.1f, 0.8f, 1.0f);
    int Position_Location = glGetUniformLocation(shaderProgram, "PlayerPosition");
    glUniform3f(Position_Location, 0.0f, 0.0f, 0.0f);
    // Game loop

    //Positions
    glm::vec2 StartPos(LEFT(0.7f), UP(0.9f));


    //Colors
    glm::vec3 PlayerColor(0.15f, 1.0f, 0.39f);
    glm::vec3 EnemyColor(1.0f, 0.23f, 0.19f);
    glm::vec3 CoinColor(1.0f, 0.56f, 0.19f);
    glm::vec3 WallColor(0.31f, 0.31f, 0.29f);

    //TODO: Zczytywanie lvli z plikow | 0 - Pustka, 1 - Przeciwnik, 2 - Gracz, M - Moneta

    // Coin Locations
    glm::vec2 Lvl1Coin(RIGHT(0.7f), DOWN(0.9f));
    glm::vec2 Lvl2Coin(LEFT(0.9f), UP(0.8f));

    //   Colisions
    bool EColision = false;
    int EColidedArrIndex = -1;
    bool WallCol[] = {
        false,
        false,
        false,
        false
    };
    int WColidedArrIndex[] = {
        -1,
        -1,
        -1,
        -1
    };

    // Player, Enamy, Coin Size
    glm::vec2 PECSize(0.05f, 0.05f);
    


    // TIMER
    double Time = 0;
    int Moved = 21;
    int CurLvl = lvl;
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(0.156f, 0.176f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        EColision = false;
        EColidedArrIndex = -1;
        WallCol[0] = false;
        WallCol[1] = false;
        WallCol[2] = false;
        WallCol[3] = false;
        WColidedArrIndex[0] = -1;
        WColidedArrIndex[1] = -1;
        WColidedArrIndex[2] = -1;
        WColidedArrIndex[3] = -1;


        if (pause != true) // JAK KLIKNIETO ESCAPE TO NIC SIE NIE WYSWIETLA I JEST ZATRZYMANY CZAS
        {
            //                   PrevPos
            if (PrevPPos2 != PlayerPos)
            {
                PrevPPos = PrevPPos2;
                PrevPPos2 = PlayerPos;
            }
            //                   TIMER
            if (lvl >= 1 && Moved > 0 && CurLvl != lvl)
            {
                Moved = 21;
                for (int i = 0; i < 21; i++)
                {
                    TIMER_POSITIONS[i] = TIMER_POSITIONS_COPY[i];
                }
                CurLvl = lvl;
            }
            Time = glfwGetTime();
            if (Time >= 0.5 && Moved >= 0 && lvl != 0) // Powtarza co 0.5s 
            {
                TIMER_POSITIONS[Moved] = glm::vec2(2.0f, 2.0f);
                Moved--;
                glfwSetTime(0.0);
            }
            else if (Moved < 0)
                lvl = 0;
            //                   TIMER END

            if (lvl == 1)
            {

                if (!SetPos)
                {
                    PlayerPos = glm::vec2(LEFT(0.8f), UP(0.9f));
                    SetPos = true;
                }
                // Draw Lvl1
                DrawObj(shaderProgram, VAO, 6, PlayerPos, Position_Location, PlayerColor, Color_Location); // Player
                DrawObjects(Lvl1, LVL1_LENGTH, shaderProgram, VAO, 6, Position_Location, EnemyColor, Color_Location); // Drawing Lvl1
                DrawObj(shaderProgram, VAO, 6, Lvl1Coin, Position_Location, CoinColor, Color_Location);
                //Kolizje do Przeciwnikow
                DoCollisions(PlayerPos, Lvl1, LVL1_LENGTH, PECSize, PECSize, &EColidedArrIndex, &EColision);
                //Kolizje do sciany 
                Wall(PlayerPos, WALLUP, WALLLEFT, WALLDOWN, WALLRIGHT, 21, PECSize, WColidedArrIndex, WallCol);
                //            Drawing Timer
                DrawObjects(TIMER_POSITIONS, 21, shaderProgram, VAO, 6, Position_Location, glm::vec3(0.0f, 0.5f, 0.5f), Color_Location);
                if (EColision) // Sprawdza czy gracz wszedl w  przeciwnika jesli tak to smierc
                    lvl = 0;

                else if (CheckCollision(PlayerPos, Lvl1Coin, PECSize, PECSize)) // jesli gracz wszedl w Monetke lvl++
                    lvl++;
            }
            if (lvl == 2)
            {
                if (!SetPos)
                {
                    PlayerPos = glm::vec2(RIGHT(0.8f), DOWN(0.9f));
                    SetPos = true;
                }
                // Draw Lvl1
                DrawObj(shaderProgram, VAO, 6, PlayerPos, Position_Location, PlayerColor, Color_Location); // Player
                DrawObjects(Lvl2, LVL2_LENGTH, shaderProgram, VAO, 6, Position_Location, EnemyColor, Color_Location); // Drawing Lvl1
                DrawObjects(Lvl2Walls, LVL2_WALL_LENGTH, shaderProgram, VAO, 6, Position_Location, WallColor, Color_Location);
                if (CheckCollision(PlayerPos, Lvl2Walls[0], PECSize, PECSize))
                {
                    PlayerPos = PrevPPos;
                }
                DrawObj(shaderProgram, VAO, 6, Lvl2Coin, Position_Location, CoinColor, Color_Location);
                //Kolizje do przeciwnikow
                DoCollisions(PlayerPos, Lvl2, LVL2_LENGTH, PECSize, PECSize, &EColidedArrIndex, &EColision);
                //Kolizje Do sciany
                Wall(PlayerPos, WALLUP, WALLLEFT, WALLDOWN, WALLRIGHT, 21, PECSize, WColidedArrIndex, WallCol);
                //TIMER
                DrawObjects(TIMER_POSITIONS, 21, shaderProgram, VAO, 6, Position_Location, glm::vec3(0.0f, 0.5f, 0.5f), Color_Location);
                if (EColision == true) // Sprawdza czy gracz wszedl w jakiegos przeciwnika jesli tak to smierc
                {
                    lvl = 0;
                    SetPos = false;
                }
                else if (CheckCollision(PlayerPos, Lvl2Coin, PECSize, PECSize)) // jesli gracz wszedl w Monetke lvl++
                {
                    lvl++;
                    SetPos = false;
                }
            }
        }

        glBindVertexArray(0);
        glfwSwapBuffers(window);
    }

    // Properly de-allocate all resources once they've outlived their purpose
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    // Terminate GLFW, clearing any resources allocated by GLFW.
    glfwTerminate();
    return EXIT_SUCCESS;
}

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && CLICKED(key, action))
    {
        pause = !pause;
    }
    if (pause == true)
    {
        Menu(GameStatus::PAUSE, key, action);
    }
    if (action == GLFW_PRESS || action == GLFW_REPEAT && action != GLFW_RELEASE)
    {
        if (pause == false)
        {
            switch (key)
            {
            case GLFW_KEY_UP:
                PlayerPos.y += UP(0.1f);
                break;
            case GLFW_KEY_LEFT:
                PlayerPos.x += LEFT(0.1f);
                break;
            case GLFW_KEY_RIGHT:
                PlayerPos.x += RIGHT(0.1f);
                break;
            case GLFW_KEY_DOWN:
                PlayerPos.y += DOWN(0.1f);
                break;
            }
        }
        //////////// DEBUG //////////////
        switch (key)
        {
        case GLFW_KEY_1:  
            lvl = 1;
            break;
        case GLFW_KEY_2:
            lvl = 2;
            break;
        case GLFW_KEY_Y: // PRINTS POSITION
            std::cout << "X: " << PlayerPos.x << " Y: " << PlayerPos.y << std::endl;
            break;
        }
    }
}