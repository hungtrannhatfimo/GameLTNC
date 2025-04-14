#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_mixer.h>
#include "Player.h"
#include "Background.h"
#include "Obstacle.h"
#include <SDL_ttf.h>

class GameLoop
{
private:
        Mix_Chunk* flapSound = nullptr;
    Mix_Chunk* hitSound = nullptr;

    SDL_Texture* soundOnTex = nullptr;
    SDL_Texture* soundOffTex = nullptr;
    SDL_Rect soundIconRect = {750, 10, 32, 32};

    bool isMuted = false;

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
void loadDigitTextures(); // Loads number textures
    void renderScore(int x, int y); // Displays score on screen
public:

        void InitSounds(SDL_Renderer* renderer);
    void PlayFlapSound();
    void PlayHitSound();
    void ToggleSound();
    void RenderSoundIcon(SDL_Renderer* renderer);
    void FreeSounds();


    void renderGameOverScreen();
    bool isPaused = false;
    void ResetGame();
//void ShowMenu();
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



};
