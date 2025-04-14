#include "menu_manager.h"
#include <iostream>

MenuManager::MenuManager(SDL_Renderer* renderer) {
    this->renderer = renderer;
    menuState = MENU_START;  // Default menu state
}

void MenuManager::changeState(MenuState newState) {
    menuState = newState;
}

bool MenuManager::isMenuActive() {
    return menuState != NONE;
}

void MenuManager::render() {
    if (menuState == MENU_START) {
        // Render Start Button
        SDL_RenderCopy(renderer, startButtonTexture, nullptr, &startButton);
    }
    else if (menuState == MENU_PAUSE) {
        // Render Pause Menu (Continue, Restart)
        SDL_RenderCopy(renderer, continueButtonTexture, nullptr, &continueButton);
        SDL_RenderCopy(renderer, restartButtonTexture, nullptr, &restartButton);
    }
}

bool MenuManager::handleEvent(SDL_Event* event) {
    int x = event->button.x;
    int y = event->button.y;

    if (event->type == SDL_MOUSEBUTTONDOWN) {
        // If in MENU_START state, handle start button click
        if (menuState == MENU_START && x >= startButton.x && x <= startButton.x + startButton.w &&
            y >= startButton.y && y <= startButton.y + startButton.h) {
            changeState(NONE); // Hide menu, start game
            return true;
        }

        // If in MENU_PAUSE state, handle resume/restart clicks
        if (menuState == MENU_PAUSE) {
            if (x >= continueButton.x && x <= continueButton.x + continueButton.w &&
                y >= continueButton.y && y <= continueButton.y + continueButton.h) {
                changeState(NONE); // Resume the game
                return true;
            }
            if (x >= restartButton.x && x <= restartButton.x + restartButton.w &&
                y >= restartButton.y && y <= restartButton.y + restartButton.h) {
                // Trigger restart
                return true;
            }
        }
    }
    return false;
}
