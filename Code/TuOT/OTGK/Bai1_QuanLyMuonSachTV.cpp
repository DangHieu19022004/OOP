#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;

class BanDoc{
    private:
        static int MaBanDocID;
        int MaBanDoc;
        string HoTen;
        string DiaChi;
        string SoDT;
        string LoaiBanDoc;
    public:
        BanDoc(){
            this->MaBanDoc = MaBanDocID++;
        };
        BanDoc(string HoTen, string DiaChi, string SoDT, string LoaiBanDoc) : HoTen(HoTen), DiaChi(DiaChi), SoDT(SoDT), LoaiBanDoc(LoaiBanDoc){
            this->MaBanDoc = MaBanDocID++;
        };
        int getMaBanDoc(){
            return this->MaBanDoc;
        }
        string getHoTen(){
            return this->HoTen;
        }
        void Nhap();
        void Xuat();
};

int BanDoc::MaBanDocID = 10000;

void BanDoc::Nhap(){
    cout << endl << "Nhap ho ten: ";
    getline(cin, HoTen);
    cout << "Nhap dia chi: ";
    getline(cin, DiaChi);
    cout << "Nhap so dien thoai: ";
    getline(cin, SoDT);
    cout << "Nhap loai ban doc: ";
    getline(cin, LoaiBanDoc);
}

void BanDoc::Xuat(){
    cout << left << setw(15) << MaBanDoc << setw(40) << HoTen << setw(40) << DiaChi << setw(15) << SoDT << setw(20) << LoaiBanDoc << endl;
}

class Sach{
    private:
        static int MaSachID;
        int MaSach;
        string TenSach;
        string TenTacGia;
        string ChuyenNganh;
        int NamXuatBan;
    public:
        Sach(){
            this->MaSach = MaSachID++;
        };
        Sach(string TenSach, string TenTacGia, string ChuyenNganh, int NamXuatBan) : TenSach(TenSach), TenTacGia(TenTacGia), ChuyenNganh(ChuyenNganh), NamXuatBan(NamXuatBan){
            this->MaSach = MaSachID++;
        };
        string getTenSach(){
            return this->TenSach;
        }
        void Nhap();
        void Xuat();
};

int Sach::MaSachID = 10000;

void Sach::Nhap(){
    cout << endl << "Nhap ten sach: ";
    getline(cin, TenSach);
    cout << "Nhap ten tac gia: ";
    getline(cin, TenTacGia);
    cout << "Nhap chuyen nganh: ";
    getline(cin, ChuyenNganh);
    cout << "Nhap nam xuat ban: ";
    cin >> NamXuatBan; 
    cin.ignore();
}

void Sach::Xuat(){
    cout << left << setw(15) << MaSach << setw(40) << TenSach << setw(40) << TenTacGia << setw(60) << ChuyenNganh << setw(10) << NamXuatBan << endl;
}

class BangQLMuonSach{
    private:
        BanDoc banDoc;
        Sach sach;
        string TinhTrangSach;
        time_t NgayMuon;
    public:
        BangQLMuonSach(){};
        BangQLMuonSach(BanDoc banDoc, Sach sach, string TinhTrangSach, time_t NgayMuon) : banDoc(banDoc), sach(sach), TinhTrangSach(TinhTrangSach), NgayMuon(NgayMuon){
        };
        void Xuat();
        string getHoTen(){
            return this->banDoc.getHoTen();
        }
        string getNgayMuon(){
            return ctime(&NgayMuon);
        }
};

void BangQLMuonSach::Xuat(){
    cout << left << setw(40) << banDoc.getHoTen() << setw(40) << sach.getTenSach() << setw(20) << TinhTrangSach << setw(30) << ctime(&NgayMuon) << endl;
}

