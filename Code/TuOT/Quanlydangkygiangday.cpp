#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <regex>

using namespace std;

class GiangVien{
    private:
        static int MaGVID;
        int MaGV;
        string HoTen;
        string DiaChi;
        string SoDT;
        string Khoa;
    public:
        GiangVien(){
            this -> MaGV = MaGVID++;
        }
        GiangVien(string DiaChi, string SoDT, string Khoa) : DiaChi(DiaChi), SoDT(SoDT), Khoa(Khoa){
            this -> MaGV = MaGVID++;
        }
        void Nhap();
        void Xuat();
};

int GiangVien::MaGVID = 10000;

void GiangVien::Nhap(){
    cout << "Nhap ho ten giang vien: ";
    getline(cin, HoTen);
    cout << "Nhap dia chi giang vien: ";
    getline(cin, DiaChi);
    cout << "Nhap so dien thoai giang vien: ";
    getline(cin, SoDT);
    cout << "Nhap khoa giang vien: ";
    getline(cin, Khoa);
}

void GiangVien::Xuat(){
    cout << "Ma giang vien: " << MaGV << endl;
    cout << "Ho ten giang vien: " << HoTen << endl;
    cout << "Dia chi giang vien: " << DiaChi << endl;
    cout << "So dien thoai giang vien: " << SoDT << endl;
    cout << "Khoa giang vien: " << Khoa << endl;
}


class MonHoc{
    private:
        static int idmonhoc;
        int MaMH;
        string TenMH;
        int TongSoTiet;
        string LoaiMH;
    public:
        MonHoc(){
            this->MaMH = idmonhoc++;
        }
        MonHoc(string TenMH, int TongSoTiet, string LoaiMH):TenMH(TenMH), TongSoTiet(TongSoTiet), LoaiMH(LoaiMH){
            this->MaMH = idmonhoc++;
        }
        string getTenMH(){
            return TenMH;
        }
        int getMaMH(){
            return MaMH;
        }
        void nhapMH();
        void xuatMH();
};

int MonHoc::idmonhoc = 100;

void MonHoc::nhapMH(){
    cout << "Nhap ten mon hoc: ";
    getline(cin, TenMH);
    cout << "Nhap tong so tiet cua mon hoc: ";
    cin >> TongSoTiet;
    cin.ignore();
    cout << "Nhap loai mon hoc: ";
    getline(cin, LoaiMH);
}

void MonHoc::xuatMH(){
    cout << "Ma mon hoc: " << MaMH << endl;
    cout << "Ten mon hoc: " << TenMH << endl;
    cout << "Tong so tiet cua mon hoc: " << TongSoTiet << endl;
    cout << "Loai mon hoc: " << LoaiMH << endl;
}

int main(){
    vector<GiangVien*> Listgv;
    vector<MonHoc*> Listmh;
    //Nhap danh sach mon hoc
    int n;
    cout << "Nhap so luong mon hoc: ";
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        MonHoc *mh = new MonHoc();
        mh->nhapMH();
        Listmh.push_back(mh);
    }
    cout << endl << endl << "Danh sach mon hoc" << endl;
    for(int i = 0; i < Listmh.size(); i++){
        Listmh[i]->xuatMH();
    }
    //Nhap danh sach giang vien
    int m;
    cout << "Nhap so luong giang vien: ";
    cin >> m;
    cin.ignore();
    for(int i = 0; i < m; i++){
        GiangVien *gv = new GiangVien();
        gv->Nhap();
        Listgv.push_back(gv);
    }
    cout << endl << endl << "Danh sach giang vien" << endl;
    for(int i = 0; i < Listgv.size(); i++){
        Listgv[i]->Xuat();
    }
}