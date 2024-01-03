#include <iostream>
#include <string>
#include <vector>
#include <ctime>

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

class BangDangKy : public SinhVien, public MonHoc{
    private:
        SinhVien SV;
        MonHoc MH;
        time_t NgayDangKy;
    public:
        BangDangKy() : SinhVien(), MonHoc() {
            this->NgayDangKy = time(0);
        }
        friend BangDangKy operator+(SinhVien a, MonHoc b);
        void xuatBDK();
};

BangDangKy operator+(SinhVien a, MonHoc b){
    BangDangKy bd;
    bd.SV = a;
    bd.MH = b;
    return bd;
}

void BangDangKy::xuatBDK(){
    cout<<"Ma sinh vien: "<<SV.getMaSV()<<endl;
    cout<<"Ma mon hoc: "<<MH.getMaMH()<<endl;
}

int main(){
    SinhVien sv[100];
    MonHoc mh[100];
    BangDangKy bdk[100];
    int n,m;
    cout << "Nhap so mon hoc: ";
    cin >> m;
    cin.ignore();
    for(int i=0; i<m; i++){
        cout << "Nhap thong tin mon hoc thu " << i+1 << endl;
        mh[i].nhapMH();
        cout<<endl;
    }
    cout << endl << ">>>>>>>>>>><<<<<<<<<<<" << endl << endl;
    for(int i=0; i<m; i++){
        cout << "Thong tin mon hoc thu " << i+1 << endl;
        mh[i].xuatMH();
        cout<<endl;
    }
    cout << endl << ">>>>>>>>>>><<<<<<<<<<<" << endl << endl;
    cout << "Nhap so sinh vien: ";
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin sinh vien thu " << i+1 << endl;
        sv[i].nhapSV();
        cout<<endl;
    }

    cout << endl << ">>>>>>>>>>><<<<<<<<<<<"<< endl << endl;
    for(int i = 0; i < n; i++){
        cout << "Thong tin sinh vien thu " << i+1 << endl;
        sv[i].xuatSV();
        cout<<endl;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            string dk;
            cout<<"Dang ky mon hoc " << mh[j].getTenMH() << " cho sinh vien " << sv[i].getHoten() << " [Y/N] : "<<endl;
            getline(cin, dk);
            if(dk == "Y" || dk == "y"){
                cout<<"Dang ky thanh cong!"<<endl;
                bdk[i]=sv[i]+mh[j];
            }
            else{
                cout<<"Dang ky that bai!"<<endl;
            }
        }
    }

    cout << endl << ">>>>>>>>>>><<<<<<<<<<<"<< endl << endl;

    for(int i=0; i<n; i++){
        cout<<"Thong tin dang ky cua sinh vien thu "<<i+1<<endl;
        bdk[i].xuatBDK();
        cout<<endl;
    }
    return false;
}