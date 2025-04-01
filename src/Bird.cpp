//#include <SDL.h>
//#include <SDL_image.h>
//#include<iostream>
//#include "Bird.h"
//Bird::Bird(SDL_Renderer* renderer, const char* filePath, int x, int y, int w, int h) {
//    // Load the bird texture
//    texture = IMG_LoadTexture(renderer, filePath);
//
//    if (!texture) {
//        SDL_Log("Failed to load texture: %s", SDL_GetError());
//    }
//
//    // Set initial bird position and size
//    birdRect.x = x;
//    birdRect.y = y;
//    birdRect.w = w;
//    birdRect.h = h;
//}
//
//Bird::~Bird() {
//    // Free the texture memory
//    SDL_DestroyTexture(texture);
//}
//
//void Bird::update() {
//    // TODO: Implement gravity & jumping mechanics
//}
//
//void Bird::render(SDL_Renderer* renderer) {
//    SDL_RenderCopy(renderer, texture, NULL, &birdRect);
//}
