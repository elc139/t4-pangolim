#ifndef __RANDOM_H
#define __RANDOM_H
#include <random>
//
// Classe para geração de números pseudo-aleatórios.
//
class Random {
  private:
    std::minstd_rand0 generator;

  public:
    Random();
    Random(unsigned int seed);

    // Retorna próximo número da seqüência pseudo-aleatória
    // (valores entre 0.0 e 1.0)
    double nextDouble();

    void setSeed(unsigned int seed);
    void setSeedByTime();
};

#endif