#include<bits/stdc++.h>

using namespace std;

struct NhanVien{
	string MaNV;
	string HoTen;
	float Can;
	int Tuoi;
	int Luong;
}nv;

void SortNV(NhanVien nv[]){
	for ( int i = 0; i < 5; i++){
		for (int j = i+1; j < 4; j++){
			if (nv[i].Tuoi > nv[j].Tuoi){
				NhanVien temp = nv[i];
				nv[i] = nv[j];
				nv[j] = temp;
			}
		}
	}
}

void print(NhanVien nv[]){
	for (int i = 0; i < 5; i++){
		cout << "Ma NV: "<< nv[i].MaNV << endl <<"Ho Ten: "<< nv[i].HoTen << endl <<"Can: "<< nv[i].Can << endl;
		cout <<"Tuoi: "<< nv[i].Tuoi << endl <<"Luong: "<< nv[i].Luong << endl;
	}
}

void FindMaxMinCanNang(NhanVien nv[]){
	float max = nv[0].Can;
	int vtmax = 0;
	int vtmin = 0;
	float min = nv[0].Can;
	for (int i = 1; i < 5; i++){
		if (nv[i].Can > max){
			max = nv[i].Can;
			vtmax = i;
		}
		if (nv[i].Can < min){
			min = nv[i].Can;
			vtmin = i;
		}
	}
	cout<<"Nhan vien co can nang lon nhat la: ";
	cout<< nv[vtmax].MaNV << endl << nv[vtmax].HoTen << endl << nv[vtmax].Can << endl << nv[vtmax].Tuoi << endl << nv[vtmax].Luong << endl;
	cout<<"Nhan vien co can nang nho nhat la: ";
	cout<< nv[vtmin].MaNV << endl << nv[vtmin].HoTen << endl << nv[vtmin].Can << endl << nv[vtmin].Tuoi << endl << nv[vtmin].Luong << endl;
}

int main(){
	NhanVien nv[100];
	float Can[100]; 
	int j=0, k=0;
	float Tuoi[100];	
	for(int i=0; i<5; i++){
		cout << "Ma NV: "; cin >> nv[i].MaNV;
		cout << "Ho Ten: "; 
		cin.ignore(); 
		getline(cin,nv[i].HoTen);
		cout << "Can: "; cin >> nv[i].Can;
		cout << "Tuoi: "; cin >> nv[i].Tuoi;
		cout << "Luong: "; cin >> nv[i].Luong;
		Can[j]=nv[i].Can; j++;
		Tuoi[k]=nv[i].Tuoi; k++;
	}
	SortNV(nv);
	print(nv);
	FindMaxMinCanNang(nv);
}
