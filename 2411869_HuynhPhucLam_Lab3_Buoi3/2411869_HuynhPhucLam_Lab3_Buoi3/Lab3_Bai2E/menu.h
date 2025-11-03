void XuatMenu()
{
    cout << "\n================== MENU ==================\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "1. Tao du lieu random\n";
    cout << "2. Doc du lie tu file\n";
    cout << "3. Xem du lieu\n";
    cout << "4. Thuat giai Merge Sort\n";
    cout << "5. Thuat giai Heap Sort\n";
    cout << "6. Thuat giai Radix Sort\n";
    cout << "7. Thuat giai Quick Sort\n";
    cout << "==========================================\n";
}

int ChonMenu(int soMenu)
{
    int chon;
    do
    {
        cout << "\nNhap tuy chon [0.." << soMenu << "]: ";
        cin >> chon;
    } while (chon < 0 || chon > soMenu);
    return chon;
}

void XuLyMenu(int menu, int a[MAX], int& n)
{
    int kq;
    char filename[50];

    switch (menu)
    {
    case 0:
        system("CLS");
        cout << "0. Thoat chuong trinh\n";
        break;
    case 1:
        system("CLS");
        cout << "1. Tao du lieu random\n";
        TaoDuLieu(a, n);
        break;
    case 2:
        system("CLS");
        cout << "2. Doc du lie tu file\n";
        do
        {
            cout << "\nNhap ten tap tin (vi du: test1.txt): ";
            cin >> filename;
            kq = File_Array(filename, a, n);
            if (!kq)
                cout << "\nLoi mo tap tin, vui long nhap lai!\n";
        } while (!kq);
        cout << "\nDu lieu vua doc tu tap tin:\n";
        Output(a, n);
        cout << endl;
        break;
    case 3:
        system("CLS");
        cout << "3. Xem du lieu\n";
        XemDuLieu(a, n);
        break;
    case 4:
        system("CLS");
        cout << "4. Thuat giai Merge Sort\n";
        mergeSort(a, 0, n - 1);
        cout << "Da sap xep xong";
        XemDuLieu(a, n);
        break;
    case 5:
        system("CLS");
        cout << "5. Thuat giai Heap Sort\n";
        heapSort(a, n);
        cout << "Da sap xep xong";
        XemDuLieu(a, n);
        break;
    case 6:
        system("CLS");
        cout << "6. Thuat giai Radix Sort\n";
        radixSort(a, n);
        cout << "Da sap xep xong";
        XemDuLieu(a, n);
        break;
    case 7:
        system("CLS");
        quickSort(a, 0, n - 1);
        cout << "7. Thuat giai Quick Sort";
        cout << "Da sap xep xong";
        XemDuLieu(a, n);
        break;
    }

    if (menu > 0)
    {
        cout << "Chon mot phim bat ky de tiep tuc";
        _getch();
    }
}