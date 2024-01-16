#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class NhanVien{
	protected:
		string HoTen;
		int NamSinh;
		string GioiTinh;
		string DiaChi;
	public:
		NhanVien(){}
		NhanVien(string HoTen, int NamSinh, string GioiTinh, string DiaChi){
			this->HoTen = HoTen;
			this->NamSinh = NamSinh;
			this->GioiTinh = GioiTinh;
			this->DiaChi = DiaChi;
		}
		string getHoTen(){
			return HoTen;
		}
		friend istream& operator>>(istream& is, NhanVien& NV){
			cout << "Nhap ho ten: ";
			getline(is, NV.HoTen);
			cout << "Nhap nam sinh: ";
			is >> NV.NamSinh;
			is.ignore();
			cout << "Nhap gioi tinh: ";
			getline(is, NV.GioiTinh);
			cout << "Nhap dia chi: ";
			getline(is, NV.DiaChi);
			return is;
		}
		friend ostream& operator<<(ostream& os, NhanVien NV){
			os << "Ho ten: " << NV.HoTen << endl;
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
		CongNhan(){}
		CongNhan(string HoTen, int NamSinh, string GioiTinh, string DiaChi, double TienLuong, string CongViec)
			: NhanVien(HoTen, NamSinh, GioiTinh, DiaChi){
				this->TienLuong = TienLuong;
				this->CongViec = CongViec;
			}
		
		friend istream& operator>>(istream& is, CongNhan& CN){
			cout << "Nhap ho ten: ";
			getline(is, CN.HoTen);
			cout << "Nhap nam sinh: ";
			is >> CN.NamSinh;
			is.ignore();
			cout << "Nhap gioi tinh: ";
			getline(is, CN.GioiTinh);
			cout << "Nhap dia chi: ";
			getline(is, CN.DiaChi);
			cout << "Nhap tien luong: ";
			is >> CN.TienLuong;
			is.ignore();
			cout << "Nhap cong viec: ";
			getline(is, CN.CongViec);
			return is;
		}
		friend ostream& operator<<(ostream& os, CongNhan CN){
			os << "Ho ten: " << CN.HoTen << endl;
			os << "Nam sinh: " << CN.NamSinh << endl;
			os << "Gioi tinh: " << CN.GioiTinh << endl;
			os << "Dia chi: " << CN.DiaChi << endl;
			os << "Tien luong: " << CN.TienLuong << endl;
			os << "Cong viec: " << CN.CongViec << endl;
			return os;
		}
};

int main(){
	vector<CongNhan*> dsCongNhan;
	int N;
	do{
		cout << "Nhap so cong nhan: ";
		cin >> N;
		cin.ignore();
		if(N<=0 || N>=10){
			cout << "Nhap sai, vui long nhap lai!!!" << endl;
		}
	}while(N<=0 || N>=10);
	for(int i=0; i<N; i++){
		cout << endl << "Nhap thong tin cong nhan thu " << i+1 << ": " << endl;
   		CongNhan *congNhan = new CongNhan();
   		cin >> *congNhan;
    	dsCongNhan.push_back(congNhan);
	}
	cout << endl << endl << "Danh sach cong nhan: " << endl;
	for(int i=0; i<N; i++){
		cout << endl;
		cout << *dsCongNhan[i];
	}
	string find;
	cout << "Nhap ten tim kiem: ";
	getline(cin, find);
	for(int i=0; i<N; i++){
		if(find==dsCongNhan[i]->getHoTen()){
			cout << *dsCongNhan[i];
		}
	}
}
