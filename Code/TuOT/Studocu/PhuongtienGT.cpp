#include<iostream>

using namespace std;

class PhuongTienGiaoThong{
    private:
        string HangSanXuat;
        string TenPhuongTien;
        int NamSanXuat;
        float VanTocMax;
    public:
        PhuongTienGiaoThong():HangSanXuat(""),TenPhuongTien(""),NamSanXuat(0),VanTocMax(0){};
        PhuongTienGiaoThong(string HangSanXuat, string TenPhuongTien, int NamSanXuat, float VanTocMax):HangSanXuat(HangSanXuat),TenPhuongTien(TenPhuongTien),NamSanXuat(NamSanXuat),VanTocMax(VanTocMax){};
        void Nhap();
        void Xuat();
        float getVanTocMax(){return VanTocMax;};
};

class Oto : public PhuongTienGiaoThong{
    private:
        int SoChoNgoi;
        string KieuDongCo;
    public:
        Oto():PhuongTienGiaoThong(),SoChoNgoi(0),KieuDongCo(""){};
        Oto(string HangSanXuat, string TenPhuongTien, int NamSanXuat, float VanTocMax, int SoChoNgoi, string KieuDongCo):PhuongTienGiaoThong(HangSanXuat,TenPhuongTien,NamSanXuat,VanTocMax),SoChoNgoi(SoChoNgoi),KieuDongCo(KieuDongCo){};
        ~Oto(){};
        float VanTocCoSo(){
            float vt = 
        }
};

int main(){}