using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OnTap_CTDL_GT
{
    public class GiangVien
    {
        public string MaGV { get; set; }
        public string HoTen { get; set; }
        public string Khoa { get; set; }
        public int NamSinh { get; set; }
        public float HeSoLuong { get; set; }
        public string HocVi { get; set; }
        public GiangVien()
        {

        }
        public GiangVien(string maGV, string hoTen, string khoa, int namSinh, float heSoLuong, string hocVi)
        {
            MaGV = maGV;
            HoTen = hoTen;
            Khoa = khoa;
            NamSinh = namSinh;
            HeSoLuong = heSoLuong;
            HocVi = hocVi;
        }

        public string GetTen()
        {
            if (string.IsNullOrEmpty(HoTen)) return "";
            string[] s = HoTen.Split(' ');
            return s[s.Length - 1];
        }

        public string GetHo()
        {
            if (string.IsNullOrEmpty(HoTen)) return "";
            string[] s = HoTen.Split(' ');
            return s[0];
        }

        public void Xuat1GiangVien()
        {
            Console.WriteLine($"| {MaGV,-8} | {HoTen,-15} | {Khoa,-5} | {NamSinh,-9} | {HeSoLuong,-12} | {HocVi,-8} |");
        }
    }
}
