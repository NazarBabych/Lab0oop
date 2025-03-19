#include <iostream>
#include <fstream>
#include <string>

int main()
{
    struct Price
    {
        int hrn;
        int kop;
    };
    Price price;
    int q;
    int totalhrn, totalkop =0;

    std::ifstream file(R"(C:\Users\Nazar\Desktop\lab111.txt)");
    if (!file) {
        std::cerr << "Не вдалося відкрити файл!" << std::endl;
        return 1;
    }

    std::string line;
    while (file >> price.hrn >> price.kop >> q)
    {
        totalhrn += (price.hrn*q);
        totalkop += (price.kop*q);
    }
    totalhrn += totalkop / 100;
    totalkop = totalkop % 100;
    std::cout << "Prise " << totalhrn << " Hrn " << totalkop << " kop" << std::endl;
    if (totalkop % 10 < 5) {
        totalkop -= totalkop % 10;
    }
    else {totalkop += 10 - totalkop % 10;
    }
    if (totalkop == 100) {
        totalhrn++;
        totalkop = 0;
    }

    std::cout << "payable " << totalhrn << " hrn " << totalkop << " kop" << std::endl;
    file.close();
    return 0;
}