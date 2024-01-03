#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include <regex>

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

class DanhSachBanHang{
    private:
        pair<NhanVienBanHang*, MatHang*> NhanVienPairMatHang;
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

int main(){
    vector<NhanVienBanHang*> ListnhanVien;
    vector<MatHang*> ListmatHang;
    vector<DanhSachBanHang*> ListdanhSachBanHang;
    //1. Nhap danh sach hang + in
    int soLuongHang;
    cout << "Nhap so luong hang: ";
    cin >> soLuongHang;
    cin.ignore();
    for(int i = 0; i < soLuongHang; i++){
        cout << endl << "Nhap thong tin hang thu " << i + 1 << ": " << endl;
        MatHang* temp = new MatHang();
        temp -> Nhap();
        ListmatHang.push_back(temp);
    }
    cout << endl;
    cout << right << setw(80) << "Danh sach mat hang vua nhap: " << endl;
    cout << left << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
    cout << left << setw(15) << "Ma hang" << setw(30) << "Ten hang" << setw(30) << "Nhom hang" << setw(30) << "Gia mua" << setw(10) << "Gia ban" << endl;
    cout << left << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
    for(int i = 0; i < ListmatHang.size(); i++){
        ListmatHang[i] -> Xuat();
    }
    //2. Nhap danh sach nhan vien + in
    int soLuongNhanVien;
    cout << endl << "Nhap so luong nhan vien: ";
    cin >> soLuongNhanVien;
    cin.ignore();
    for(int i = 0; i < soLuongNhanVien; i++){
        cout << endl << "Nhap thong tin nhan vien thu " << i + 1 << ": " << endl;
        NhanVienBanHang* temp = new NhanVienBanHang();
        temp -> input();
        ListnhanVien.push_back(temp);
    }
    cout << endl;
    cout << right << setw(80) << "Danh sach nhan vien vua nhap: " << endl;
    cout << left << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
    cout << left << setw(15) << "Ma NV" << setw(30) << "Ho ten" << setw(30) << "Dia chi" << setw(30) << "So dien thoai" << setw(10) << "Ngay HD" << endl;
    cout << left << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
    for(int i = 0; i < ListnhanVien.size(); i++){
        ListnhanVien[i] -> output();
    }
    //3.1 Lap bang ban hang
    cout << endl << right << setw(80) << "Nhap thong tin ban hang(Nhap x hoac de trong de ket thuc): " << endl;
    for(int i=0; i < ListnhanVien.size(); i++){
        bool check=false;
        do{
            cout << endl << "Nhap thong tin ban hang cua nhan vien " << ListnhanVien[i]->getHoTen() << ": " << endl;
            cout << "Nhap ten hang ban ra: ";  
            string tenHang;
            getline(cin, tenHang);
            if(tenHang == "x" || tenHang == "X" || tenHang == ""){
                check = true;
                cout << "Da ket thuc nhap thong tin ban hang cua nhan vien " << ListnhanVien[i]->getHoTen() << "! " << endl;
                break;
            }
            cout << "Nhap so luong ban ra: ";
            int soLuong;
            cin >> soLuong;
            cin.ignore();
            pair<string, int> Thongtin = make_pair(tenHang, soLuong);
            for(int j=0; j < ListmatHang.size(); j++){
                if(ListmatHang[j]->getTenHang() == Thongtin.first){
                    DanhSachBanHang* temp = new DanhSachBanHang(ListnhanVien[i], ListmatHang[j], Thongtin.second);
                    ListdanhSachBanHang.push_back(temp);
                    break;
                }
                if(j == ListmatHang.size() - 1){
                    cout << "Khong tim thay ten hang trong danh sach hang hoa! Vui long Nhap lai" << endl;
                }
            }
        }while(check==false);
    }
    //3.2 In bang ban hang
    cout << endl << endl << right << setw(50) << "Bang ban hang: " << endl;
    cout << left << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    cout << left << setw(30) << "Nhan vien" << setw(30) << "Mat hang" << setw(10) << "So luong" << endl;
    cout << left << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    for(int i=0; i < ListdanhSachBanHang.size(); i++){
        ListdanhSachBanHang[i]->Xuat();
    }

    //4 Sap xep
    //4.1 Sap xep theo ten nhan vien
    for(int i=0; i < ListdanhSachBanHang.size() - 1; i++){
        for(int j=i+1; j < ListdanhSachBanHang.size(); j++){
            if(ListdanhSachBanHang[i]->getNhanVien() > ListdanhSachBanHang[j]->getNhanVien()){
                swap(ListdanhSachBanHang[i], ListdanhSachBanHang[j]);
            }
        }
    }
    cout << endl << endl << right << setw(60) << "Bang ban hang sap xep theo ten nhan vien: " << endl;
    cout << left << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    cout << left << setw(30) << "Nhan vien" << setw(30) << "Mat hang" << setw(10) << "So luong" << endl;
    cout << left << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    for(int i=0; i < ListdanhSachBanHang.size(); i++){
        ListdanhSachBanHang[i]->Xuat();
    }
    //4.2 Sap xep theo ten mat hang
    for(int i=0; i < ListdanhSachBanHang.size() - 1; i++){
        for(int j=i+1; j < ListdanhSachBanHang.size(); j++){
            if(ListdanhSachBanHang[i]->getMatHang() > ListdanhSachBanHang[j]->getMatHang()){
                swap(ListdanhSachBanHang[i], ListdanhSachBanHang[j]);
            }
        }
    }
    cout << endl << endl << right << setw(60) << "Bang ban hang sap xep theo ten mat hang: " << endl;
    cout << left << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    cout << left << setw(30) << "Nhan vien" << setw(30) << "Mat hang" << setw(10) << "So luong" << endl;
    cout << left << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    for(int i=0; i < ListdanhSachBanHang.size(); i++){
        ListdanhSachBanHang[i]->Xuat();
    }
    cout << endl;
    //5. lap bang tinh cong cho nhan vien
    cout << endl << endl << right << setw(50) << "Bang tinh cong cho nhan vien: " << endl;
    cout << left << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    cout << left << setw(30) << "Nhan vien" << setw(30) << "Cong" << endl;
    cout << left << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    for(int i=0; i < ListnhanVien.size(); i++){
        double Cong = 0;
        for(int j=0; j < ListdanhSachBanHang.size(); j++){
            if(ListdanhSachBanHang[j]->getNhanVien() == ListnhanVien[i]->getHoTen()){
                Cong += ListdanhSachBanHang[j]->getSoluong() * ListdanhSachBanHang[j]->getLai();
            }
        }
        cout << left << setw(30) << ListnhanVien[i]->getHoTen() << setw(30) << fixed << setprecision(2) << Cong*2/100 << endl;
    }
    // //Tim kiem bang regex
    // bool checkNhap=false;
    // do{
    //     string tentimkiem;
    //     cout << endl << "Nhap ten nhan vien can tim kiem(Nhap x de ket thuc tim kiem): ";
    //     getline(cin, tentimkiem);
    //     if(tentimkiem == "x" || tentimkiem == "X"){
    //         checkNhap = true;
    //         cout << "Da ket thuc tim kiem!" << endl;
    //         break;
    //     }
    //     regex patern(tentimkiem, regex_constants::icase);
    //     cout << endl << right << setw(20) << "Bang ban hang cua nhan vien " << tentimkiem << ": " << endl;
    //     cout << left << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    //     cout << left << setw(30) << "Nhan vien" << setw(30) << "Mat hang" << setw(10) << "So luong" << endl;
    //     cout << left << setfill('-') << setw(80) << "-" << setfill(' ') << endl;
    //     for(int i=0; i<ListdanhSachBanHang.size(); i++){
    //         if(regex_search(ListdanhSachBanHang[i]->getNhanVien(), patern)){
    //             ListdanhSachBanHang[i]->Xuat();
    //         }
    //     }
    // }while(checkNhap==false);
    return 0;
}