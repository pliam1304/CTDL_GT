#include <iostream> 
#include <fstream>
#include<iomanip> 
#include<string.h> 

using namespace std;

#include "thuvien.h" 
#include "menu.h" 

void ChayTruongTrinh()
{
	int soMenu = 6, menu;
	sinhvien a[MAX];
	int n = 0;
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
	return 0;
}