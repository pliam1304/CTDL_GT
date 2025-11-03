void XuatMenu()
{
    cout << "\n==================== MENU ====================";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n1. Doc du lieu tu file";
    cout << "\n2. Xuat danh sach";
    cout << "\n3. Thuat giai Chon truc tiep";
    cout << "\n4. Thuat giai Chen truc tiep";
    cout << "\n5. Thuat giai Doi cho truc tiep";
    cout << "\n6. Thuat giai Bubble sort";
    cout << "\n=============================================\n";
}

int ChonMenu(int soMenu)
{
    int menu;
    do
    {
        cout << "\nNhap so menu (0.." << soMenu << "): ";
        cin >> menu;
    } while (menu < 0 || menu > soMenu);
    return menu;
}

void XuLyMenu(int menu, int a[MAX], int& n)
{
    char filename[MAX];
    int kq;
    system("cls");
    long ss, hv;
    switch (menu)
    {
    case 0:
        cout << "\nThoat chuong trinh!";
        break;
    case 1:
        system("cls");
        cout << "\n1. Doc du lieu tu file.";
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
        break;
    case 2:
        if (n > 0)
            XuatMang(a, n);
        else
            cout << "\nMang rong!";
        break;
    case 3:
        SelectionSort(a, n, ss, hv);
        cout << "\nSau khi sap xep (Chon truc tiep): ";
        XuatMang(a, n);
        cout << "So phep so sanh: " << ss << ", So phep hoan vi: " << hv;
        break;
    case 4:
        InsertionSort(a, n, ss, hv);
        cout << "\nSau khi sap xep (Chen truc tiep): ";
        XuatMang(a, n);
        cout << "So phep so sanh: " << ss << ", So phep hoan vi: " << hv;
        break;
    case 5:
        InterchangeSort(a, n, ss, hv);
        cout << "\nSau khi sap xep (Doi cho truc tiep): ";
        XuatMang(a, n);
        cout << "So phep so sanh: " << ss << ", So phep hoan vi: " << hv;
        break;
    case 6:
        BubbleSort(a, n, ss, hv);
        cout << "\nSau khi sap xep (Bubble sort): ";
        XuatMang(a, n);
        cout << "So phep so sanh: " << ss << ", So phep hoan vi: " << hv;
        break;
    }
}