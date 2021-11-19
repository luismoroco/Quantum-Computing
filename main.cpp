#include "./Class/Genetic.h"

// Testing Data!

vector<int> profit_vector = {15, 13, 21, 22, 18, 12, 16, 23, 16, 14, 27, 14, 28, 10, 24, 14, 20, 17, 14, 18, 13, 15, 18, 26, 15, 24, 12, 11, 26, 15, 24, 26, 23, 24, 17, 12, 28, 26, 21, 11, 25, 22, 24, 21, 23, 10, 11, 29, 15, 14};
vector<int> weight_vector = {16, 8, 12, 10, 7, 15, 12, 17, 5, 9, 15, 6, 8, 13, 10, 13, 16, 5, 6, 12, 10, 14, 13, 17, 19, 9, 11, 7, 12, 11, 18, 14, 10, 9, 16, 8, 14, 17, 9, 17, 17, 7, 16, 15, 14, 16, 13, 11, 7, 5};
const int sum_weight = 591;

/*
*  This is a short Framework for Quantum-Genetic Testing
*  inside 'Genetic (x, y, z, m, t)'
*  x = Population size
*  y = Cromosome size 
*  z = Number of Generations (Crossover and death of individuals)
*  m = Max KnapSack Capacity
*  t = Type of crossover (Penalty : 1 || Repair(Best) : 2)
*  
*  Run(p, w, s) where :
*  p = Profit vector 
*  w = Weight vector
*  s = Sum of all weights
*
*  Data is indexing for memory positions : 
*  Object[i] Object has: 
            profit : p[i] 
            weight : w[i]
*
*  Then, we can press 'Run' for execute! 
*/

int main(int argc, char **argv)
{
    puts("fitness : Penalty!");
    srand(static_cast<unsigned int>(time(nullptr)));
    Genetic a(20, 50, 1000, 300, 1);
    a.run(profit_vector, weight_vector, sum_weight);

    puts("fitness : Repair");
    srand(static_cast<unsigned int>(time(nullptr)));
    Genetic b(20, 50, 1000, 300, 2);
    b.run(profit_vector, weight_vector, sum_weight);

    return EXIT_SUCCESS;
}