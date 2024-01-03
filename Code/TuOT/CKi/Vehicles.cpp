#include <iostream>
#include <string>
#include <vector>

using namespace std;

class vehicles{
    protected:
        int TocDoTC;
    public:
        vehicles(){}
        vehicles(int TocDoTC){
            this->TocDoTC = TocDoTC;
        }
        virtual int maxSpeed() const = 0;
};

class Ferrari : public vehicles{
    private:
        string MauSac;
        double hesoTocDo;
    public:
        Ferrari(){};
        Ferrari(int TocDoTC, string MauSac, double hesoTocDo) : vehicles(TocDoTC){
            this->MauSac = MauSac;
            this->hesoTocDo = hesoTocDo;
        };
        int maxSpeed() const{
            return TocDoTC * hesoTocDo;
        }
        void input(){
            cout << "Nhap mau sac: ";
            getline(cin, MauSac);
            cout << "Nhap he so toc do: ";                  
            cin >> hesoTocDo;
            cin.ignore();
        }
        void output(){
            cout << "Mau sac: " << MauSac << endl;
            cout << "Toc do toi da: " << maxSpeed() << endl;
        }
        bool operator > (Ferrari &a){
            return this->maxSpeed() > a.maxSpeed();
        }
};

int main(){
    vector<Ferrari*> a;
    int tocdotc;
    cout << "Nhap toc do tieu chuan: ";
    cin >> tocdotc;
    cin.ignore();
    int n;
    cout << "Nhap so luong xe ferrari: ";
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin xe thu " << i + 1 << endl;
        Ferrari *x = new Ferrari(tocdotc, "", 0);
        x->input();
        a.push_back(x);
    }
    Ferrari *max = a[0];
    for(int i = 0; i < n; i++){
        if(*a[i] > *max){
            max = a[i];
        }
    }
    cout << "Xe co toc do lon nhat la: " << endl;
    max->output();
}