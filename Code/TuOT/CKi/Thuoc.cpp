#include <iostream>
#include <string>
#include <vector>

using namespace std;

class THUOC{
	private:
		string MaThuoc;
		string TenThuoc;
		string HangThuoc;
		double Gia;
	public:
		THUOC(){};
		THUOC(string MaThuoc, string TenThuoc, string HangThuoc, double Gia){
			this->MaThuoc = MaThuoc;
			this->TenThuoc = TenThuoc;
			this->HangThuoc = HangThuoc;
			this->Gia = Gia;
		}
		// ham truy cap
		string getMaThuoc(){
			return MaThuoc;
		}
		string getTenThuoc(){
			return TenThuoc;
		}
		string getHangThuoc(){
			return HangThuoc;
		}
		double getGia(){
			return Gia;
		}
		//ham bien doi
		void setMaThuoc(string maThuoc){
			this->MaThuoc = maThuoc;
		}
		void setTenThuoc(string tenThuoc){
			this->TenThuoc = tenThuoc;
		}
		void setHangThuoc(string hangThuoc){
			this->HangThuoc = hangThuoc;
		}
		void setGia(double gia){
			this->Gia = gia;
		}
		// ham nhap
		virtual void Nhap(){
			cout << "Nhap ma thuoc: ";
			getline(cin, MaThuoc);
			cout << "Nhap ten thuoc: ";
			getline(cin, TenThuoc);
			cout << "Nhap hang thuoc: ";
			getline(cin, HangThuoc);
			cout << "Nhap gia: ";
			cin >> Gia;
			cin.ignore();
		}
		// ham xuat
		virtual void Xuat(){
			cout << "Ma thuoc: " << MaThuoc << endl;
			cout << "Ten thuoc: " << TenThuoc << endl;
			cout << "Hang thuoc: " << HangThuoc << endl;
			cout << "Gia: " << Gia << endl;
		}
		// nap chong toan tu
		friend bool operator == (THUOC a, THUOC b){
			return a.MaThuoc == b.MaThuoc;
		}
};

class THUOCBO : public THUOC{
	private:
		string CongDung;
	public:
		THUOCBO(){}
		THUOCBO(string MaThuoc, string TenThuoc, string HangThuoc, double Gia, string CongDung) : THUOC(MaThuoc, TenThuoc, HangThuoc, Gia){
			this->CongDung = CongDung;
		}
		~THUOCBO(){}
		// ham truy cap
		string getCongDung(){
			return CongDung;
		}
		// ham bien doi
		void setCongDung(string congDung){
			this->CongDung = congDung;
		}
		// ham nhap
		void Nhap(){
			THUOC::Nhap();
			cout << "Nhap cong dung: ";
			getline(cin, CongDung);
		}
		// ham xuat
		void Xuat(){
			THUOC::Xuat();
			cout << "Cong dung: " << CongDung << endl;
		}
};

class KHANGSINH : public THUOC{
	private:
		string HamLuongSuDung;
	public:
		KHANGSINH(){}
		KHANGSINH(string MaThuoc, string TenThuoc, string HangThuoc, double Gia, string HamLuongSuDung) : THUOC(MaThuoc, TenThuoc, HangThuoc, Gia){
			this->HamLuongSuDung = HamLuongSuDung;
		}
		~KHANGSINH(){}
		// ham truy cap
		string getHamLuongSuDung(){
			return HamLuongSuDung;
		}
		// ham bien doi
		void setHamLuongSuDung(string hamLuongSuDung){
			this->HamLuongSuDung = hamLuongSuDung;
		}
		// ham nhap
		void Nhap(){
			THUOC::Nhap();
			cout << "Nhap ham luong su dung: ";
			getline(cin, HamLuongSuDung);
		}
		// ham xuat
		void Xuat(){
			THUOC::Xuat();
			cout << "Ham luong su dung: " << HamLuongSuDung << endl;
		}
};

int main(){
	vector<THUOC*> dsThuoc;
	vector<THUOCBO*> dsThuocBo;
	vector<KHANGSINH*> dsKhangSinh;
	int N;
	cout << "Nhap so thuoc trong danh sach: ";
	cin >> N;
	cin.ignore();
	int choice;
	// nhap thong tin
	for(int i=0; i<N; i++){
		cout << endl << "Nhap lua chon [1] THUOC BO, [2] KHANG SINH: ";
		cin >> choice;
		cin.ignore();
		if(choice == 1){
			THUOCBO *thuocBo = new THUOCBO();
			thuocBo->Nhap();
			dsThuocBo.push_back(thuocBo);
			dsThuoc.push_back(thuocBo);
		}else if(choice == 2){
			KHANGSINH *khangSinh = new KHANGSINH();
			khangSinh->Nhap();
			dsKhangSinh.push_back(khangSinh);
			dsThuoc.push_back(khangSinh);
		}
	}
	// xuat thong tin
	cout << endl << endl << "Danh sach N thuoc: " << endl;
	for(int i=0; i<N; i++){
		cout << endl;
		dsThuoc[i]->Xuat();
		cout << endl;
	}
	//
	cout << "Nhap thong tin bo sung: ";
	string bonus;
	cout << "Nhap loai thuoc: ";
	getline(cin, bonus);
	if(bonus == "Thuoc bo"){
		THUOCBO *thuocBo = new THUOCBO();
		thuocBo->Nhap();
		dsThuocBo.push_back(thuocBo);
		dsThuoc.push_back(thuocBo);
	}else if(bonus == "Khang sinh"){
		KHANGSINH *khangSinh = new KHANGSINH();
		khangSinh->Nhap();
		dsKhangSinh.push_back(khangSinh);
		dsThuoc.push_back(khangSinh);
	}
	cout << endl << "Danh sach thuoc sau khi them: " << endl;
	for(int i=0; i<dsThuoc.size(); i++){
		cout << endl;
		dsThuoc[i]->Xuat();
		cout << endl;
	}
	bool check=false;
	for(int i=0; i<N; i++){
		if(*dsThuoc[dsThuoc.size()-1]==*dsThuoc[i]){
			check=true;
			break;
		}
	}
	if(check==true){
		cout << endl << "Thong tin bi trung!!!";
	}else{
		cout << endl << "Thong tin khong bi trung!!!";
	}
}
