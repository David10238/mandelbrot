
#include <complex>
#include <SDL2/SDL.h>

constexpr int DEATH_ITERATIONS = 100;

bool inJuliaSet(const std::complex<double> c, std::complex<double> z){
    //todo optimize with textbook information
    for(int i = 0; i < DEATH_ITERATIONS; i++){
        z = z*z + c;

        if(std::abs(z) < 0.1){
            return true;
        }

        if(std::abs(z) > 10.0){
            return false;
        }
    }

    return false;
}

void renderJulia(SDL_Renderer *renderer, std::complex<double> c){
    for(int x = 0; x < SIZE_PIXELS; x++){
        for(int y = 0; y < SIZE_PIXELS; y++){
            const std::complex pixel = pixelToComplex(x, y);

            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            if(inJuliaSet(c, pixel)){
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }   
    }
}