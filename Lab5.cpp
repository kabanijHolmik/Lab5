#include <iostream>
#include <cstring>

using namespace std;

class Weapon
{
public:
	Weapon(const char (*n), int bp, int pp) : blow_power(bp), protect_power(pp) {
		strcpy_s(this->name, n);
	}

protected:
	char name[20];
	int blow_power;
	int protect_power;
public:
	virtual int strike() {
		int a = 0+rand()%this->blow_power;
		this->blow_power -= a/10;
		cout << "Нанесенный урон: " << a << endl;
		return a;
	};
	virtual int protect(int power) {
		int a = 0 + rand() % this->protect_power;
		int getDamage = power-a;
		if (getDamage < 0) getDamage = 0;
		cout << "Получено урона: " << getDamage << endl;
		return getDamage;
	};
	char* getName() {
		return this->name;
	};
	void getInf() {
		cout << "Название: " << this->name << " Урон: " << this->blow_power << " Защита: " << this->protect_power << endl;
	}
	int getArmour() {
		return protect_power;
	}
	int getDamage() {
		return blow_power;
	}

};


class Shield :public Weapon
{
public:
	Shield(const char(*n), int bp, int pp): Weapon(n, bp, pp){
	}
public:
	int strike() {
		int a = 0 + rand() % this->blow_power;
		this->blow_power -= a / 10;
		return a;
	};
	int protect(int power) {
		int a = 0 + rand() % this->protect_power;
		int getDamage = power - a;
		if (getDamage < 0) getDamage = 0;
		return getDamage;
	};
};


class Club :public Weapon
{
public:
	Club(const char(*n), int bp, int pp): Weapon(n, bp, pp){
	}
	int strike() {
		int a = 0 + rand() % this->blow_power;
		this->blow_power -= a / 10;
		return a;
	};
	int protect(int power) {
		int a = 0 + rand() % this->protect_power;
		int getDamage = power - a;
		if (getDamage < 0) getDamage = 0;
		return getDamage;
	};
};


class Sword :public Weapon
{
public:
	Sword(const char(*n), int bp, int pp) : Weapon(n, bp, pp) {
	}
	int strike() {
		int a = 0 + rand() % this->blow_power;
		this->blow_power -= a / 10;
		return a;
	};
	int protect(int power) {
		int a = 0 + rand() % this->protect_power;
		int getDamage = power - a;
		if (getDamage < 0) getDamage = 0;
		return getDamage;
	};
};


int main()
{
	setlocale(LC_ALL,"ru");
	/*char s[20];
	char* s1;
	s1 = a.GetName();
	strcpy_s(s, s1);
	cout << s;*/
	Shield shield1("Металлический щит", 10, 100);
	Club club1("Деревянная дубина", 60, 30);
	Sword sword1("Двуручный меч", 80, 15);
	Weapon a("Алкаш", club1.getDamage(), shield1.getArmour());
	a.getInf();
	a.strike();
	a.getInf();
	a.protect(club1.strike());
	a.getInf();
	return 0;
}
