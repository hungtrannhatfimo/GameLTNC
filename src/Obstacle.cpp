#include "Obstacle.h"

#include <cstdlib>
#include <ctime>
#include "GameLoop.h"
// Define constants
const int Obstacle::PIPE_WIDTH = 40;
const int Obstacle::PIPE_GAP = 150;
const int Obstacle::PIPE_SPEED = 3;
const int screen_height = 600;
const int ground_height = 180;
int distanceForPipe = screen_height - ground_height;

Obstacle::Obstacle(int startX) {
    x = startX;
    reset(x);// gọi để random chiều cao
}

void Obstacle::reset(int startX) {  // khi cột ra khỏi màn hình hoặc trờ chơi bắt đầu
x = startX;


    y = distanceForPipe - PIPE_GAP - (rand() % 261); // độ dài y từ 0 tới 260


    passed = false;

    upperPipeRect = {x, 0, PIPE_WIDTH,y};
    lowerPipeRect = {x,y+PIPE_GAP,PIPE_WIDTH, distanceForPipe - (y + PIPE_GAP)};
}

void Obstacle::update() {   // làm cho pipe chạy
    if(!GameLoop::gameStarted)return;

    x -= PIPE_SPEED;   //chạy màn vs vận tốc 3px/frame


    upperPipeRect = { x, 0, PIPE_WIDTH, y };// ống trên được tạo: tọa độ x (chiều ngang), tọa độ y = 0 (đỉnh trên cùng của màn), độ lớn ống, chiều cao là y
    lowerPipeRect = { x, y + PIPE_GAP, PIPE_WIDTH, distanceForPipe - (y + PIPE_GAP) };

    if (x + PIPE_WIDTH < 0) {
        x = 800;  // x ở góc ngoài cùng bên phải màn
        reset(x);
    }
}

void Obstacle::loadTexture(SDL_Renderer* renderer) {
    pipeTexture = TextureManager::Texture("Image/pipe-green.png", renderer);
}




void Obstacle::render(SDL_Renderer* renderer) {

    if (pipeTexture) {
        SDL_RenderCopyEx(renderer, pipeTexture, nullptr, &upperPipeRect, 0, nullptr, SDL_FLIP_VERTICAL); // Pipe trên, sdl_flip_vertical để lật ảnh lên trên
        SDL_RenderCopy(renderer, pipeTexture, nullptr, &lowerPipeRect); // Pipe dưới
    } else {  //test
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        SDL_RenderFillRect(renderer, &upperPipeRect);
        SDL_RenderFillRect(renderer, &lowerPipeRect);
    }
}
SDL_Rect Obstacle::getUpperRect() { return upperPipeRect; }
SDL_Rect Obstacle::getLowerRect() { return lowerPipeRect; }
