#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <iomanip>


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