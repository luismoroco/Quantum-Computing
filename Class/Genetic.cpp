#include "Genetic.h"

void 
Genetic::initialize_Population(std::vector<int> profit, std::vector<int> weight, const int addWeight)
{
    for (size_t i = 0; i < population_size; ++i)
    {
        population.push_back(Individuo(cromosoma_size, profit, weight, addWeight));
    }
}

void 
Genetic::make()
{
    for (size_t i = 0; i < population_size; ++i)
    {
        population[i].Individuo::make();
    }
}

void 
Genetic::repair()
{
    for (size_t i = 0; i < population_size; ++i)
    {
        population[i].Individuo::repair(max_capacity);
    }
}

void 
Genetic::evaluate()
{
    for (size_t i = 0; i < population_size; ++i)
    {
        population[i].evaluate_fitness(ty_fitness, max_capacity);
    }
    sort(population.begin(), population.end());
}

float 
Genetic::get_rotation_angle(const int xi, const int bi, bool condition)
{
    const float pi = acosf(-1);
    if (xi == 0 && bi == 1 && condition == false)
    {
        return 0.01f * pi;
    }
    else if (xi == 1 && bi == 0 && condition == false)
    {
        return -1 * 0.01f * pi;
    }
    else
    {
        return 0;
    }
}

void 
Genetic::update(Individuo &initial, Individuo &best)
{
    const float pi = acosf(-1);
    bool condition = initial.fitness >= best.fitness;
    for (size_t i = 0; i < initial.size; ++i)
    {
        float angle = get_rotation_angle(initial.cromosome_colapsed[i], best.cromosome_colapsed[i], condition);
        if ((angle >= 0 && angle <= pi / 2) || angle >= pi && angle <= (3 / 2) * pi)
        {
            initial[i].alpha = initial[i].alpha * cos(angle) - initial[i].alpha * sin(angle);
            initial[i].beta = initial[i].beta * sin(angle) + initial[i].beta * cos(angle);
        }
        else
        {
            initial[i].alpha = initial[i].alpha * sin(angle) - initial[i].alpha * cos(angle);
            initial[i].beta = initial[i].beta * -1 * sin(angle) - initial[i].beta * cos(angle);
        }
    }
}

Genetic::Genetic(size_t popu_size, size_t cromo_size, size_t generations, const int max_capacity, const int type)
    : population_size{popu_size}, cromosoma_size{cromo_size}, generations{generations}, max_capacity{max_capacity}, ty_fitness{type}
{
    population.reserve(population_size);
}

void 
Genetic::run(std::vector<int> profit, std::vector<int> weight, const int addWeight)
{
    initialize_Population(profit, weight, addWeight);
    make();
    if (ty_fitness == 2)
        repair();
    evaluate();
    Individuo best = population[0];
    for (int i = 0; i < generations; ++i)
    {
        make();
        if (ty_fitness == 2)
        {
            repair();
        }
        evaluate();

        for (int j = 0; j < population_size; ++j)
        {
            update(population[j], best);
        }

        if (population[0].fitness > best.fitness)
        {
            best = population[0];
        }
        cout << "Generation: " << i << "  fitness: " << best.fitness <<" weight: "<< best.weight << "  >>" << endl;
    }
    cout << "Best Solution:" << endl;
    best.show_binary();
    cout << "Final fitness: " << best.fitness << endl;
    cout << "Final weight: " << best.weight << endl;
    cout << "Knapsack capacity used: " << best.weight * 100 / max_capacity << "% " << endl;
    EXIT_SUCCESS;
}

Genetic::~Genetic()
{
    population.clear();
}