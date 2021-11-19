#pragma once
#include "Individuo.h"

class Genetic
{
    private:
        size_t generations;
        size_t cromosoma_size;
        size_t population_size;
        const int max_capacity;
        vector<Individuo> population;
        const int ty_fitness;

    private:
        void initialize_Population(std::vector<int>, std::vector<int>, const int);
        void make();
        void repair();
        void evaluate();
        float get_rotation_angle(const int, const int, bool);
        void update(Individuo &, Individuo &);
        Individuo &operator=(const Individuo &);

    public:
        Genetic(size_t, size_t, size_t, const int, const int);
        ~Genetic();
        void run(std::vector<int>, std::vector<int>, const int);
};

#include "Genetic.cpp"