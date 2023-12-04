#include<bits/stdc++.h>

using namespace std;

class Tong{
    private:
        int a;
        int b;
    public:
        void Nhap(){
            cin>>a;
            cin>>b;
        }
        int sum(){
            return a+b;
        }
};

int main(){
    Tong t;
    t.Nhap();
    cout<<t.sum();
    return 0;
}