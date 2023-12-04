#include<iostream>
#include<cmath>

using namespace std;

class PhanSo{
	private:
		double tu, mau;
	public:
		PhanSo(double tu=0, double mau=1):tu(tu), mau(mau){};
		void rutgon();
		double gtu(){
			return tu;
		}
		double gmau(){
			return mau;
		}
		friend istream& operator>>(istream& is, PhanSo& a);
		friend ostream& operator<<(ostream& os, PhanSo a);
		friend PhanSo operator+(PhanSo a, PhanSo b);
		friend PhanSo operator-(PhanSo a, PhanSo b);
};


double UCLN(double a,double b){
	while (b != 0) {
        int temp = b;
        b = fmod(a,b);
        a = temp;
    }
    return a;
}

void PhanSo::rutgon(){
	double uc = UCLN(this->tu, this->mau);
	this->tu /= uc;
	this->mau /= uc;
}


PhanSo operator-(PhanSo a, PhanSo b){
	PhanSo subtract(a.tu*b.mau-b.tu*a.mau,a.mau*b.mau);
	return subtract;
}

PhanSo operator+(PhanSo a, PhanSo b){
	PhanSo sum(a.tu*b.mau+b.tu*a.mau,a.mau*b.mau);
	return sum;
}

istream& operator>>(istream& is, PhanSo& a){
	cout<<"Tu/Mau: ";
	is >> a.tu >> a.mau;
	return is;
}

ostream& operator<<(ostream& os, PhanSo a){
	os << a.tu <<"/"<< a.mau<<endl;
	return os;
}

int main(){
	PhanSo a, b, sum, subtract;
	cin >> a >> b;
	sum = a+b;
	sum.rutgon();
	subtract = a-b;
	subtract.rutgon();
	if(sum.gtu()==0){
		cout<<0<<endl;
	}else if(sum.gtu()==sum.gmau()){
		cout<<1<<endl;
	}else	cout<<sum<<endl;
	
	if(subtract.gtu()==0){
		cout<<0<<endl;
	}else if(subtract.gtu()==subtract.gmau()){
		cout<<1<<endl;
	}else cout<<subtract<<endl;
	return 0;
}