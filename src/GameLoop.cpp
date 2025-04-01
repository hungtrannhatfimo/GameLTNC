#include "GameLoop.h"
#include <iostream>

#define SCREEN_HEIGHT 600
#define GROUND_HEIGHT 190
using namespace std;

bool GameLoop::gameStarted = false;
int GameLoop::score = 0;

SDL_Texture* digits[10];

GameLoop::GameLoop() : pipe1(WIDTH), pipe2(WIDTH + WIDTH / 2) {
    window = nullptr;
    renderer = nullptr;
    GameState = false;

    p.setSrc(0, 0, 24, 32);
    p.setDest(25, HEIGHT / 2, 28, 38);
    ground1.setSrc(0, 0, 180, 800);
    ground1.setDest(0, 420, 180, 800);
}

// Load textures for digits (0-9)
void GameLoop::loadDigitTextures() {
    for (int i = 0; i < 10; i++) {
        string filename = "Image/" + to_string(i) + ".png";
        digits[i] = IMG_LoadTexture(renderer, filename.c_str());
        if (!digits[i]) {
            cerr << "Failed to load " << filename << ": " << IMG_GetError() << endl;
        }
    }
}

// Render score on screen
void GameLoop::renderScore(int x, int y) {
    string scoreStr = to_string(score);
    int digitWidth = 20, digitHeight = 30;

    for (size_t i = 0; i < scoreStr.size(); i++) {
        int digit = scoreStr[i] - '0';
        SDL_Rect destRect = {x + (i * digitWidth), y, digitWidth, digitHeight};
        SDL_RenderCopy(renderer, digits[digit], nullptr, &destRect);
    }
}

bool GameLoop::getGameState() {
    return GameState;
}

void GameLoop::checkCollision() {
    SDL_Rect birdRect = p.getDest();
    SDL_Rect pipe1Upper = pipe1.getUpperRect();
    SDL_Rect pipe1Lower = pipe1.getLowerRect();
    SDL_Rect pipe2Upper = pipe2.getUpperRect();
    SDL_Rect pipe2Lower = pipe2.getLowerRect();

    if (SDL_HasIntersection(&birdRect, &pipe1Upper) || SDL_HasIntersection(&birdRect, &pipe1Lower) ||
        SDL_HasIntersection(&birdRect, &pipe2Upper) || SDL_HasIntersection(&birdRect, &pipe2Lower)) {
        cout << "Game Over! Bird hit a pipe." << endl;
        SDL_Quit();
        exit(0);
    }

    if (birdRect.y + birdRect.h >= SCREEN_HEIGHT - GROUND_HEIGHT) {
        cout << "Game Over! Bird hit the ground." << endl;
        SDL_Quit();
        exit(0);
    }

    if (birdRect.y <= 0) {
        cout << "Game Over! Bird hit the top." << endl;
        SDL_Quit();
        exit(0);
    }

    // Increase score when the bird passes a pipe
    if (p.getDest().x > pipe1.getUpperRect().x + pipe1.getUpperRect().w && !pipe1.passed) {
        score++;
        pipe1.passed = true;
    }
    if (p.getDest().x > pipe2.getUpperRect().x + pipe2.getUpperRect().w && !pipe2.passed) {
        score++;
        pipe2.passed = true;
    }
}

void GameLoop::Initialize() {
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("My Flappy Doms", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    if (window) {
        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer) {
            cout << "Succeeded!" << endl;
            GameState = true;
            p.CreateTexture("Image/yellowbird1.png", renderer);
			p.CreateTexture1("Image/yellowbird2.png", renderer);
			p.CreateTexture2("Image/yellowbird3.png", renderer);

			b.CreateTexture("img_source/background_flappy.png", renderer);

			ground1.CreateTexture("img_source/base.png", renderer);

			loadDigitTextures();

        } else {
            cerr << "Renderer not created!" << endl;
        }
    } else {
        cerr << "Window not created!" << endl;
    }
}

void GameLoop::Event() {
    p.GetJumpTime();
    SDL_PollEvent(&event1);
    if (event1.type == SDL_QUIT) {
        GameState = false;
    }

    if (event1.type == SDL_MOUSEBUTTONDOWN || event1.type == SDL_KEYDOWN) {
        if (event1.key.keysym.sym == SDLK_UP || event1.button.button == SDL_BUTTON_LEFT || event1.key.keysym.sym == SDLK_SPACE) {
            if (!p.JumpState()) {
                gameStarted = true;
                p.Jump();
            }
        }
    }

    if (gameStarted) {
        p.Gravity();
    }
}

void GameLoop::Update() {
    pipe1.update();
    pipe2.update();
    checkCollision();
}

void GameLoop::Render() {
    SDL_RenderClear(renderer);
    b.Render(renderer);
    pipe1.render(renderer);
    pipe2.render(renderer);
    ground1.GroundRender(renderer);
    p.Render(renderer);
    renderScore(700, 50); // Display score at top-right
    SDL_RenderPresent(renderer);
}

void GameLoop::Clear() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}




