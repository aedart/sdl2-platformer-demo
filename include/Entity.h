#ifndef ENTITY_H
#define ENTITY_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Position.h"

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
        Entity(int x, int y, SDL_Texture* texture);

        /**
         * Get the X position of entity
         *
         * @return
         */
        int getX();

        /**
         * Get the Y position of entity
         *
         * @return
         */
        int getY();

        /**
         * Get the position of this entity
         *
         * @return
         */
        Position& getPosition();

        /**
         * Get the texture used by this entity
         *
         * @return
         */
        [[nodiscard]] SDL_Texture* getTexture() const;

        /**
         * Get the texture used by this entity
         *
         * @return
         */
        [[nodiscard]] SDL_Rect getCurrentFrame() const;

    protected:
        /**
         * Position of this entity
         */
        Position position;

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
