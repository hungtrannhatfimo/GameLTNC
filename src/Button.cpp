
#include "Button.h"

Button::Button(int x, int y, int w, int h, SDL_Texture* texture, std::function<void()> onClick)
    : rect{x, y, w, h}, texture(texture), onClick(onClick) {}

void Button::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

void Button::handleEvent(SDL_Event* e) {
    if (e->type == SDL_MOUSEBUTTONDOWN) {
        int x = e->button.x;
        int y = e->button.y;

        if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h) {
            onClick();  // trigger button action
        }
    }
}
