#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

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

    std::vector<Entity> entities;

    for (int x = 0; x < 12; x++){
        for (int y = 0; y < 5; y++){
            Entity alien(Vector2f(1*16*x, 1*16*y), 4, alien1Texture);
            entities.push_back(alien);
        }
    }

    Entity players[1] = {
                        Entity(Vector2f(window_width / 4 * 0.5 - 8, window_height / 4 - 18), 4, playerTexture),
                        };
    
    bool gameRunning = true;
    SDL_Event event;

    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    // Game Loop
    while (gameRunning)
    {

        int startTicks = SDL_GetTicks();

        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {
            if (event.type == SDL_QUIT)
                gameRunning = false;
            }

            accumulator -= timeStep;
        }

        // const float alpha = accumulator / timeStep;

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

        int frameTicks = SDL_GetTicks() - startTicks;

        if (frameTicks < 1000 / window.getRefreshRate())
        {
            SDL_Delay(1000 / window.getRefreshRate() - frameTicks);
        }
    }

    // Close window functions
    window.cleanUp();
    SDL_Quit();

    return 0;
}
