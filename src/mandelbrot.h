

#include <SDL2/SDL.h>
#include <complex>

bool inMandelbrot(std::complex<double> c){
    if(abs(c) <= 0.25){
        return true;
    }

    if(abs(c) > 2.0){
        return false;
    }

    return inJuliaSet(c, std::complex<double>(0.0, 0.0));
}

void renderMandelbrot(SDL_Renderer *renderer){
    for(int x = 0; x < SIZE_PIXELS; x++){
        for(int y = 0; y < SIZE_PIXELS; y++){
            const std::complex pixel = pixelToComplex(x, y);

            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            if(inMandelbrot(pixel)){
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }   
    }
}