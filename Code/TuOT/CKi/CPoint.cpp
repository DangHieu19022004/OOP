#include <bits/stdc++.h>

using namespace std;

class CPoint{
	private:
		double x, y;
	public:
		CPoint(){}
		CPoint(double x, double y){
			this->x = x;
			this->y = y;
		}
		void Nhap(){
			cout << "Nhap toa do x: ";
			cin >> x;
			cout << "Nhap toa do y: ";
			cin >> y;
			cin.ignore();
		}
		void Xuat(){
			cout << "Toa do vua nhap: " << "(" << x << "," << y << ")" << endl;
		}
		void Dichuyen(){
			x=x+1;
		}
		friend double KhoangCach(CPoint a, CPoint b){
			return sqrt(pow((a.x - b.x),2) + pow((a.y - b.y),2));
		}
		friend bool ThangHang(double a, double b, double c);
};

bool ThangHang(double a, double b, double c){
	if(a+b==c || a+c==b || b+c==a){
		return true;
	}else{
		return false;
	}
}

int main(){
	CPoint P1(2, 3);
	CPoint *P2 = new CPoint();
	P2->Nhap();
	double a1 = KhoangCach(P1, *P2);
	cout << "Khoang cach P1 P2: " << a1;
	P2->Dichuyen();
	P2->Xuat();
	CPoint P3(0, 1);
	double a = KhoangCach(*P2, P3);
	double b = KhoangCach(P1, P3);
	double c = KhoangCach(P1, *P2);
	if(ThangHang(a, b, c) == true){
		cout << "Thang hang" << endl;
	}else{
		cout << "Khong thang hang" << endl;
	}
}
