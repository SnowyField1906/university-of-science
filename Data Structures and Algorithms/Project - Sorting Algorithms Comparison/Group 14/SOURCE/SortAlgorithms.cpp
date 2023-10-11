#include <ctime>
#include <vector>
#include "DataGenerator.cpp"

//====== SELECTION SORT ======//

void SelectionSort(int a[], int n, long long& compare){
    for (int i = 0; ++compare && i < n - 1; i++) {
        int min_pos = i;
        for (int j = i + 1; ++compare && j < n; j++) {
            if (++compare && a[j] < a[min_pos]) {
                min_pos = j;
            }
        }
        HoanVi(a[min_pos], a[i]);
    }
}

void SelectionSort(int a[], int n){
    for (int i = 0; i < n - 1; i++) {
        int min_pos = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_pos]) {
                min_pos = j;
            }
        }
        HoanVi(a[min_pos], a[i]);
    }
}

//====== INSERTION SORT ======//

void InsertionSort(int A[], int n, long long& compare)
{
    int pos, x;
    for (int i = 1; ++compare && (i < n); i++)
    {
        x = A[i]; 
        pos = i - 1;
        while ((++compare && pos >= 0) && (++compare && A[pos] > x))
        {
            A[pos + 1] = A[pos];
            pos--;
        }
        A[pos + 1] = x;
    }
}

void InsertionSort(int A[], int n)
{
    int pos, x;
    for (int i = 1; i < n; i++)
    {
        x = A[i];
        pos = i - 1;

        while (pos >= 0 &&  A[pos] > x)
        {
            A[pos + 1] = A[pos];
            pos--;
        }

        A[pos + 1] = x;
    }
}



//====== BUBBLE SORT ======//

void BubbleSort(int A[], int n, long long& compare)
{
    for (int i = 0; (++compare && (i < n - 1)); i++)
    {
        for (int j = 0; (++compare && j < n - i - 1); j++)
        {
            if (++compare && (A[j] > A[j + 1]))
            {
                HoanVi(A[j], A[j + 1]); 
            }
        }
    }
}

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                HoanVi(A[j], A[j + 1]);
            }
        }
    }
}


//====== SHAKER SORT ======//

