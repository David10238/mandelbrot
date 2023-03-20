
#include <complex>

constexpr int DEATH_ITERATIONS = 50;

bool inJuliaSet(const std::complex<double> c, std::complex<double> z){
    //todo optimize with textbook information
    for(int i = 0; i < DEATH_ITERATIONS; i++){
        if(std::abs(z) < 0.5){
            return true;
        }

        if(std::abs(z) > 100.0){
            return false;
        }

        z = z*z + c;
    }

    return false;
}