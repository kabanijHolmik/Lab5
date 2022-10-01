#include <iostream>
#include <cstring>
#include "Class.h"
using namespace std;



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
