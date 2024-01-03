#include <iostream>
#include <vector>
#include<string>

using namespace std;

class Logger {
public:
    static void log(const string& message, int check) {
        if(check==0){
            cout <<"[INFO]: "<< message << endl;
        }else if(check==1){
            cout <<"[DEBUG]: "<< message << endl;
        }else if(check==2){
            cout <<"[ERROR]: "<< message << endl;
        }
    }
};

class Matrix {
private:
    int m; 
    int n; 
    double elements[100][100];

public:
    Matrix() : m(0), n(0) {}

    Matrix(const Matrix& a) : m(a.m), n(a.n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                elements[i][j] = a.elements[i][j];
            }
        }
    }

    void nhap() {
        cout << "Nhap so hang: ";
        cin >> m;
        cout << "Nhap so cot: ";
        cin >> n;

        cout << "Nhap cac phan tu cua ma tran:" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << "Nhap phan tu thu [" << i << "][" << j << "]: ";
                cin >> elements[i][j];
            }
        }
    }

    void xuat() const {
        cout << "Ma tran:" << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix& a) const {
        Matrix result(*this);
        if (m == a.m && n == a.n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    result.elements[i][j] += a.elements[i][j];
                }
            }
            Logger::log("phep cong ma tran",0);
            return result;
        }
        Logger::log("Khong the cong 2 ma tran khong cung kich thuoc",2);
        Logger::log("Vui long nhap lai ma tran",1);
        return *this;
    }

    Matrix operator-(const Matrix& a) const {
        Matrix result(*this);
        if (m == a.m && n == a.n) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    result.elements[i][j] -= a.elements[i][j];
                }
            }
            Logger::log("Phep tru ma tran",0);
            return result;
        }
        Logger::log("Khong the tru 2 ma tran khong cung kich thuoc",2);
        Logger::log("Vui long nhap lai ma tran",1);
        return *this;
    }

    Matrix operator*(const Matrix& a) const {
        Matrix result;
        if (n == a.m) {
            result.m = m;
            result.n = a.n;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < a.n; j++) {
                    result.elements[i][j] = 0;
                    for (int k = 0; k < n; k++) {
                        result.elements[i][j] += elements[i][k] * a.elements[k][j];
                    }
                }
            }
            Logger::log("Nhan ma tran",0);
            return result;
        }
        Logger::log("Khong nhan duoc 2 ma tran khac kich thuoc",2);
        Logger::log("Vui long nhap lai ma tran",1);
        return result;
    }

    Matrix operator/(const Matrix& a) const {
        Logger::log("Khong co phep chia",2);
        Logger::log("Ban co the su dung ma tran nghich dao",1);
        return *this;
    }
};

int main() {
    Matrix mt1, mt2;
    cout << "Nhap ma tran thu nhat:" << endl;
    mt1.nhap();
    cout << "Nhap ma tran thu hai:" << endl;
    mt2.nhap();

    cout << "Ma tran thu nhat:" << endl;
    mt1.xuat();
    cout << "Ma tran thu hai:" << endl;
    mt2.xuat();

    Matrix result;

    result = mt1 + mt2;
    cout << "Ket qua phep cong ma tran:" << endl;
    result.xuat();

    result = mt1 - mt2;
    cout << "Ket qua phep tru ma tran:" << endl;
    result.xuat();

    result = mt1 * mt2;
    cout << "Ket qua phep nhan ma tran:" << endl;
    result.xuat();

    result = mt1 / mt2;
    cout << "Ket qua phep chia ma tran:" << endl;
    return 0;
}
