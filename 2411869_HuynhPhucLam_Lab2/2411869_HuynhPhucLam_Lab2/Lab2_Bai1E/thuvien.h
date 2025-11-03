#define		MAX		100

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define MAX 100

struct Date 
{
    int ngay[3];
    int thang[3];
    int nam[5];
};

struct NhanVien 
{
    char maNV[8];
    string ho[11];
    string tenLot[11];
    string ten[11];
    Date NTNSinh;
    string diaChi[16];
    double luong[7];
};

int TapTin_MangNV(char* filename, NhanVien a[MAX], int& n)
{
    ifstream in(filename);
    if (!in)
        return 0;
    n = 0;
    while (!in.eof() && n < MAX)
    {
        in >> a[n].maNV[0];
        in >> a[n].ho[0];
        in >> a[n].tenLot[0];
        in >> a[n].ten[0];
        in >> a[n].NTNSinh.ngay[0];
        in.ignore(); 
        in >> a[n].NTNSinh.thang[0];
        in.ignore(); 
        in >> a[n].NTNSinh.nam[0];
        in >> a[n].diaChi[0];
        in >> a[n].luong[0];
        if (in.fail()) break;
        n++;
    }
    in.close();
    return 1;
}


void Xuat1NV(NhanVien nv) 
{
    cout << left << setw(10) << nv.maNV[0]
        << setw(10) << nv.ho[0]
        << setw(10) << nv.tenLot[0]
        << setw(10) << nv.ten[0];
    cout << setw(2) << setfill('0') << nv.NTNSinh.ngay[0] << "/"
        << setw(2) << setfill('0') << nv.NTNSinh.thang[0] << "/"
        << setw(4) << setfill('0') << nv.NTNSinh.nam[0] << "   ";

    cout << setfill(' ') << setw(15) << nv.diaChi[0]
        << fixed << setprecision(0) << nv.luong[0] << endl;
}

void TieuDe_NV()
{
    cout << "\n";
    cout << ':';
    for (int i = 1; i <= 92; i++)
        cout << '=';
    cout << ":\n";

    cout << setiosflags(ios::left);
    cout << ':'
        << setw(9) << "Ma NV" << ':'
        << setw(10) << "Ho" << setw(10) << "TenLot" << setw(10) << "Ten" << ':'
        << setw(12) << "Ngay Sinh" << ':'
        << setw(15) << "Dia Chi" << ':'
        << setw(10) << "Luong" << ':';

    cout << "\n:";
    for (int i = 1; i <= 92; i++)
        cout << '=';
    cout << ":\n";
}

void Xuat_NV(NhanVien nv)
{
    cout << ':';
    cout << setiosflags(ios::left)
        << setw(9) << nv.maNV[0] << ':'
        << setw(10) << nv.ho[0]
        << setw(10) << nv.tenLot[0]
        << setw(10) << nv.ten[0] << ':';

    cout << setw(2) << setfill('0') << nv.NTNSinh.ngay[0] << "/"
        << setw(2) << setfill('0') << nv.NTNSinh.thang[0] << "/"
        << setw(4) << setfill('0') << nv.NTNSinh.nam[0] << setfill(' ') << ':';

    cout << setw(15) << nv.diaChi[0] << ':'
        << setw(10) << fixed << setprecision(0) << nv.luong[0] << ':';
}

void XuatDSNV(NhanVien a[MAX], int n)
{
    TieuDe_NV();
    for (int i = 0; i < n; i++)
    {
        Xuat_NV(a[i]);
        cout << '\n';
    }
    cout << ':';
    for (int i = 1; i <= 92; i++)
        cout << '=';
    cout << ":\n";
}

void TimKiem_TheoHoTen(NhanVien a[], int n, string ho, string ten) 
{
    cout << "\nNhan vien co ho = " << ho << " va ten = " << ten << ":\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i].ho[0] == ho && a[i].ten[0] == ten) {
            Xuat1NV(a[i]);
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay nhan vien nao phu hop!\n";
}

void TimKiem_TheoNamSinh(NhanVien a[], int n, int nam) 
{
    cout << "\nNhan vien co nam sinh = " << nam << ":\n";
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (a[i].NTNSinh.nam[0] == nam) {
            Xuat1NV(a[i]);
            found = true;
        }
    }
    if (!found) cout << "Khong tim thay nhan vien nao phu hop!\n";
}