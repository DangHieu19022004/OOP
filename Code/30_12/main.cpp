#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <utility>
//thu vien utility de su dung pair

using namespace std;

class NGUOI {
    protected:
        char hoTen[50];
        int namSinh;
    public:
        NGUOI(){};
        NGUOI(char *hoTen, int namSinh){
            strcpy(this->hoTen, hoTen);
            this->namSinh = namSinh;
        }
        // get hoTen
        char* getHoTen(){
            return hoTen;
        }

        // set hoTen
        void setHoTen( char *newHoTen){
            strcpy(this->hoTen, newHoTen);
        }

        // get namSinh
        int getNamSinh(){
            return namSinh;
        }

        // set namSinh
        void setNamSinh(int newNamSinh){
            namSinh = newNamSinh;
        }

        // nhap thong tin
        void nhap(){
            string hoten;
            cout << endl << "Nhap ho ten: ";
            cin.ignore();
            getline(cin, hoten);
            strcpy(this->hoTen, hoten.c_str());
            //c_str() chuyen string thanh chuoi ki tu
            cout << "Nhap nam sinh: ";
            cin >> namSinh;
        }

        // xuat thong tin
        void xuat(){
            cout << left << setw(40) << hoTen << setw(20) << namSinh << endl;
        }
};

class SINHVIEN : public NGUOI {
    private:
        double MaSV;
    public:
        SINHVIEN(){};
        SINHVIEN(char *hoTen, int namSinh, double MaSV){
            strcpy(this->hoTen, hoTen);
            this->namSinh = namSinh;
            this->MaSV = MaSV;
        }
        // get MaSV
        double getMaSV(){
            return MaSV;
        }
        void Xuat(){
            cout << left << setw(40) << hoTen << setw(20) << fixed << setprecision(0) << MaSV << endl;
        }
};

void sapxep(vector<SINHVIEN*> &dsSinhVien){
    for(int i = 0; i < dsSinhVien.size() - 1; i++){
        for(int j = i + 1; j < dsSinhVien.size(); j++){
            if(dsSinhVien[i]->getMaSV() > dsSinhVien[j]->getMaSV()){
                SINHVIEN *temp = dsSinhVien[i];
                dsSinhVien[i] = dsSinhVien[j];
                dsSinhVien[j] = temp;
            }
        }
    }
}

int main(){
    vector<NGUOI*> dsNguoi;
    vector<SINHVIEN*> dsSinhVien;
    
    //Nhap thong tin nguoi
    int n;
    cout << "Nhap so luong nguoi: ";
    cin >> n;
    for(int i = 0; i < n; i++){
        cout << endl << "Nhap thong tin nguoi thu " << i + 1 << endl;
        NGUOI *nguoi = new NGUOI();
        nguoi->nhap();
        dsNguoi.push_back(nguoi);
    }

    //Xuat thong tin nguoi
    cout << endl << endl;
    cout << right << setw(40) << "Danh sach nguoi vua nhap: " << endl << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    cout << left << setw(40) << "Ho ten" << setw(20) << "Nam sinh" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    for(int i = 0; i < n; i++){
        dsNguoi[i]->xuat();
    }
    cout << endl << endl;

    //Nhap thong tin sinh vien
    for(int i=0; i < n; i++){
        cout << endl << "Nhap MSV cho sinh vien " << dsNguoi[i]->getHoTen() << ": ";
        double MaSV;
        cin >> MaSV;
        cin.ignore();
        pair<double, NGUOI*> sinhvien(MaSV, dsNguoi[i]);
        SINHVIEN *sinhVien = new SINHVIEN(sinhvien.second->getHoTen(), sinhvien.second->getNamSinh(), sinhvien.first);
        dsSinhVien.push_back(sinhVien);
    }

    //Sap xep va xuat thong tin sinh vien
    cout << endl << endl;
    sapxep(dsSinhVien);
    cout << right << setw(45) << "Danh sach sinh vien sau khi sap xep: " << endl << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    cout << left << setw(40) << "Ho ten" << setw(20) << "Ma sinh vien" << endl;
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
    for(int i = 0; i < n; i++){
        dsSinhVien[i]->Xuat();
    }
    return 0;
}