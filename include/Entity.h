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
        Entity(int x, int y, SDL_Texture* texture);

        /**
         * Get the X position of entity
         *
         * @return
         */
        [[nodiscard]] int getX() const;

        /**
         * Get the Y position of entity
         *
         * @return
         */
        [[nodiscard]] int getY() const;

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
         * X position
         */
        int x;

        /**
         * Y position
         */
        int y;

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
