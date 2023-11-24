#include<bits/stdc++.h>
using namespace std;

class Matrix{
    private:
        int m, n;
        double elements[100][100];
    public:
        Matrix(){
            m=0;
            n=0;
        };
        Matrix(const Matrix& a){
            for (int i = 0; i < a.m; ++i) {
                for (int j = 0; j < a.n; ++j) {
                    elements[i][j] = a.elements[i][j];
                }
            }
        };
        void nhap();
        void xuat();
        int Cong(const Matrix& a);
        friend Matrix Nhan(const Matrix& a, int k);
};

void Matrix::nhap(){
    cout << "Nhap so hang: "; cin >> m;
    cout << "Nhap so cot: "; cin >> n;
    cout << "Nhap cac phan tu: " << endl;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++){
            cout << "Nhap phan tu thu [" << i << "][" << j << "]: ";
            cin >> elements[i][j];
        }
}

void Matrix::xuat(){
    cout << "Ma tran vua nhap la: " << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++)
            cout << elements[i][j] << " ";
        cout << endl;
    }
}

int Matrix::Cong(const Matrix& a){
    if(m != a.m || n != a.n) return 0;
    return 1;
}

Matrix Nhan(const Matrix& a, int k){
    Matrix b;
    b.m = a.m;
    b.n = a.n;
    for(int i = 0; i < a.m; i++)
        for(int j = 0; j < a.n; j++)
            b.elements[i][j] = a.elements[i][j] * k;
    return b;
}

int main(){
    Matrix a;
    a.nhap();
    // b.nhap();
    // a.xuat();
    // b.xuat();
    // cout<< a.Cong(b)<<endl;
    Matrix b = Nhan(a, 2);
    b.xuat();
    return 0;
}