#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <ctime>

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

// main
int main(){
    //Khai bao
    vector<SinhVien*> danhSachSinhVien;
    vector<MonHoc*> danhSachMonHoc;
    vector<BangDangKy*> danhSachBangDangKy;

    //bai 1: nhap danh sach mon hoc va in ra danh sach mon hoc
    int slMonHoc;
    cout << "Nhap so luong mon hoc: ";
    cin >> slMonHoc;
    cin.ignore();
        //nhap danh sach mon hoc
    for(int i=0; i<slMonHoc; i++){
        MonHoc *monHoc = new MonHoc();
        monHoc->Nhap();
        danhSachMonHoc.push_back(monHoc);
    }
        //in ra danh sach mon hoc
    cout << endl << right << setw(50) << "Danh sach mon hoc vua nhap: " << endl << endl;
    cout << left << setw(15) << "Ma mon hoc" << setw(30) << "Ten mon hoc" << setw(15) << "So tiet" << setw(30) << "Loai mon hoc" << endl;
    cout << setfill('-') << setw(85) << "-" << setfill(' ')<< endl;
    for(int i=0; i<slMonHoc; i++){
        danhSachMonHoc[i]->Xuat();
    }

    //bai 2: nhap danh sach sinh vien va in ra danh sach sinh vien
    int slSinhVien;
    cout << endl << "Nhap so luong sinh vien: ";
    cin >> slSinhVien;
    cin.ignore();
        //nhap danh sach sinh vien
    for(int i=0; i<slSinhVien; i++){
        SinhVien *sinhVien = new SinhVien();
        sinhVien->Nhap();
        danhSachSinhVien.push_back(sinhVien);
    }
        //in ra danh sach sinh vien
    cout << endl << right << setw(50) << "Danh sach sinh vien vua nhap: " << endl << endl;
    cout << left << setw(15) << "Ma sinh vien" << setw(40) << "Ho ten" << setw(40) << "Dia chi" << setw(15) << "So dien thoai" << endl;
    cout << setfill('-') << setw(110) << "-" << setfill(' ')<< endl;
    for(int i=0; i<slSinhVien; i++){
        danhSachSinhVien[i]->Xuat();
    }
    //bai 3:Lập Bảng Đăng ký cho từng sinh viên 
        //Dang ky mon hoc
    for(int i=0; i<danhSachSinhVien.size(); i++){
        for(int j=0; j<danhSachMonHoc.size(); j++){
            cout << endl << "Ban co muon dang ky mon hoc " << danhSachMonHoc[j]->getTenMonHoc() << " cho sinh vien "<< danhSachSinhVien[i]->getHoTen() << " khong? (Y/N): ";
            string check;
            getline(cin, check);
            if(check=="Y" || check=="y"){
                time_t thoigianDangKy = time(nullptr);
                BangDangKy *bangDangKy = new BangDangKy(*danhSachMonHoc[j], *danhSachSinhVien[i], thoigianDangKy);
                danhSachBangDangKy.push_back(bangDangKy);
            }
        }
    }
        //in ra bang dang ky
    cout << endl << right << setw(50) << "Danh sach bang dang ky: " << endl << endl;
    cout << left << setw(40) << "Ho ten" << setw(30) << "Ten mon hoc" << setw(30) << "Thoi gian dang ky" << endl;
    cout << setfill('-') << setw(100) << "-" << setfill(' ')<< endl;
    for(int i=0; i<danhSachBangDangKy.size(); i++){
        danhSachBangDangKy[i]->Xuat();
    }
    return 0;
}