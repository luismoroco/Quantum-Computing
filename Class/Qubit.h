#pragma once

#include <bits/stdc++.h>

using namespace std;


class Qubit
{
    friend class Genetic;

    private:
        double alpha;
        double beta;

    public:
        Qubit();
        int collapse() const;
};

#include "Qubit.cpp"