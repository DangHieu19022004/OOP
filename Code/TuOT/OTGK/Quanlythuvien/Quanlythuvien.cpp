#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <utility>

using namespace std;

class Books{
    private:
        static int BooksIDraise;
        int BooksID;
        string BooksName;
        string Author;
        string Specialization;
        int PublishYear;
        int Quantity;
    public:
        Books(){
            this -> BooksID = BooksIDraise++;
        }
        Books(string BooksName, string Author, string Specialization, int PublishYear, int Quantity): BooksName(BooksName), Author(Author), Specialization(Specialization), PublishYear(PublishYear), Quantity(Quantity){
            this -> BooksID = BooksIDraise++;
        }
        string getBoooksName(){
            return BooksName;
        }
        void input();
        void output();
};

int Books::BooksIDraise = 10000;

void Books::input(){
    cout << endl << "Nhap ten sach: ";
    getline(cin, BooksName);
    cout << "Nhap ten tac gia: ";
    getline(cin, Author);
    cout << "Nhap chuyen nganh: ";
    getline(cin, Specialization);
    cout << "Nhap nam xuat ban: ";
    cin >> PublishYear;
    cin.ignore();
    cout << "Nhap so luong: ";
    cin >> Quantity;
    cin.ignore();
}

void Books::output(){
    cout << left << setw(15) << BooksID << setw(30) << BooksName << setw(30) << Author << setw(30) << Specialization << setw(10) << PublishYear << setw(5) << Quantity << endl;
}

class Readers{
    private:
        static int ReadersIDraise;
        int ReadersID;
        string ReadersName;
        string ReadersAddress;
        string ReadersPhonenumber;
    public:
        Readers(){
            this -> ReadersID = ReadersIDraise++;
        }
        Readers(string ReadersName, string ReadersAddress, string ReadersPhonenumber): ReadersName(ReadersName), ReadersAddress(ReadersAddress), ReadersPhonenumber(ReadersPhonenumber){
            this -> ReadersID = ReadersIDraise++;
        }
        string getReadersName(){
            return ReadersName;
        }
        void input();
        void output();
};

int Readers::ReadersIDraise = 10000;

void Readers::input(){
    cout << endl << "Nhap ten doc gia: ";
    getline(cin, ReadersName);
    cout << "Nhap dia chi: ";
    getline(cin, ReadersAddress);
    cout << "Nhap so dien thoai: ";
    getline(cin, ReadersPhonenumber);
}

void Readers::output(){
    cout << left << setw(15) << ReadersID << setw(40) << ReadersName << setw(40) << ReadersAddress << setw(15) << ReadersPhonenumber << endl;
}

class ManageBorrowBooks{
    private:
        pair<Books*, Readers*> bookReaderPair;
        string BookStatus;
    public:
        ManageBorrowBooks(){};
        ManageBorrowBooks(Books* books, Readers* readers, string BookStatus): BookStatus(BookStatus){
            bookReaderPair = make_pair(books, readers);
        };
        void output();
};

void ManageBorrowBooks::output(){
    cout << left << setw(15) << bookReaderPair.first->getBoooksName() << setw(40) << bookReaderPair.second->getReadersName() << setw(15) << BookStatus << endl;
}

int main(){
    cout << 2251061797%30 +1;
    // vector<Books*> Listbooks;
    // vector<Readers*> Listreaders;
    // vector<ManageBorrowBooks*> ListmanageBorrowBooks;
    // //1. import and print List books
    // int quantityBooks;
    // cout << "Nhap so luong sach: ";
    // cin >> quantityBooks;
    // cin.ignore();
    // for(int i=0; i<quantityBooks; i++){
    //     cout << endl << "Nhap thong tin sach thu " << i+1 << endl;
    //     Books *book = new Books();
    //     book -> input();
    //     Listbooks.push_back(book);
    // }
    // cout << endl << right << setw(50) << "Danh sach sach vua nhap: " << endl;
    // cout << left << setw(15) << "Ma sach" << setw(30) << "Ten sach" << setw(30) << "Tac gia" << setw(30) << "Chuyen nganh" << setw(10) << "Nam XB" << setw(5) << "SL" << endl;
    // cout << left << setfill('-') << setw(120) << "-" << setfill(' ') << endl;
    // for(int i=0; i<Listbooks.size(); i++){
    //     Listbooks[i] -> output();
    // }
    // //2. import and print List readers
    // int quantityReaders;
    // cout << endl << "Nhap so luong doc gia: ";
    // cin >> quantityReaders;
    // cin.ignore();
    // for(int i=0; i<quantityReaders; i++){
    //     cout << endl << "Nhap thong tin doc gia thu " << i+1 << endl;
    //     Readers *reader = new Readers();
    //     reader -> input();
    //     Listreaders.push_back(reader);
    // }
    // cout << endl << right << setw(50) << "Danh sach doc gia vua nhap: " << endl;
    // cout << left << setw(15) << "Ma doc gia" << setw(40) << "Ten doc gia" << setw(40) << "Dia chi" << setw(15) << "So dien thoai" << endl;
    // cout << left << setfill('-') << setw(110) << "-" << setfill(' ') << endl;
    // for(int i=0; i<Listreaders.size(); i++){
    //     Listreaders[i] -> output();
    // }
    // //3. create ManageBorrowBooks
    // for(int i=0; i<Listreaders.size(); i++){
    //     int countBorrowBooks = 0;
    //     int countBooks = 0;
    //     for(int j=0; j<Listbooks.size(); j++){
    //         cout << endl << "Ban co muon muon sach " << Listbooks[j]->getBoooksName() << " cho doc gia "<< Listreaders[i]->getReadersName() << " khong? (Y/N): ";
    //         string check;
    //         getline(cin, check);
    //         if(check=="Y" || check=="y"){
    //             string BookStatus = "Chua tra";
    //             ManageBorrowBooks *manageBorrowBooks = new ManageBorrowBooks(Listbooks[j], Listreaders[i], BookStatus);
    //             ListmanageBorrowBooks.push_back(manageBorrowBooks);
    //         }
    //     }
    // }
    // //4. print ManageBorrowBooks
    // cout << endl << right << setw(50) << "Danh sach muon sach vua nhap: " << endl;
    // cout << left << setw(15) << "Ten sach" << setw(40) << "Ten doc gia" << setw(15) << "Tinh trang" << endl;
    // cout << left << setfill('-') << setw(70) << "-" << setfill(' ') << endl;
    // for(int i=0; i<ListmanageBorrowBooks.size(); i++){
    //     ListmanageBorrowBooks[i] -> output();
    // }
}