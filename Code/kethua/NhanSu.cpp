#include<iostream>

using namespace std;

class NhanSu{
    private:
        string MaNV;
        string HoTen;
        int Tuoi;
    public:
        NhanSu(string MaNV, string HoTen, int Tuoi) : MaNV(MaNV), HoTen(HoTen), Tuoi(Tuoi) {};
        void Nhap();
        void Xuat();
        bool kiemtravehuu();
};

void NhanSu::Nhap(){
    cout << "Nhap ma nhan vien: ";
    cin.ignore();
    getline(cin, MaNV);
    cout << "Nhap ho ten: ";
    getline(cin, HoTen);
    cout << "Nhap tuoi: ";
    cin >> Tuoi;
}

void NhanSu::Xuat(){
    cout << "Ma nhan vien: " << MaNV << endl;
    cout << "Ho ten: " << HoTen << endl;
    cout << "Tuoi: " << Tuoi << endl;
}

bool NhanSu::kiemtravehuu(){
    if(Tuoi >= 60){
        return true;
    }
    return false;
}

class CongNhan : public NhanSu{
    private:
        int Luong;
        int NgayCong;
        string Taynghe;
    public:
        CongNhan() : NhanSu("", "", 0), Luong(0), NgayCong(0), Taynghe("") {};
        void Nhap();
        void Xuat();
        int TinhLuong();
};

void CongNhan::Nhap(){
    NhanSu::Nhap();
    cout << "Nhap luong: ";
    cin >> Luong;
    cout << "Nhap ngay cong: ";
    cin >> NgayCong;
    cout << "Nhap tay nghe: ";
    cin.ignore();
    getline(cin, Taynghe);
}

void CongNhan::Xuat(){
    NhanSu::Xuat();
    cout << "Luong: " << Luong << endl;
    cout << "Ngay cong: " << NgayCong << endl;
    cout << "Tay nghe: " << Taynghe << endl;
}

int CongNhan::TinhLuong(){
    return Luong * NgayCong;
}

class CanBo : public NhanSu{
    private:
        int HeSoLuong;
        int PhuCap;
        string ChuyenMon;
        string Trinhdo;
    public:
        CanBo() : NhanSu("", "", 0), HeSoLuong(0), PhuCap(0), ChuyenMon(""), Trinhdo("") {};
        void Nhap();
        void Xuat();
        int TinhLuong();
};

void CanBo::Nhap(){
    NhanSu::Nhap();
    cout << "Nhap he so luong: ";
    cin >> HeSoLuong;
    cout << "Nhap phu cap: ";
    cin >> PhuCap;
    cout << "Nhap chuyen mon: ";
    cin.ignore();
    getline(cin, ChuyenMon);
    cout << "Nhap trinh do: ";
    getline(cin, Trinhdo);
}

void CanBo::Xuat(){
    NhanSu::Xuat();
    cout << "He so luong: " << HeSoLuong << endl;
    cout << "Phu cap: " << PhuCap << endl;
    cout << "Chuyen mon: " << ChuyenMon << endl;
    cout << "Trinh do: " << Trinhdo << endl;
}

int CanBo::TinhLuong(){
    return HeSoLuong * 1000000 + PhuCap;
}

int main(){
    CongNhan cn[100];
    CanBo cb[100];
    int n, m;
    cout<<"Nhap so Cong nhan: ";
    cin>>n;
    cout<<"Nhap so can bo: ";
    cin>>m;
    cout<<"Nhap thong tin cong nhan: "<<endl;
    for (int i = 0; i < n; i++) {
        cout<<"Nhap cong nhan thu "<<i+1<<endl;
        cn[i].Nhap();
    }
    cout<<"Nhap thong tin can bo: "<<endl;
    for(int i = 0; i < m; i++){
        cout<<"Nhap can bo thu "<<i+1<<endl;
        cb[i].Nhap();
    }
    // xuat
    cout<<"---------------------------"<<endl;
    cout<<"Danh sach cong nhan: "<<endl;
    for(int i=0; i<n; i++){
        cn[i].Xuat();
    }
    cout<<">>>>>>>>>>>>";
    cout<<"Danh sach can bo: "<<endl;
    for(int i=0; i<m; i++){
        cb[i].Xuat();
    }
    //cong nhan du dk ve huu
    cout<<">>>>>>>>>>>>";
    cout<<"Cong nhan du dk ve huu: "<<endl;
    for(int i=0; i<n; i++){
        if(cn[i].kiemtravehuu()){
            cn[i].Xuat();
        }
    }
    //can bo chua du dk ve huu
    cout<<">>>>>>>>>>>>";
    cout<<"Can bo chua du dk ve huu"<<endl;
    for (int i = 0; i < n; i++) {
        if (!cb[i].kiemtravehuu()) {
            cb[i].Xuat();
        }
    }
    //tinh luong max
    cout<<">>>>>>>>>>>>";
    int luongmax=cn[0].TinhLuong();
    for(int i=0; i<n; i++){
        if(luongmax<cn[i].TinhLuong()){
            luongmax=cn[i].TinhLuong();
        }
    }
    cout<<"Luong cao nhan cua cong nhan: "<<luongmax<<endl;
    //tinh luong min
    cout<<">>>>>>>>>>>>";
    int luongmin=cb[0].TinhLuong();
    for(int i=0; i<m; i++){
        if(luongmin<cb[i].TinhLuong()){
            luongmin=cb[i].TinhLuong();
        }
    }
    cout<<"Luong thap nhat cua can bo: "<<luongmin<<endl;

    return 0;
}
