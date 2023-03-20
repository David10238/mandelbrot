
#include <utility>
#include <complex>

constexpr int SIZE_PIXELS = 1000;

std::complex<double> pixelToComplex(int x, int y){
    constexpr double D_SIZE_PIXELS = 500.0;
    constexpr double HALF_SIZE_DECIMAL = 1.0;
    constexpr double SIZE_DECIMAL = HALF_SIZE_DECIMAL * 2.0;

    const double re = ((x / D_SIZE_PIXELS) * SIZE_DECIMAL) - HALF_SIZE_DECIMAL;
    const double im = HALF_SIZE_DECIMAL - ((y / D_SIZE_PIXELS) * SIZE_DECIMAL);
    return std::complex<double>(re, im);
}