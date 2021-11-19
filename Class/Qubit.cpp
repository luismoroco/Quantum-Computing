#include "Qubit.h"
using std::sqrt;

Qubit::Qubit()
    : alpha{1 / sqrt(2)}, beta{1 / sqrt(2)} {}

int 
Qubit::collapse() const
{
    double probability = (double)rand() / (double)RAND_MAX;
    if (probability < beta * beta)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}