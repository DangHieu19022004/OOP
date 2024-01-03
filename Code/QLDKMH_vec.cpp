#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>

using namespace std;

class SinhVien{
    private:
        static int idsinhvien;
        int MaSV;
        string Hoten;
        string Diachi;
        string SoDT;
    public:
        SinhVien(){
            this->MaSV = idsinhvien++;
        }
        SinhVien(string Hoten, string Diachi, string SoDT):Hoten(Hoten), Diachi(Diachi), SoDT(SoDT){
            this->MaSV = idsinhvien++;
        }
        string getHoten(){
            return Hoten;
        }
        int getMaSV(){
            return MaSV;
        }
        void nhapSV();
        void xuatSV();
};

int SinhVien::idsinhvien = 10000;

void SinhVien::nhapSV(){
    cout << "Nhap ho ten sinh vien: ";
    getline(cin, Hoten);
    cout << "Nhap dia chi sinh vien: ";
    getline(cin, Diachi);
    cout << "Nhap so dien thoai sinh vien: ";
    getline(cin, SoDT);
}

void SinhVien::xuatSV(){
    cout << "Ma sinh vien: " << MaSV << endl;
    cout << "Ho ten sinh vien: " << Hoten << endl;
    cout << "Dia chi sinh vien: " << Diachi << endl;
    cout << "So dien thoai sinh vien: " << SoDT << endl;
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
    vector<SinhVien> dssv;
    vector<MonHoc> dsmh;
    int n, m;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        SinhVien sv;
        sv.nhapSV();
        dssv.push_back(sv);
        cout << endl;
    }
    cout << endl << endl <<"Danh sach sinh vien: " <<endl;
    for(int i = 0; i < n; i++){
        dssv[i].xuatSV();
        cout<<endl;
    }
    return 0;
}