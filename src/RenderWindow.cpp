#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "RenderWindow.h"

RenderWindow::RenderWindow(const char *title, const int width, const int height):
    window(nullptr),
    renderer(nullptr)
{
    // Initialise a window
    this->window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    // Output error, in case that window failed (an exception might be better here)
    if (this->window == nullptr) {
        std::cerr << "Failed to create window: " << SDL_GetError() << std::endl;
    }

    // Initialise the renderer
    this->renderer = SDL_CreateRenderer(
        this->window,
        -1,
        SDL_RENDERER_ACCELERATED
    );

    // Output error, in case that renderer failed (an exception might be better here)
    if (this->renderer == nullptr) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
    }
}

RenderWindow::~RenderWindow()
{
    this->destroy();

    // Perhaps a bit redundant, but it should be safe enough to delete
    // null pointers...
    delete this->window;
    delete this->renderer;
}

void RenderWindow::destroy()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);

    this->window = nullptr;
    this->renderer = nullptr;
}