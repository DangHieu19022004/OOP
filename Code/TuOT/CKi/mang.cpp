#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

template <typename T>
class mang{
	private:
		unsigned int SoPhanTu;
		vector<T> DuLieu;
	public:
		mang(){}
		mang(unsigned int SoPhanTu, vector<T> DuLieu){
			this->SoPhanTu = SoPhanTu;
			this->DuLieu = DuLieu;
		}
		friend istream& operator>>(istream& is, mang& m){
			cout << "Nhap so phan tu cua mang: ";
			is >> m.SoPhanTu;
			m.DuLieu.resize(m.SoPhanTu);
			cout << "Nhap du lieu mang: " << endl;
			for(int i=0; i<m.SoPhanTu; i++){
				cout << "Du lieu mang thu " << i+1 << ": ";
				is >> m.DuLieu[i];
			}
			return is;
		}
		friend ostream& operator<<(ostream& os, mang& m){
			for(int i=0; i<m.DuLieu.size(); i++){
				os << m.DuLieu[i] << " ";
			}
			return os;
		}
		void sapxep(){
			sort(DuLieu.begin(), DuLieu.end());
		}
		void ptuXuatHienMax(){
			map<T,int> TongXH;
			vector<T> duLieu = DuLieu;
			for(int i=0; i<duLieu.size(); i++){
				int sl=0;
				T key = duLieu[i];
				for(int j=0; j<duLieu.size(); j++){
					if(key == duLieu[j]){
						sl++;
						duLieu.erase(duLieu.begin()+j);
						j--;
					}
				}
				TongXH[key] = sl;
			}
			int maxXH = 0;
			for(auto pair : TongXH){
				T keyy = pair.first;
				int count = pair.second;
				if(maxXH < count){
					maxXH = count;
				}
			}
			
			for(auto pair : TongXH){
				T keyy = pair.first;
				int count = pair.second;
				if(maxXH == count){
					cout << "Gia tri: " << keyy << ", so lan xuat hien: " << count << endl;
					break;
				}
			}
		}
};

int main(){
	mang<float> mf;
	mang<int> mi;
	cout << "Nhap mang so thuc: " << endl;
	cin >> mf;
	cout << "Nhap mang so nguyen: " << endl;
	cin >> mi;
	cout << "Mang so thuc: " << mf << endl;
	cout << "So lan xuat hien nhieu nhat trong mang so thuc:" << endl;
	mf.ptuXuatHienMax();
	cout << "Mang so nguyen: " << mi << endl;
	cout << "So lan xuat hien nhieu nhat trong mang so nguyen:" << endl;
	mi.ptuXuatHienMax();
	cout << "Mang so thuc sau sap xep: ";
	mf.sapxep();
	cout << mf;
	cout << endl << "Mang so nguyen sau sap xep: ";
	mi.sapxep();
	cout << mf;
}
