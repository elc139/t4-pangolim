#ifndef __POPULATION_H
#define __POPULATION_H

#include "Random.h"
//
// Representação de um indivíduo.
// Cada indivíduo pode estar em 3 estados distintos.
//
enum Person {
    Uninfected, // pessoa não infectada
    Exposed,    // pessoa exposta
    Infected    // pessoa infectada
};
//
// Representação do posicionamento de um indivíduo.
//
struct PersonPosn {
    int i; // linhas
    int j; // colunas
} typedef PersonPosn;
//
// Classe que representa uma população contaminável.
//
class Population {
  private:
    // A população é armazenada em uma matriz.
    // Cada elemento é um indivíduo.
    Person **pop;
    int size;
    bool hasExposed;

    void reset();
    void propagate(double prob_spread, Random &r);
    bool virusSpreads(double prob_spread, Random &r);

  public:
    Population(int size);
    ~Population();

    PersonPosn centralPerson();
    int propagateUntilOut(PersonPosn sp, double prob_spread, Random &r);
    // Retorna percentual de pessoas infectadas
    double getPercentInfected();
};

#endif