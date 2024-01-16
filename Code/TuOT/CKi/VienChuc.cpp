#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

class VIENCHUC{
	private:
		string MaVienChuc;
		string HoTen;
		int NamSinh;
		double HeSoLuong;
	public:
		VIENCHUC(){};
		VIENCHUC(string MaVienChuc, string HoTen, int NamSinh, double HeSoLuong){
			this->MaVienChuc = MaVienChuc;
			this->HoTen = HoTen;
			this->NamSinh = NamSinh;
			this->HeSoLuong = HeSoLuong;
		}
		virtual void Nhap(){
			cout << "Ma vien chuc: ";
			getline(cin, MaVienChuc);
			cout << "Ho ten: ";
			getline(cin, HoTen);
			cout << "Nam sinh: ";
			cin >> NamSinh;
			cin.ignore();
			cout << "He so luong: ";
			cin >> HeSoLuong;
			cin.ignore();
		}
		virtual void Xuat(){
			cout << "Ma vien chuc: " << MaVienChuc << endl;
			cout << "Ho ten: " << HoTen << endl;
			cout << "Nam sinh: " << NamSinh << endl;
			cout << "He so luong: " << HeSoLuong << endl;
		}
		double getHeSoLuong(){
			return HeSoLuong;
		}
		virtual double TinhLuong()=0;
};

class CBHANHCHINH : public VIENCHUC{
	private:
		string ChucDanh;
		double PhuCapAnTrua;
	public:
		CBHANHCHINH(){}
		CBHANHCHINH(string MaVienChuc, string HoTen, int NamSinh, double HeSoLuong, string ChucDanh, double PhuCapAnTrua) : VIENCHUC(MaVienChuc, HoTen, NamSinh, HeSoLuong){
			this->ChucDanh = ChucDanh;
			this->PhuCapAnTrua = PhuCapAnTrua;
		}
		virtual void Nhap(){
			VIENCHUC::Nhap();
			cout << "Nhap chuc danh: ";
			getline(cin, ChucDanh);
			cout << "Nhap phu cap an trua: ";
			cin >> PhuCapAnTrua;
			cin.ignore();
		}
		virtual void Xuat(){
			VIENCHUC::Xuat();
			cout << "Chuc danh: " << ChucDanh << endl;
			cout << "Phu cap: " << PhuCapAnTrua << endl;
		}
		double TinhLuong(){
			return getHeSoLuong()*2000000+PhuCapAnTrua;
		}
};

class GIAOVIEN : public VIENCHUC{
	private:
		string MonDay;
		string TrinhDoChuyenMon;
		int ThamNien;
	public:
		GIAOVIEN(){}
		GIAOVIEN(string MaVienChuc, string HoTen, int NamSinh, double HeSoLuong, string MonDay, string TrinhDoChuyenMon, int ThamNien) : VIENCHUC(MaVienChuc, HoTen, NamSinh, HeSoLuong){
			this->MonDay = MonDay;
			this->TrinhDoChuyenMon = TrinhDoChuyenMon;
			this->ThamNien = ThamNien;
		}
		virtual void Nhap(){
			VIENCHUC::Nhap();
			cout << "Nhap mon day: ";
			getline(cin, MonDay);
			cout << "Nhap trinh do chuyen mon: ";
			getline(cin, TrinhDoChuyenMon);
			cout << "Nhap tham nien: ";
			cin >> ThamNien;
			cin.ignore();
		}
		virtual void Xuat(){
			VIENCHUC::Xuat();
			cout << "Mon day: " << MonDay << endl;
			cout << "Trinh do chuyen mon: " << TrinhDoChuyenMon << endl;
			cout << "Tham nien: " << ThamNien << endl;
		}
		double TinhLuong(){
			return getHeSoLuong()*2000000*(130+ThamNien)/100;
		}
};

int main(){
	vector<VIENCHUC*> dsVienChuc;
	vector<CBHANHCHINH*> dsCBHanhChinh;
	vector<GIAOVIEN*> dsGiaoVien;
	int N;
	cout << "Nhap so vien chuc: ";
	cin >> N;
	cin.ignore();
	int choice;
	for(int i=0; i<N; i++){
		cout << "Nhap thong tin cho CBHANHCHINH [1] hay GIAOVIEN [2]: ";
		cin >> choice;
		cin.ignore();
		if(choice==1){
			CBHANHCHINH *cbhc = new CBHANHCHINH();
			cbhc->Nhap();
			dsCBHanhChinh.push_back(cbhc);
			dsVienChuc.push_back(cbhc);
		}else if(choice==2){
			GIAOVIEN *gv = new GIAOVIEN();
			gv->Nhap();
			dsGiaoVien.push_back(gv);
			dsVienChuc.push_back(gv);
		}
	}
	cout << endl << endl << "Danh sach vien chuc: " << endl;
	for(int i=0; i<N; i++){
		dsVienChuc[i]->Xuat();
		cout << endl;
	}
	//
	cout << endl << endl << "Vien chuc co luong cao nhat truong:" << endl;
	double maxL = dsVienChuc[0]->TinhLuong();
	for(int i=0; i<N; i++){
		if(maxL < dsVienChuc[i]->TinhLuong()){
			maxL = dsVienChuc[i]->TinhLuong();
		}
	}
	for(int i=0; i<N; i++){
		if(maxL == dsVienChuc[i]->TinhLuong()){
			dsVienChuc[i]->Xuat();
			cout << "Luong: " << fixed << setprecision(2) <<  maxL << endl;
			break;
		}
	}
}
