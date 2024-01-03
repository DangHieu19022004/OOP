#include <iostream>
#include <string.h>
#include <vector>
#include <iomanip>
#include <ctime>
#include <algorithm>

using namespace std;

//Khai bao class mon hoc
class MonHoc {
private:
    static int IDMonHoc;
public:
    int MaMonHoc;
    string TenMonHoc;
    int TongSoTiet;
    string LoaiMonHoc;

    MonHoc(string TenMonHoc, int TongSoTiet, string LoaiMonHoc) {
        this->MaMonHoc = IDMonHoc++;
        this->TenMonHoc = TenMonHoc;
        this->TongSoTiet = TongSoTiet;
        this->LoaiMonHoc = LoaiMonHoc;
    }
};

int MonHoc::IDMonHoc = 100;

// Khai bao class sinh vien
class SinhVien {
private:
    static int IDSinhVien;
public:
    int MaSinhVien;
    string HoTen;
    string DiaChi;
    string SoDT;
    string Lop;

    SinhVien(string HoTen, string DiaChi, string SoDT, string Lop) {
        this->MaSinhVien = IDSinhVien++;
        this->HoTen = HoTen;
        this->DiaChi = DiaChi;
        this->SoDT = SoDT;
        this->Lop = Lop;
    }
};

int SinhVien::IDSinhVien = 10000;

//Khai bao class bang dang ky
class BangDangKy {
public:
    SinhVien* sinhVien;
    MonHoc* monHoc;
    time_t thoiGianDangKy;
    
    BangDangKy(SinhVien* sinhVien, MonHoc* monHoc) {
        this->sinhVien = sinhVien;
        this->monHoc = monHoc;
        this->thoiGianDangKy = time(0);
    }
};

//In danh sach mon hoc
void InDanhSachMonHoc(vector<MonHoc*> danhSachMonHoc) {
    cout << endl;
    cout << setw(60) << "Danh sach cac mon hoc" << endl << endl;
	//ke bang
	cout << setfill('-') << setw(25) << "" << setw(25) << "" << setw(25) << "" << setw(20) << "" << endl;
    cout << setfill(' ');
    cout << left << setw(25) << "Ma Mon Hoc" << setw(25) << "Ten Mon Hoc" << setw(25) << "Tong So Tiet" << setw(20) << "Loai Mon Hoc" << endl;
    for (int i = 0; i < danhSachMonHoc.size(); i++) {
    	cout << setfill('-') << setw(25) << "" << setw(25) << "" << setw(25) << "" << setw(20) << "" << endl;
    	cout << setfill(' ');
        MonHoc* monHoc = danhSachMonHoc[i];
        cout << setw(25) << monHoc->MaMonHoc << setw(25) << monHoc->TenMonHoc << setw(25) << monHoc->TongSoTiet << setw(20) << monHoc->LoaiMonHoc << endl;
    }
    cout << endl;
}


//in danh sach sinh vien
void InDanhSachSinhVien(vector<SinhVien*> danhSachSinhVien) {
	cout << endl;
    cout << right << setw(65) << "Danh sach sinh vien " << endl << endl;
    //ke bang
	cout << setfill('-') << setw(20) << "" << setw(20) << "" << setw(30) << "" << setw(30) << "" << setw(15) << "" << setw(15) << endl;
    cout << setfill(' ');    
    cout << left << setw(20) << "Ma Sinh Vien" << setw(20) << "Ho Ten" << setw(30) << "Dia Chi" << setw(30) << "So DT" << setw(15) << "Lop" << endl;
    for (int i = 0; i < danhSachSinhVien.size(); i++) {
		cout << setfill('-') << setw(20) << "" << setw(20) << "" << setw(30) << "" << setw(30) << "" << setw(15) << "" << setw(15) <<  endl;
   		cout << setfill(' ');  
        SinhVien* sinhVien = danhSachSinhVien[i];
        cout << setw(20) << sinhVien->MaSinhVien << setw(20) << sinhVien->HoTen << setw(30) << sinhVien->DiaChi << setw(30) << sinhVien->SoDT << setw(15) << sinhVien->Lop << endl;
    }
    cout << endl << endl;
}

//In bang dang ky
void InBangDangKy(vector<BangDangKy*> danhSachBangDangKy, SinhVien* sinhVien) {
	cout << endl << endl;
    cout << right << setw(60) << "Bang Dang Ky cua sinh vien " << sinhVien->MaSinhVien << ": " << endl;
    //ke bang
	cout << setfill('-') << setw(15) << "" << setw(15) << "" << setw(15) << "" << setw(15) << "" << setw(25) << "" << setw(15) << endl;
    cout << setfill(' ');    
    cout << left << setw(15) << "Ma Mon Hoc" << setw(15) << "Ten Mon Hoc" << setw(15) << "Tong So Tiet"  << setw(15) << "Loai Mon Hoc" << setw(25) << "Thoi Gian Dang Ky" << endl;
    for (int i = 0; i < danhSachBangDangKy.size(); i++) {
        BangDangKy* bangDangKy = danhSachBangDangKy[i];
        if (bangDangKy->sinhVien == sinhVien) {
       		cout << setfill('-') << setw(15) << "" << setw(15) << "" << setw(15) << "" << setw(15) << "" << setw(25) << "" << setw(15) << endl;
    		cout << setfill(' ');
            cout << setw(15) << bangDangKy->monHoc->MaMonHoc << setw(15) << bangDangKy->monHoc->TenMonHoc  << setw(15) << bangDangKy->monHoc->TongSoTiet << setw(15) << bangDangKy->monHoc->LoaiMonHoc << setw(25) << ctime(&bangDangKy->thoiGianDangKy);
        }
    }
    cout << endl << endl;
}

