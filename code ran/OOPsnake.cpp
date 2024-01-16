//Nghich day
///*#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <iomanip>
#include <ctime> 
#include <windows.h>
#define KEY_NONE	-1

using namespace std;


class Game {
protected:
	//sf::RenderWindow window;
    int dokho;
    int sl;
    int ToaDoX[100];
    int ToaDoY[100];
    int ChuongNgaiX[100];
	int ChuongNgaiY[100];
    int x;
    int y;
    int check;
    int xqua;
    int yqua;
    string replay;

public:
    Game() : dokho(0), sl(3), x(50), y(13), check(2), xqua(0), yqua(0) {}
	 //window.create(sf::VideoMode(800, 600), "SFML Snake Game");

    virtual void batdau() {
        SetColor(13);
		cout<<setw(180)<<"GAME RAN SAN MOI"<<endl<<endl<<endl<<endl;
		SetColor(11);
		cout<<setw(60)<<"Huong dan: Di chuyen bang 4 phim w, a, s, d. Ban se thua khi ran"<<endl;
		cout<<setw(67)<<"cham phai chuong ngai vat hoac cham tuong hoac can duoi."<< endl;
		SetColor(4);
		cout<<setw(20)<<"Luu y: Vui long tat Unikey va Caps Lock truoc khi choi game de co trai nghiem tot nhat !!!"<< endl<<endl;
		SetColor(11);
		cout<<"Co 3 muc do:"<<endl<<endl;
		SetColor(2);
		cout<<"1. De"<<endl;
		SetColor(6);
		cout<<"2. Trung binh"<<endl;
		SetColor(4);
		cout<<"3. Cao"<<endl<<endl;
		SetColor(11);
		cout<<"Chon do kho: ";
		bool nhapdung = false;
        do {
            cin >> dokho;
            if (dokho < 1 || dokho > 3) {
                cout << "Nhap sai! Vui long nhap lai" << endl;
                cin.clear(); 
            	cin.ignore();
                cout << "Chon do kho: ";
            }
            else{
            	nhapdung = true;
			}
            
        } while (!nhapdung);

        if (dokho == 1) {
            dokho = 300;
        }
        else if (dokho == 2) {
            dokho = 150;
        }
        else if (dokho == 3) {
            dokho = 100;
        }
        cout << "Ban da chon do kho: " << endl;
        if(dokho==100){
        	SetColor(5);
        	cout << "Trinh choi game chua bang thang code" << endl;
		}
		if(dokho==150){
			SetColor(3);
			cout << "Kha hon thang non" << endl;
		}
		if(dokho==300){
			SetColor(1);
			cout << "Choi ngu thi cu noi" << endl;
		}
        cout << "Tro choi se bat dau sau giay lat" << endl;
        SetColor(9);
		cout<<setw(16)<<"3\t";
		Sleep(1000);
		cout<<setw(16)<<"2\t";
		Sleep(1000);
		cout<<setw(16)<<"1\t";
		Sleep(250);
		cout<<setw(16)<<".\t";
		Sleep(250);
		cout<<setw(16)<<".\t";
		Sleep(250);
		cout<<setw(16)<<".\t";
		Sleep(250);
		SetColor(7);
        system("cls");
    }

    void gotoXY(int x, int y) {
        HANDLE hConsoleOutput;
        COORD Cursor_an_Pos = { x, y };
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
    }

    void SetColor(WORD color) {
        HANDLE hConsoleOutput;
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

        CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
        GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

        WORD wAttributes = screen_buffer_info.wAttributes;
        color &= 0x000f;
        wAttributes &= 0xfff0;
        wAttributes |= color;

        SetConsoleTextAttribute(hConsoleOutput, wAttributes);
    }

    void xoacontro() {
        CONSOLE_CURSOR_INFO Info;
        Info.bVisible = FALSE;
        Info.dwSize = 20;
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
    }

    void vesnake() {
        for (int i = 0; i < sl; i++) {
            gotoXY(ToaDoX[i], ToaDoY[i]);
            if (i == 0) {
                SetColor(4);
                cout << "S";
                SetColor(7);
            }
            else {
                cout << "s";
            }
        }
    }

    void xoadulieucu() {
        for (int i = 0; i < sl; i++) {
            gotoXY(ToaDoX[i], ToaDoY[i]);
            cout << " ";
        }
    }

