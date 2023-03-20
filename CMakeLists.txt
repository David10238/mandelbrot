cmake_minimum_required(VERSION 3.0.0)
project(mandelbrot VERSION 0.1.0)

add_executable(mandelbrot 
    main.cpp
    src/complex.cpp
)

target_link_libraries(mandelbrot SDL2main SDL2)