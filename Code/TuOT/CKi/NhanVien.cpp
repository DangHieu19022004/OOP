#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

class NhanVien{
	protected:
		string HoTen;
		int NamSinh;
		string GioiTinh;
		string DiaChi;
	public:
		NhanVien(){};
		NhanVien(string HoTen, int NamSinh, string GioiTinh, string DiaChi){
			this->HoTen = HoTen;
			this->NamSinh = NamSinh;
			this->GioiTinh = GioiTinh;
			this->DiaChi = DiaChi;
		}
		friend istream& operator>>(istream& is, NhanVien& NV){
			cout << "Nhap ho ten: ";
			getline(is, NV.HoTen);
			cout << "Nhap nam sinh: ";
			is >> NV.NamSinh;
			is.ignore();
			cout << "Gioi tinh: ";
			getline(is, NV.GioiTinh);
			cout << "Dia chi: ";
			getline(is, NV.DiaChi);
			return is;
		}
		friend ostream& operator<<(ostream& os, NhanVien NV){
			os << "Ten nhan vien: " << NV.HoTen << endl;
			os << "Nam sinh: " << NV.NamSinh << endl;
			os << "Gioi tinh: " << NV.GioiTinh << endl;
			os << "Dia chi: " << NV.DiaChi << endl;
			return os;
		}
};

class CongNhan : public NhanVien{
	private:
		double TienLuong;
		string CongViec;
	public:
		CongNhan(){};
		CongNhan(string HoTen, int NamSinh, string GioiTinh, string DiaChi, double TienLuong, string CongViec){
			this->HoTen = HoTen;
			this->NamSinh = NamSinh;
			this->GioiTinh = GioiTinh;
			this->DiaChi = DiaChi;
			this->TienLuong = TienLuong;
			this->CongViec = CongViec;
		}
		string getTen(){
			return this->HoTen;
		}
		friend istream& operator>>(istream& is, CongNhan& CN){
			cout << "Nhap ho ten: ";
			getline(is, CN.HoTen);
			cout << "Nhap nam sinh: ";
			is >> CN.NamSinh;
			is.ignore();
			cout << "Gioi tinh: ";
			getline(is, CN.GioiTinh);
			cout << "Dia chi: ";
			getline(is, CN.DiaChi);
			cout << "Nhap Luong: ";
			is >> CN.TienLuong;
			is.ignore();
			cout << "Nhap cong viec: ";
			getline(is, CN.CongViec);
			return is;
		}
		friend ostream& operator<<(ostream& os, CongNhan CN){
			os << left << setw(30) << CN.HoTen << setw(10) << CN.NamSinh << setw(10) << CN.GioiTinh << setw(30) << CN.DiaChi << setw(20) << CN.TienLuong << setw(30) << CN.CongViec << endl;
			return os;
		}
};

int main() {
	vector<CongNhan*> dsCongNhan;
	int N;
	do{
		cout << "Nhap so luong cong nhan: ";
		cin >> N;
		cin.ignore();
		if(N <= 0 || N >= 10){
			cout << "Nhap sai, vui long nhap lai!" << endl;
		}
		else{
			break;
		}
	}while(N <= 0 || N >= 10);
	
	for(int i=0; i<N; i++){
		cout << "Nhap thong tin cong nhan thu " << i+1 << ": "<<endl;
		CongNhan *p = new CongNhan();
		cin >> *p;
		dsCongNhan.push_back(p);
	}
	
	cout << endl << right << setw(50) << "Danh sach vua nhap" << endl;
	cout << endl << left << setfill('-') << setw(130) << "-" << setfill(' ') << endl;
	cout << left << setw(30) << "Ho ten" << setw(10) << "Nam sinh" << setw(10) << "Gioi tinh" << setw(30) << "Dia chi" << setw(20) << "Tien luong" << setw(30) << "Cong viec" << endl;
	cout << left << setfill('-') << setw(130) << "-" << setfill(' ') << endl;
	for(int i=0; i<N; i++){
		cout << *dsCongNhan[i];
	}
	string ten;
	bool check=false;
	do{
		cout << endl << "Nhap ten cong nhan can tim(Nhap x de thoat): ";
		getline(cin, ten);
		for(int i=0; i<N; i++){
			if(ten==dsCongNhan[i]->getTen()){
				cout << endl << left << setfill('-') << setw(130) << "-" << setfill(' ') << endl;
				cout << left << setw(30) << "Ho ten" << setw(10) << "Nam sinh" << setw(10) << "Gioi tinh" << setw(30) << "Dia chi" << setw(20) << "Tien luong" << setw(30) << "Cong viec" << endl;
				cout << left << setfill('-') << setw(130) << "-" << setfill(' ') << endl;
				cout << *dsCongNhan[i];					
				check=true;
				break;
			}
			else{
				check=false;
			}
		}
		if(check==false){
			if(ten=="x" && ten=="X"){
				cout << "Thoat tim kiem.";
			}
			cout<<"Khong tim thay nhan vien " << ten << " trong danh sach cong nhan.";
		}
	}while(ten!="x" && ten!="X");
	return 0;
}
