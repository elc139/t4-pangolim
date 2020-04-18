#include "Population.h"

Population::Population(int s) : size(s) {
    pop = new Person *[size];
    for (int i = 0; i < size; i++)
        pop[i] = new Person[size];
    reset();
}

Population::~Population() {
    for (int i = 0; i < size; i++)
        delete[] pop[i];
    delete[] pop;
}

PersonPosn Population::centralPerson() {
    struct PersonPosn p = {size / 2, size / 2};
    return p;
}

int Population::propagateUntilOut(PersonPosn sp, double prob_spread,
                                  Random &r) {
    int count;

    reset();
    pop[sp.i][sp.j] = Exposed;
    hasExposed = true;

    // queima a floresta até terminar o fogo
    count = 0;
    while (hasExposed) {
        propagate(prob_spread, r);
        count++;
    }

    return count;
}

double Population::getPercentInfected() {
    int total = size * size - 1;
    int sum = 0;

    // calcula quantidade de árvores queimadas
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (pop[i][j] == Infected) {
                sum++;
            }
        }
    }
    // retorna percentual de árvores queimadas
    return ((double)(sum - 1) / (double)total);
}

void Population::propagate(double prob_spread, Random &r) {

    // pessoas expostas são infectadas pelo vírus
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (pop[i][j] == Exposed)
                pop[i][j] = Infected;
        }
    }
    hasExposed = false;
    // pessoas não infectadas são expostas ao vírus quando se aproximam de uma
    // infectada
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (pop[i][j] == Infected) {
                if (i != 0) { // pessoa ao norte
                    if (pop[i - 1][j] == Uninfected &&
                        virusSpreads(prob_spread, r)) {
                        pop[i - 1][j] = Exposed;
                        hasExposed = true;
                    }
                }
                if (i != size - 1) { // pessoa ao sul
                    if (pop[i + 1][j] == Uninfected &&
                        virusSpreads(prob_spread, r)) {
                        pop[i + 1][j] = Exposed;
                        hasExposed = true;
                    }
                }
                if (j != 0) { // pessoa a oeste
                    if (pop[i][j - 1] == Uninfected &&
                        virusSpreads(prob_spread, r)) {
                        pop[i][j - 1] = Exposed;
                        hasExposed = true;
                    }
                }
                if (j != size - 1) { // pessoa a leste
                    if (pop[i][j + 1] == Uninfected &&
                        virusSpreads(prob_spread, r)) {
                        pop[i][j + 1] = Exposed;
                        hasExposed = true;
                    }
                }
            }
        }
    }
}

void Population::reset() {
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            pop[i][j] = Uninfected;
}

bool Population::virusSpreads(double prob_spread, Random &r) {
    if (r.nextDouble() < prob_spread)
        return true;
    else
        return false;
}
