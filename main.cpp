#include <iostream>

class Tank
{
	std::string armour;
	std::string tower;
	std::string gun;
	std::string mobility;

	public:
	int SetArmour (std::string armo_type)
	{
		armour = armo_type;
		return 1;
	};
	int IsTower (std::string is_t)
	{
		tower = is_t;
		return 1;
	};
	int GunType (std::string gun_type)
	{
		gun = gun_type;
		return 1;
	};
	int Mob (std::string mobility_type)
	{
		mobility = mobility_type;
		return 1;
	};
	protected:
	int CreateTank()
	{
		std::cout << "Має " << armour << " броню та " << tower << " башту, а також " << gun << " як гармату і " << mobility << " мобільність";
		return 1;
	};
	int Modif()
	{
		std::cout << "\n";
		return 1;
	};
};

class ATspg:Tank
{
	public:
	ATspg()
	{
		int e = IsTower("має");
		e = SetArmour("хорошу");
		e = GunType("Величезний 152мм дрин");
		e = Mob("Не дуже хорошу");
		e = Modif();
	};
	int Modif()
	{
		std::cout << " а також має велику дальність стрільби і фугаси на 1200\n";
		return 1;
	};
};

class LT:Tank
{
	public:
	LT()
	{
		int e = IsTower("має");
		e = SetArmour("погану");
		e = GunType("слабкий 90мм дирокол");
		e = Mob("чудову");
		e = Modif();
	};
	int Modif()
	{
		std::cout << " а також має чудове маскування і хороший у розвідці\n";
		return 1;
	};

};

class LTsndGen:LT
{
	protected:
	std::string mods;

	public:
	int SetMods(std::string tank_mods)
	{
		mods = tank_mods;
		return 1;
	};

	LTsndGen(std::string tank_mods)
	{
		int e = SetMods (tank_mods);
		std::cout <<"\n Нововведення " << mods;
	}
	LTsndGen(){}
};

class LTthrdGen: LTsndGen
{
	std::string name;
	std::string nation;

	public:
	int SetName (std::string tank_name)
	{
		name = tank_name;
		return 1;
	};

	int SetNation (std::string nation)
	{
		nation = nation;
		return 1;
	};

	LTthrdGen (std::string tank_mods, std::string tank_name, std::string nation)
	{
		int e =  SetMods (tank_mods);
		e =  SetNation (nation);
		e =  SetName (tank_name);
		std::cout <<"\n То "<< nation << " танк " << mods << ". Зветься " << name;
	}
};
int main()
{
	LTthrdGen *tank = new LTthrdGen("з магазином заряджання", "tvp t 50/51 b", "чеський");
}
