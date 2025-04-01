#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_mixer.h>
#include "Player.h"
#include "Background.h"
#include "Obstacle.h"


class GameLoop
{
private:
    Player p;
    Background b;
    Background ground1;
    const int HEIGHT = 600;
    const int WIDTH = 800;
    SDL_Window* window;
    SDL_Event event1;
    SDL_Renderer* renderer;
    bool GameState = false;
    Obstacle pipe1;
    Obstacle pipe2;

public:
    static int highestScore;
    static bool gameStarted;
    static int score;
bool getGameState();
    GameLoop();
    void Initialize();
    void Event();
    void Update();
    void Render();
    void Clear();
    void checkCollision();

private:
    void loadDigitTextures(); // Loads number textures
    void renderScore(int x, int y); // Displays score on screen
};
