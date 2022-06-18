#include "SortingAlgorithms.h"

void readFile(string file, int a[], int size) {
	ifstream in(file);
	string s;
	getline(in, s);
	for (int i = 0; i < size; i++)
		in >> a[i];
	in.close();
}

//SELECTION SORT

void selectionSort_Time(int a[], int n, double& t) {
	auto start = chrono::high_resolution_clock::now();
	int i, j, pos;
	for (i = 0; i < n - 1; ++i) {
		pos = i;
		for (j = i + 1; j < n; ++j) {
			if (a[j] < a[pos]) {
				pos = j;
			}
		}
		swap(a[i], a[pos]);
	}
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void selectionSort_Compare(int a[], int n, long long& cmp) {
	int i, j, pos;
	for (i = 0; ++cmp, i < n - 1; ++i) {
		pos = i;
		for (j = i + 1; ++cmp, j < n; ++j) {
			if ((++cmp) && (a[j] < a[pos])) {
				pos = j;
			}
		}
		swap(a[i], a[pos]);
	}
}

void selectionSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1) {
		selectionSort_Time(a, size, t);
	}
	else if (output == 2) {
		selectionSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		selectionSort_Time(a, size, t);
		readFile(data_file, a, size);
		selectionSort_Compare(a, size, cmp);
	}
}

//INSERTION SORT

