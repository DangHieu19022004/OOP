#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Nguoi{
    private:
        string HoTen;
        int Tuoi;
        string DiaChi;
    public:
        Nguoi() : HoTen(""), Tuoi(0), DiaChi(""){};
        Nguoi(string HoTen, int Tuoi, string DiaChi) : HoTen(HoTen), Tuoi(Tuoi), DiaChi(DiaChi){};
        string getHoTen(){return HoTen;}
        int getTuoi(){return Tuoi;}
        string getDiaChi(){return DiaChi;}
        void Nhap();
        virtual void Xuat();
};

void Nguoi::Nhap(){
    cout<<"Nhap ten: "; getline(cin, HoTen);
    cout<<"Nhap tuoi: "; cin>>Tuoi; cin.ignore();
    cout<<"Nhap dia chi: "; getline(cin, DiaChi);
}

void Nguoi::Xuat(){
    cout << left << setw(30) << HoTen << setw(30) << Tuoi << setw(30) << DiaChi << endl;
}

class CongChucNhaNuoc : public Nguoi{
    private:
        string MaCC;
        float Luong;
    public:
        CongChucNhaNuoc() : Nguoi(), MaCC(""), Luong(0){};
        CongChucNhaNuoc(string HoTen, int Tuoi, string DiaChi, string MaCC, float Luong) : Nguoi(HoTen, Tuoi, DiaChi), MaCC(MaCC), Luong(Luong){};
        void Nhap();
        void Xuat();
};

void CongChucNhaNuoc::Nhap(){
    Nguoi::Nhap();
    cout<<"Nhap ma cong chuc: "; getline(cin, MaCC);
    cout<<"Nhap luong: "; cin>>Luong; cin.ignore();
}

void CongChucNhaNuoc::Xuat(){
    cout << left << setw(30) << getHoTen() << setw(30) << getTuoi() << setw(30) << getDiaChi() << setw(20) << MaCC << setw(30) << Luong << endl;
}


int main(){
    vector<Nguoi*> dsNguoi;
    vector<CongChucNhaNuoc*> dsCCNN;
    int n;
    cout << "Nhap so luong nguoi: "; cin >> n; cin.ignore();
    for(int i=0; i<n; i++){
        cout << "Nhap thong tin nguoi thu " << i+1 << endl;
        cout << "Co them nguoi thu " << i+1 << " vao danh sach cong chuc nha nuoc khong? (y/n): ";
        string check;
        getline(cin, check);
        if(check=="y" || check == "Y"){
            CongChucNhaNuoc *CCNN = new CongChucNhaNuoc();
            CCNN->Nhap();
            dsCCNN.push_back(CCNN);
            dsNguoi.push_back(CCNN);
        }else{
            Nguoi *nguoi = new Nguoi();
            nguoi->Nhap();
            dsNguoi.push_back(nguoi);
        }
    }
    cout << endl << setw(30) << "Danh sach nguoi: " << endl;
    cout << left << setw(30) << "Ho ten" << setw(30) << "Tuoi" << setw(30) << "Dia chi" << endl;
    cout << setfill('-') << setw(30) << "" << setw(30) << "" << setw(30) << "" << setfill(' ')<< endl;
    for(int i=0; i<n; i++){
        dsNguoi[i]->Xuat();
    }
    cout << endl << "Danh sach CCNH: " << endl;
    cout << left << setw(30) << "Ho ten" << setw(30) << "Tuoi" << setw(30) << "Dia chi" << setw(20) << "Ma CC" << setw(30) << "Luong" << endl;
    cout << left << setfill('-') << setw(30) << "" << setw(30) << "" << setw(30) << "" << setw(20) << "" << setw(30) << "" << setfill(' ')<< endl;
    for(int i=0; i<n; i++){
        dsCCNN[i]->Xuat();
    }
    cout << endl << "--------------------------------------------"<<endl;
}