#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class VeMayBay{
	private:
		string TenChuyen;
		string NgayBay;
		double GiaVe;
	public:
		VeMayBay(){}
		VeMayBay(string TenChuyen, string NgayBay, double GiaVe){
			this->TenChuyen = TenChuyen;
			this->NgayBay = NgayBay;
			this->GiaVe = GiaVe;
		}
		//nhap
		void Nhap(){
			cout << "Nhap ten chuyen: ";
			getline(cin, TenChuyen);
			cout << "Nhap ngay bay: ";
			getline(cin, NgayBay);
			cout << "Nhap gia ve: ";
			cin >> GiaVe;
			cin.ignore();
		}
		//xuat
		void Xuat(){
			cout << "Ten chuyen: " << TenChuyen << endl;
			cout << "Ngay bay: " << NgayBay << endl;
			cout << "Gia ve: " << GiaVe << endl;
		}
		//lay gia ve
		double getGiaVe(){
			return GiaVe;
		}
};

class Nguoi{
	private:
		string HoTen;
		string GioiTinh;
		int Tuoi;
	public:
		Nguoi(){};
		Nguoi(string HoTen, string GioiTinh, int Tuoi){
			this->HoTen = HoTen;
			this->GioiTinh = GioiTinh;
			this->Tuoi = Tuoi;
		}
		//nhap
		virtual void Nhap(){
			cout << "Nhap ho ten: ";
			getline(cin, HoTen);
			cout << "Nhap gioi tinh: ";
			getline(cin, GioiTinh);
			cout << "Nhap tuoi: ";
			cin >> Tuoi;
			cin.ignore();
		}
		//xuat
		virtual void Xuat(){
			cout << "Ho ten: " << HoTen << endl;
			cout << "Gioi tinh: " << GioiTinh << endl;
			cout << "Tuoi: " << Tuoi << endl;
		}
		//
		string getHoTen(){
			return HoTen;
		}
};

class HanhKhach : public Nguoi{
	private:
		VeMayBay *ve;
		int SoLuong;
	public:
		HanhKhach(){}
		HanhKhach(VeMayBay *ve, int SoLuong){
			this->ve = ve;
			this->SoLuong = SoLuong;
		}
		//nhap
		void Nhap(){
			cout << endl;
			ve = new VeMayBay();
			ve->Nhap();
			Nguoi::Nhap();
			cout << "Nhap so luong ve: ";
			cin >> SoLuong;
			cin.ignore();
			cout << endl;
		}
		//xuat
		void Xuat(){
			Nguoi::Xuat();
			cout << "So luong ve: " << SoLuong << endl;
		}
		//tinh tien
		double TongTien(){
			return SoLuong * ve->getGiaVe();
		}
};

int main(){
	vector<HanhKhach*> dsHanhKhach;
	int n;
	cout << "Nhap so danh sach hanh khach: ";
	cin >> n;
	cin.ignore();
	cout << endl;
	for(int i=0; i<n; i++){
		HanhKhach *hk = new HanhKhach();
		hk->Nhap();
		dsHanhKhach.push_back(hk);
	}
	cout << endl << endl << "Danh sach hanh khach:" << endl;
	for(int i=0; i<n; i++){
		cout << endl;
		dsHanhKhach[i]->Xuat();
		cout << "Tong tien thanh toan: " << dsHanhKhach[i]->TongTien() << endl;
	}
	return 0;
}
