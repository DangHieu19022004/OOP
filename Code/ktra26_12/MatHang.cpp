#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class MatHang{
    private:
        static int MaHangID;
        int MaHang;
        string TenHang;
        string NhomHang;
        double GiaMua;
        double GiaBan;
    public:
        MatHang(){
            this -> MaHang = MaHangID++;
        }
        MatHang(string TenHang, string NhomHang, double GiaMua, double GiaBan): TenHang(TenHang), NhomHang(NhomHang), GiaMua(GiaMua), GiaBan(GiaBan){
            this -> MaHang = MaHangID++;
        }
        string getTenHang(){
            return TenHang;
        }
        double getGiaMua(){
            return GiaMua;
        }
        double getGiaBan(){
            return GiaBan;
        }
        void Nhap();
        void Xuat();
};

int MatHang::MaHangID = 1000;

void MatHang::Nhap(){
    cout << endl << "Nhap ten hang: ";
    getline(cin, TenHang);
    cout << "Nhap nhom hang: ";
    getline(cin, NhomHang);
    cout << "Nhap gia mua: ";
    cin >> GiaMua;
    cout << "Nhap gia ban: ";
    cin >> GiaBan;
    cin.ignore();
}

void MatHang::Xuat(){
    cout << left << setw(15) << MaHang << setw(30) << TenHang << setw(30) << NhomHang << setw(30) << GiaMua << setw(10) << GiaBan << endl;
}