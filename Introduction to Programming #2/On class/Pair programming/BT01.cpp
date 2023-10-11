#include<iostream>
#include<conio.h>     
#include<windows.h>
using namespace std;

int main (){
    for(int i=57;; i++) {
        int mm = i / 60;
        int hh = mm / 60;
        cout << hh%60 << ":" <<  mm%60 << ":" << i%60 << '\b';
        if(kbhit()){
            cout << endl;
            auto got=getch();
            if(got==' '){
                do auto got=getch(); while(got!=' ');
                cout << hh%60 << ":" <<  mm%60 << ":" << i%60 << '\b';
            }
            system("cls");  
        }
        cout << endl;
}   
        Sleep(1000);
        return 0;
    }