void ShakerSort(int a[], int n, long long & compare)
{
    int Left = 0;
    int Right = n - 1;
    int k = 0;
    while (++compare && (Left < Right))
    {
        for (int i = Left; ++compare && (i < Right); i++)
        {
            if (++compare && (a[i] > a[i + 1]))
            {
                HoanVi(a[i], a[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (int i = Right; ++compare && (i > Left); i--)
        {
            if (++compare && (a[i] < a[i - 1]))
            {
                HoanVi(a[i], a[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}

void ShakerSort(int a[], int n)
{
    int Left = 0;
    int Right = n - 1;
    int k = 0;
    while (Left < Right)
    {
        for (int i = Left; i < Right; i++)
        {
            if (a[i] > a[i + 1])
            {
                HoanVi(a[i], a[i + 1]);
                k = i;
            }
        }
        Right = k;
        for (int i = Right; i > Left; i--)
        {
            if (a[i] < a[i - 1])
            {
                HoanVi(a[i], a[i - 1]);
                k = i;
            }
        }
        Left = k;
    }
}



//====== SHELL SORT ======//

int ShellSort(int arr[], int N, long long& compare)
{
    for (int gap = N / 2; ++compare && gap > 0; gap /= 2)
    {
        for (int i = gap; ++compare && i < N; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; (++compare && (j >= gap)) && (++compare && (arr[j - gap] > temp)); j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return 0;
}

int ShellSort(int arr[], int N)
{
    for (int gap = N / 2;  gap > 0; gap /= 2)
    {
        for (int i = gap;  i < N; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return 0;
}

//====== HEAP SORT ======//

void heapify(int arr[], int n, int i, long long & compare)
{ 
    int max = i;    
    int l = i * 2 + 1; 
    int r = l + 1;   
    if ((++compare && (l < n)) && (++compare && (arr[l] > arr[max])))
    {  
        max = l;
    }

    if ((++compare && (r < n)) && (++compare && (arr[r] > arr[max])))
    { 
        max = r;
    }
    if (++compare && (max != i))
    {
        HoanVi(arr[i], arr[max]);
        heapify(arr, n, max, compare);
    }

}

void HeapSort(int arr[], int n, long long & compare) 
{
    for (int i = n / 2 - 1; ++compare && (i >= 0); i--)
    {
        heapify(arr, n, i, compare);
    }
    for (int j = n - 1; ++compare && (j > 0); j--)
    {  
        HoanVi(arr[0], arr[j]);
        heapify(arr, j, 0, compare);    
    }
}

void heapify(int arr[], int n, int i)
{
    int max = i;
    int l = i * 2 + 1;
    int r = l + 1;
    if (l < n && arr[l] > arr[max])
    {
        max = l;
    }

    if (r < n && arr[r] > arr[max])
    {
        max = r;
    }
    if (max != i)
    {
        HoanVi(arr[i], arr[max]);
        heapify(arr, n, max);
    }

}

void HeapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int j = n - 1; j > 0; j--)
    {
        HoanVi(arr[0], arr[j]);
        heapify(arr, j, 0);
    }
}


//====== MERGE SORT ======//

void Merge(int A[], int left, int mid, int right, long long& compare)
{
    int n1 = mid - left + 1; 
    int n2 = right - mid; 

    int* LeftArr = new int[n1];
    int* RightArr = new int[n2];

    for (int i = 0; ++compare && (i < n1); i++)
    {
        LeftArr[i] = A[left + i];
    }
    for (int i = 0; ++compare && (i < n2); i++)
    {
        RightArr[i] = A[mid + 1 + i];
    }

    int i = 0, j = 0, current = left;

    while ((++compare && i < n1) && (++compare && j < n2))
    {
        if (++compare && (LeftArr[i] <= RightArr[j]))
        {
            A[current++] = LeftArr[i++];
        }
        else
        {
            compare += 2;
            A[current++] = RightArr[j++];
        }
    }

    while (++compare && (i < n1))
    {
        A[current++] = LeftArr[i++];
    }

    while (++compare && (j < n2))
    {
        A[current++] = RightArr[j++];
    }

    delete[] LeftArr, RightArr;
}

void MergeSort(int A[], int left, int right, long long& compare)
{
    if (++compare && (left < right))
    {
        int mid = left + (right - left) / 2;
        MergeSort(A, left, mid, compare);
        MergeSort(A, mid + 1, right, compare);
        Merge(A, left, mid, right, compare);
    }
}


void Merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* LeftArr = new int[n1];
    int* RightArr = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        LeftArr[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        RightArr[i] = A[mid + 1 + i];
    }

    int i = 0, j = 0, current = left;

    while (i < n1 &&  j < n2)
    {
        if (LeftArr[i] <= RightArr[j])
        {
            A[current++] = LeftArr[i++];
        }
        else
        {
            A[current++] = RightArr[j++];
        }
    }

    while (i < n1)
    {
        A[current++] = LeftArr[i++];
    }

    while (j < n2)
    {
        A[current++] = RightArr[j++];
    }

    delete[] LeftArr, RightArr;
}

void MergeSort(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid + 1, right);
        Merge(A, left, mid, right);
    }
}


//====== QUICK SORT ======//

int partition(int a[], int l, int r, long long& compare){
    int pivot = a[(l+r)/2];
    int i = l;
    int j = r;
    while(++compare && i <= j){
        while(++compare && a[i] < pivot) i++;
        while(++compare && a[j] > pivot) j--;
        if(++compare && i <= j){
            HoanVi(a[i], a[j]);
            i++;
            j--;
        }
    }
    return i;
}

void QuickSort(int a[], int l, int r, long long& compare){
    int part = partition(a, l, r, compare);
    if(++compare && l < part - 1){
        QuickSort(a, l, part - 1, compare);
    }
    if(++compare && part < r){
        QuickSort(a, part, r, compare);
    }
}

int partition(int a[], int l, int r){
    int pivot = a[(l+r)/2];
    int i = l;
    int j = r;
    while(i <= j){
        while(a[i] < pivot){
            i++;
        }
        while(a[j] > pivot){
            j--;
        }
        if(i <= j){
            HoanVi(a[i], a[j]);
            i++;
            j--;
        }
    }
    return i;
}

void QuickSort(int a[], int l, int r){
    int part = partition(a, l, r);
    if(l < part - 1){
        QuickSort(a, l, part - 1);
    }
    if(part < r){
        QuickSort(a, part, r);
    }
}

int LomutoPartition(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(a[j] < pivot){
            i++;
            HoanVi(a[i], a[j]);
        }
    }
    HoanVi(a[i + 1], a[r]);
    return i + 1;
}

int Hoare(int a[], int l, int r){
    int pivot = a[l];
    int i = l - 1;
    int j = r + 1;
    while(true){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);
        if(i >= j){
            return j;
        }
        HoanVi(a[i], a[j]);
    }
}

//====== COUNTING SORT ======//

void CountingSort(int a[], int n, long long& compare){
    int max = a[0];
    for(int i = 1; ++compare && i < n; i++){
        if(++compare && a[i] > max){
            max = a[i];
        }
    }
    int *count = new int[max + 1];
    for(int i = 0; ++compare && i <= max; i++){
        count[i] = 0;
    }
    for(int i = 0; ++compare && i < n; i++){
        count[a[i]]++;
    }
    int index = 0;
    for(int i = 0; ++compare && i <= max; i++){
        for(int j = 0; ++compare && j < count[i]; j++){
            a[index] = i;
            index++;
        }
    }
}

void CountingSort(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    int *count = new int[max + 1];
    for(int i = 0; i <= max; i++){
        count[i] = 0;
    }
    for(int i = 0; i < n; i++){
        count[a[i]]++;
    }
    int index = 0;
    for(int i = 0; i <= max; i++){
        for(int j = 0; j < count[i]; j++){
            a[index] = i;
            index++;
        }
    }
}

//====== RADIX SORT ======//

void RadixSort(int a[], int n, long long& compare){
    int max = a[0];
    for(int i = 1; ++compare && i < n; i++){
        if(++compare && a[i] > max){
            max = a[i];
        }
    }
    int exp = 1;
    while(++compare && max / exp > 0){
        vector<int> buckets[10];
        for(int i = 0; ++compare && i < n; i++){
            buckets[(a[i] / exp) % 10].push_back(a[i]);
        }
        int index = 0;
        for(int i = 0; ++compare && i < 10; i++){
            for(int j = 0; ++compare && j < buckets[i].size(); j++){
                a[index] = buckets[i][j];
                index++;
            }
        }
        exp*= 10;
    }
}

void RadixSort(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    int exp = 1;
    while(max / exp > 0){
        vector<int> buckets[10];
        for(int i = 0; i < n; i++){
            buckets[(a[i] / exp) % 10].push_back(a[i]);
        }
        int index = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < buckets[i].size(); j++){
                a[index] = buckets[i][j];
                index++;
            }
        }
        exp*= 10;
    }
}

void RadixSortWithoutVector(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; i++){
        if(a[i] > max){
            max = a[i];
        }
    }
    int exp = 1;
    while(max / exp > 0){
        int count[10] = {0};
        for(int i = 0; i < n; i++){
            count[(a[i] / exp) % 10]++;
        }
        for(int i = 1; i < 10; i++){
            count[i] += count[i - 1];
        }
        int *output = new int[n];
        for(int i = n - 1; i >= 0; i--){
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }
        for(int i = 0; i < n; i++){
            a[i] = output[i];
        }
        exp*= 10;
    }
}

void RadixSortForString(string a[], int n){
    int max = a[0].length();
    int exp = max - 1;
    while(exp >= 0){
        vector<string> buckets[10];
        for(int i = 0; i < n; i++){
            buckets[a[i][exp] - '0'].push_back(a[i]);
        }
        int index = 0;
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < buckets[i].size(); j++){
                a[index] = buckets[i][j];
                index++;
            }
        }
        exp--;
    }
}
//====== FLASH SORT ======//

void FlashSort(int a[], int n, long long& compare){
    int minVal = a[0];
	int maxIdx = 0;
	int m = 0.43 * n;
	int* l = new int[m];
	for (int i = 0;++compare && i < m; i++) {
        l[i] = 0;
    }
		
	for (int i = 1;++compare && i < n; i++)
	{
		if (++compare && a[i] < minVal) {
            minVal = a[i];
        }
		if (++compare && a[i] > a[maxIdx]) {
            maxIdx = i;
        }
	}
    
	if (++compare && a[maxIdx] == minVal) {
        return;
    }

	double c1 = (double) (m - 1) / (a[maxIdx] - minVal);

	for (int i = 0;++compare && i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}

	for (int i = 1;++compare && i < m; i++) {
        l[i] += l[i - 1];
    }
		
	HoanVi(a[maxIdx], a[0]);

	int move = 0;
	int j = 0;
	int k = m - 1;
	int flash = a[0];   
	while (++compare && move < n - 1)
	{
		while (++compare && j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		while (++compare && j != l[k])
		{
			k = int(c1*(flash - minVal));
			swap(flash, a[--l[k]]);
			++move;
        }
    }
	delete[] l;
	InsertionSort(a, n, compare);
}

void FlashSort(int a[], int n){
    int minVal = a[0];
	int maxIdx = 0;
	int m = 0.43 * n;
	int* l = new int[m];
	for (int i = 0; i < m; i++) {
        l[i] = 0;
    }
	for (int i = 1; i < n; i++)
	{
		if (a[i] < minVal) {
            minVal = a[i];
        }
		if (a[i] > a[maxIdx]) {
            maxIdx = i;
        }
	}
    
	if (a[maxIdx] == minVal) {
        return;
    }

	double c1 = (double) (m - 1) / (a[maxIdx] - minVal);

	for (int i = 0; i < n; i++)
	{
		int k = int(c1 * (a[i] - minVal));
		++l[k];
	}

	for (int i = 1; i < m; i++) {
        l[i] += l[i - 1];
    }
		
	HoanVi(a[maxIdx], a[0]);

	int move = 0;
	int j = 0;
	int k = m - 1;
	int flash = a[0];   
	while (move < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1*(a[j] - minVal));
		}
		while (j != l[k])
		{
			k = int(c1*(flash - minVal));
			swap(flash, a[--l[k]]);
			++move;
		}
	}
	delete[] l;
	InsertionSort(a, n);
}

        

