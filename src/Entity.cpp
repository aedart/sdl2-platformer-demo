#include "Entity.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

Entity::Entity(const int x, const int y, SDL_Texture* texture):
    position(x, y),
    currentFrame(),
    texture(texture)
{
    this->currentFrame.x = 0;
    this->currentFrame.y = 0;
    this->currentFrame.w = 32;
    this->currentFrame.h = 32;
}

int Entity::getX()
{
    return this->getPosition().x;
}

int Entity::getY()
{
    return this->getPosition().y;
}

Position& Entity::getPosition()
{
    return this->position;
}

SDL_Texture* Entity::getTexture() const
{
    return this->texture;
}

SDL_Rect Entity::getCurrentFrame() const
{
    return this->currentFrame;
}