//Sap xep theo ten sinh vien
bool sapXepTheoTenSinhVien(BangDangKy* a, BangDangKy* b) {
    return a->sinhVien->HoTen < b->sinhVien->HoTen;
}

//Sap xep theo thoi gian dang ky
bool sapXepTheoThoiGianDangKy(BangDangKy* a, BangDangKy* b) {
    return a->thoiGianDangKy < b->thoiGianDangKy;
}


int main() {
    vector<MonHoc*> danhSachMonHoc;
    vector<SinhVien*> danhSachSinhVien;
    vector<BangDangKy*> danhSachBangDangKy;

    //Nhap danh sach mon hoc
    int soMonHoc;
    cout << "Nhap so mon hoc: ";
    cin >> soMonHoc;
    cout<<endl;
    cin.ignore();

    for (int i = 0; i < soMonHoc; i++) {
        string TenMonHoc, LoaiMonHoc;
        int TongSoTiet;

        cout << "Nhap ten mon hoc thu " << i+1 << ": ";
        getline(cin, TenMonHoc);

        cout << "Nhap tong so tiet cua mon hoc thu " << i+1 << ": ";
        cin >> TongSoTiet;
        cin.ignore();

        cout << "Nhap loai mon hoc thu " << i+1 << ": ";
        getline(cin, LoaiMonHoc);

        MonHoc* monHoc = new MonHoc(TenMonHoc, TongSoTiet, LoaiMonHoc);
        danhSachMonHoc.push_back(monHoc);
        cout<<endl;
    }

    //in danh sach mon hoc
    InDanhSachMonHoc(danhSachMonHoc);

    // Nhap danh sach sinh vien
    int soSinhVien;
    cout << endl<< "Nhap so sinh vien: ";
    cin >> soSinhVien;
    cin.ignore();
	cout << endl;
    for (int i = 0; i < soSinhVien; i++) {
        string HoTen, DiaChi, SoDT, Lop;

        cout << "Nhap ho ten sinh vien thu " << i+1 << ": ";
        getline(cin, HoTen);

        cout << "Nhap dia chi sinh vien thu " << i+1 << ": ";
        getline(cin, DiaChi);

        cout << "Nhap so dien thoai sinh vien thu " << i+1 << ": ";
        getline(cin, SoDT);

        cout << "Nhap Lop cua sinh vien thu " << i+1 << ": ";
        getline(cin, Lop);

        SinhVien* sinhVien = new SinhVien(HoTen, DiaChi, SoDT, Lop);
        danhSachSinhVien.push_back(sinhVien);
        cout << endl;
    }

    // In danh sach sinh vien
    InDanhSachSinhVien(danhSachSinhVien);

    //Lap bang dang ky
    for (int i = 0; i < danhSachSinhVien.size(); i++) {
        SinhVien* sinhVien = danhSachSinhVien[i];

        for (int j = 0; j < danhSachMonHoc.size(); j++) {
            MonHoc* monHoc = danhSachMonHoc[j];  
		    string luaChon;            
			do{
            	cout << "Ban co muon dang ky mon hoc " << monHoc->TenMonHoc << " cho sinh vien " << sinhVien->HoTen << "? (Y/N): ";  		
				getline(cin, luaChon);
		        if (luaChon == "Y" || luaChon == "y") {
            		cout << "Dang ky mon hoc thanh cong!" <<endl;
                	BangDangKy* bangDangKy = new BangDangKy(sinhVien, monHoc);
                	danhSachBangDangKy.push_back(bangDangKy);
                	break;
            	}else if(luaChon == "N" || luaChon == "n"){
            		cout << "Dang ky that bai!" << endl;
            		break;
				}else{
					cout << "Nhap thong tin sai! Vui long nhap lai!" <<endl;
				}
			}while(luaChon != "Y" || luaChon != "y" || luaChon != "N" || luaChon != "n" );

        }
    }

    //in bang dang ky
    for (int i = 0; i < danhSachSinhVien.size(); i++) {
        SinhVien* sinhVien = danhSachSinhVien[i];
        InBangDangKy(danhSachBangDangKy, sinhVien);
    }

    // sap xep
    // Sap xem theo ten sinh vien
    sort(danhSachBangDangKy.begin(), danhSachBangDangKy.end(), sapXepTheoTenSinhVien);
    cout << endl << "Danh sach dang ky theo ten sinh vien:" ;
    for (int i = 0; i < danhSachSinhVien.size(); i++) {
        SinhVien* sinhVien = danhSachSinhVien[i];
        InBangDangKy(danhSachBangDangKy, sinhVien);
    }

    // Sap xep theo thoi gian dang ky
    sort(danhSachBangDangKy.begin(), danhSachBangDangKy.end(), sapXepTheoThoiGianDangKy);
    cout << endl << "Danh sach dang ky theo thoi gian dang ky:";
    for (int i = 0; i < danhSachSinhVien.size(); i++) {
        SinhVien* sinhVien = danhSachSinhVien[i];
        InBangDangKy(danhSachBangDangKy, sinhVien);
    }

    return 0;
}
