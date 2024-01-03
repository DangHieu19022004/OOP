#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
#include "DanhSachBanHang.cpp"

using namespace std;

int main(){
    // Khai bao cac vector luu danh sach nhan vien, mat hang, danh sach ban hang
    vector<NhanVienBanHang*> ListnhanVien;
    vector<MatHang*> ListmatHang;
    vector<DanhSachBanHang*> ListdanhSachBanHang;

    //1. Nhap danh sach hang + in
        //Nhap
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
        //Xuat
    cout << right << setw(80) << "Danh sach mat hang vua nhap: " << endl;
    cout << left << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
    cout << left << setw(15) << "Ma hang" << setw(30) << "Ten hang" << setw(30) << "Nhom hang" << setw(30) << "Gia mua" << setw(10) << "Gia ban" << endl;
    cout << left << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
    for(int i = 0; i < ListmatHang.size(); i++){
        ListmatHang[i] -> Xuat();
    }

    //2. Nhap danh sach nhan vien + in 
        //Nhap
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
        //Xuat
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
                //su dung pair de luu cap gia tri ten nhan vien va so luong
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
}