int main(){



    vector<BanDoc*> DanhSachBanDoc;
    vector<Sach*> DanhSachSach;
    vector<BangQLMuonSach*> DanhSachBangQLMuonSach;
    
    int slSach;
    cout << "Nhap so dau sach moi: ";
    cin >> slSach;
    cin.ignore();
    for(int i=0; i<slSach; i++){
        Sach *sach = new Sach();
        sach->Nhap();
        DanhSachSach.push_back(sach);
    }
    cout << endl << right << setw(100) << "Danh sach dau sach vua nhap: " << endl << endl;
    cout << left << setw(15) << "Ma sach" << setw(40) << "Ten sach" << setw(40) << "Ten tac gia" << setw(60) << "Chuyen nganh" << setw(10) << "Nam xuat ban" << endl;
    cout << setfill('-') << setw(165) << "-" << setfill(' ')<< endl;
    for(int i=0; i<slSach; i++){
        DanhSachSach[i]->Xuat();
    }
    int slBanDoc;
    cout << endl << "Nhap so ban doc moi: ";
    cin >> slBanDoc;
    cin.ignore();
    for(int i=0; i<slBanDoc; i++){
        BanDoc *banDoc = new BanDoc();
        banDoc->Nhap();
        DanhSachBanDoc.push_back(banDoc);
    }
    cout << endl << right << setw(100) << "Danh sach ban doc vua nhap: " << endl << endl;
    cout << left << setw(15) << "Ma ban doc" << setw(40) << "Ho ten" << setw(40) << "Dia chi" << setw(15) << "So dien thoai" << setw(20) << "Loai ban doc" << endl;
    for(int i=0; i<slBanDoc; i++){
        DanhSachBanDoc[i]->Xuat();
    }
    //
    cout << endl ;
    cout << "Quan ly muon sach: " << endl;
    for(int i=0; i<slBanDoc; i++){
        for(int j=0; j<slSach; j++){
            cout << "Ban doc " << DanhSachBanDoc[i]->getHoTen() << " co muon muon sach " << DanhSachSach[j]->getTenSach() << " khong? (Y/N): ";
            string check;
            getline(cin, check);
            if(check=="Y" || check =="y" ){
                string tinhtrang;
                time_t ngaymuon = time(nullptr);
                cout << "Nhap tinh trang sach: ";
                getline(cin, tinhtrang);
                BangQLMuonSach *bangQLMuonSach = new BangQLMuonSach(*DanhSachBanDoc[i], *DanhSachSach[j], tinhtrang, ngaymuon);
                DanhSachBangQLMuonSach.push_back(bangQLMuonSach);
            }
        }
    }
    cout << endl << right << setw(100) << "Bang quan ly muon sach: " << endl << endl;
    cout << left << setw(40) << "Ho ten ban doc" << setw(40) << "Ten sach" << setw(20) << "Tinh trang sach" << setw(30) << "Ngay Muon" << endl;
    cout << left << setfill('-') << setw(130) << "-" << setfill(' ')<< endl;
    for(int i=0; i<DanhSachBangQLMuonSach.size(); i++){
        DanhSachBangQLMuonSach[i]->Xuat();
    }
    
// sap xep

//sap xep ten ban doc
    for(int i=0; i<DanhSachBangQLMuonSach.size()-1; i++){
        for(int j=i+1; j<DanhSachBangQLMuonSach.size(); j++){
            if(DanhSachBangQLMuonSach[i]->getHoTen() > DanhSachBangQLMuonSach[j]->getHoTen()){
                BangQLMuonSach *temp = DanhSachBangQLMuonSach[i];
                DanhSachBangQLMuonSach[i] = DanhSachBangQLMuonSach[j];
                DanhSachBangQLMuonSach[j] = temp;
            }
        }
    }
    cout << endl << right << setw(100) << "Bang quan ly muon sach sau khi sap xep theo ten ban doc: " << endl << endl;
    cout << left << setw(40) << "Ho ten ban doc" << setw(40) << "Ten sach" << setw(20) << "Tinh trang sach" << endl;
    for(int i=0; i<DanhSachBangQLMuonSach.size(); i++){
        DanhSachBangQLMuonSach[i]->Xuat();
    }
//sap xep theo thoi gian
cout << endl << endl << "Sap xep theo thoi gian:" << endl;
    for(int i=0; i<DanhSachBangQLMuonSach.size()-1; i++){
        for(int j=0; j<DanhSachBangQLMuonSach.size(); j++){
            if(DanhSachBangQLMuonSach[i]->getNgayMuon() < DanhSachBangQLMuonSach[j]->getNgayMuon()){
                BangQLMuonSach *temp = DanhSachBangQLMuonSach[i];
                DanhSachBangQLMuonSach[i] = DanhSachBangQLMuonSach[j];
                DanhSachBangQLMuonSach[j] = temp;
            }
        }
    }
    for(int i=0; i<DanhSachBangQLMuonSach.size(); i++){
        DanhSachBangQLMuonSach[i]->Xuat();
    }
// lap danh sach lop
    vector<vector<string>> DanhSachLop;
    vector<string> DanhSachMoiLop;
for(int i=0; i<DanhSachBangQLMuonSach.size(); i++){
    if(DanhSachMoiLop.size() <= 30){
        bool daCo = false;
        for(int j=0; j<DanhSachMoiLop.size(); j++){
            if(DanhSachBangQLMuonSach[i]->getHoTen() == DanhSachMoiLop[j]){
                daCo = true;
                break;
            }
        }
        if (!daCo) {
            DanhSachMoiLop.push_back(DanhSachBangQLMuonSach[i]->getHoTen());
        }
    } else {
        DanhSachLop.push_back(DanhSachMoiLop);
        DanhSachMoiLop.clear();
    }
}

    cout << endl << right << setw(100) << "Danh sach lop: " << endl << endl;
    for(int i=0; i<DanhSachLop.size(); i++){
        cout << "Lop " << i+1 << ": " << endl;
        for(int j=0; j<DanhSachLop[i].size(); j++){
            cout << DanhSachLop[i][j] << endl;
        }
    }





//tim kiem theo ten ban doc
    string tenBanDoc;
    cout << endl << "Nhap ten ban doc can tim: ";
    getline(cin, tenBanDoc);
    cout << endl << right << setw(100) << "Bang quan ly muon sach cua ban doc " << tenBanDoc << ": " << endl << endl;
    cout << left << setw(40) << "Ho ten ban doc" << setw(40) << "Ten sach" << setw(20) << "Tinh trang sach" << endl;
    for(int i=0; i<DanhSachBangQLMuonSach.size(); i++){
        if(DanhSachBangQLMuonSach[i]->getHoTen() == tenBanDoc){
            DanhSachBangQLMuonSach[i]->Xuat();
        }
    }



    return 0;
}