#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "Entity.hpp"

Entity::Entity(float p_x, float p_y, float p_s, SDL_Texture* p_tex)
:x(p_x), y(p_y), scale(p_s), tex(p_tex)
{
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 16;
    currentFrame.h = 16;
}

float Entity::getX()
{
    return x;    
}

float Entity::getY()
{
    return y;  
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
