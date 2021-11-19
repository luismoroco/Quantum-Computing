#pragma once
#include "Qubit.h"

class Individuo
{
    friend class Genetic;

    private:
        Qubit *cromosoma;
        int *cromosome_colapsed;
        float fitness;
        size_t size;
        int profit;
        int weight;
        std::vector<int> profit_vector;
        std::vector<int> weight_vector;
        int sum_weight;
        int get_t_weight();

    public:
        Individuo(size_t, std::vector<int>, std::vector<int>,  int);
        bool operator<(const Individuo &) const;
        void evaluate_fitness(const int, const int);
        Qubit &operator[](int);
        const int &operator[](int) const;
        void make();
        void repair(const int);
        void show_binary();
};

#include "Individuo.cpp"