void XuatMenu()
{
    cout << "\n==================== MENU ====================\n";
    cout << "0. Thoat chuong trinh\n";
    cout << "1. Nhap danh sach nhan vien\n";
    cout << "2. Xuat danh sach nhan vien\n";
    cout << "3. Sap tang theo MaNV\n";
    cout << "4. Sap tang theo DiaChi\n";
    cout << "5. Sap tang theo Luong (Heap Sort)\n";
    cout << "6. Sap tang theo Luong (Quick Sort)\n";
    cout << "7. Sap tang theo Luong (Merge Sort)\n";
    cout << "8. Sap tang theo Luong (Shaker Sort)\n";
    cout << "9. Sap tang theo NamSinh (Radix Sort)\n";
    cout << "==============================================\n";
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

void XuLyMenu(int menu, NhanVien ds[MAX], int& n)
{
    char filename[MAX];
    int kq;
    system("cls");
    switch (menu)
    {
    case 0:
        cout << "0. Thoat chuong trinh\n";
        break;
    case 1:
        system("cls");
        cout << "\n1. Doc du lieu tu file.";
        cout << "\nNhap ten file: ";
        cin >> filename;

        kq = File_Array(filename, ds, n);
        if (kq)
            cout << "\nDoc file thanh cong. Co " << n << " sinh vien.";
        else
            cout << "\nKhong mo duoc file!";
        break;
    case 2:
        system("cls");
        cout << "\n2. Xuat danh sach nhan vien.\n";
        if (n > 0)
            Output_Arr(ds, n);
        else
            cout << "\nDanh sach rong!";
        break;
    case 3:
        cout << "3. Sap tang theo MaNV\n";
        SapTangTheoMa(ds, n);
        cout << "DS sau khi sap xep: \n";
        Output_Arr(ds, n);
        break;
    case 4:
        cout << "4. Sap tang theo DiaChi\n";
        SapTangTheoDiaChi(ds, n);
        cout << "DS sau khi sap xep: \n";
        Output_Arr(ds, n);
        break;
    case 5:
        cout << "5. Sap tang theo Luong (Heap Sort)\n";
        heapSortLuong(ds, n);
        cout << "DS sau khi sap xep: \n";
        Output_Arr(ds, n);
        break;
    case 6:
        cout << "6. Sap tang theo Luong (Quick Sort)\n";
        quickSortLuong(ds, 0, n - 1);
        cout << "DS sau khi sap xep: \n";
        Output_Arr(ds, n);
        break;
    case 7:
        cout << "7. Sap tang theo Luong (Merge Sort)\n";
        mergeSortLuong(ds, 0, n - 1);
        cout << "DS sau khi sap xep: \n";
        Output_Arr(ds, n);
        break;
    case 8:
        cout << "8. Sap tang theo Luong (Shaker Sort)\n";
        shakerSortLuong(ds, n);
        cout << "DS sau khi sap xep: \n";
        Output_Arr(ds, n);
        break;
    case 9:
        cout << "9. Sap tang theo NamSinh (Radix Sort)\n";
        radixSortNamSinh(ds, n);
        cout << "DS sau khi sap xep: \n";
        Output_Arr(ds, n);
        break;
    }

    if (menu > 0)
    {
        cout << "\nNhan phim bat ky de tiep tuc...";
        _getch();
    }
}