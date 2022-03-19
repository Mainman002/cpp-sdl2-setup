#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Math.hpp"

class Entity
{
    public:
        Entity(Vector2f p_pos, float p_s, SDL_Texture* p_tex);
        Vector2f& getPos()
        {
            return pos;
        }

        float getScale();
        SDL_Texture* getTex();
        SDL_Rect getCurrentFrame();

    private:
        Vector2f pos;
        float scale;
        SDL_Rect currentFrame;
        SDL_Texture* tex;
};

