#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

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

    // Entity aliens[7] = {
    //                     Entity(16*0,0, 4, alien1Texture), 
    //                     Entity(16*1,0, 4, alien1Texture),
    //                     Entity(16*2,0, 4, alien1Texture),
    //                     Entity(16*3,0, 4, alien1Texture),
    //                     Entity(16*4,0, 4, alien1Texture),
    //                     Entity(16*5,0, 4, alien1Texture),
    //                     Entity(16*6,0, 4, alien1Texture),
    //                     };

    std::vector<Entity> entities;

    for (int x = 0; x < 12; x++){
        for (int y = 0; y < 5; y++){
            Entity alien(1*16*x,1*16*y, 4, alien1Texture);
            entities.push_back(alien);
        }
    }


    Entity players[1] = {
                        Entity(window_width / 4 * 0.5 - 8, window_height / 4 - 18, 4, playerTexture),
                        };
    
    bool gameRunning = true;
    SDL_Event event;

    // Game Loop
    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }

        // Clear window pixels
        window.clear();

        // Render Players
        for (int i = 0; i < 1; i++)
        {
            window.render(players[i]);
        }

        // Render Aliens
        for (Entity& ob : entities)
        {
            window.render(ob);
        }

        // Render Window
        window.display();
    }

    // Close window functions
    window.cleanUp();
    SDL_Quit();

    return 0;
}
