#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Math.hpp"

class Entity
{
    public:
        Entity(Vector2f p_pos, float p_speed, float p_scale, SDL_Texture* p_tex);
        Vector2f& getPos()
        {
            return pos;
        }

        float getScale();
        float getSpeed();
        SDL_Texture* getTex();
        SDL_Rect getCurrentFrame();

        float update();

    private:
        Vector2f pos;
        float scale;
        float speed;
        SDL_Rect currentFrame;
        SDL_Texture* tex;
};

