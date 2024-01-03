#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;
class Nhanvien{
	private:
		static int nextID;
		int maNV;
		string Hoten;
		string Diachi;
		string SoDT;
		string ngaykyhopdong;
	public:
    Nhanvien(){
        this->maNV = nextID++;
    }
    Nhanvien(string Hoten, string Diachi, string SoDT, string ngaykyhopdong){
            this->maNV = nextID++;
 		   	this->Hoten = Hoten;
 		   	this->Diachi = Diachi;
			this->SoDT = SoDT;
        	this->ngaykyhopdong = ngaykyhopdong;
    }
    void Nhap();
    void Xuat();
};

void Nhanvien::Nhap(){
    cout << endl << "Nhap ho ten: ";
    getline(cin, Hoten);
    cout << "Nhap dia chi: ";
    getline(cin, Diachi);
    cout << "Nhap so dien thoai: ";
    getline(cin, SoDT);
    cout << "Nhap ngay ky hop dong: ";
    getline(cin, ngaykyhopdong);
}

void Nhanvien::Xuat(){
    cout << left << setw(15) << maNV << setw(40) << Hoten << setw(40) << Diachi << setw(15) << SoDT << setw(15) << ngaykyhopdong << endl;
}

int Nhanvien::nextID = 1000;

class MatHang {
private:
    static int nextID;
    int maHang;
    string tenHang;
    string nhomHang;
    float giaBan;
    int soLuong;

public:
    MatHang() {
        this->maHang = nextID++;
    }
    MatHang(string tenHang, string nhomHang, float giaBan, int soLuong){
        this->maHang = nextID++;
    	this->tenHang = tenHang;
    	this->nhomHang = nhomHang;
    	this->giaBan = giaBan;
    	this->soLuong = soLuong;
	}
	void Nhap();
    void Xuat();        
};

void MatHang::Nhap(){
    cout << endl << "Nhap ten hang: ";
    getline(cin, tenHang);
    cout << "Nhap nhom hang: ";
    getline(cin, nhomHang);
    cout << "Nhap gia ban: ";
    cin >> giaBan;
    cout << "Nhap so luong: ";
    cin >> soLuong;
    cin.ignore();
}

void MatHang::Xuat(){
    cout << left << setw(15) << maHang << setw(40) << tenHang << setw(40) << nhomHang << setw(15) << giaBan << setw(15) << soLuong << endl;
}

int MatHang::nextID = 2000;
class BangDanhSachBanHang {
private:
    unordered_map<int, vector<int>> danhSachBanHang; 

public:
    void themMatHangChoNhanVien(int maNV, int maHang) {
        auto& danhSachNV = danhSachBanHang[maNV];
        if (find(danhSachNV.begin(), danhSachNV.end(), maHang) == danhSachNV.end()) {
            if (danhSachNV.size() < 5) {
                danhSachNV.push_back(maHang);
            } else {
                cout << "Nhan vien da ban toi da so luong mat hang cho phep.\n";
            }
        } else {
            cout << "Mat hang da ton tai trong bang danh sach.\n";
        }
    }
    void inDanhSachBanHang() {
        cout << "Bang danh sach ban hang:\n";
        for (const auto& pair : danhSachBanHang) {
            cout << "Ma NV: " << pair.first << " - Danh sach mat hang: ";
            for (const auto& maHang : pair.second) {
                cout << maHang << " ";
            }
            cout << "\n";
        }
    }
};

int main(){
	vector<Nhanvien*> danhSachNhanVien;
    vector<MatHang*> danhSachMatHang;
    int slMh;
    cout << "Nhap so luong mat hang: ";
    cin >> slMh;
    cin.ignore();
    for(int i=0; i<slMh; i++){
        MatHang *matHang = new MatHang();
        matHang->Nhap();
        danhSachMatHang.push_back(matHang);
    }
    cout << "Danh sach mat hang vua nhap: " << endl;
    cout << left << setw(15) << "Ma hang" << setw(40) << "Ten hang" << setw(40) << "Nhom hang" << setw(15) << "Gia ban" << setw(15) << "So luong" << endl;
    cout << setfill('-') << setw(125) << "-" << setfill(' ')<< endl;
    for(int i=0; i< slMh; i++){
        danhSachMatHang[i]->Xuat();
    }
    int slSV;
    cout << endl << "Nhap so luong nhan vien: ";
    cin >> slSV;
    cin.ignore();
    for(int i=0; i<slSV; i++){
        Nhanvien *nhanvien = new Nhanvien();
        nhanvien->Nhap();
        danhSachNhanVien.push_back(nhanvien);
    }
    cout << endl << "Danh sach nhan vien vua nhap: " << endl;
    cout << left << setw(15) << "Ma nhan vien" << setw(40) << "Ho ten" << setw(40) << "Dia chi" << setw(15) << "So dien thoai" << setw(15) << "Ngay ky hop dong" << endl;
    cout << setfill('-') << setw(125) << "-" << setfill(' ')<< endl;
    for(int i=0; i< slSV; i++){
        danhSachNhanVien[i]->Xuat();
    }
    
    return 0;
}
