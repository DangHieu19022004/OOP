#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class NhanVienBanHang{
    private:
        static int MaNVId;
        int MaNV;
        string HoTen;
        string DiaChi;
        string SoDienThoai;
        string NgayHopDong;
    public:
        NhanVienBanHang(){
            this -> MaNV = MaNVId++;
        }
        NhanVienBanHang(string HoTen, string DiaChi, string SoDienThoai, string NgayHopDong): HoTen(HoTen), DiaChi(DiaChi), SoDienThoai(SoDienThoai), NgayHopDong(NgayHopDong){
            this -> MaNV = MaNVId++;
        }
        string getHoTen(){
            return HoTen;
        }
        void input();
        void output();
};

int NhanVienBanHang::MaNVId = 1000;

void NhanVienBanHang::input(){
    cout << endl << "Nhap ho ten: ";
    getline(cin, HoTen);
    cout << "Nhap dia chi: ";
    getline(cin, DiaChi);
    cout << "Nhap so dien thoai: ";
    getline(cin, SoDienThoai);
    cout << "Nhap ngay hop dong: ";
    getline(cin, NgayHopDong);
}

void NhanVienBanHang::output(){
    cout << left << setw(15) << MaNV << setw(30) << HoTen << setw(30) << DiaChi << setw(30) << SoDienThoai << setw(10) << NgayHopDong << endl;
}