    bool checkrananqua(int xqua, int yqua, int x0, int y0) {
        if (x0 == xqua && y0 == yqua) {
            return true;
        }
        return false;
    }

    bool checktrung(int xqua, int yqua) {
        for (int i = 0; i < sl; i++) {
            if (ToaDoX[i] == xqua && ToaDoY[i] == yqua) {
                return true;
            }
        }
        
        for(int i=0; i<60; i++){
			if(ChuongNgaiX[i]==xqua && ChuongNgaiY[i]==yqua){
				return true;
			}
		}
        return false;
    }

    void taoqua() {
        int i = rand() % (15 - 1 + 1) + 1;
        SetColor(i);
        do {
            xqua = rand() % (99 - 11 + 1) + 11;
            yqua = rand() % (25 - 2 + 1) + 2;
        } while (checktrung(xqua, yqua) == true);
        gotoXY(xqua, yqua);
        cout << "*";
        SetColor(7);
    }

    void them(int a[], int gt) {
        for (int i = sl; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = gt;
        sl++;
    }

    void xoa(int a[], int vt) {
        for (int i = vt; i < sl; i++) {
            a[i] = a[i + 1];
        }
        sl--;
    }

    void xulyran() {
        them(ToaDoX, x);
        them(ToaDoY, y);

        if (checkrananqua(xqua, yqua, ToaDoX[0], ToaDoY[0]) == false) {
            xoa(ToaDoX, sl - 1);
            xoa(ToaDoY, sl - 1);
        }
        else {
            taoqua();
        }
        vesnake();

    }

    void Khoitaoso_nach() {
        //int x = 50, y = 13;
        srand(time(NULL));
        
        int startX = rand() % (80 - 12 + 1) + 12;
        int startY = rand() % (23 - 3 + 1) + 3; 

        for (int i = 0; i < sl; i++) {
            ToaDoX[i] = startX;
            ToaDoY[i] = startY;
            x--;
        }
    }

    void Khung() {
	        int x = 10, y = 0;
	        SetColor(11);
	        while (y != 28) {
	            gotoXY(x, y);
	            cout << "x";
	            y++;
	            Sleep(10);
	        }
	        while (x != 100) {
	            gotoXY(x, y - 1);
	            cout << "x";
	            x++;
	            Sleep(10);
	        }
	        while (y != 0) {
	            gotoXY(x, y - 1);
	            cout << "x";
	            y--;
	            Sleep(10);
	        }
	        while (x != 10) {
	            gotoXY(x, y);
	            cout << "x";
	            x--;
	            Sleep(10);
	        }
	        SetColor(7);
	        Sleep(300);
	    }
		
	void Chuongngai(){
			int x1=20, y1=8;
		for(int i=0; i<3; i++){
			ChuongNgaiX[i]=x1;
			ChuongNgaiY[i]=y1;
			y1--;
		}
		for(int i=3; i<15; i++){
			ChuongNgaiX[i]=x1;
			ChuongNgaiY[i]=y1;
			x1++;
		}
		int x2=90, y2=8;
		for(int i=15; i<18; i++){
			ChuongNgaiX[i]=x2;
			ChuongNgaiY[i]=y2;
			y2--;		
		}
		for(int i=18; i<30; i++){
			ChuongNgaiX[i]=x2;
			ChuongNgaiY[i]=y2;
			x2--;		
		}
		int x3=20 ,y3=18;
		for(int i=30; i<33; i++){
			ChuongNgaiX[i]=x3;
			ChuongNgaiY[i]=y3;
			y3++;
		}
		for(int i=33; i<45; i++){
			ChuongNgaiX[i]=x3;
			ChuongNgaiY[i]=y3;
			x3++;
		}
		int x4=90, y4=18;
		for(int i=45; i<48; i++){
			ChuongNgaiX[i]=x4;
			ChuongNgaiY[i]=y4;
			y4++;
		}
		for(int i=48; i<60; i++){
			ChuongNgaiX[i]=x4;
			ChuongNgaiY[i]=y4;
			x4--;
		}
		//ve chuong ngai vat
		for(int i=0; i<60; i++){
			gotoXY(ChuongNgaiX[i], ChuongNgaiY[i]);
			cout << "o";
		}
	}
	
    bool checkchamtuong(int x0, int y0) {
        if (y0 == 0 || y0 == 27 || x0 == 10 || x0 == 100) {
            return true;
        }
        else return false;
    }

    bool checkrancan() {
        for (int i = 1; i < sl; i++) {
            if (ToaDoX[0] == ToaDoX[i] && ToaDoY[0] == ToaDoY[i]) {
                return true;
            }
        }
        
        for(int i=0; i<60; i++){
			if(ChuongNgaiX[i]==ToaDoX[0] && ChuongNgaiY[i]==ToaDoY[0]){
				return true;
			}
		}
        return false;
    }

    bool checkdie() {
        bool kt1 = checkchamtuong(x, y);
        bool kt2 = checkrancan();
        if (kt1 == true || kt2 == true) {
            return true;
        }
        return false;
    }
    
    void ketthuc(){
		system("cls");
		SetColor(11);
		gotoXY(40,13);
		cout<<"Cam on ban da choi game va chuc 1 doi an yen <3";
		Sleep(1000);
		gotoXY(37,14);
		cout<<"credit: Nguyen Khac Trung - Tran Dang Hieu aka Hieu nghien";
		gotoXY(20,16);
		SetColor(9);
		cout<<setw(16)<<"3\t";
		Sleep(1000);
		cout<<setw(16)<<"2\t";
		Sleep(1000);
		cout<<setw(16)<<"1\t";
		Sleep(250);
		cout<<setw(16)<<".\t";
		Sleep(250);
		cout<<setw(16)<<".\t";
		Sleep(250);
		cout<<setw(16)<<".\t";
		Sleep(250);
		SetColor(7);
		system("cls");
		gotoXY(40,13);
		cout<<"Mong cac ban khong bi thong duyt nhu hieu"<<endl<<endl<<endl<<endl<<endl<<endl;
		Sleep(1000);
	}
	

    void start() {
    do
    {
        xoacontro();
        batdau();
        
        //quay ty
        /*while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
          */  
            
        srand(time(NULL));
        bool gameover = false;
        Khung();
        Chuongngai();
        Khoitaoso_nach();
        vesnake();
        taoqua();
        
        int prevX = x;
        int prevY = y;
        
        while (!gameover) {
            xoadulieucu();
            if (_kbhit()) {
                char kytu = _getch();
                if (kytu == 'w' && check != 0) {
                    check = 1;
                }
                else if (kytu == 's' && check != 1) {
                    check = 0;
                }
                else if (kytu == 'a' && check != 2) {
                    check = 3;
                }
                else if (kytu == 'd' && check != 3) {
                    check = 2;
                }
            }
            
            prevX = x;
            prevY = y;
            
            if (check == 0) {
                y++;
            }
            else if (check == 1) {
                y--;
            }
            else if (check == 2) {
                x++;
            }
            else if (check == 3) {
                x--;
            }
            
            if(x<=10 || x>=100 || y<=0 || y>=27 || checkrancan()){
            	x = prevX;
            	y = prevY;
            	gameover = true;
			}
            
            //nghich day
            /*window.clear();
            drawSnake();
            drawFood();
            window.display();*/
            
            
            xulyran();
            gameover = checkdie();
            Sleep(dokho);
        }
        Sleep(3000);
        system("cls");

		bool over = true;
        if(over){
        	SetColor(4);
        	gotoXY(10,1);
        	cout << "Co choi duoc khong ma heo som the, NON hon ca 1 dua tre 5 tuoi";
		}
		SetColor(11);
        
        gotoXY(10,3);
        cout<<"Bam phim 1 de choi lai"<<endl;
        gotoXY(10,4);
		cout<<"Bam phim 'x' de thoat";
		gotoXY(10,5);
		cout << "Nhap lua chon cua ban: ";
		cin.ignore();
		int i=6;
		do{
			getline(cin, replay);
			if(replay=="x" || replay=="1"){
				break;
			}
			if(replay!="x" && replay !="x"){
				gotoXY(10,i);
				cout <<"Nhap sai! Vui long nhap lai: ";
				i++;
			}
		}while(replay!="1" && replay!="x");

		if(replay=="x"){
			ketthuc();
			return;
		}else{
			system("cls");
		}
	}while(replay == "1");
	
	ketthuc();

	}
        
};

class SnakeGame : public Game {
public:
    SnakeGame() : Game() {}

    void batdau() {
        Game::batdau();
    }

    void start() {
        Game::start();
    }
};

int main() {
    SnakeGame game;
    game.start();
    return 0;
}


