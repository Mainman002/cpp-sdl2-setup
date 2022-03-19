#include "Entity.hpp"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

Entity::Entity(Vector2f p_pos, float p_speed, float p_scale, SDL_Texture* p_tex)
:pos(p_pos), scale(p_scale), speed(p_speed), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 16;
    currentFrame.h = 16;
}

SDL_Texture* Entity::getTex()
{
    return tex;  
}

SDL_Rect Entity::getCurrentFrame()
{
    return currentFrame;  
}

float Entity::getScale()
{
    return scale;
}

float Entity::update()
{
    pos.x = pos.x + speed;

    if (pos.x > 1920 * 0.5 / 4)
    {
        pos.x = 0 - 16;
    }

    return pos.x;
}
