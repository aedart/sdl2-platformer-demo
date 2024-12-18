#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include "RenderWindow.h"

int main(int argc, char *argv[])
{
    // Window title
    const auto WINDOW_TITLE = "Game v.0.1.0";

    // Screen width in pixels
    constexpr int SCREEN_WIDTH = 1280;

    // Screen height in pixels
    constexpr int SCREEN_HEIGHT = 720;

    // Define the SDL flags for initialisation, which must be ready
    // before able to start a game loop.
    constexpr int SDL_FLAGS = SDL_INIT_VIDEO | SDL_INIT_TIMER;

    // Define the SDL Image flags for initialisation.
    constexpr int SDL_IMAGE_FLAGS = IMG_INIT_PNG;

    // -------------------------------------------------------------------------
    // Initialisation
    // -------------------------------------------------------------------------

    // Abort if SDL failed to initialise.
    if (SDL_Init(SDL_FLAGS) != 0) {
        std::cerr << "SDL Init Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    // Abort if SDL Image failed to initialise
    if (IMG_Init(SDL_IMAGE_FLAGS) == 0) {
        std::cerr << "SDL Image Init Error: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    // Init the window
    RenderWindow window(
        WINDOW_TITLE,
        SCREEN_WIDTH,
        SCREEN_HEIGHT
    );

    SDL_Texture* grassTexture = window.loadTexture("resources/gfx/ground_grass_1.png");

    // -------------------------------------------------------------------------
    // Game Loop
    // -------------------------------------------------------------------------

    // Game loop state
    bool running = true;

    // Event to listen for
    SDL_Event event;

    // While game is running...
    while (running) {

        // While polling for an SDL event...
        while (SDL_PollEvent(&event)) {
            // When user requests the window closed
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }

        window.clear();

        window.render(grassTexture);

        window.display();
    }

    // -------------------------------------------------------------------------
    // Destroy
    // -------------------------------------------------------------------------

    // Destroy the window and quit the SDL
    window.destroy();
    SDL_Quit();

    return EXIT_SUCCESS;
}
