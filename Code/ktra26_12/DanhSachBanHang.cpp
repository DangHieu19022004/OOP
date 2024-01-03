#include <iostream>
#include <string>
#include <iomanip>
#include <utility>
#include "MatHang.cpp"
#include "NhanVienBanHang.cpp"

using namespace std;

class DanhSachBanHang{
    private:
        // su dung pair de luu cap NhanVienBanHang va MatHang
        pair<NhanVienBanHang*, MatHang*> NhanVienPairMatHang;
        //
        int SoLuongBanRa;
    public:
        DanhSachBanHang(){};
        DanhSachBanHang(NhanVienBanHang* nhanvien, MatHang* mathang, int SoLuongBanRa): NhanVienPairMatHang(make_pair(nhanvien, mathang)), SoLuongBanRa(SoLuongBanRa){};
        string getNhanVien(){
            return NhanVienPairMatHang.first -> getHoTen();
        }
        string getMatHang(){
            return NhanVienPairMatHang.second -> getTenHang();
        }
        int getSoluong(){
            return SoLuongBanRa;
        }
        double getLai(){
            return (NhanVienPairMatHang.second -> getGiaBan() - NhanVienPairMatHang.second -> getGiaMua());
        }
        void Xuat();
};

void DanhSachBanHang::Xuat(){
    cout << left << setw(30) << NhanVienPairMatHang.first ->getHoTen() << setw(30) << NhanVienPairMatHang.second -> getTenHang() << setw(10) << SoLuongBanRa << endl;
}
