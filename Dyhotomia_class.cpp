#include <iostream>
#include <cmath>
#include "Dyhotomia_class.h"

Dyhotomia_class::Dyhotomia_class()
{
    a = 0;
    b = 0;
    epsilon = 0.0001;
    max_iterations = 100;
}

double Dyhotomia_class::function(double x)
{
    return x * x / 4.0 + x - 1.2502;
}

double Dyhotomia_class::pohidna(double x)
{
    return x / 2.0 + 1;
}

void Dyhotomia_class::setParameters(double at, double bt, double eps)
{
    a = at;
    b = bt;
    epsilon = eps;
}

void Dyhotomia_class::solveBisection()
    {
    int iter = 0;
    double fa = function(a), fb = function(b);

    if (fa * fb > 0)
    {
        std::cout << "Problems.\n";
        return;
    }

    while ((b - a) > epsilon && iter < max_iterations)
        {
        double c = (a + b) / 2.0;
        double fc = function(c);
        if (fa * fc < 0)
        {
            b = c;
            fb = fc;
        }
        else
        {
            a = c;
            fa = fc;
        }
        iter++;
    }

    double x = (a + b) / 2.0;
    std::cout << "Results: x = " << x << ", Iter: " << iter << "\n";
}

void Dyhotomia_class::solveNewton()
{
    int iter = 0;
    double x = 100;

    while (std::fabs(function(x)) > epsilon && iter < max_iterations)
    {
        double pf = pohidna(x);
        if (pf == 0)
        {
            std::cout << "Dopobachenia.\n";
            return;
        }
        x = x - function(x) / pf;
        iter++;
    }

    std::cout << "Results: x = " << x << ", iter: " << iter << "\n";
}