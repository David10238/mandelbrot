#include <SDL2/SDL.h>
#include <iostream>

#include "src/constants.h"
#include "src/julia.h"

int main()
{
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SIZE_PIXELS, SIZE_PIXELS, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for(int x = 0; x < SIZE_PIXELS; x++){
        for(int y = 0; y < SIZE_PIXELS; y++){
            const std::complex pixel = pixelToComplex(x, y);

            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            if(inJuliaSet(std::complex<double>(-1, 0), pixel)){
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }   
    }

    SDL_RenderPresent(renderer);
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}