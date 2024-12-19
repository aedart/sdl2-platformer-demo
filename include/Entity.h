#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * Entity
 */
class Entity
{
    public:
        /**
         * Constructor
         *
         * @param x X position on screen
         * @param y Y position on screen
         * @param texture The texture of this entity
         */
        Entity(float x, float y, SDL_Texture* texture);

    protected:
        /**
         * X position
         */
        float x;

        /**
         * Y position
         */
        float y;

        /**
         * The current frame of this entity
         */
        SDL_Rect currentFrame;

        /**
         * The texture of this entity
         */
        SDL_Texture* texture;
};

#endif  // ENTITY_H
