#include <SDL2/SDL.h>
#include <iostream>

#include "src/complex.h"

constexpr int WIDTH = 800;
constexpr int HEIGHT = 800;
constexpr double WIDTH_VAL = 1.0;
constexpr double HEIGHT_VAL = 1.0;

int main()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT,
                                          0);

    if(!window)
    {
        std::cout << "Failed to create window\n";
        return -1;
    }

    SDL_Surface *window_surface = SDL_GetWindowSurface(window);

    if(!window_surface)
    {
        std::cout << "Failed to get the surface from the window\n";
        return -1;
    } 

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);
}