
#include <utility>
#include <complex>

constexpr int SIZE_PIXELS = 1000;
constexpr double D_SIZE_PIXELS = 1000.0;
constexpr double SIZE_DECIMAL = 4.0;

std::complex<double> pixelToComplex(int x, int y){
    const double reScale = (x / D_SIZE_PIXELS) * SIZE_DECIMAL;
    const double imScale = (y / D_SIZE_PIXELS) * SIZE_DECIMAL;


    constexpr double OFFSET = SIZE_DECIMAL / 2.0;
    return std::complex<double>(reScale - OFFSET, OFFSET - imScale);
}