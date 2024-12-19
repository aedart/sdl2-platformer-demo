#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "RenderWindow.h"
#include "Entity.h"

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
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    // Output error, in case that renderer failed (an exception might be better here)
    if (this->renderer == nullptr) {
        std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
    }
}

RenderWindow::~RenderWindow()
{
    this->destroy();

    // window and renderer should already be set to null pointers,
    // so deleting them is redundant.
    // delete this->window;
    // delete this->renderer;
}

SDL_Texture* RenderWindow::loadTexture(const char* file)
{
    SDL_Texture* texture = IMG_LoadTexture(this->renderer, file);

    if (texture == nullptr) {
        std::cerr << "Failed to load texture: " << SDL_GetError() << std::endl;
    }

    return texture;
}

void RenderWindow::clear()
{
    SDL_RenderClear(this->renderer);
}

void RenderWindow::render(Entity &entity)
{
    const auto [
        x,
        y,
        w,
        h
    ] = entity.getCurrentFrame();

    // The source position and dimensions of the texture
    // to be copied.
    SDL_Rect source;
    source.x = x;
    source.y = y;
    source.w = w;
    source.h = h;

    // TODO: Scale factor... should somehow be at class level, or in entity?
    constexpr int scaleFactor {4};

    // The destination position and dimensions...
    SDL_Rect destination;
    destination.x = entity.getX() * scaleFactor;
    destination.y = entity.getY() * scaleFactor;
    destination.w = w * scaleFactor;
    destination.h = h * scaleFactor;

    SDL_RenderCopy(this->renderer, entity.getTexture(), &source, &destination);
}

void RenderWindow::display()
{
    SDL_RenderPresent(this->renderer);
}

void RenderWindow::destroy()
{
    this->clear();

    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);

    this->window = nullptr;
    this->renderer = nullptr;
}
