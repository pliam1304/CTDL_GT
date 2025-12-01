using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OnTap_CTDL_GT
{
    public class DanhSachGiangVien
    {
        LinkedList<GiangVien> ds;
        public DanhSachGiangVien()
        {
            ds = new LinkedList<GiangVien>();
        }

        //1. Nhap tu File
        //public void NhapTuFile(string tenFile)
        //{
        //    if (!File.Exists(tenFile))
        //    {
        //        Console.WriteLine($"Khong tin thay file {tenFile}!");
        //        return;
        //    }
        //    ds.Clear();
        //    try
        //    {
        //        using (StreamReader sr = new StreamReader(tenFile))
        //        {
        //            string line;
        //            while ((line = sr.ReadLine()) != null)
        //            {
        //                string[] s = line.Split(';');
        //                if (s.Length == 6)
        //                {
        //                    string ma = s[0].Trim();
        //                    string ten = s[1].Trim();
        //                    string khoa = s[2].Trim();
        //                    int nam = int.Parse(s[3].Trim());
        //                    float heSo = float.Parse(s[4].Trim());
        //                    string hocVi = s[5].Trim();
        //                    GiangVien gv = new GiangVien(ma, ten, khoa, nam, heSo, hocVi);
        //                    ds.AddLast(gv);
        //                }
        //            }
        //            sr.Close();
        //        }
        //    }

        //    catch (Exception ex)
        //    {
        //        Console.WriteLine("Loi: " + ex.Message);
        //    }
        //    Console.WriteLine("Nhap file thanh cong!");

        //}
        public void NhapTuFile(string tenFile)
        {
            if (!File.Exists(tenFile))
            {
                Console.WriteLine("Khong tim thay file!");
                return;
            }
            ds.Clear();
            try
            {
                using (StreamReader sr = new StreamReader(tenFile))
                {
                    string line;
                    while ((line = sr.ReadLine()) != null)
                    {
                        string[] strings = line.Split(';');
                        if (strings.Length == 2)
                        {

                        }
                    }
                    sr.Close();
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Loi: " + ex.Message);
            }
            Console.WriteLine("Nhap thanh cong! ");
        }
        // 2. Xuat danh sach
        public void XuatDanhSach()
        {
            if (ds.Count == 0)
            {
                Console.WriteLine("Danh sach rong!");
                return;
            }
            Console.WriteLine($"| {"Ma GV",-8} | {"Ho ten",-15} | {"Khoa",-5} | {"Nam sinh",-9} | {"He so luong",-12} | {"Hoc vi",-8} |");
            foreach (var gv in ds)
                gv.Xuat1GiangVien();
        }

        public void ThemCuoi(GiangVien gv)
        {
            this.ds.AddLast(gv);
        }

        // Xoa danh sach
        public void XoaDanhSach()
        {
            this.ds.Clear();
        }

        // Copy
        public void Copy(DanhSachGiangVien dsMoi)
        {
            dsMoi.XoaDanhSach();
            foreach (var gv in this.ds)
            {
                GiangVien gvMoi = new GiangVien(gv.MaGV, gv.HoTen, gv.Khoa, gv.NamSinh, gv.HeSoLuong, gv.HocVi);
                dsMoi.ThemCuoi(gvMoi);
            }
        }

        // Hoan vi
        private void HoanViNode(LinkedListNode<GiangVien> a, LinkedListNode<GiangVien> b)
        {
            (a.Value, b.Value) = (b.Value, a.Value);
        }

        // 3. Tim kiem giang vien theo ma giang vien
        // 3.1. Tim kiem tuyen tinh
        public LinkedListNode<GiangVien> TimKiemTuyenTinh_Ma(string ma)
        {
            LinkedListNode<GiangVien> p = ds.First;
            while (p != null)
            {
                if (p.Value.MaGV.Equals(ma)) return p;
                p = p.Next;
            }
            return null;
        }
        // 3.2. Tim kiem tuyen tinh co linh canh
        public LinkedListNode<GiangVien> TimKiemTTCoLinhCanh_Ma(string ma)
        {
            // Them phan tu linh canh
            GiangVien linhCanh = new GiangVien { MaGV = ma };
            ds.AddLast(linhCanh);

            // Duyet
            LinkedListNode<GiangVien> p = ds.First;
            while (p != null && !p.Value.MaGV.Equals(ma))
                p = p.Next;
            if (p == ds.Last) return null;
            ds.RemoveLast(); // Xoa phan tu linh canh
            return p;
        }

        // Sap tang theo ma
        public void DoiChoTrucTiep_TangMa()
        {
            if (ds.Count < 2) return;

            for (LinkedListNode<GiangVien> p = ds.First; p != null; p = p.Next)
                for (LinkedListNode<GiangVien> q = p.Next; q != null; q = q.Next)
                    if (string.Compare(p.Value.MaGV, q.Value.MaGV) > 0)
                        HoanViNode(p, q);

        }

        // 3.3. Tim kiem nhi phan
        public List<LinkedListNode<GiangVien>> GetListNode()
        {
            List<LinkedListNode<GiangVien>> tam = new List<LinkedListNode<GiangVien>>();
            LinkedListNode<GiangVien> p = ds.First;
            while (p != null)
            {
                tam.Add(p);
                p = p.Next;
            }
            return tam;
        }
        public LinkedListNode<GiangVien> TimKiemNhiPhan_Ma(string ma)
        {
            // Sap xep
            DoiChoTrucTiep_TangMa();
            List<LinkedListNode<GiangVien>> dsTam = GetListNode();
            //Tim kiem
            int left = 0, right = dsTam.Count - 1;
            while (left <= right)
            {
                int mid = (left + right) / 2;
                int cmp = string.Compare(dsTam[mid].Value.MaGV, ma);
                if (cmp == 0) return dsTam[mid];
                else if (cmp < 0) left = mid + 1;
                else right = mid - 1;
            }
            return null;
        }

        // 4. Sap xep TANG dan theo ten, neu trung ten thi GIAM dan theo nam sinh 
        //4.1. Chon truc tiep
        public void SXChonTrucTiep_TangTen_GiamNamSinh()
        {
            if (ds.Count < 2) return;
            for (LinkedListNode<GiangVien> p = ds.First; p != null; p = p.Next)
            {
                LinkedListNode<GiangVien> minNode = p;
                for (LinkedListNode<GiangVien> q = p.Next; q != null; q = q.Next)
                    if (string.Compare(minNode.Value.GetTen(), q.Value.GetTen()) > 0
                    || (string.Compare(minNode.Value.GetTen(), q.Value.GetTen()) == 0 && minNode.Value.NamSinh < q.Value.NamSinh))
                        minNode = q;
                if (minNode != p)
                    HoanViNode(minNode, p);
            }
        }

        //4.2. Chen truc tiep
        public void SXChenTrucTiep_TangTen_GiamNamSinh()
        {
            if (ds.Count < 2) return;
            LinkedListNode<GiangVien> p = ds.First.Next; // Mac dinh phan tu dau tien da duoc sap xep, bat dau tu phan tu thu 2
            while (p != null)
            {
                LinkedListNode<GiangVien> q = p;
                while (q.Previous != null) // Lay q lam moc, xet cai truoc q da dung vi tri chua
                {
                    if ((string.Compare(q.Previous.Value.GetTen(), q.Value.GetTen()) > 0)
                    || (string.Compare(q.Previous.Value.GetTen(), q.Value.GetTen()) == 0 && q.Previous.Value.NamSinh < q.Value.NamSinh))
                    {
                        HoanViNode(q.Previous, q);
                        q = q.Previous;
                    }
                    else break;
                }
                p = p.Next;
            }
        }

        // 4.3. Noi bot - Bubble Sort
        public void SXNoiBot_TangTen_GiamNamSinh()
        {
            if (ds.Count < 2) return;
            bool swap;
            do
            {
                swap = false;
                LinkedListNode<GiangVien> p = ds.First;
                while (p.Next != null)
                {
                    if (string.Compare(p.Value.GetTen(), p.Next.Value.GetTen()) > 0
                    || (string.Compare(p.Value.GetTen(), p.Next.Value.GetTen()) == 0 && p.Value.NamSinh < p.Next.Value.NamSinh))
                    {
                        HoanViNode(p, p.Next);
                        swap = true;
                    }
                    p = p.Next;
                }
            } while (swap);
        }

        // 4.4. Doi cho truc tiep
        public void SXDoiChoTrucTiep_TangTen_GiamNamSinh()
        {
            if (ds.Count < 2) return;
            for (LinkedListNode<GiangVien> p = ds.First; p != null; p = p.Next)
                for (LinkedListNode<GiangVien> q = p.Next; q != null; q = q.Next)
                    if ((string.Compare(p.Value.GetTen(), q.Value.GetTen(), StringComparison.OrdinalIgnoreCase) > 0)
                    || (string.Compare(p.Value.GetTen(), q.Value.GetTen(), StringComparison.OrdinalIgnoreCase) == 0 && p.Value.NamSinh < q.Value.NamSinh))
                        HoanViNode(p, q);
        }

        // 5. Dem so luong giang vien co he so luong [a, b]
        private void HoanViSo(float a, float b)
        {
            (a, b) = (b, a);
        }
        public int DemSLTheoHSLuong(float a, float b)
        {
            if (a > b) HoanViSo(a, b);
            int dem = 0;
            LinkedListNode<GiangVien> p = ds.First;
            while (p != null)
            {
                if (p.Value.HeSoLuong >= a && p.Value.HeSoLuong <= b) dem++;
                p = p.Next;
            }
            return dem;
        }

        // 6. Chen giang vien truoc giang vien co ma X
        public bool ChenTruocMaX(string maX, GiangVien gv)
        {
            LinkedListNode<GiangVien> nodeX = TimKiemTuyenTinh_Ma(maX);
            LinkedListNode<GiangVien> nodeGV = TimKiemTuyenTinh_Ma(gv.MaGV);
            if (nodeX != null && nodeGV == null) // Tim thay Node cua maX va giang vien them vao khong duoc co trong danh sach
            {
                ds.AddBefore(nodeX, gv);
                return true;
            }
            return false;
        }

        // 7. Xoa tat ca giang vien sinh truoc nam Y
        public void XoaGVSinhTruocNamY(int namY)
        {
            LinkedListNode<GiangVien> p = ds.First;
            while (p != null)
            {
                LinkedListNode<GiangVien> nextNode = p.Next; // Phai luu Node Next
                if (p.Value.NamSinh < namY)
                    ds.Remove(p);
                p = nextNode;
            }
        }

        // 8. Tong ke SL giang vien theo hoc vi
        public void ThongKeTheoHocVi()
        {
            int cuNhan = 0, kySu = 0, thacSi = 0, tienSi = 0;
            LinkedListNode<GiangVien> p = ds.First;
            while (p != null)
            {
                string hocVi = p.Value.HocVi;
                if (hocVi.Equals("Cu nhan")) cuNhan++;
                else if (hocVi.Equals("Ky su")) kySu++;
                else if (hocVi.Equals("Thac si")) thacSi++;
                else tienSi++;

                p = p.Next;
            }
            Console.WriteLine($"Cu nhan: {cuNhan}, Ky su: {kySu}, Thac si: {thacSi}, Tien si: {tienSi}");
        }
    }
}
