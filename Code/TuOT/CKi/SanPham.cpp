#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

class SANPHAM{
	private:
		string Ten;
		double Giasanpham;
	public:
		SANPHAM(){};
		SANPHAM(string Ten, double Giasanpham){
			this->Ten = Ten;
			this->Giasanpham = Giasanpham;
		}
		//ham truy cap
		string getTen(){
			return this->Ten;
		}
		double getGiasanpham(){
			return this->Giasanpham;
		}
		//ham bien doi
		void setTen(string tenmoi){
			this->Ten = tenmoi;
		}
		void setGiasanpham(double giamoi){
			this->Giasanpham = giamoi;
		}
		void Nhap(){
			cout << "Nhap ten: ";
			getline(cin,Ten);
			cout << "Nhap gia san pham: ";
			cin >> Giasanpham;
			cin.ignore();
		}
		void Xuat(){
			cout << "Ten: " << Ten << endl;
			cout << "Gia san pham: " << fixed << setprecision(2) << Giasanpham << endl;
		}
		virtual double Thanhtoan()=0;
};

class DOHOP : public SANPHAM{
	private:
		int Soluongsp;
	public:
		DOHOP(){};
		DOHOP(string Ten, double Giasanpham, int Soluongsp) : SANPHAM(Ten, Giasanpham){
			this->Soluongsp = Soluongsp;
		}
		void Nhap(){
			SANPHAM::Nhap();
			cout << "Nhap so luong san pham: ";
			cin >> Soluongsp;
			cin.ignore();
		}
		void Xuat(){
			SANPHAM::Xuat();
			cout << "So luong san pham: " << Soluongsp << endl;
		}
		double Thanhtoan(){
			return getGiasanpham()*Soluongsp;
		}
};

class RAUQUA : public SANPHAM{
	private:
		double Cannang;
	public:
		RAUQUA(){};
		RAUQUA(string Ten, double Giasanpham, double Cannang) : SANPHAM(Ten, Giasanpham){
			this->Cannang = Cannang;
		}
		void Nhap(){
			SANPHAM::Nhap();
			cout << "Nhap can nang rau qua: ";
			cin >> Cannang;
			cin.ignore();
		}
		void Xuat(){
			SANPHAM::Xuat();
			cout << "Can nang rau qua: " << Cannang << endl;
		}
		double Thanhtoan(){
			return getGiasanpham()*Cannang;
		}
};

int main(){
	vector<SANPHAM*> dsSanPham;
	int N;
	cout << "Nhap so san pham: ";
	cin >> N;
	cin.ignore();
	int choice;
	for(int i=0; i<N; i++){
		cout << endl << "Nhap thong tin cho DOHOP [1] hay RAUQUA [2]: ";
		cin >> choice;
		cin.ignore();
		if(choice==1){
			DOHOP *dohop = new DOHOP();
			dohop->Nhap();
			dsSanPham.push_back(dohop);
		}else if(choice==2){
			RAUQUA *rauqua = new RAUQUA();
			rauqua->Nhap();
			dsSanPham.push_back(rauqua);
		}
	}
	cout << endl << endl << "Danh sach san pham:" << endl;
	for(int i=0; i<N; i++){
		dsSanPham[i]->Xuat();
	}
	double maxTien = dsSanPham[0]->Thanhtoan();
	for(int i=0; i<N; i++){
		if(maxTien < dsSanPham[i]->Thanhtoan()){
			maxTien = dsSanPham[i]->Thanhtoan();
		}
	}
	cout << endl << endl << "San pham thanh toan nhieu nhat: " << endl;
	for(int i=0; i<N; i++){
		if(maxTien == dsSanPham[i]->Thanhtoan()){
			dsSanPham[i]->Xuat();
		}
	}
}
