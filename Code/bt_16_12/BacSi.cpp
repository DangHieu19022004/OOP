#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

class NGUOI{
    private:
        string HoTen;
        int Tuoi;
    public:
        NGUOI(): HoTen(""), Tuoi(0){}
        NGUOI(string HoTen, int Tuoi):HoTen(HoTen), Tuoi(Tuoi){}
        int getTuoi(){return Tuoi;}
        void Nhap();
        virtual void Xuat();
};

void NGUOI::Nhap(){
    cout<<"Nhap ten: "; getline(cin, HoTen);
    cout<<"Nhap Tuoi: "; cin>>Tuoi; cin.ignore();
}

void NGUOI::Xuat(){
    cout << endl << "Danh sach nguoi vua nhap"<<endl;
    cout << left << setw(30) << setfill(' ') << "Ten";
    cout << left << setw(20) << setfill(' ') << "Tuoi" << endl;

    cout << left << setw(30) << setfill(' ') << HoTen;
    cout << left << setw(20) << setfill(' ') << Tuoi << endl;
    cout << endl<<endl;
}

class BACSI : public NGUOI{
    private:
        char MaBS;
        float SoNgayLamViec;
        float TienCong;
    public:
        BACSI(): NGUOI(), MaBS('0'), SoNgayLamViec(0), TienCong(0){}
        BACSI(string HoTen, int Tuoi, char MaBS, float SoNgayLamViec, float TienCong): NGUOI(HoTen, Tuoi), MaBS(MaBS), SoNgayLamViec(SoNgayLamViec), TienCong(TienCong){}
        void Nhap();
        double TinhLuong();
        void Xuat();
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
    cout<<endl;
    NGUOI::Xuat();
    cout << left << setw(30) << setfill(' ') << "Ma bac si";
    cout << left << setw(15) << setfill(' ') << "So ngay lam viec";
    cout << left << setw(15) << setfill(' ') << "Tien cong thang" << endl;

    cout << left << setw(30) << setfill(' ') << MaBS;
    cout << left << setw(15) << setfill(' ') << SoNgayLamViec;
    cout << left << setw(15) << setfill(' ') << TinhLuong() << endl;
    cout << endl<<endl;
}

class BENHNHAN : public NGUOI{
    private:
        char MaBN;
        float SoNgayDieuTri;
    public:
        BENHNHAN(): NGUOI(), MaBN('0'), SoNgayDieuTri(0){}
        BENHNHAN(string HoTen, int Tuoi, char MaBN, float SoNgayDieuTri): NGUOI(HoTen, Tuoi), MaBN(MaBN), SoNgayDieuTri(SoNgayDieuTri){}
        void Nhap();
        void Xuat();
};

void BENHNHAN::Nhap(){
    NGUOI::Nhap();
    cout<<"Nhap ma benh nhan: "; cin>>MaBN;
    cout<<"Nhap so ngay dieu tri: "; cin>>SoNgayDieuTri;
}

void BENHNHAN::Xuat(){
    cout<<endl;
    NGUOI::Xuat();
    cout << left << setw(30) << setfill(' ') << "Ma benh nhan";
    cout << left << setw(15) << setfill(' ') << "So ngay dieu tri" << endl;

    cout << left << setw(30) << setfill(' ') << MaBN;
    cout << left << setw(15) << setfill(' ') << SoNgayDieuTri << endl;
    cout << endl<<endl;
}
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

    for(int i=0; i<dsNguoi.size(); i++){
        dsNguoi[i]->Xuat();
    }
    cout<<endl<<"Danh sach benh nhan duoi 20 tuoi: "<<endl;
    for(int i=0; i<dsBenhNhan.size(); i++){
        if(dsBenhNhan[i]->getTuoi()<=20){
            dsBenhNhan[i]->Xuat();
        }
    }
    sort(dsBacSi.begin(), dsBacSi.end(), [](BACSI* a, BACSI* b) {
        return a->TinhLuong() > b->TinhLuong();
    });

    cout <<endl<< "Danh sach bac si co so ngay lam viec nhieu nhat:\n";
    dsBacSi[0]->Xuat();
    return 0;
}