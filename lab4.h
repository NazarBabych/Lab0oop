#pragma once
#include <string>

class Tank
{
    std::string armour;
    std::string tower;
    std::string gun;
    std::string mobility;

public:
    int SetArmour(std::string armo_type);
    int IsTower(std::string is_t);
    int GunType(std::string gun_type);
    int Mob(std::string mobility_type);

protected:
    int CreateTank();
};

class ATspg : public Tank
{
public:
    ATspg();
    int Modif();
};

class LT : public Tank
{
public:
    LT();
    int Modif();
};

class LTsndGen : public LT
{
protected:
    std::string mods;

public:
    int SetMods(std::string tank_mods);
    LTsndGen(std::string tank_mods);
    LTsndGen();
};

class LTthrdGen : public LTsndGen
{
    std::string name;
    std::string nation;

public:
    int SetName(std::string tank_name);
    int SetNation(std::string nation);
    LTthrdGen(std::string tank_mods, std::string tank_name, std::string nation);
};




