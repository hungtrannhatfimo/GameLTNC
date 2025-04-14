#include "Obstacle.h"

#include <cstdlib>
#include <ctime>
#include "GameLoop.h"
// Define constants
const int Obstacle::PIPE_WIDTH = 40;
const int Obstacle::PIPE_GAP = 150;
const int Obstacle::PIPE_SPEED = 3;

Obstacle::Obstacle(int startX) {
    x = startX;
    reset(x);
}

void Obstacle::reset(int startX) {
x = startX;
    const int screen_height = 600;
    const int ground_height = 190;

    int lowerPipeTop = screen_height - ground_height;
    y = lowerPipeTop - PIPE_GAP - (rand() % 200 + 100);


    passed = false;

    upperPipeRect = {x, 0, PIPE_WIDTH,y};
    lowerPipeRect = {x,y+PIPE_GAP,PIPE_WIDTH, lowerPipeTop - (y + PIPE_GAP)};
}

void Obstacle::update() {
    if(!GameLoop::gameStarted)return;

    x -= PIPE_SPEED;


        // Check if bird has passed the obstacle and increase score
      // Assuming bird is at x = 100



    // Update pipe positions
    upperPipeRect = { x, 0, PIPE_WIDTH, y };
    lowerPipeRect = { x, y + PIPE_GAP, PIPE_WIDTH, 600 - (y + PIPE_GAP) };

    if (x + PIPE_WIDTH < 0) { // If off-screen, reset position
        x = 800;
        reset(x);
    }
}

void Obstacle::render(SDL_Renderer* renderer) {
    SDL_Rect topPipe = { x, 0, PIPE_WIDTH, y };
    SDL_Rect bottomPipe = { x, y + PIPE_GAP, PIPE_WIDTH, 600 - (y + PIPE_GAP) };

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green pipes
    SDL_RenderFillRect(renderer, &topPipe);
    SDL_RenderFillRect(renderer, &bottomPipe);
}
SDL_Rect Obstacle::getUpperRect() { return upperPipeRect; }
SDL_Rect Obstacle::getLowerRect() { return lowerPipeRect; }
