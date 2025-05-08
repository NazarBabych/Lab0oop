#include "geo.h"
#include "geo.cpp"

int main() {
    Points();
    ABCDEFG();
    int ppp;

    std::cout << "enter medod\n 1) Geron\n 2)Vector\n";
    std::cin >> ppp;
    if (ppp == 1)
    {
        Geron();
    }
    else if (ppp ==2)
    {
        Perevirka();
    }
    else
    {
        std::cout << "error";
    }
    return 0;
}












