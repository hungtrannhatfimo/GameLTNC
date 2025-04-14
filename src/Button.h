
#pragma once
#include <SDL.h>
#include <functional>

class Button {
public:
    Button(int x, int y, int w, int h, SDL_Texture* texture, std::function<void()> onClick);

    void render(SDL_Renderer* renderer);
    void handleEvent(SDL_Event* e);

private:
    SDL_Rect rect;
    SDL_Texture* texture;
    std::function<void()> onClick;
};
