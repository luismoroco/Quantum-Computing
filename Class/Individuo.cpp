#include "Individuo.h"

Individuo::Individuo(size_t size, std::vector<int> _profit, std::vector<int> _weight, int addWeight)
    : size{size}, cromosoma{new Qubit[size]}, fitness{0.f}, profit{0}, cromosome_colapsed{new int[size]}, profit_vector{_profit}, weight_vector{_weight}, sum_weight{addWeight} {}

bool 
Individuo::operator<(const Individuo &o) const
{
    return (fitness > o.fitness);
}

Qubit
&Individuo::operator[](int index)
{
    return cromosoma[index];
}

const int &Individuo::operator[](int index) const
{
    return cromosome_colapsed[index];
}

void 
Individuo::make()
{
    for (size_t i = 0; i < size; ++i)
    {
        int aux = cromosoma[i].collapse();
        cromosome_colapsed[i] = aux;
    }
}

void
Individuo::evaluate_fitness(const int type_fitness, const int max_capacity)
{
    int total_profit = 0;
    int total_weight = 0;

    for (size_t i = 0; i < size; ++i)
    {
        if (cromosome_colapsed[i] == 1)
        {
            total_profit += profit_vector[i];
            total_weight += weight_vector[i];
        }
        else
        {
            continue;
        }
    }
    profit = total_profit;
    weight = total_weight;

    if (type_fitness == 1)
    {
        fitness = profit - (sum_weight * abs(weight - max_capacity));
    }
    else if (type_fitness == 2)
    {
        fitness = profit;
    }
    else
    {
        EXIT_FAILURE;
    }
}

void 
Individuo::show_binary()
{
    for (size_t i = 0; i < size; ++i)
    {
        cout << cromosome_colapsed[i] << " ";
    }
    cout << endl;
}

void 
Individuo::repair(const int max_capacity)
{
    bool overfilled = false;

    if (get_t_weight() > max_capacity)
    {
        overfilled = true;
    }

    srand(time(0));
    int i_th;
    while (overfilled)
    {
        i_th = rand() % size;
        cromosome_colapsed[i_th] = 0;

        if (get_t_weight() <= max_capacity)
        {
            overfilled = false;
        }
    }

    srand(time(0));
    int j_th;
    while (!overfilled)
    {
        j_th = rand() % size;
        cromosome_colapsed[j_th] = 1;

        if (get_t_weight() > max_capacity)
        {
            overfilled = true;
        }
    }
    cromosome_colapsed[j_th] = 0;
}

int 
Individuo::get_t_weight()
{
    int temp_weight = 0;
    for (int i = 0; i < size; i++)
    {
        if (cromosome_colapsed[i] == 1)
        {
            temp_weight += weight_vector[i];
        }
        else
        {
            continue;
        }
    }
    return temp_weight;
}