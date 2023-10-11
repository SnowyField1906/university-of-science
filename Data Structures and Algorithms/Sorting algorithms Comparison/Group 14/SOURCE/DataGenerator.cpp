#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

template <class T>
void HoanVi(T &a, T &b) {
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n) {
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++) {
		a[i] = rand()%n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++) {
		int r1 = rand()%n;
		int r2 = rand()%n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType) {
	switch (dataType) {
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

	
bool checkGivenInput(string s){
	return s.find(".txt") != -1;
}

void generateDataWithInputOrder(int a[], int n, string nameData){
	if(nameData == "-rand"){
		GenerateRandomData(a, n);
	}
	else if(nameData == "-nsorted"){
		GenerateNearlySortedData(a, n);
	}
	else if(nameData == "-sorted"){
		GenerateSortedData(a, n);
	}
	else if(nameData == "-rev"){
		GenerateReverseData(a, n);
	}
	else {
		cout << "Error: unknown data type!\n" << endl;
	}
}

void generateDataWithAll(int a[], int n, int i){
	if(i==0){
		cout << "Input order: Randomize" << endl;
		GenerateRandomData(a, n);
	}
	else if(i==1){
		cout << "Input order: Nearly Sorted " << endl;
		GenerateNearlySortedData(a, n);
	}
	else if(i==2){
		cout << "Input order: Sorted" << endl;
		GenerateSortedData(a, n);
	}
	else if(i==3){
		cout << "Input order: Reverse" << endl;
		GenerateReverseData(a, n);
	}

	//Write Input
    ofstream writeData("./Files/input_"+to_string(i+1)+".txt");
    if(!writeData.is_open()){
        cout << "Error: fila not found!\n" << endl;
        return;
    }
    writeData << n << endl;
    for(int i = 0; i < n; i++){
        writeData << a[i] << " ";
    }
    writeData.close();
}

