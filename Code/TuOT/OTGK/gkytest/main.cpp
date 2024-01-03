#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <ctime>
#include "BangDangKy.cpp"

using namespace std;

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