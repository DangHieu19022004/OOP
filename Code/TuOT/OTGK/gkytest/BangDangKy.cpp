#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include "SinhVien.cpp"
#include "MonHoc.cpp"

using namespace std;
// khai bao lop bang dang ky
class BangDangKy{
    private:
        MonHoc monHoc;
        SinhVien sinhVien;
        time_t thoiGianDangKy;
    public:
        BangDangKy(){};
        BangDangKy(MonHoc monHoc, SinhVien sinhVien, time_t thoiGianDangKy) : monHoc(monHoc), sinhVien(sinhVien), thoiGianDangKy(thoiGianDangKy){};
        void Xuat();
};
    
        //Xuat bang dang ky
    void BangDangKy::Xuat(){
        cout << left << setw(40) << sinhVien.getHoTen() << setw(30) << monHoc.getTenMonHoc() << setw(30) << ctime(&thoiGianDangKy) << endl;
    }