#include <SDL2/SDL.h>
#include <iostream>
#include <string>
#include <vector>

#include "src/constants.h"
#include "src/julia.h"
#include "src/mandelbrot.h"

std::vector<std::string> strSplit(std::string str, char separator) {
    std::vector<std::string> strings;
    int startIndex = 0, endIndex = 0;
    for (int i = 0; i <= str.size(); i++) {
        
        // If we reached the end of the word or the end of the input.
        if (str[i] == separator || i == str.size()) {
            endIndex = i;
            std::string temp;
            temp.append(str, startIndex, endIndex - startIndex);
            strings.push_back(temp);
            startIndex = endIndex + 1;
        }
    }
    return strings;
}

int main()
{
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(SIZE_PIXELS, SIZE_PIXELS, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);


    std::cout << "1) Mandelbrot" << std::endl;
    std::cout << "2) Julia" << std::endl;
    
    std::string selection;
    std::cin >> selection;

    if(selection.compare("1") == 0){
        renderMandelbrot(renderer);
    } 
    else if(selection.compare("2") == 0){
        std::cout << "Enter real" << std::endl;
        std::string input;
        std::cin >> input;
        double re = stod(input);
        
        std::cout << "Enter imaginary" << std::endl;
        input = "";
        std::cin >> input;
        double im = stod(input);

        renderJulia(renderer, std::complex<double>(re, im));
    }
    else {
        std::cout << "Not an option, quiting" << std::endl;
        return 0;
    }

    std::cout << "Finished Render" << std::endl;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

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