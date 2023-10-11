#include<iostream>

using namespace std;

int main() {
    int ways = 0;
    for (int i = 1; i < 200; i++){
        for(int j = 1; j < 100; j++){
            if((200 - i - 2*j) % 5 == 0) ways++;   
        }
    }
    cout << "There is " << ways << " ways" << endl;

    return 0;
}