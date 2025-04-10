#include <iostream>
#include "Calc.h"
#include <string>
#include <fstream>

int totalhrn = 0;
int totalkop = 0;

void calculate1(const std::string& filename)
{
    Price price;
    std::ifstream file(R"(C:\Users\Nazar\Desktop\lab111.txt)");
    if (!file) {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
        return;
    }
    int q;
    std::string line;
    while (file >> price.hrn >> price.kop >> q)
    {
        totalhrn += (price.hrn*q);
        totalkop += (price.kop*q);
    }
    file.close();
}
void calculate2(int& totalhrn, int& totalkop)
{
    totalhrn += totalkop / 100;
    totalkop = totalkop % 100;
    std::cout << "Prise " << totalhrn << " Hrn " << totalkop << " kop" << std::endl;
}
void calculate3(int& totalhrn, int& totalkop)
{
    if (totalkop % 10 < 5) {
        totalkop -= totalkop % 10;
    }
    else {totalkop += 10 - totalkop % 10;
    }
    if (totalkop == 100) {
        totalhrn++;
        totalkop = 0;
    }
}
void consoloutput(int& totalhrn, int& totalkop)
{
    std::cout << "payable " << totalhrn << " hrn " << totalkop << " kop" << std::endl;
}

