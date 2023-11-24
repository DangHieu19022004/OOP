#include<iostream>
using namespace std;

class SinhVien{
    float DiemGiuaKy, DiemCuoiKy;
    public:
        void input(){
            cout<<"Nhap Diem: ";
            cin>>DiemGiuaKy;
        }
        void getDiemGiuaKy(){
            cout<<DiemGiuaKy;
        }
};

int main(){
    SinhVien sv;
    sv.input();
    sv.getDiemGiuaKy();
}