#include <fstream>
#include <string>
#include "SortAlgorithms.cpp"

void generateAlgorithms(int a[], int n, int& time_use, long long& compare, string algorithmName, string outputPara){
    clock_t startTime, endTime; 
	if(algorithmName == "bubble-sort"){
        if(outputPara == "-time"){
            startTime = clock();
            BubbleSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "Runtime: " << time_use << "ms" << endl;
        }
        else if(outputPara == "-compare"){
            BubbleSort(a, n, compare);
            cout << "Compare: " << compare << endl;
        }
        else if(outputPara == "-both"){
            int* b = new int[n];
            copy(a, a+n, b);
            startTime = clock();
            BubbleSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            BubbleSort(b, n, compare);
            delete[] b;
            cout << "Runtime: " << time_use << "ms" << endl;
            cout << "Compare: " << compare << endl;
        }
        else {
            cout << "Invalid command line arguments!"  << endl; exit(0);
        }
	}
	else if(algorithmName == "counting-sort"){
        if(outputPara == "-time"){
            startTime = clock();
            CountingSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "Runtime: " << time_use << "ms" << endl;
        }
        else if(outputPara == "-comp"){
            CountingSort(a, n, compare);
            cout << "Compare: " << compare << endl;
        }
        else if(outputPara == "-both"){
            int* b = new int[n];
            copy(a, a+n, b);
            startTime = clock();
            CountingSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            CountingSort(b, n, compare);
            delete[] b;
            cout << "Runtime: " << time_use << "ms" << endl;
            cout << "Compare: " << compare << endl;
        }
        else {
            cout << "Invalid command line arguments!"  << endl; exit(0);
        }
	}
	else if(algorithmName == "flash-sort"){
        if(outputPara == "-time"){
            startTime = clock();
            FlashSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "Runtime: " << time_use << "ms" << endl;
        }
        else if(outputPara == "-comp"){
            FlashSort(a, n, compare);
            cout << "Compare: " << compare << endl;
        }
        else if(outputPara == "-both"){
            int* b = new int[n];
            copy(a, a+n, b);
            startTime = clock();
            FlashSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            FlashSort(b, n, compare);
            delete[] b;
            cout << "Runtime: " << time_use << "ms" << endl;
            cout << "Compare: " << compare << endl;
        }
        else {
            cout << "Invalid command line arguments!"  << endl; exit(0);
        }
	}
	else if(algorithmName == "heap-sort"){
        if(outputPara == "-time"){
            startTime = clock();
            HeapSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "Runtime: " << time_use << "ms" << endl;
        }
        else if(outputPara == "-comp"){
            HeapSort(a, n, compare);
            cout << "Compare: " << compare << endl;
        }
        else if(outputPara == "-both"){
            int* b = new int[n];
            copy(a, a+n, b);
            startTime = clock();
            HeapSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            HeapSort(b, n, compare);
            delete[] b;
            cout << "Runtime: " << time_use << "ms" << endl;
            cout << "Compare: " << compare << endl;
        }
        else {
            cout << "Invalid command line arguments!"  << endl; exit(0);
        }
	}
	else if(algorithmName == "insertion-sort"){
        if(outputPara == "-time"){
            startTime = clock();
            InsertionSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "Runtime: " << time_use << "ms" << endl;
        }
        else if(outputPara == "-comp"){
            InsertionSort(a, n, compare);
            cout << "Compare: " << compare << endl;
        }
        else if(outputPara == "-both"){
            int* b = new int[n];
            copy(a, a+n, b);
            startTime = clock();
            InsertionSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            InsertionSort(b, n, compare);
            delete[] b;
            cout << "Runtime: " << time_use << "ms" << endl;
            cout << "Compare: " << compare << endl;
        }
        else {
            cout << "Invalid command line arguments!"  << endl; exit(0);
        }
	}
	else if(algorithmName == "merge-sort"){
		if(outputPara == "-time"){
            startTime = clock();
            MergeSort(a,0, n - 1);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "Runtime: " << time_use << "ms" << endl;
        }
        else if(outputPara == "-comp"){
            MergeSort(a, 0, n-1, compare);
            cout << "Compare: " << compare << endl;
        }
        else if(outputPara == "-both"){
            int* b = new int[n];
            copy(a, a+n, b);
            startTime = clock();
            MergeSort(a, 0, n - 1);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            MergeSort(b, 0, n-1, compare);
            delete[] b;
            cout << "Runtime: " << time_use << "ms" << endl;
            cout << "Compare: " << compare << endl;
        }
        else {
            cout << "Invalid command line arguments!"  << endl; exit(0);
        }
	}
	else if(algorithmName == "quick-sort"){
		if(outputPara == "-time"){
            startTime = clock();
            QuickSort(a, 0, n - 1);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "Runtime: " << time_use << "ms" << endl;
        }
        else if(outputPara == "-comp"){
            QuickSort(a, 0, n-1, compare);
            cout << "Compare: " << compare << endl;
        }
        else if(outputPara == "-both"){
            int* b = new int[n];
            copy(a, a+n, b);
            startTime = clock();
            QuickSort(a, 0, n - 1);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            QuickSort(b, 0, n-1, compare);
            delete[] b;
            cout << "Runtime: " << time_use << "ms" << endl;
            cout << "Compare: " << compare << endl;
        }
        else {
            cout << "Invalid command line arguments!"  << endl; exit(0);
        }
	}
	else if(algorithmName == "radix-sort"){
		if(outputPara == "-time"){
            startTime = clock();
            RadixSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "Runtime: " << time_use << "ms" << endl;
        }
        else if(outputPara == "-comp"){
            RadixSort(a, n, compare);
            cout << "Compare: " << compare << endl;
        }
        else if(outputPara == "-both"){
            int* b = new int[n];
            copy(a, a+n, b);
            startTime = clock();
            RadixSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            RadixSort(b, n, compare);
            delete[] b;
            cout << "Runtime: " << time_use << "ms" << endl;
            cout << "Compare: " << compare << endl;
        }
        else {
            cout << "Invalid command line arguments!"  << endl; exit(0);
        }
	}
	else if(algorithmName == "selection-sort"){
		if(outputPara == "-time"){
            startTime = clock();
            SelectionSort(a, n);
            endTime = clock();
            time_use =(double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "Runtime: " << time_use << "ms" << endl;
        }
        else if(outputPara == "-comp"){
            SelectionSort(a, n, compare);
            cout << "Compare: " << compare << endl;
        }
        else if(outputPara == "-both"){
            int* b = new int[n];
            copy(a, a+n, b);
            startTime = clock();
            SelectionSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            SelectionSort(b, n, compare);
            delete[] b;
            cout << "Runtime: " << time_use << "ms" << endl;
            cout << "Compare: " << compare << endl;
        }
        else {
            cout << "Invalid command line arguments!"  << endl; exit(0);
        }
	}
	else if(algorithmName == "shaker-sort"){
		if(outputPara == "-time"){
            startTime = clock();
            ShakerSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "Runtime: " << time << "ms" << endl;
        }
        else if(outputPara == "-comp"){
            ShakerSort(a, n, compare);
            cout << "Compare: " << compare << endl;
        }
        else if(outputPara == "-both"){
            int* b = new int[n];
            copy(a, a+n, b);
            startTime = clock();
            ShakerSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            ShakerSort(b, n, compare);
            delete[] b;
            cout << "Runtime: " << time << "ms" << endl;
            cout << "Compare: " << compare << endl;
        }
        else {
            cout << "Invalid command line arguments!"  << endl;
            exit(0);
        }
	}
	else if(algorithmName == "shell-sort"){
		if(outputPara == "-time"){
            startTime = clock();
            ShellSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            cout << "Runtime: " << time << "ms" << endl;
        }
        else if(outputPara == "-comp"){
            ShellSort(a, n, compare);
            cout << "Compare: " << compare << endl;
        }
        else if(outputPara == "-both"){
            int* b = new int[n];
            copy(a, a+n, b);
            startTime = clock();
            ShellSort(a, n);
            endTime = clock();
            time_use = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
            ShellSort(b, n, compare);
            delete[] b;
            cout << "Runtime: " << time << "ms" << endl;
            cout << "Compare: " << compare << endl;
        }
        else {
            cout << "Invalid command line arguments!"  << endl; exit(0);
        }
	}
    else{
        cout << "Invalid command line arguments!"  << endl; exit(0);
    }
}


void cmd1(string algorithmName, string fileName, string outputPara){
    //Read file
    ifstream readFile("./Files/"+fileName);
    if(!readFile.is_open()){
        cout << "Error: file not found!\n" << endl;
        return;
    }
    int n;
    readFile >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        readFile >> a[i];
    }
    int time = 0;
    long long compare = 0;
    
    generateAlgorithms(a, n, time, compare, algorithmName, outputPara);

    //Write file
    ofstream writeFile("./Files/output.txt");
    if(!writeFile.is_open()){
        cout << "Error: file not found!\n" << endl;
        return;
    }
    writeFile << n << endl;
    for(int i = 0; i < n; i++){
        writeFile << a[i] << " ";
    }
    readFile.close();
    writeFile.close();

    delete[] a;
}

