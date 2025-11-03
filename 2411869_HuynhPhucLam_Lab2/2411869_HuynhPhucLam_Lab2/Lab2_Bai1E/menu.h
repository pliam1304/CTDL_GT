void XuatMenu() {
    cout << "\n================ MENU ================";
    cout << "\n0. Thoat chuong trinh";
    cout << "\n1. Tao danh sach nhan vien";
    cout << "\n2. Xem danh sach nhan vien";
    cout << "\n3. Tim kiem theo ho va ten";
    cout << "\n4. Tim kiem theo nam sinh";
    cout << "\n=====================================\n";
}
int ChonMenu(int soMenu)
{
    int stt;
    for (;;)
    {
        system("CLS");
        XuatMenu();
        cout << "\nNhap mot so (0 <= so <= " << soMenu << " ) de chon menu, stt = ";
        cin >> stt;
        if (0 <= stt && stt <= soMenu)
            break;
    }
    return stt;
}

void XuLyMenu(int soMenu, NhanVien a[], int& n)
{
    int kq;
    char filename[MAX];
    string ho, ten;
    switch (soMenu)
    {
    case 0:
        cout << "\nThoat chuong trinh!\n";
        break;

    case 1:
        system("CLS");
        cout << "\n1. Tao danh sach nhan vien";
        do
        {
            cout << "\nNhap ten tap tin, filename = ";
            cin >> filename;
            kq = TapTin_MangNV(filename, a, n);
            if (!kq)
                cout << "\nLoi mo tap tin, vui long nhap lai!\n";
        } while (!kq);
        cout << "\nDanh sach sinh vien vua nhap:\n";
        XuatDSNV(a, n);
        cout << endl;
        break;
    case 2:
        system("CLS");
        cout << "\n2. Xem danh sach nhan vien";
        XuatDSNV(a, n);
        break;
    case 3:
        system("CLS");
        cout << "\n3. Tim kiem theo ho va ten";
        cout << "\nNhap ho can tim: ";
        cin >> ho;
        cout << "\nNhap ten can tim: ";
        cin >> ten;
        TimKiem_TheoHoTen(a, n, ho, ten);
        break;
    case 4:
        system("CLS");
        cout << "\n4. Tim kiem theo nam sinh";
        int nam;
        cout << "\nNhap nam sinh can tim: ";
        cin >> nam;
        TimKiem_TheoNamSinh(a, n, nam);
        break;
    default:
        cout << "Lua chon khong hop le!\n";
    }
}