#include <iostream>
#include "lab4.h"

// Tank
int Tank::SetArmour(std::string armo_type) { armour = armo_type; return 1; }
int Tank::IsTower(std::string is_t) { tower = is_t; return 1; }
int Tank::GunType(std::string gun_type) { gun = gun_type; return 1; }
int Tank::Mob(std::string mobility_type) { mobility = mobility_type; return 1; }
int Tank::CreateTank()
{
    std::cout << "Має " << armour << " броню та " << tower << " башту, а також " << gun << " як гармату і " << mobility << " мобільність";
    return 1;
}


ATspg::ATspg()
{
    int e = IsTower("не має");
    e = SetArmour("хорошу");
    e = GunType("Величезний 152мм дрин");
    e = Mob("Не дуже хорошу");
    e = CreateTank();
    e = Modif();
}
int ATspg::Modif()
{
    std::cout << " а також має велику дальність стрільби і фугаси на 1200\n";
    return 1;
}


LT::LT()
{
    int e = IsTower("має");
    e = SetArmour("погану");
    e = GunType("слабкий 90мм дирокол");
    e = Mob("чудову");
    e = CreateTank();
    e = Modif();
}
int LT::Modif()
{
    std::cout << " а також має чудове маскування і хороший у розвідці\n";
    return 1;
}


int LTsndGen::SetMods(std::string tank_mods)
{
    mods = tank_mods;
    return 1;
}
LTsndGen::LTsndGen(std::string tank_mods)
{
    int e = SetMods(tank_mods);
    std::cout << "\nНововведення " << mods;
}
LTsndGen::LTsndGen() {}


int LTthrdGen::SetName(std::string tank_name)
{
    name = tank_name;
    return 1;
}
int LTthrdGen::SetNation(std::string nation_)
{
    nation = nation_;
    return 1;
}
LTthrdGen::LTthrdGen(std::string tank_mods, std::string tank_name, std::string nation_)
{
    int e = SetMods(tank_mods);
    e = SetNation(nation_);
    e = SetName(tank_name);
    std::cout << "\nТо " << nation << " танк " << mods << ". Зветься " << name << std::endl;
}