void cmd2(string algorithmName, string inputSize, string inputOrder, string outputPara){
    int n = stoi(inputSize);
    int *a = new int[n];
    generateDataWithInputOrder(a, n, inputOrder);

    //Write Input
    ofstream writeInput("./Files/input.txt");
    if(!writeInput.is_open()){
        cout << "Error: file not found!\n" << endl;
        return;
    }
    writeInput << n << endl;
    for(int i = 0; i < n; i++){
        writeInput << a[i] << " ";
    }
    writeInput.close();
    
    int time = 0;
    long long compare = 0;
    //Sort
    generateAlgorithms(a, n, time, compare, algorithmName, outputPara);

    //Write file
    ofstream writeOuput("./Files/output.txt");
    if(!writeOuput.is_open()){
        cout << "Error: file not found!\n" << endl;
        return;
    }
    writeOuput << n << endl;
    for(int i = 0; i < n; i++){
        writeOuput << a[i] << " ";
    }
    writeOuput.close();
    delete[] a;
}

void cmd3(string algorithmName, string inputSize, string outputPara){
    for(int i = 0; i < 4; i++){
        int n = stoi(inputSize);
        int *a = new int[n];
        generateDataWithAll(a, n, i);

        int time = 0;
        long long compare = 0;
        
        generateAlgorithms(a, n, time, compare, algorithmName, outputPara);
        cout << "----------------------\n";
        delete[] a;
    }
}

