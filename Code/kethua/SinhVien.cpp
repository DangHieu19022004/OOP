#include<iostream>
#include<string>

using namespace std;

class SinhVien {
private:
    string MaSV;
    string HoTen;
    int Tuoi;
public:
    SinhVien(string MaSV, string HoTen, int Tuoi) : MaSV(MaSV), HoTen(HoTen), Tuoi(Tuoi) {};
    void Nhap();
    void Xuat();
};

void SinhVien::Nhap() {
    cout << "Nhap ma sinh vien: ";
    cin.ignore();
    getline(cin, MaSV);
    cout << "Nhap ho ten sinh vien: ";
    getline(cin, HoTen);
    cout << "Nhap tuoi sinh vien: ";
    cin >> Tuoi;
}

void SinhVien::Xuat() {
    cout << "Ma sinh vien: " << MaSV << endl;
    cout << "Ho ten sinh vien: " << HoTen << endl;
    cout << "Tuoi sinh vien: " << Tuoi << endl;
}

class DiemTongKet : public SinhVien {
private:
    float DiemToan;
    float DiemLy;
    float DiemHoa;
public:
    DiemTongKet() : SinhVien("", "", 0), DiemToan(0), DiemLy(0), DiemHoa(0) {}
    void Nhap();
    void Xuat();
    float TinhDiemTB();
    string XepLoai();
};

void DiemTongKet::Nhap() {
    SinhVien::Nhap();
    cout << "Nhap diem toan: ";
    cin >> DiemToan;
    cout << "Nhap diem ly: ";
    cin >> DiemLy;
    cout << "Nhap diem hoa: ";
    cin >> DiemHoa;
}

void DiemTongKet::Xuat() {
    SinhVien::Xuat();
    cout << "Diem toan: " << DiemToan << endl;
    cout << "Diem ly: " << DiemLy << endl;
    cout << "Diem hoa: " << DiemHoa << endl;
}

float DiemTongKet::TinhDiemTB() {
    return (DiemToan + DiemLy + DiemHoa) / 3;
}

string DiemTongKet::XepLoai() {
    float DiemTB = TinhDiemTB();
    if (DiemTB >= 8) {
        return "Gioi";
    } else if (DiemTB >= 7) {
        return "Kha";
    } else if (DiemTB >= 5) {
        return "Trung binh";
    } else {
        return "Yeu";
    }
}

int main() {
    DiemTongKet ds[100];
    int n, i, dem=0;
    cout << "Nhap so luong sinh vien: "; 
    cin >> n;
    cin.ignore();
    cout << "Nhap thong tin sinh vien: " << endl;
    for (i = 0; i < n; i++) {
        cout << "Nhap thong tin sinh vien thu " << i + 1 << endl;
        ds[i].Nhap();
    }
    cout<<"----------------------------------";
    cout << "Thong tin sinh vien: " << endl;
    for (i = 0; i < n; i++) {
        cout << "Thong tin sinh vien thu " << i + 1 << endl;
        ds[i].Xuat();
    }
    cout << "Xep loai sinh vien: " << endl;
    for (i = 0; i < n; i++) {
        if (ds[i].XepLoai() == "Kha") {
            dem+=1;
        }
    }
    cout<<"So luong sinh vien xep loai Kha la: "<<dem<<endl;

    return 0;
}
