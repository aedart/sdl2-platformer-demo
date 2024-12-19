#ifndef UTILS_H
#define UTILS_H

#include <SDL2/SDL.h>

namespace Utils
{
/**
 * Returns elapsed time since SDL initialised in seconds
 *
 * @return
 */
    inline float elapsedTimeInSeconds()
    {
        float t = SDL_GetTicks();
        t *= 0.001f; // Convert to seconds

        return t;
    }
};

#endif //UTILS_H
