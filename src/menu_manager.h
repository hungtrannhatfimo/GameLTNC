#ifndef MENU_MANAGER_H
#define MENU_MANAGER_H

#include <SDL.h>
#include <string>

enum MenuState {
    MENU_START,
    MENU_PAUSE,
    NONE
};

class MenuManager {
public:
    MenuManager(SDL_Renderer* renderer);

    void changeState(MenuState newState);
    bool isMenuActive();
    void render();
    bool handleEvent(SDL_Event* event);

private:
    SDL_Renderer* renderer;
    MenuState menuState;

    SDL_Rect startButton = {100, 100, 200, 100};    // Start button position
    SDL_Rect continueButton = {100, 250, 200, 100}; // Continue button
    SDL_Rect restartButton = {100, 400, 200, 100};  // Restart button

   SDL_Texture* startButtonTexture = nullptr;
   SDL_Texture* continueButtonTexture = nullptr;
    SDL_Texture* restartButtonTexture = nullptr;
};

#endif // MENU_MANAGER_H
