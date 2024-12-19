#include "Entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Entity::Entity(const float x, const float y, SDL_Texture* texture):
    x(x),
    y(y),
    currentFrame(),
    texture(texture)
{
    this->currentFrame.x = 0;
    this->currentFrame.y = 0;
    this->currentFrame.w = 32;
    this->currentFrame.h = 32;
}

