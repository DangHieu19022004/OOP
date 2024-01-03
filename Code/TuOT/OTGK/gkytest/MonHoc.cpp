#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// khai bao lop mon hoc
class MonHoc{
    private:
        static int MaMHID;
        int MaMonHoc;
        string TenMonHoc;
        int TongSoTiet;
        string LoaiMonHoc;
    public:
        MonHoc(){
            this->MaMonHoc = MaMHID++;
        };
        MonHoc(string TenMonHoc, int TongSoTiet, string LoaiMonHoc) : TenMonHoc(TenMonHoc), TongSoTiet(TongSoTiet), LoaiMonHoc(LoaiMonHoc){
            this->MaMonHoc = MaMHID++;
        };
        string getTenMonHoc(){
            return this->TenMonHoc;
        }
        void Nhap();
        void Xuat();
};

    //Nhap mon hoc
void MonHoc::Nhap(){
    cout << endl << "Nhap ten mon hoc: ";
    getline(cin, TenMonHoc);
    cout << "Nhap tong so tiet: ";
    cin >> TongSoTiet;
    cin.ignore();
    cout << "Nhap loai mon hoc: ";
    getline(cin, LoaiMonHoc);
}

    //Xuat mon hoc
void MonHoc::Xuat(){
    cout << left << setw(15) << MaMonHoc << setw(30) << TenMonHoc << setw(15) << TongSoTiet << setw(30) << LoaiMonHoc << endl;
}

int MonHoc::MaMHID = 100;