void insertionSort_Time(int a[], int n, double& t) {
	auto start = chrono::high_resolution_clock::now();
	int x, i, j;
	for (i = 1; i < n; ++i) {
		x = a[i];
		j = i - 1;
		while ((j >= 0) && (a[j] > x)) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void insertionSort_Compare(int a[], int n, long long& cmp) {
	int x, i, j;
	for (i = 1; ++cmp, i < n; ++i) {
		x = a[i];
		j = i - 1;
		while ((++cmp) && (j >= 0) && (++cmp) && (a[j] > x)) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

void insertionSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1) {
		insertionSort_Time(a, size, t);
	}
	else if (output == 2) {
		insertionSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		insertionSort_Time(a, size, t);
		readFile(data_file, a, size);
		insertionSort_Compare(a, size, cmp);
	}
}

//BUBBLE SORT

void bubbleSort_Time(int a[], int n, double& t) {
	auto start = chrono::high_resolution_clock::now();
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void bubbleSort_Compare(int a[], int n, long long& cmp) {
	int i, j;
	for (i = 0; ++cmp && i < n - 1; i++)
		for (j = 0; ++cmp && j < n - i - 1; j++)
			if (++cmp && a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}

void bubbleSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1) {
		bubbleSort_Time(a, size, t);
	}
	else if (output == 2) {
		bubbleSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		bubbleSort_Time(a, size, t);
		readFile(data_file, a, size);
		bubbleSort_Compare(a, size, cmp);
	}
}

//HEAP SORT

void heapRebuild_Time(int pos, int A[], int n) {
	int k = pos;
	int v = A[k];
	bool isHeap = false;
	while ((isHeap == false) && (2 * k + 1 < n)) {
		int j = 2 * k + 1;
		if (j < n - 1) {
			if (A[j] < A[j + 1]) {
				j = j + 1;
			}
		}
		if (A[k] >= A[j]) {
			isHeap = true;
		}
		else {
			swap(A[k], A[j]);
			k = j;
		}
	}
}

void heapConstruct_Time(int A[], int n) {
	int index = (n - 1) / 2;
	while (index >= 0) {
		heapRebuild_Time(index, A, n);
		index = index - 1;
	}
}

void heapSort_Time(int A[], int n, double& t) {
	auto start = chrono::high_resolution_clock::now();
	heapConstruct_Time(A, n);
	int r = n - 1;
	while (r > 0) {
		swap(A[0], A[r]);
		heapRebuild_Time(0, A, r);
		r = r - 1;
	}
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void heapRebuild_Compare(int pos, int A[], int n, long long& cmp) {
	int k = pos;
	int v = A[k];
	bool isHeap = false;
	while ((++cmp) && (isHeap == false) && (++cmp) && (2 * k + 1 < n)) {
		int j = 2 * k + 1;
		if ((++cmp) && (j < n - 1)) {
			if ((++cmp) && (A[j] < A[j + 1])) {
				j = j + 1;
			}
		}
		if ((++cmp) && (A[k] >= A[j])) {
			isHeap = true;
		}
		else {
			swap(A[k], A[j]);
			k = j;
		}
	}
}

void heapConstruct_Compare(int A[], int n, long long& cmp) {
	int index = (n - 1) / 2;
	while ((++cmp) && (index >= 0)) {
		heapRebuild_Compare(index, A, n, cmp);
		index = index - 1;
	}
}

void heapSort_Compare(int A[], int n, long long& cmp) {
	heapConstruct_Compare(A, n, cmp);
	int r = n - 1;
	while ((++cmp) && (r > 0)) {
		swap(A[0], A[r]);
		heapRebuild_Compare(0, A, r, cmp);
		r = r - 1;
	}
}

void heapSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1) {
		heapSort_Time(a, size, t);
	}
	else if (output == 2) {
		heapSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		heapSort_Time(a, size, t);
		readFile(data_file, a, size);
		heapSort_Compare(a, size, cmp);
	}
}

//MERGE SORT

void merge_Time(int A[], int left, int mid, int right) {
	int nA = mid - left + 1;
	int nB = right - mid;
	int* L = new int[nA];
	int* R = new int[nB];
	int i, j, k;

	for (i = 0; i < nA; ++i) {
		L[i] = A[left + i];
	}

	for (j = 0; j < nB; ++j) {
		R[j] = A[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;

	while (i < nA && j < nB) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			++i;
		}
		else {
			A[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < nA) {
		A[k] = L[i];
		++i;
		++k;
	}

	while (j < nB) {
		A[k] = R[j];
		++j;
		++k;
	}
	delete[]L;
	delete[]R;
}

void mergeSort_Time(int A[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort_Time(A, left, mid);
		mergeSort_Time(A, mid + 1, right);
		merge_Time(A, left, mid, right);
	}
}

void mergeSort_Time(int A[], int left, int right, double& t) {
	auto start = chrono::high_resolution_clock::now();
	mergeSort_Time(A, left, right);
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void merge_Compare(int A[], int left, int mid, int right, long long& cmp) {
	int nA = mid - left + 1;
	int nB = right - mid;

	int* L = new int[nA];
	int* R = new int[nB];
	int i, j, k;

	for (i = 0; ++cmp, i < nA; ++i) {
		L[i] = A[left + i];
	}

	for (j = 0; ++cmp, j < nB; ++j) {
		R[j] = A[mid + 1 + j];
	}

	i = 0;
	j = 0;
	k = left;

	while ((++cmp) && (i < nA) && (++cmp) && (j < nB)) {
		if ((++cmp) && (L[i] <= R[j])) {
			A[k] = L[i];
			++i;
		}
		else {
			A[k] = R[j];
			++j;
		}
		++k;
	}

	while ((++cmp) && (i < nA)) {
		A[k] = L[i];
		++i;
		++k;
	}

	while ((++cmp) && (j < nB)) {
		A[k] = R[j];
		++j;
		++k;
	}
	delete[]L;
	delete[]R;
}

void mergeSort_Compare(int A[], int left, int right, long long& cmp) {
	if ((++cmp) && (left < right)) {
		int mid = (left + right) / 2;
		mergeSort_Compare(A, left, mid, cmp);
		mergeSort_Compare(A, mid + 1, right, cmp);
		merge_Compare(A, left, mid, right, cmp);
	}
}

void mergeSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1) {
		mergeSort_Time(a, 0, size, t);
	}
	else if (output == 2) {
		mergeSort_Compare(a, 0, size, cmp);
	}
	else if (output == 3) {
		mergeSort_Time(a, 0, size, t);
		readFile(data_file, a, size);
		mergeSort_Compare(a, 0, size, cmp);
	}
}

//QUICK SORT

int partition_Time(int* arr, int low, int high) {
	int i = low;
	int j = high;
	int pivot = arr[low];
	while (i < j) {
		while (pivot >= arr[i])
			i++;
		while (pivot < arr[j])
			j--;
		if (i < j)
			swap(arr[i], arr[j]);
	}
	swap(arr[low], arr[j]);
	return j;
}

int median_Time(int* arr, int low, int high) {
	int middle = (low + high) / 2;

	if (arr[low] > arr[middle])
		swap(arr[middle], arr[low]);
	if (arr[low] > arr[high])
		swap(arr[low], arr[high]);
	if (arr[middle] > arr[high])
		swap(arr[high], arr[middle]);

	swap(arr[middle], arr[low]);

	return partition_Time(arr, low, high);
}

void quickSort_Time(int* arr, int low, int high) {
	if (low < high) {
		int pivot = median_Time(arr, low, high);
		quickSort_Time(arr, low, pivot - 1);
		quickSort_Time(arr, pivot + 1, high);
	}
}

void quickSort_Time(int* arr, int n, double& t) {
	auto start = chrono::high_resolution_clock::now();
	quickSort_Time(arr, 0, n - 1);
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int partition_Compare(int* arr, int low, int high, long long& cmp) {
	int i = low;
	int j = high;
	int pivot = arr[low];
	while ((++cmp) && (i < j)) {
		while ((++cmp) && (pivot >= arr[i])) {
			i++;
		}
		while ((++cmp) && (pivot < arr[j])) {
			j--;
		}
		if ((++cmp) && (i < j)) {
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[low], arr[j]);
	return j;
}

int median_Compare(int* arr, int low, int high, long long& cmp) {
	int middle = (low + high) / 2;

	if ((++cmp) && (arr[low] > arr[middle])) {

		swap(arr[middle], arr[low]);
	}
	if ((++cmp) && (arr[low] > arr[high])) {
		swap(arr[low], arr[high]);
	} 
	if ((++cmp) && (arr[middle] > arr[high])) {
		swap(arr[high], arr[middle]);
	}

	swap(arr[middle], arr[low]);

	return partition_Compare(arr, low, high, cmp);

}

void quickSort_Compare(int* arr, int low, int high, long long& cmp) {
	if ((++cmp) && (low < high)) {
		int pivot = partition_Compare(arr, low, high, cmp);
		quickSort_Compare(arr, low, pivot - 1, cmp);
		quickSort_Compare(arr, pivot + 1, high, cmp);
	}
}

void quickSort_Compare(int* arr, int n, long long& cmp) {
	quickSort_Compare(arr, 0, n - 1, cmp);

}

void quickSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1) {
		quickSort_Time(a, size, t);
	}
	else if (output == 2) {
		quickSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		quickSort_Time(a, size, t);
		readFile(data_file, a, size);
		quickSort_Compare(a, size, cmp);
	}
}

//RADIX SORT

int getMax_Time(int array[], int n) {
	int max = array[0];
	for (int i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

void countSort_Time(int array[], int size, int place) {
	const int max = 10;
	int* output = new int[size];
	int count[max];

	for (int i = 0; i < max; ++i)
		count[i] = 0;

	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	for (int i = 1; i < max; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; i >= 0; i--) {
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (int i = 0; i < size; i++)
		array[i] = output[i];
}

void radixSort_Time(int array[], int size, double& t) {
	auto start = chrono::high_resolution_clock::now();
	int max = getMax_Time(array, size);
	for (int place = 1; max / place > 0; place *= 10)
		countSort_Time(array, size, place);
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int getMax_Compare(int array[], int n, long long& cmp) {
	int max = array[0];
	for (int i = 1; ++cmp && i < n; i++)
		if (++cmp && array[i] > max)
			max = array[i];
	return max;
}

void countSort_Compare(int array[], int size, int place, long long& cmp) {
	const int max = 10;
	int* output = new int[size];
	int count[max];

	memset(count, 0, sizeof(count));

	for (int i = 0; ++cmp && i < size; i++)
		count[(array[i] / place) % 10]++;

	for (int i = 1; ++cmp && i < max; i++)
		count[i] += count[i - 1];

	for (int i = size - 1; ++cmp && i >= 0; i--) {
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	for (int i = 0; ++cmp && i < size; i++)
		array[i] = output[i];
}

void radixSort_Compare(int array[], int size, long long& cmp) {
	int max = getMax_Compare(array, size, cmp);
	for (int place = 1; ++cmp && max / place > 0; place *= 10)
		countSort_Compare(array, size, place, cmp);
}

void radixSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1) {
		radixSort_Time(a, size, t);
	}
	else if (output == 2) {
		radixSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		radixSort_Time(a, size, t);
		readFile(data_file, a, size);
		radixSort_Compare(a, size, cmp);
	}
}

//SHAKER SORT

void shakerSort_Time(int a[], int n, double& t) {
	auto start = chrono::high_resolution_clock::now();
	int left, right, j, k;
	k = 0;
	left = 1;
	right = n - 1;
	do {
		for (j = right; j >= left; --j) {
			if (a[j - 1] > a[j]) {
				swap(a[j], a[j - 1]);
				k = j;
			}
		}
		left = k + 1;
		for (j = left; j <= right; ++j) {
			if (a[j - 1] > a[j]) {
				swap(a[j], a[j - 1]);
				k = j;
			}
		}
		right = k - 1;
	} while (left <= right);
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void shakerSort_Compare(int a[], int n, long long& cmp) {
	int left, right, j, k;
	k = 0;
	left = 1;
	right = n - 1;
	do {
		for (j = right; ++cmp, j >= left; --j) {
			if ((++cmp) && (a[j - 1] > a[j])) {
				swap(a[j], a[j - 1]);
				k = j;
			}
		}
		left = k + 1;
		for (j = left; ++cmp, j <= right; ++j) {
			if ((++cmp) && (a[j - 1] > a[j])) {
				swap(a[j], a[j - 1]);
				k = j;
			}
		}
		right = k - 1;
	} while ((++cmp) && (left <= right));
}

void shakerSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1) {
		shakerSort_Time(a, size, t);
	}
	else if (output == 2) {
		shakerSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		shakerSort_Time(a, size, t);
		readFile(data_file, a, size);
		shakerSort_Compare(a, size, cmp);
	}
}

//SHELL SORT

void shellSort_Time(int array[], int n, double& t) {
	auto start = chrono::high_resolution_clock::now();
	for (int interval = n / 2; interval > 0; interval /= 2)
	{
		for (int i = interval; i < n; i += 1)
		{
			int temp = array[i];
			int j;
			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
	}
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void shellSort_Compare(int array[], int n, long long& cmp) {
	for (int interval = n / 2; ++cmp && interval > 0; interval /= 2) {
		for (int i = interval; ++cmp && i < n; i += 1) {
			int temp = array[i];
			int j;
			for (j = i; ++cmp && j >= interval && ++cmp && array[j - interval] > temp; j -= interval) {
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
	}
}

void shellSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1) {
		shellSort_Time(a, size, t);
	}
	else if (output == 2) {
		shellSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		shellSort_Time(a, size, t);
		readFile(data_file, a, size);
		shellSort_Compare(a, size, cmp);
	}
}

//COUNTING SORT

void countingSort_Time(int input[], int n, double& t) {
	auto start = chrono::high_resolution_clock::now();
	int* output = new int[n];
	int max = input[0];
	int min = input[0];

	int i;
	for (i = 1; i < n; i++) {
		if (input[i] > max) {
			max = input[i];
		}
		else if (input[i] < min) {
			min = input[i];
		}
	}
	int k = max - min + 1;
	int* count_array = new int[k];
	for (i = 0; i < k; i++) {
		count_array[i] = 0;
	}
	for (i = 0; i < n; i++) {
		count_array[input[i] - min]++;
	}
	for (i = 1; i < k; i++) {
		count_array[i] += count_array[i - 1];
	}
	for (i = 0; i < n; i++) {
		output[count_array[input[i] - min] - 1] = input[i];
		count_array[input[i] - min]--;
	}
	for (i = 0; i < n; i++) {
		input[i] = output[i];
	}
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
	delete[]output;
	delete[]count_array;
}

void countingSort_Compare(int input[], int n, long long& cmp) {
	int* output = new int[n];
	int max = input[0];
	int min = input[0];

	int i;
	for (i = 1; ++cmp, i < n; i++) {
		if ((++cmp) && (input[i] > max)) {
			max = input[i];
		}
		else if ((++cmp) && (input[i] < min)) {
			min = input[i];
		}
	}
	int k = max - min + 1;
	int* count_array = new int[k];
	for (i = 0; ++cmp, i < k; i++) {
		count_array[i] = 0;
	}
	for (i = 0; ++cmp, i < n; i++) {
		count_array[input[i] - min]++;
	}
	for (i = 1; ++cmp, i < k; i++) {
		count_array[i] += count_array[i - 1];
	}
	for (i = 0; ++cmp, i < n; i++) {
		output[count_array[input[i] - min] - 1] = input[i];
		count_array[input[i] - min]--;
	}
	for (i = 0; ++cmp, i < n; i++) {
		input[i] = output[i];
	}
	delete[] output;
	delete[] count_array;
}

void countingSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1) {
		countingSort_Time(a, size, t);
	}
	else if (output == 2) {
		countingSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		countingSort_Time(a, size, t);
		readFile(data_file, a, size);
		countingSort_Compare(a, size, cmp);
	}
}

//FLASH SORT

void flashInsertionSort_Time(int* a, int s, int e) {
	for (int i = s; i < e - 1; ++i) {
		int pos = i;
		for (int j = i + 1; j < e; ++j) {
			if ((a[j] < a[pos])) {
				pos = j;
			}
		}
		swap(a[i], a[pos]);
	}
}

void flashSort_Time(int* a, int size, double& t) {
	auto start = chrono::high_resolution_clock::now();
	int m = 0.005 * size;
	int* M = new int[m];
	int* _M = new int[m];
	for (int i = 0; i < m; i++) {
		M[i] = 0;
	}

	int min = a[0], maxId = 0;
	for (int i = 0; i < size; i++) {
		if (a[i] < min)
			min = a[i];
		if (a[i] > a[maxId])
			maxId = i;
	}

	for (int i = 0; i < size; i++) {
		int k = (m - 1) * (a[i] - min) / (a[maxId] - min);
		M[k]++;
	}
	for (int i = 0; i < m - 1; i++) {
		M[i + 1] = M[i] + M[i + 1];
		_M[i] = M[i];
	}
	_M[m - 1] = M[m - 1];

	int* b = new int[size];
	for (int i = 0; i < size; i++) {
		int k = (m - 1) * (a[i] - min) / (a[maxId] - min);
		b[--M[k]] = a[i];
	}

	for (int i = 0; i < size; i++)
		a[i] = b[i];
	delete[] b;

	int cnt = 0;
	int s = 0;
	while (cnt < m - 1) {
		flashInsertionSort_Time(a, s, _M[cnt]);
		s = _M[cnt];
		cnt++;
	}
	delete[] M;
	delete[] _M;
	auto end = chrono::high_resolution_clock::now();
	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

void flashInsertionSort_Compare(int* a, int s, int e, long long& cmp) {
	for (int i = s; ++cmp && i < e - 1; ++i) {
		int pos = i;
		for (int j = i + 1; ++cmp && j < e; ++j) {
			if (++cmp && (a[j] < a[pos])) {
				pos = j;
			}
		}
		swap(a[i], a[pos]);
	}
}

void flashSort_Compare(int* a, int size, long long& cmp) {
	int m = 0.005 * size;
	int* M = new int[m];
	int* _M = new int[m];
	for (int i = 0; ++cmp && i < m; i++) {
		_M[i] = 0;
		M[i] = 0;
	}

	int min = a[0], maxId = 0;
	for (int i = 0; ++cmp && i < size; i++) {
		if (++cmp && (a[i] < min))
			min = a[i];
		if (++cmp && (a[i] > a[maxId]))
			maxId = i;
	}

	for (int i = 0; ++cmp && i < size; i++) {
		int k = (m - 1) * (a[i] - min) / (a[maxId] - min);
		M[k]++;
	}
	for (int i = 0; ++cmp && i < m - 1; i++) {
		M[i + 1] = M[i] + M[i + 1];
		_M[i] = M[i];
	}
	_M[m - 1] = M[m - 1];

	int* b = new int[size];
	for (int i = 0; ++cmp && i < size; i++) {
		int k = (m - 1) * (a[i] - min) / (a[maxId] - min);
		b[--M[k]] = a[i];
	}

	for (int i = 0; ++cmp && i < size; i++)
		a[i] = b[i];
	delete[] b;

	int cnt = 0;
	int s = 0;
	while (++cmp && (cnt < m - 1)) {
		flashInsertionSort_Compare(a, s, M[cnt], cmp);
		s = M[cnt];
		cnt++;
	}
	delete[] M;
}

void flashSort(int a[], int size, double& t, long long& cmp, int output, string data_file) {
	if (output == 1)
		flashSort_Time(a, size, t);
	else if (output == 2)
		flashSort_Compare(a, size, cmp);
	else if (output == 3) {
		flashSort_Time(a, size, t);
		readFile(data_file, a, size);
		flashSort_Compare(a, size, cmp);
	}
}