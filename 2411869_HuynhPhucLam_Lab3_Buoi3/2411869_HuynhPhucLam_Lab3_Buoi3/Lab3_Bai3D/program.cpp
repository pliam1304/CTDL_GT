#include <iostream>
#include <fstream>

using namespace std;

#include "thuvien.h"
#include "menu.h"

void ChayTruongTrinh()
{
	int soMenu = 9, menu;
	int a[MAX], n = 0;
	do
	{
		system("cls");
		menu = ChonMenu(soMenu);
		XuLyMenu(menu, a, n);
		system("PAUSE");
	} while (menu > 0);
}

int main()
{
	ChayTruongTrinh();
	return 1;
}