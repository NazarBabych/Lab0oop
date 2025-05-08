#include <iostream>
#include "Dyhotomia_class.h"
#include "Dyhotomia_class.cpp"

int main()
{
    Dyhotomia_class* solver = new Dyhotomia_class();

    double a = 0, b = 2, epsilon = 0.0001;
    solver->setParameters(a, b, epsilon);

    int choice;
    std::cout << "Method:\n1 Dyhotomy\n2 Newton\n> ";
    std::cin >> choice;

    if (choice == 1) solver->solveBisection();
    else if (choice == 2) solver->solveNewton();
    else std::cout << "Ahtung!!!! Falsch gewählte Methode!!!!!\n";

    delete solver;
    return 0;
}