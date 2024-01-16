#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cstring>

using namespace std;

//class nguoi
class NGUOI{
    private:
        string HoTen;
        int Namsinh;
    public:
        NGUOI(): HoTen(""), Namsinh(0){}
        NGUOI(string HoTen, int Namsinh):HoTen(HoTen), Namsinh(Namsinh){}
        int getNamsinh(){return Namsinh;}
        string getHoTen(){
        	return HoTen;
		}
        void Nhap();
        virtual void Xuat();
};

void NGUOI::Nhap(){
    cout<<"Nhap ten: "; getline(cin, HoTen);
    cout<<"Nhap Nam sinh: "; cin>>Namsinh; cin.ignore();
}

void NGUOI::Xuat(){
	cout << left << setw(20) << HoTen << setw(10) << Namsinh << endl;
}

// class bac si ke thua lop nguoi
class BACSI : public NGUOI{
    private:
        char MaBS[50];
        float SoNgayLamViec;
        float TienCong;
    public:
        BACSI(){};
        BACSI(char MaBS[50], float SoNgayLamViec, float TienCong)
            : SoNgayLamViec(SoNgayLamViec), TienCong(TienCong) {
                strcpy(this->MaBS, MaBS);
            }
        void Nhap();
        double TinhLuong();
        void Xuat();
        float getSoNgayLamViec();
};

void BACSI::Nhap(){
    NGUOI::Nhap();
    cout<<"Nhap ma bac si: "; cin>>MaBS;
    cout<<"Nhap so ngay lam viec: "; cin>>SoNgayLamViec;
    cout<<"Nhap tien luong: "; cin>>TienCong;
}

double BACSI::TinhLuong(){
    return (TienCong*SoNgayLamViec)/30;
}

void BACSI::Xuat(){
    cout << left << setw(20) << getHoTen() << setw(15) << getNamsinh() << setw(20) << MaBS << setw(40) << SoNgayLamViec << setw(20) << fixed << setprecision(0) << TienCong << setw(20) << TinhLuong() << endl;
}

float BACSI::getSoNgayLamViec(){
	return SoNgayLamViec;
}

//class benh nhan ke thua lop nguoi
class BENHNHAN : public NGUOI{
    private:
        char Tenbenhan[50];
        int Songaynam;
        double Giavienphi;
    public:
        BENHNHAN(){};
        BENHNHAN(char Tenbenhnhan[50], int Songaynam, double Giavienphi)
            : Songaynam(Songaynam), Giavienphi(Giavienphi) {
                strcpy(this->Tenbenhan, Tenbenhnhan);
            }
        int Tinhtuoi();
        double TinhTien();
        void Nhap();
        void Xuat();
};

int BENHNHAN::Tinhtuoi(){
    return 2024 - getNamsinh();
}

double BENHNHAN::TinhTien(){
    return Giavienphi*Songaynam;
}

void BENHNHAN::Nhap(){
    NGUOI::Nhap();
    cout<<"Nhap ten benh an: "; cin>>Tenbenhan;
    cout<<"Nhap so ngay dieu tri: "; cin>>Songaynam;
    cout<<"Nhap gia vien phi: "; cin>>Giavienphi;
}

void BENHNHAN::Xuat(){
	cout << left << setw(20) << getHoTen() << setw(15) << getNamsinh() << setw(10) << Tinhtuoi() << setw(20) << Tenbenhan << setw(20) << Songaynam << setw(20) << fixed << setprecision(0) << Giavienphi << setw(20) << TinhTien() << endl;
}

// hàm main
int main(){
    vector<NGUOI*> dsNguoi;
    vector<BACSI*> dsBacSi;
    vector<BENHNHAN*> dsBenhNhan;
    int n;
    cout << "Nhap so nguoi trong danh sach: ";
    cin >> n;
    cin.ignore();
    cout<<endl;
    char check;
    //Nhap thong tin 
    for(int i=1; i<=n; i++){
        cout<<"Nhap thong tin nguoi thu "<<i<<endl;
        cout<<"Ban muon nhap thong tin bac si hay benh nhan? Nhan phim 1 de nhap thong tin bac si, phim 2 de nhap thong tin benh nhan. "<<endl;
        do{
            cout<<"Lua chon cua ban: ";
            cin>>check;
            cin.ignore();
            if(check=='1'){
                BACSI* BacSi = new BACSI();
                BacSi->Nhap();
                dsBacSi.push_back(BacSi);
                dsNguoi.push_back(BacSi);
            }else if(check=='2'){
                BENHNHAN* BenhNhan = new BENHNHAN();
                BenhNhan->Nhap();
                dsBenhNhan.push_back(BenhNhan);
                dsNguoi.push_back(BenhNhan);
            }else{
                cout<<"Nhap sai, moi nhap lai: ";
            }
        }while(check!='1' && check!='2');
    }
    
    //in thong tin vua nhap
    
    cout << endl << right << setw(70) << "Danh sach bac si" << endl;
    cout << endl << left << setw(20) << "Ho Ten" << setw(15) << "Nam Sinh" <<setw(20) << "Ma Bac Si" << setw(40) << "So ngay lam viec"<< setw(20) << "Tien cong " << setw(20) << "Luong" << endl;
    for(int i=0; i<dsBacSi.size(); i++){
        dsBacSi[i]->Xuat();
    }
    
    cout << endl << endl << right << setw(70) << "Danh sach benh nhan" << endl;
    cout << endl << left << setw(20) << "Ho Ten" << setw(15) << "Nam Sinh" << setw(10) << "Tuoi" << setw(20) << "Ten benh an" << setw(20) << "So ngay nam" << setw(20) << "Gia vien phi" << setw(20) << "Tong tien"<< endl;
    for(int i=0; i<dsBenhNhan.size(); i++){
        dsBenhNhan[i]->Xuat();
    }
    cout << endl << endl << right << setw(65) << "Danh sach benh nhan co tuoi <= 10" << endl;
    cout << endl << left << setw(20) << "Ho Ten" << setw(15) << "Nam Sinh" << setw(10) << "Tuoi" << setw(20) << "Ten benh an" << setw(20) << "So ngay nam" << setw(20) << "Gia vien phi" << setw(20) << "Tong tien"<< endl;
    for(int i=0; i<dsBenhNhan.size(); i++){
    	if(dsBenhNhan[i]->Tinhtuoi() <= 10){
    		dsBenhNhan[i]->Xuat();
		}
	}
	cout << endl << endl << right << setw(60) << "Danh sach bac si co so ngay lam nhieu nhat" << endl;
	cout << endl << left << setw(20) << "Ho Ten" << setw(15) << "Nam Sinh" <<setw(20) << "Ma Bac Si" << setw(40) << "So ngay lam viec"<< setw(20) << "Tien cong " << setw(20) << "Luong" << endl;
	int maxNgaylamviec=dsBacSi[0]->getSoNgayLamViec();
	for(int i=0; i<dsBacSi.size(); i++){
		if(maxNgaylamviec < dsBacSi[i]->getSoNgayLamViec()){
			maxNgaylamviec = dsBacSi[i]->getSoNgayLamViec();
		}
	}
	for(int i=0; i<dsBacSi.size(); i++){
		if(maxNgaylamviec == dsBacSi[i]->getSoNgayLamViec()){
			dsBacSi[i]->Xuat();
		}
	}
    return 0;
}
