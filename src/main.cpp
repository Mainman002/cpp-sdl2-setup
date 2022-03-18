#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

const int window_width = 1920 * 0.5;
const int window_height = 1080 * 0.5;

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL INIT FAILED" <<  SDL_GetError() << std::endl;
    }

    if (!(IMG_Init(IMG_INIT_PNG)))
    {
        std::cout << "SDL_IMG INIT FAILED" <<  SDL_GetError() << std::endl;
    }

    RenderWindow window("Game v1.0", window_width, window_height);

    SDL_Texture* playerTexture = window.loadTexture("res/img/Players/Player1/Player1.png");
    SDL_Texture* alien1Texture = window.loadTexture("res/img/Enemies/Alien_01/Alien_01_f1.png");

    Entity platform0(window_width * 0.5 - 16 * 4 * 0.5, window_height - 16 * 4 - 8, playerTexture);

    Entity a01(32, 8, alien1Texture);
    
    bool gameRunning = true;
    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }
        window.clear();

        window.render(platform0);
        
        window.render(a01);

        window.display();
    }

    window.cleanUp();
    SDL_Quit();

    return 0;
}
