#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <algorithm>

using namespace std;

//Khai bao lop mon hoc
class MonHoc {
private:
    static int nextId;
public:
    int maMonHoc;
    string tenMonHoc;
    int tongSoTiet;
    string loaiMonHoc;

    MonHoc(string tenMonHoc, int tongSoTiet, string loaiMonHoc) {
        this->maMonHoc = nextId++;
        this->tenMonHoc = tenMonHoc;
        this->tongSoTiet = tongSoTiet;
        this->loaiMonHoc = loaiMonHoc;
    }
};

int MonHoc::nextId = 100;

// Khai bao lop sinh vien
class SinhVien {
private:
    static int nextId;
public:
    int maSinhVien;
    string hoTen;
    string diaChi;
    string soDT;
    string lop;

    SinhVien(string hoTen, string diaChi, string soDT, string lop) {
        this->maSinhVien = nextId++;
        this->hoTen = hoTen;
        this->diaChi = diaChi;
        this->soDT = soDT;
        this->lop = lop;
    }
};

int SinhVien::nextId = 10000;

//Khai bao bang dang ky
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
void inDanhSachMonHoc(vector<MonHoc*> danhSachMonHoc) {
    cout << "----------Danh sach cac mon hoc da co----------" << endl;
    cout << left << setw(15) << "Ma Mon Hoc" << setw(15) << "Ten Mon Hoc" << setw(15) << "Tong So Tiet" << setw(20) << "Loai Mon Hoc" << endl;
    for (int i = 0; i < danhSachMonHoc.size(); i++) {
        MonHoc* monHoc = danhSachMonHoc[i];
        cout << setw(15) << monHoc->maMonHoc << setw(15) << monHoc->tenMonHoc << setw(15) << monHoc->tongSoTiet << setw(20) << monHoc->loaiMonHoc << endl;
    }
    cout << endl;
}

//in danh sach sinh vien
void inDanhSachSinhVien(vector<SinhVien*> danhSachSinhVien) {
    cout << "----------Danh sach sinh vien da co----------" << endl;
    cout << left << setw(15) << "Ma Sinh Vien" << setw(30) << "Ho Ten" << setw(30) << "Dia Chi" << setw(30) << "So DT" << setw(15) << "Lop" << endl;
    for (int i = 0; i < danhSachSinhVien.size(); i++) {
        SinhVien* sinhVien = danhSachSinhVien[i];
        cout << setw(15) << sinhVien->maSinhVien << setw(30) << sinhVien->hoTen << setw(30) << sinhVien->diaChi << setw(30) << sinhVien->soDT << setw(15) << sinhVien->lop << endl;
    }
    cout << endl;
}

//In bang dang ky
void inBangDangKy(vector<BangDangKy*> danhSachBangDangKy, SinhVien* sinhVien) {
    cout << "Bang Dang Ky cua sinh vien " << sinhVien->maSinhVien << ": " << endl;
    cout << setw(15) << "Ma Mon Hoc" << setw(15) << "Ten Mon Hoc" << setw(15) << "Tong So Tiet"  << setw(15) << "Loai Mon Hoc" << setw(25) << "Thoi Gian Dang Ky" << endl;
    for (int i = 0; i < danhSachBangDangKy.size(); i++) {
        BangDangKy* bangDangKy = danhSachBangDangKy[i];
        if (bangDangKy->sinhVien == sinhVien) {
            cout << setw(15) << bangDangKy->monHoc->maMonHoc << setw(15) << bangDangKy->monHoc->tenMonHoc  << setw(15) << bangDangKy->monHoc->tongSoTiet << setw(15) << bangDangKy->monHoc->loaiMonHoc << setw(25) << ctime(&bangDangKy->thoiGianDangKy);
        }
    }
    cout << endl;
}

bool sapXepTheoTenSinhVien(BangDangKy* a, BangDangKy* b) {
    return a->sinhVien->hoTen < b->sinhVien->hoTen;
}

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
    cin.ignore();

    for (int i = 0; i < soMonHoc; i++) {
        string tenMonHoc, loaiMonHoc;
        int tongSoTiet;

        cout << "Nhap ten mon hoc thu " << i+1 << ": ";
        getline(cin, tenMonHoc);

        cout << "Nhap tong so tiet cua mon hoc thu " << i+1 << ": ";
        cin >> tongSoTiet;
        cin.ignore();

        cout << "Nhap loai mon hoc thu " << i+1 << ": ";
        getline(cin, loaiMonHoc);

        MonHoc* monHoc = new MonHoc(tenMonHoc, tongSoTiet, loaiMonHoc);
        danhSachMonHoc.push_back(monHoc);
    }

//in danh sach mon hoc
    inDanhSachMonHoc(danhSachMonHoc);

    // Nhap danh sach sinh vien
    int soSinhVien;
    cout << "Nhap so sinh vien: ";
    cin >> soSinhVien;
    cin.ignore();

    for (int i = 0; i < soSinhVien; i++) {
        string hoTen, diaChi, soDT, lop;

        cout << "Nhap ho ten sinh vien thu " << i+1 << ": ";
        getline(cin, hoTen);

        cout << "Nhap dia chi sinh vien thu " << i+1 << ": ";
        getline(cin, diaChi);

        cout << "Nhap so dien thoai sinh vien thu " << i+1 << ": ";
        getline(cin, soDT);

        cout << "Nhap lop cua sinh vien thu " << i+1 << ": ";
        getline(cin, lop);

        SinhVien* sinhVien = new SinhVien(hoTen, diaChi, soDT, lop);
        danhSachSinhVien.push_back(sinhVien);
    }

    // In danh sach sinh vien
    inDanhSachSinhVien(danhSachSinhVien);

//Lap bang dang ky
    for (int i = 0; i < danhSachSinhVien.size(); i++) {
        SinhVien* sinhVien = danhSachSinhVien[i];

        for (int j = 0; j < danhSachMonHoc.size(); j++) {
            MonHoc* monHoc = danhSachMonHoc[j];

            string luaChon;
            cout << "Ban co muon dang ky mon hoc " << monHoc->tenMonHoc << " cho sinh vien " << sinhVien->hoTen << "? (Y/N): ";
            getline(cin, luaChon);

            if (luaChon == "Y" || luaChon == "y") {
                BangDangKy* bangDangKy = new BangDangKy(sinhVien, monHoc);
                danhSachBangDangKy.push_back(bangDangKy);
            }
        }
    }

//in bang dang ky
    for (int i = 0; i < danhSachSinhVien.size(); i++) {
        SinhVien* sinhVien = danhSachSinhVien[i];
        inBangDangKy(danhSachBangDangKy, sinhVien);
    }
// sap xep

// Sap xem theo ten sinh vien
sort(danhSachBangDangKy.begin(), danhSachBangDangKy.end(), sapXepTheoTenSinhVien);
cout << "Danh sach Bang Dang Ky theo ten sinh vien:" << endl;
for (int i = 0; i < danhSachSinhVien.size(); i++) {
    SinhVien* sinhVien = danhSachSinhVien[i];
    inBangDangKy(danhSachBangDangKy, sinhVien);
}

// Sap xep theo thoi gian dang ky
sort(danhSachBangDangKy.begin(), danhSachBangDangKy.end(), sapXepTheoThoiGianDangKy);
cout << "Danh sach Bang Dang Ky theo thoi gian dang ky:" << endl;
for (int i = 0; i < danhSachSinhVien.size(); i++) {
    SinhVien* sinhVien = danhSachSinhVien[i];
    inBangDangKy(danhSachBangDangKy, sinhVien);
}

    return 0;
}
