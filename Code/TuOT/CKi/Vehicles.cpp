#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class vehicles{
    protected:
        int TocDoTC;
    public:
        vehicles(){}
        vehicles(int TocDoTC){
            this->TocDoTC = TocDoTC;
        }
        virtual double maxSpeed() const = 0;
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
        double maxSpeed() const {
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
            cout << "Toc do toi da: " << fixed << setprecision(2) << maxSpeed() << endl;
        }
		friend bool operator > (Ferrari a, Ferrari b){
			return a.maxSpeed() > b.maxSpeed();
		}
};

int main(){
	vector<Ferrari*> dsVehicles;
	int N; 
	cout << "Nhap so xe Ferrari: ";
	cin >> N;
	cin.ignore();
	for(int i=0; i<N; i++){
		cout << endl << "Nhap thong tin xe Ferrari thu " << i+1 << ": " << endl;
		Ferrari *ferr = new Ferrari();
		ferr->input();
		dsVehicles.push_back(ferr);
	}
	cout << endl << endl << "Danh sach ferrari: " << endl;
	for(int i=0; i<N; i++){
		dsVehicles[i]->output();
	}
	cout << endl << endl << "xe Ferrari co toc do lon nhat:" << endl;
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			if(*dsVehicles[i] > *dsVehicles[j]){
				swap(dsVehicles[i], dsVehicles[j]);
			}
		}
	}
	dsVehicles.back()->output();
}
