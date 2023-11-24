#include<bits/stdc++.h>

using namespace std;

class So{
    private:
        double a;
        double b;
    public:
        So(double a, double b){
            this->a = a;
            this->b = b;
        }
        friend void Nhan();
        friend void Chia();
};

void Nhan(){
    cout<<"Tích 2 số: "<< a*b<<endl;
}

void Chia(){
    if(b==0){
        cout<<"Không thể chia cho 0"<<endl;
    }
    else{
        cout<<"Thương 2 số: "<< a/b<<endl;
    }
}

int main(){
    So a(2.3,3.4);
    Nhan();
    Chia();
    return 0;
}