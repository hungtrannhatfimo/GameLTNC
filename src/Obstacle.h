#pragma once

#include <SDL.h>
#include <SDL_image.h>
class Obstacle {
private:
    int x, y;

    SDL_Rect upperPipeRect;
    SDL_Rect lowerPipeRect;

public:
    bool passed;
SDL_Texture* pipeTexture = nullptr;
void loadTexture(SDL_Renderer* renderer);
    static const int PIPE_WIDTH;
    static const int PIPE_GAP;
    static const int PIPE_SPEED;

    Obstacle(int startX);

    void reset(int startX);
    void update();
    void render(SDL_Renderer* renderer);
    SDL_Rect getUpperRect();
    SDL_Rect getLowerRect();
};
