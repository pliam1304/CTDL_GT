using System;
using OnTap_CTDL_GT;


//ds.NhapTuFile("2411849.txt");
//ds.XuatDanhSach();
class Program
{
    static void Menu()
    {
        Console.WriteLine("Menu");
        Console.WriteLine("1. Nhap ds giang vien tu File");
        Console.WriteLine("2. Xuat danh sach giang vien");
        Console.WriteLine("3. Tim kiem theo ma giang vien");
        Console.WriteLine("3.1. Tim kiem tuyen tinh");
        Console.WriteLine("3.2. Tim kiem tuyen tinh co linh canh");
        Console.WriteLine("3.3. Tim kiem nhi phan");
        Console.WriteLine("4. Sap xep tang dan theo ten, neu ten trung nhau thi giam theo nam sinh");
        Console.WriteLine("4.1. Chon truc tiep");
        Console.WriteLine("4.2. Chen truc tiep");
        Console.WriteLine("4.3. Noi bot - Bubble Sort");
        Console.WriteLine("4.4. Doi cho truc tiep");
        Console.WriteLine("5. Dem so luong giang vien co he so luong [a,b]");
        Console.WriteLine("6. Chen 1 giang vien truoc giang vien co ma giang vien x");
        Console.WriteLine("7. Xoa tat ca giang vien sinh truoc nam Y");
        Console.WriteLine("8. Thong ke so luong giang vien theo hoc vi");
    }
    static void Main(string[] args)
    {
        DanhSachGiangVien ds = new DanhSachGiangVien();
        DanhSachGiangVien tam = new DanhSachGiangVien();

        int chon = -1;
        do
        {
            Console.Clear();
            Menu();
            Console.Write("Nhap chon: "); chon = int.Parse(Console.ReadLine());
            switch (chon)
            {
                case 0:
                    Console.WriteLine("Thoat chuong trinh!");
                    return;

                case 1:
                    Console.WriteLine("Nhap file");
                    ds.NhapTuFile("2411849.txt");
                    break;

                case 2:
                    ds.XuatDanhSach();
                    break;

                case 3:
                    Console.Write("Nhap ma giang vien can tim: ");
                    string ma = Console.ReadLine();
                    Console.WriteLine("(1) Tim kiem tuyen tinh, (2) Tim kiem tuyen tinh co linh canh, (3) Tim kiem nhi phan: ");
                    int chon1 = int.Parse(Console.ReadLine());
                    LinkedListNode<GiangVien> i = null; ;
                    if (chon1 == 1) i = ds.TimKiemTuyenTinh_Ma(ma);
                    else if (chon1 == 2) i = ds.TimKiemTTCoLinhCanh_Ma(ma);
                    else if (chon1 == 3) i = ds.TimKiemNhiPhan_Ma(ma);

                    if (i == null)
                    {
                        Console.WriteLine($"Khong tin thay giang vien co ma {ma}");
                        break;
                    }
                    else
                    {
                        Console.WriteLine($"Thong tin giang vien co ma {ma} la: ");
                        i.Value.Xuat1GiangVien();
                    }
                    break;

                case 4:
                    Console.WriteLine("Sap xep tang dan theo ten, neu ten trung nhau thi giam theo nam sinh");
                    Console.Write("(1) Chon truc tiep, (2) Chen truc tiep, (3) Noi bot, (4) Doi cho truc tiep: ");
                    chon1 = int.Parse(Console.ReadLine());
                    ds.Copy(tam);
                    if (chon1 == 1) tam.SXChonTrucTiep_TangTen_GiamNamSinh();
                    else if (chon1 == 2) tam.SXChenTrucTiep_TangTen_GiamNamSinh();
                    else if (chon1 == 3) tam.SXNoiBot_TangTen_GiamNamSinh();
                    else if (chon1 == 4) tam.SXDoiChoTrucTiep_TangTen_GiamNamSinh();
                    Console.WriteLine("Danh sach ban dau: "); ds.XuatDanhSach();
                    Console.WriteLine("Danh sach sau khi sap xep: "); tam.XuatDanhSach();

                    break;

                case 5:
                    Console.Write("Nhap a: "); float a = float.Parse(Console.ReadLine());
                    Console.Write("Nhap b: "); float b = float.Parse(Console.ReadLine());
                    ds.XuatDanhSach();
                    Console.WriteLine($"So luong giang vien co he so luong [{a},{b}]: " + ds.DemSLTheoHSLuong(a, b));
                    break;

                case 6:
                    Console.Write("Nhap ma giang vien X: "); ma = Console.ReadLine();
                    GiangVien chenGV = new GiangVien("GV0007", "A B C", "TN", 2005, 5.5f, "Tien si");
                    ds.Copy(tam);
                    bool chen = tam.ChenTruocMaX(ma, chenGV);
                    if (chen == true)
                    {
                        Console.WriteLine("Danh sach ban dau: "); ds.XuatDanhSach();
                        Console.WriteLine("Danh sach sau khi chen: "); tam.XuatDanhSach();
                    }
                    else Console.WriteLine("Khong chen duoc!");
                    break;

                case 7:
                    Console.Write("Nhap nam Y: "); int nam = int.Parse(Console.ReadLine());
                    ds.Copy(tam);
                    tam.XoaGVSinhTruocNamY(nam);
                    Console.WriteLine("Danh sach ban dau: "); ds.XuatDanhSach();
                    Console.WriteLine("Danh sach sau khi xoa: "); tam.XuatDanhSach();
                    break;

                case 8:
                    ds.ThongKeTheoHocVi();
                    ds.XuatDanhSach();
                    break;
            }
            if (chon > 0)
            {
                Console.WriteLine("Tiep tuc...");
                Console.ReadKey();
            }
        } while (chon != 0);
    }


}