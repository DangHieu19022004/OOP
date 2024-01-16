#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class MonHoc{
	private:
		string MaMH;
		string TenMH;
		int SoTinChi;
	public:
		// ham khoi tao
		MonHoc(){};
		MonHoc(string MaMH, string TenMH, int SoTinChi){
			this->MaMH = MaMH;
			this->TenMH = TenMH;
			this->SoTinChi = SoTinChi;
		}
		
		// truy cap
		string getMaMH(){
			return MaMH;
		}
		string getTenMH(){
			return TenMH;
		}
		int getSoTinChi(){
			return SoTinChi;
		}
		
		// bien doi
		void setMaMH(string maMH){
			this->MaMH = maMH;
		}
		void setTenMH(string tenMH){
			this->TenMH = tenMH;
		}
		void setSoTinChi(int soTinChi){
			this->SoTinChi = soTinChi;
		}
		
		//nhap
		void input(){
			cout << "Nhap ma mon hoc: ";
			getline(cin, MaMH);
			cout << "Nhap ten mon hoc: ";
			getline(cin, TenMH);
			cout << "Nhap so tin chi: ";
			cin >> SoTinChi;
			cin.ignore();
		}
		
		//xuat
		void output(){
			cout << "Ma mon hoc: " << MaMH << endl;
			cout << "Ten mon hoc: " << TenMH << endl;
			cout << "So tin chi: " << SoTinChi << endl;
		}
};

class ToanHoc : public MonHoc{
	private:
		string KieuHoc;
	public:
		ToanHoc(){};
		ToanHoc(string MaMH, string TenMH, int SoTinChi) : MonHoc(MaMH, TenMH, SoTinChi){
			this->KieuHoc = KieuHoc;
		}
		
		// truy cap
		string getKieuHoc(){
			return KieuHoc;
		}
		
		// bien doi
		void setKieuHoc(string kieuHoc){
			this->KieuHoc = kieuHoc;
		}
		
		// nhap
		void input(){
			MonHoc::input();
			cout << "Nhap kieu hoc: ";
			getline(cin, KieuHoc);
		}
		
		// xuat
		void output(){
			MonHoc::output();
			cout << "Kieu hoc: " << KieuHoc << endl;
		}
		
		friend bool operator!=(ToanHoc a, ToanHoc b){
			return a.getMaMH() != b.getMaMH();
		}
};


int main(){
	vector<ToanHoc*> dsToanHoc;
	int N;
	cout << "Nhap so luong mon toan hoc: ";
	cin >> N;
	cin.ignore();
	for(int i=0; i<N; i++){
		cout << endl << "Nhap mon toan thu " << i+1 << ": " << endl;
		ToanHoc *p = new ToanHoc();
		p->input();
		dsToanHoc.push_back(p);
	}
	cout << endl << "Danh sach vua nhap: " << endl;	
	for(int i=0; i<N; i++){
		dsToanHoc[i]->output();
		cout << endl;
	}
	cout << endl << endl << "Nhap thong tin bo sung: " << endl;
	ToanHoc *p = new ToanHoc();
	p->input();
	dsToanHoc.push_back(p);
	bool check=false;
	for(int i=0; i<dsToanHoc.size()-1; i++){
		if(*dsToanHoc.back()!=*dsToanHoc[i]){
			continue;
		}else{
			check=true;
			break;
		}
	}
	if(check==true){
		cout << endl << "Trung thong tin!!";
	}else{
		cout << endl << "Khong trung!!";
	}
}
