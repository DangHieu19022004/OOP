#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class SANPHAM{
	private:
		string Ten;
		string NhaSX;
	public:
		SANPHAM(){}
		SANPHAM(string Ten, string NhaSX){
			this->Ten = Ten;
			this->NhaSX = NhaSX;
		}
		//ham truy cap
		string getTen(){
			return Ten;
		}
		string getNhaSX(){
			return NhaSX;
		}
		//ham bien doi
		void setTen(string ten){
			this->Ten = ten;
		}
		void setNhaSX(string nhaSX){
			this->NhaSX = nhaSX;
		}
		//ham nhap
		virtual void input(){
			cout << "Nhap ten: ";
			getline(cin, Ten);
			cout << "Nhap nha san xuat: ";
			getline(cin, NhaSX);
		}
		//ham hien thi
		virtual void output(){
			cout << "Ten: " << Ten << endl;
			cout << "Nha san xuat: " << NhaSX << endl;
		}
		virtual double ThanhToan()=0;
};

class BANLE : public SANPHAM{
	private:
		double GiaBanLe;
		int SoLuong;
	public:
		BANLE(){}
		BANLE(string Ten, string NhaSX, double GiaBanLe, int SoLuong)
			: SANPHAM(Ten, NhaSX){
				this->GiaBanLe = GiaBanLe;
				this->SoLuong = SoLuong;
			}
		//ham thanh toan
		double ThanhToan(){
			return GiaBanLe*SoLuong;
		}
		//ham nhap
		void input(){
			SANPHAM::input();
			cout << "Nhap gia ban le: ";
			cin >> GiaBanLe;
			cin.ignore();
			do{
				cout << "Nhap so luong: ";
				cin >> SoLuong;
				cin.ignore();		
				if(SoLuong>=10){
					cout << "So luong phai < 10" << endl;
				}		
			}while(SoLuong>=10);
		}
		//ham hien thi
		void output(){
			SANPHAM::output();
			cout << "Gia ban le: " << GiaBanLe << endl;
			cout << "So luong: " << SoLuong << endl;
			cout << "Tong tien thanh toan: " << fixed << setprecision(2) << ThanhToan() << endl;
		}
};

class BANSI : public SANPHAM{
	private:
		double GiaSi;
		int SoLuong;
	public:
		BANSI(){}
		BANSI(string Ten, string NhaSX, double GiaSi, int SoLuong)
			: SANPHAM(Ten, NhaSX){
				this->GiaSi = GiaSi;
				this->SoLuong = SoLuong;	
			}
		//ham nhap
		void input(){
			SANPHAM::input();
			cout << "Nhap gia si: ";
			cin >> GiaSi;
			cin.ignore();
			do{
				cout << "Nhap so luong: ";
				cin >> SoLuong;
				cin.ignore();
				if(SoLuong<=100){
					cout << "So luong phai > 100" << endl;
				}		
			}while(SoLuong<=100);
		}
		//ham thanh toan
		double ThanhToan(){
			return GiaSi*SoLuong;
		}
		//ham hien thi
		void output(){
			SANPHAM::output();
			cout << "Gia si: " << GiaSi << endl;
			cout << "So luong: " << SoLuong << endl;
			cout << "Tong tien thanh toan: " << fixed << setprecision(2) << ThanhToan() << endl;
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
		cout << endl << "Nhap 1 de chon BANLE, nhap 2 de chon BANSI. Lua chon cua ban: ";
		cin >> choice;
		cin.ignore();
		if(choice==1){
			BANLE *banle = new BANLE();
			banle->input();
			dsSanPham.push_back(banle);
		}else if(choice==2){
			BANSI *bansi = new BANSI();
			bansi->input();
			dsSanPham.push_back(bansi);
		}
	}
	cout << endl << endl << "Danh sach san pham: " << endl;
	for(int i=0; i<N; i++){
		cout << endl;
		dsSanPham[i]->output();
	}
	cout << endl << endl << "Thong tin san pham thanh toan it nhat: " << endl << endl;
	double minThanhtoan = dsSanPham[0]->ThanhToan();
	for(int i=0; i<N; i++){
		if(minThanhtoan > dsSanPham[i]->ThanhToan()){
			minThanhtoan = dsSanPham[i]->ThanhToan(); 
		}
	}
	for(int i=0; i<N; i++){
		if(minThanhtoan == dsSanPham[i]->ThanhToan()){
			dsSanPham[i]->output();
			break;
		}
	}
}
