#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;


#include "thuVien.h"
#include "menu.h"
void ChayChuongTrinh(NhanVien a[], int n);

void ChayChuongTrinh(NhanVien a[], int n)
{
    int menu, soMenu = 9;

    do
    {
        system("cls");
        XuatMenu();
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, a, n);
    } while (menu != 0);
}

int main()
{
    NhanVien a[MAX];
    int n = 0;
    ChayChuongTrinh(a, n);
    return 0;
}

