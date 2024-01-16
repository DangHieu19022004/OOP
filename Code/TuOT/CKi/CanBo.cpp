#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class CANBO{
	protected:
		string HoTen;
		int NamSinh;
		string GioiTinh;
		string DiaChi;
	public:
		CANBO(){};
		CANBO(string HoTen, int NamSinh, string GioiTinh, string DiaChi) : HoTen(HoTen), NamSinh(NamSinh), GioiTinh(GioiTinh), DiaChi(DiaChi){};
		// truy cap
		string getHoTen(){
			return HoTen;
		}
		int getNamSinh(){
			return NamSinh;
		}
		string getGioiTinh(){
			return GioiTinh;
		}
		string getDiaChi(){
			return DiaChi;
		}
		// bien doi
		void setHoTen(string hoTen){
			this->HoTen=hoTen;
		}
		void setNamSinh(int namSinh){
			this->NamSinh=namSinh;
		}
		void setGioiTinh(string gioiTinh){
			this->GioiTinh=gioiTinh;
		}
		void setDiaChi(string diaChi){
			this->DiaChi=diaChi;
		}
		//nhap
		virtual void Nhap(){
			cout << "Nhap ho ten: ";
			getline(cin, HoTen);
			cout << "Nhap nam sinh: ";
			cin >> NamSinh;
			cin.ignore();
			cout << "Nhap gioi tinh: ";
			getline(cin,GioiTinh);
			cout << "Nhap dia chi: ";
			getline(cin, DiaChi);
		}
		// xuat
		virtual void Xuat(){
//			cout << left << setw(30) << HoTen << setw(10) << NamSinh << setw(10) << GioiTinh << setw(30) << DiaChi;
			cout << "Ho ten: " << HoTen << endl;
			cout << "Nam sinh: " << NamSinh << endl;
			cout << "Gioi tinh: " << GioiTinh << endl;
			cout << "Dia chi: " << DiaChi << endl;
		}
		// Tinh tuoi
		int TinhTuoi(){
			return 2024 - NamSinh;
		}
		
		bool operator != (CANBO &canBo){
			return this->HoTen != canBo.HoTen;
		}
};

class CONGNHAN : public CANBO{
	private:
		string Bac;
	public:
		CONGNHAN(){};
		CONGNHAN(string HoTen, int NamSinh, string GioiTinh, string DiaChi, string Bac) : CANBO(HoTen, NamSinh, GioiTinh, DiaChi){
			this->Bac=Bac;
		}
		// Nhap 
		void Nhap(){
			CANBO::Nhap();
			cout << "Bac: ";
			getline(cin, Bac);
		}
		// Xuat
		void Xuat(){
			CANBO::Xuat();
			cout << "Bac: " << Bac << endl;
		}
};

class KYSU : public CANBO{
	private:
		string NganhDaoTao;
	public:
		KYSU(){};
		KYSU(string HoTen, int NamSinh, string GioiTinh, string DiaChi, string NganhDaoTao) : CANBO(HoTen, NamSinh, GioiTinh, DiaChi){
			this->NganhDaoTao=NganhDaoTao;
		}
		// Nhap 
		void Nhap(){
			CANBO::Nhap();
			cout << "Nganh dao tao: ";
			getline(cin, NganhDaoTao);
		}
		// Xuat
		void Xuat(){
			CANBO::Xuat();
			cout << "Nganh dao tao: " << NganhDaoTao << endl;
		}		
};

int main(){
	vector<CANBO*> dsCanBo;
	vector<CONGNHAN*> dsCongNhan;
	vector<KYSU*> dsKySu;
	int n;
	do{
		cout << "Nhap so can bo: ";
		cin >> n;
		cin.ignore();
		if(n<=0 || n>100){
			cout << "Nhap sai, vui long nhap lai !!!";
		}
	}while(n<=0 || n>100);
	
	for(int i=0; i<n; i++){
		cout << "Nhap thong tin can bo thu " << i+1 << ": "<< endl;
		char check;
		do{
			cout << "Ban muon nhap thong tin cho cong nhan (1) hay ky su (2), lua chon cua ban: ";
			cin >> check;
			cin.ignore();
			if(check == '1'){
				CONGNHAN *cn = new CONGNHAN();
				cn->Nhap();
				dsCongNhan.push_back(cn);
				dsCanBo.push_back(cn);
			}else if(check == '2'){
				KYSU *ks = new KYSU();
				ks->Nhap();
				dsKySu.push_back(ks);
				dsCanBo.push_back(ks);
			}
			if(check!='1' && check != '2'){
				cout << "Nhap sai, vui long nhap lai!!!" << endl;
			}
		}while(check!='1' && check != '2');
	}
	cout << endl << endl << "Danh sach cong nhan" << endl ;
	for(int i=0; i<dsCongNhan.size(); i++){
		dsCongNhan[i]->Xuat();
	}
	
	cout << endl << endl << "Danh sach ky su" << endl;
	for(int i=0; i<dsKySu.size(); i++){
		dsKySu[i]->Xuat();
	}
	
	string ten;
	cout << endl << "Nhap ten can tim: ";
	getline(cin, ten);
	bool checktt = false;
//	
	for(int i=0; i<dsCanBo.size(); i++){
		if(dsCanBo[i]->getHoTen() == ten){
			dsCanBo[i]->Xuat();
			checktt = true;
		}
	}
//
	if(checktt == false){
		cout << endl << "khong tim thay nhan vien";
	}
	
	cout << endl << endl << "Danh sach cong nhan co tuoi >= 55" << endl;
	for(int i=0; i<dsCongNhan.size(); i++){
		if(dsCongNhan[i]->TinhTuoi() >= 55){
			dsCongNhan[i]->Xuat();
		}
	}
}
