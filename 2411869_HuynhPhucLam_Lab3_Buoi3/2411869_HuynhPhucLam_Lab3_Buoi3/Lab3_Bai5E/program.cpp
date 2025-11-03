#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

#include "thuVien.h"
#include "menu.h"

void ChayChuongTrinh()
{
    int a[MAX], n = 0;
    int menu, soMenu = 6;
    do
    {
        system("cls");
        XuatMenu();
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
        if (menu != 0)
            system("pause");
    } while (menu != 0);
}

int main()
{
    ChayChuongTrinh();
    return 0;
}