void generateAlgorithms(int a[], int n, int& time, long long& compare, string algorithms){
    int* b = new int[n];
    copy(a, a+n, b);
    clock_t startTime, endTime;
    if(algorithms == "bubble-sort"){
        startTime = clock();
        BubbleSort(a, n);
        endTime = clock();
        time = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
        BubbleSort(b, n, compare);
    }
    else if(algorithms == "insertion-sort"){
        startTime = clock();
        InsertionSort(a, n);
        endTime = clock();
        time = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
        InsertionSort(b, n, compare);
    }
    else if(algorithms == "selection-sort"){
        startTime = clock();
        SelectionSort(a, n);
        endTime = clock();
        time = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
        SelectionSort(b, n, compare);
    }
    else if(algorithms == "shaker-sort"){
        startTime = clock();
        ShakerSort(a, n);
        endTime = clock();
        time = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
        ShakerSort(b, n, compare);
    }
    else if(algorithms == "shell-sort"){
        startTime = clock();
        ShellSort(a, n);
        endTime = clock();
        time = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
        ShellSort(b, n, compare);
    }
    else if(algorithms == "merge-sort"){
        startTime = clock();
        MergeSort(a, 0, n-1);
        endTime = clock();
        time = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
        MergeSort(b, 0, n-1, compare);
    }
    else if(algorithms == "quick-sort"){
        startTime = clock();
        QuickSort(a, 0, n-1);
        endTime = clock();
        time = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
        QuickSort(b, 0, n-1, compare);
    }
    else if(algorithms == "heap-sort"){
        startTime = clock();
        HeapSort(a, n);
        endTime = clock();
        time = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
        HeapSort(b, n, compare);
    }
    else if(algorithms == "radix-sort"){
        startTime = clock();
        RadixSort(a, n);
        endTime = clock();
        time = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
        RadixSort(b, n, compare);
    }
    else if(algorithms == "counting-sort"){
        startTime = clock();
        CountingSort(a, n);
        endTime = clock();
        time = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
        CountingSort(b, n, compare);
    }
    else if(algorithms == "flash-sort"){
        startTime = clock();
        FlashSort(a, n);
        endTime = clock();
        time = (double)(endTime - startTime)/CLOCKS_PER_SEC*1000;
        FlashSort(b, n, compare);
    }
    else {
        cout << "Invalid command line arguments!"; exit(0);
    }
    delete[] b;
}
void cmd4(string algorithmName1, string algorithmName2, string fileName){
    cout << algorithmName1 << " | " << algorithmName2 << endl;
    ifstream readFile("./Files/"+fileName);
    int n;
    readFile >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++){
        readFile >> a[i];
    }
    int *b = new int[n];
    copy(a,a+n,b);
    int time1 = 0, time2 = 0;   
    long long compare1 = 0, compare2 = 0;
    generateAlgorithms(a, n, time1, compare1, algorithmName1);
    generateAlgorithms(a, n, time2, compare2, algorithmName2);
    cout << "Running time: " << time1 << "ms "<< " | " << time2 << "ms " << endl;
    cout << "Comparisons: " << compare1 << " | " << compare2 << endl;
    delete[] b;
    delete[] a;
}

void cmd5(string algorithmName1, string algorithmName2, string inputSize, string inputOrder){
    int n = stoi(inputSize);
    int *a = new int[n];
    int *b = new int[n];
    generateDataWithInputOrder(a, n, inputOrder);
    copy(a,a+n,b);

    //Write Input
    ofstream writeInput("./Files/input.txt");
    if(!writeInput.is_open()){
        cout << "Error: file not found!\n" << endl;
        return;
    }
    writeInput << n << endl;
    for(int i = 0; i < n; i++){
        writeInput << a[i] << " ";
    }
    writeInput.close();

    cout << algorithmName1 << " | " << algorithmName2 << endl;
    int time1 = 0, time2 = 0;
    long long compare1 = 0, compare2 = 0;
    generateAlgorithms(a, n, time1, compare1, algorithmName1);
    generateAlgorithms(b, n, time2, compare2, algorithmName2);
    cout << "Running time: " << time1 << "ms "<< " | " << time2 << "ms " << endl;
    cout << "Comparisons: " << compare1 << " | " << compare2 << endl;
    delete[] b;
    delete[] a;
}
