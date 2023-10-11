#include <cstring>
#include "Commands.cpp"

int main(int argc, char** argv) {
    if(argc == 5){
        if(strcmp(argv[1], "-a") == 0){
            if(checkGivenInput(argv[3])){
                cout << "CMD1" << endl;
                cout << "-----------------\n";
                cmd1(argv[2], argv[3], argv[4]);
            }
            else if(!checkGivenInput(argv[3])) {
                cout << "CMD3" << endl;
                cout << "-----------------\n";
                cmd3(argv[2], argv[3], argv[4]);
            }
        }
        else if(strcmp(argv[1], "-c") == 0) {
            cout << "CMD4" << endl;
            cout << "-----------------\n";
            cmd4(argv[2], argv[3], argv[4]);
        }
    }
    else if(argc == 6){
        if(strcmp(argv[1], "-a") == 0) {
            cout << "CMD2" << endl;
            cout << "-----------------\n";
            cmd2(argv[2], argv[3], argv[4], argv[5]);
        }
        else if(strcmp(argv[1], "-c") == 0){
            cout << "CMD5" << endl;
            cout << "-----------------\n";
            cmd5(argv[2], argv[3], argv[4], argv[5]);
        }
    }
    else{
        cout << "Invalid command line arguments!"  << endl; exit(0);
    }
    return 0;
}