#include <SDL2/SDL.h>
#include <iostream>

int main(int argc, char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO); // Initialize SDL2

  // Create an application window with the following settings:
  SDL_Window *window = SDL_CreateWindow(
      "An SDL2 window",        //    const char* title
      SDL_WINDOWPOS_UNDEFINED, //    int x: initial x position
      SDL_WINDOWPOS_UNDEFINED, //    int y: initial y position
      640,                     //    int w: width, in pixels
      480,                     //    int h: height, in pixels
      SDL_WINDOW_SHOWN         //    Uint32 flags: window options, see docs
  );

  // Check that the window was successfully made
  if (window == nullptr) {
    // In the event that the window could not be made...
    std::cout << "Could not create window: " << SDL_GetError() << std::endl;
    SDL_Quit();

    return 1;
  }

  // The window is open: enter program loop (see SDL_PollEvent)
  SDL_Delay(3000); // Wait for 3000 milliseconds, before proceeding...

  // Close and destroy the window
  SDL_DestroyWindow(window);

  // Clean up SDL2 and exit the program
  SDL_Quit();

  return 0;
}
