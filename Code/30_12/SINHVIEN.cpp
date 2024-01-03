#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include "NGUOI.cpp"

using namespace std;

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
            cout << left << setw(40) << hoTen << setw(20) << MaSV << endl;
        }
};
