#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// khai bao lop sinh vien
class SinhVien{
    private:
        static int MaSVID;
        int MaSV;
        string HoTen;
        string DiaChi;
        string SoDT;
    public:
        SinhVien(){
            this->MaSV = MaSVID++;
        };
        SinhVien(string HoTen, string DiaChi, string SoDT) : HoTen(HoTen), DiaChi(DiaChi), SoDT(SoDT){
            this->MaSV = MaSVID++;
        };
        string getHoTen(){
            return this->HoTen;
        }
        void Nhap();
        void Xuat();
};

    //Nhap sinh vien
    void SinhVien::Nhap(){
        cout << endl << "Nhap ho ten: ";
        getline(cin, HoTen);
        cout << "Nhap dia chi: ";
        getline(cin, DiaChi);
        cout << "Nhap so dien thoai: ";
        getline(cin, SoDT);
    }
    //Xuat sinh vien
    void SinhVien::Xuat(){
        cout << left << setw(15) << MaSV << setw(40) << HoTen << setw(40) << DiaChi << setw(15) << SoDT << endl;
    }

int SinhVien::MaSVID = 10000;