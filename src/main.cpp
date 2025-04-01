#include"GameLoop.h"
#include"Obstacle.h"
GameLoop* g = new GameLoop();

int main(int argc, char** argv)
{
     // Display at top-right

	double first;
	double last = 0;
	g->Initialize();
	while (g->getGameState())
	{
		g->Event();
		g->Update();
		g->Render();
		first = SDL_GetTicks();
		if (first - last < 16.7)
		{
			SDL_Delay(16.7 - (first - last));
		}
		last = first;
	}
	g->Clear();
	delete g;
	return 0;
}








//const int width = 800; code cho flappy thu
//const int height = 520;
//
//int main(int argc, char* args[])
//{
//    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
//        cout << "SDL_Init error: " << SDL_GetError() << endl;
//    }
//    if (!(IMG_Init(IMG_INIT_PNG))) {
//        cout << "IMG_init error: " << SDL_GetError() << endl;
//    }
//
//    RenderWindow window("GAME v1.0", 800, 650);
//
//SDL_Renderer* renderer = window.getRenderer();
//    // Load Background
//    SDL_Texture* background = window.loadTexture("img_source/background_flappy.png");
//
//    // Load Bird Texture
//Bird bird(renderer,"img_source/try2.png",50,220,50,50);
//    // Define Bird Position and Size
//
//    bool gameRunning = true;
//    SDL_Event event;
//
//    while (gameRunning)
//    {
//        while (SDL_PollEvent(&event))
//        {
//            if (event.type == SDL_QUIT)
//            {
//                gameRunning = false;
//            }
//        }
//
//        window.clear();  // Clear the screen
//
//        window.render(background);        // Render background
//        bird.render(renderer); // Render bird at birdRect position
//
//        window.display();  // Update the window
//    }
//
//    // Clean up resources
//    SDL_DestroyTexture(background);
//    window.cleanUp();
//    SDL_Quit();
//
//    return 0;
//}


//int main(int argc, char* args[])
//{
//
//    if (SDL_Init(SDL_INIT_VIDEO)>0){
//        cout << "SDL_Init error: "<< SDL_GetError() <<endl;
//    }
//    if(!(IMG_Init(IMG_INIT_PNG)))
//    {
//        cout << "IMG_init error: "<<SDL_GetError()<<endl;
//    }
//RenderWindow window("GAME v1.0", 800, 520);
//
// SDL_Texture* background = window.loadTexture("img_source/background_flappy.png");
//
//
//bool gameRunning = true;
//
//SDL_Event event;
//
//while (gameRunning)
//
//{
//    while (SDL_PollEvent(&event))
//    {
//        if(event.type == SDL_QUIT)
//        {
//            gameRunning = false;
//        }
//    }
//
//    window.clear();
//
//
//    window.render(background);
//
//
//    window.display();
//
//}
//
//window.cleanUp();
//SDL_Quit();
//    return 0;
//}

