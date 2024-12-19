#ifndef RENDER_WINDOW_H
#define RENDER_WINDOW_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Entity.h"

/**
 * Render Window
 */
class RenderWindow
{
    public:
        /**
         * Constructor
         *
         * @param title Title to display for window
         * @param width Width of the window
         * @param height Height of the window
         */
        RenderWindow(const char* title, int width, int height);

        /**
         * Destructor
         */
        ~RenderWindow();

        /**
         * Load texture
         *
         * @param file Full path to texture file
         *
         * @return Pointer to the loaded SDL Texture
         */
        SDL_Texture* loadTexture(const char* file);

        /**
         * Clear everything that has been rendered
         */
        void clear();

        /**
         * Render given entity
         *
         * @param entity
         */
        void render(const Entity &entity);

        /**
         * Display textures onto the screen
         */
        void display();

        /**
         * Destroy the created window
         */
        void destroy();

    protected:
        /**
         * The SDL Window pointer
         */
        SDL_Window* window;

        /**
         * The SDL Renderer
         *
         * A struct that handles all rendering
         */
        SDL_Renderer* renderer{};
};

#endif  // RENDER_WINDOW_H