//#include "GameLoop.h"
//#include <iostream>
//
//#define SCREEN_HEIGHT 600
//#define GROUND_HEIGHT 190
//using namespace std;
//bool GameLoop::gameStarted=false;
//int GameLoop::score = 0;
//GameLoop::GameLoop():pipe1(WIDTH), pipe2(WIDTH + WIDTH / 2)
//{
//	window = nullptr;
//	renderer = nullptr;
//	GameState = false;
//
//
//	p.setSrc(0, 0, 24, 32);
//	p.setDest(25, HEIGHT/2, 28, 38);
//	ground1.setSrc(0, 0, 180, 800);
//	ground1.setDest(0, 420, 180, 800);
//
//}
//
//SDL_Texture*digits[10];
//
//void loadDigitTextures(SDL_Renderer*renderer)
//{
//        for (int i = 0; i < 10; i++) {
//        std::string filename = "Image/" + std::to_string(i) + ".png"; // e.g., "assets/0.png"
//        digits[i] = IMG_LoadTexture(renderer, filename.c_str());
//        if (!digits[i]) {
//            std::cerr << "Failed to load " << filename << ": " << IMG_GetError() << std::endl;
//        }
//    }
//}
//
//void renderScore(SDL_Renderer* renderer, int score, int x, int y) {
//    std::string scoreStr = std::to_string(score);
//    int digitWidth = 20, digitHeight = 30; // Adjust based on your images
//
//    for (size_t i = 0; i < scoreStr.size(); i++) {
//        int digit = scoreStr[i] - '0'; // Convert char to int
//        SDL_Rect destRect = {x + (i * digitWidth), y, digitWidth, digitHeight};
//        SDL_RenderCopy(renderer, digits[digit], nullptr, &destRect);
//    }
//}
//
//bool GameLoop::getGameState()
//{
//	return GameState;
//}
//
//void GameLoop::checkCollision()
//{
//    SDL_Rect birdRect = p.getDest();
//    SDL_Rect pipe1Upper = pipe1.getUpperRect();
//    SDL_Rect pipe1Lower = pipe1.getLowerRect();
//    SDL_Rect pipe2Upper = pipe2.getUpperRect();
//    SDL_Rect pipe2Lower = pipe2.getLowerRect();
//
//    if (SDL_HasIntersection(&birdRect, &pipe1Upper) || SDL_HasIntersection(&birdRect, &pipe1Lower) ||
//        SDL_HasIntersection(&birdRect, &pipe2Upper) || SDL_HasIntersection(&birdRect, &pipe2Lower))
//    {
//        cout << "Game Over! Bird hit a pipe." << endl;
//       SDL_Quit();
//       exit(0);
//    }
//
//    if (birdRect.y + birdRect.h >= screen_height-ground_height)
//    {
//        cout << "Game Over! Bird hit the ground." << endl;
//        SDL_Quit();
//        exit(0);
//    }
//
//    if (birdRect.y <= 0)
//    {
//        cout << "Game Over! Bird hit the top." << endl;
//        SDL_Quit();
//        exit(0);
//    }
//
//}
//
//void GameLoop::Intialize()
//{
//	SDL_Init(SDL_INIT_EVERYTHING);
//	window = SDL_CreateWindow("My Flappy Doms", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
//	if (window)
//	{
//		renderer = SDL_CreateRenderer(window, -1, 0);
//		if (renderer)
//		{
//			cout << "Succeeded!" << endl;
//			GameState = true;
//            p.CreateTexture("Image/yellowbird1.png", renderer);
//			p.CreateTexture1("Image/yellowbird2.png", renderer);
//			p.CreateTexture2("Image/yellowbird3.png", renderer);
//
//			b.CreateTexture("img_source/background_flappy.png", renderer);
//
//			ground1.CreateTexture("img_source/base.png", renderer);
//
//			loadDigitTextures(renderer);
//
//		}
//		else
//		{
//			std::cout << "Not created!" << std::endl;
//		}
//	}
//	else
//	{
//		std::cout << "window not created!" << std::endl;
//	}
//}
//
//void GameLoop::Event()
//{
//	p.GetJumpTime();
//	SDL_PollEvent(&event1);
//	if (event1.type == SDL_QUIT)
//	{
//		GameState = false;
//	}
//
//if (event1.type == SDL_MOUSEBUTTONDOWN || event1.type == SDL_KEYDOWN)
//    {
//
//        if (event1.key.keysym.sym == SDLK_UP || event1.button.button == SDL_BUTTON_LEFT || event1.key.keysym.sym == SDLK_SPACE)
//        {
//            if (!p.JumpState())
//            {gameStarted = true;
//                p.Jump();
//            }
//        }
//    }
//
//
//    if (gameStarted)
//    {
//        p.Gravity();
//    }
//}
//
//void GameLoop::Update()
//{
//
//	pipe1.update();
//    pipe2.update();
//    checkCollision();
//}
//
//void GameLoop::Render()
//{
//	SDL_RenderClear(renderer);
//renderScore(renderer,score, 700, 50);
//	b.Render(renderer);
//	pipe1.render(renderer);
//    pipe2.render(renderer);
//	ground1.GroundRender(renderer);
//	p.Render(renderer);
//	SDL_RenderPresent(renderer);
//}
//
//void GameLoop::Clear()
//{
//
//	SDL_DestroyRenderer(renderer);
//	SDL_DestroyWindow(window);
//}
