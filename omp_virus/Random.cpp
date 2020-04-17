#include "Random.h"
#include <chrono>

Random::Random() {
    generator = std::minstd_rand0(1);
}

void Random::setSeed(unsigned int s) {
    generator = std::minstd_rand0(s);
}

void Random::setSeedByTime() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator.seed(seed);
}

// Retorna próximo número da seqüência pseudo-aleatória
// (valores entre 0.0 e 1.0)
double Random::nextDouble() {
    return (double)generator() / (double)generator.max();
}
