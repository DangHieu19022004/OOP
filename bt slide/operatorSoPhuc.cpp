#include<iostream>

using namespace std;

class SoPhuc{
	private:
		double thuc, ao;
	public:
		SoPhuc(double thuc=0, double ao=0):thuc(thuc), ao(ao){};
		friend istream& operator>>(istream& is, SoPhuc& sp);
		friend ostream& operator<<(ostream& os, SoPhuc& sp);
		friend SoPhuc operator+(SoPhuc a, SoPhuc b);
		friend SoPhuc operator-(SoPhuc a, SoPhuc b);
		friend SoPhuc operator*(SoPhuc a, SoPhuc b);
		friend bool operator==(SoPhuc a, SoPhuc b);
};

bool operator==(SoPhuc a, SoPhuc b){
	return (a.thuc==b.thuc && a.ao==b.ao);
}

SoPhuc operator*(SoPhuc a, SoPhuc b){
	SoPhuc c (a.thuc*b.thuc - a.ao*b.ao, a.thuc*b.ao+b.thuc*a.ao);
	return c;
}

SoPhuc operator-(SoPhuc a, SoPhuc b){
	SoPhuc c(a.thuc-b.thuc, a.ao-b.ao);
	return c;
}

SoPhuc operator+(SoPhuc a, SoPhuc b){
	SoPhuc c (a.thuc+b.thuc, a.ao+b.ao);
	return c;
}

ostream& operator<<(ostream& os, SoPhuc& sp){
	os << sp.thuc << " + "<<sp.ao<<"i"<<endl;
	return os;
}

istream& operator>>(istream& is, SoPhuc& sp){
	cout<<"Nhap sp: "<<endl;
	is >> sp.thuc;
	is >> sp.ao;
	return is;
}

int main(){
	SoPhuc a, b, d, c, multiplication;
	cin>>a;
	cin>>b;
	cout<<a;
	cout<<b;
	d = a +b;
	c = a-b;
	multiplication = a*b;
	cout<<"a+b="<<d<<endl;
	cout<<"a-b="<<c<<endl;
	cout<<"a*b="<<multiplication<<endl;
	if(a==b){
		cout<<"bang"<<endl;
	}
	else cout<<"not"<<endl;
	return 0;
}