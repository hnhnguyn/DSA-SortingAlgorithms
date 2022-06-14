#include "SortingAlgorithms.h"

//SELECTION SORT
void selectionSort_Time(int a[], int n, double &t) {
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

void selectionSort_Compare(int a[], int n, long long &cmp) {
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

void selectionSort(int a[], int size, double &t, long long &cmp, int output, string data_file) {
	if (output == 1) {
		selectionSort_Time(a, size, t);
	}
	else if (output == 2) {
		selectionSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		selectionSort_Time(a, size, t);
		selectionSort_Compare(a, size, cmp);
	}
}

//INSERTION SORT
void insertionSort_Time(int a[], int n, double &t) {
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

void insertionSort_Compare(int a[], int n, long long &cmp) {
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

void insertionSort(int a[], int size, double &t, long long &cmp, int output, string data_file) {
	if (output == 1) {
		insertionSort_Time(a, size, t);
	}
	else if (output == 2) {
		insertionSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		insertionSort_Time(a, size, t);
		insertionSort_Compare(a, size, cmp);
	}
}


//BUBBLE SORT
void bubbleSort(int a[], int size, double &t, long long &cmp, int output, string data_file) {

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

void heapSort_Time(int A[], int n, double &t) {
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

void heapRebuild_Compare(int pos, int A[], int n, long long &cmp) {
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

void heapConstruct_Compare(int A[], int n, long long &cmp) {
	int index = (n - 1) / 2;
	while ((++cmp) && (index >= 0)) {
		heapRebuild_Compare(index, A, n, cmp);
		index = index - 1;
	}
}

void heapSort_Compare(int A[], int n, long long &cmp) {
	heapConstruct_Compare(A, n, cmp);
	int r = n - 1;
	while ((++cmp) && (r > 0)) {
		swap(A[0], A[r]);
		heapRebuild_Compare(0, A, r, cmp);
		r = r - 1;
	}
}

void heapSort(int a[], int size, double &t, long long &cmp, int output, string data_file) {
	if (output == 1) {
		heapSort_Time(a, size, t);
	}
	else if (output == 2) {
		heapSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		heapSort_Time(a, size, t);
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

void mergeSort_Time(int A[], int left, int right, double &t) {
	auto start = chrono::high_resolution_clock::now();
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort_Time(A, left, mid, t);
		mergeSort_Time(A, mid + 1, right, t);
		merge_Time(A, left, mid, right);
	}
	auto end = chrono::high_resolution_clock::now();
	t += chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

//void CountTimeMergeSort(int A[], int left, int right, double &t) {
//	auto start = chrono::high_resolution_clock::now();
//	MergeSort_Time(A, left, right);
//	auto end = chrono::high_resolution_clock::now();
//	t = chrono::duration_cast<chrono::milliseconds>(end - start).count();
//}

void merge_Compare(int A[], int left, int mid, int right, long long &cmp) {
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

void mergeSort_Compare(int A[], int left, int right, long long &cmp) {
	if ((++cmp) && (left < right)) {
		int mid = (left + right) / 2;
		mergeSort_Compare(A, left, mid, cmp);
		mergeSort_Compare(A, mid + 1, right, cmp);
		merge_Compare(A, left, mid, right, cmp);
	}
}

void mergeSort(int a[], int size, double &t, long long &cmp, int output, string data_file) {
	if (output == 1) {
		mergeSort_Time(a, 0, size, t);
	}
	else if (output == 2) {
		mergeSort_Compare(a, 0, size, cmp);
	}
	else if (output == 3) {
		mergeSort_Time(a, 0, size, t);
		mergeSort_Compare(a, 0, size, cmp);
	}
}

//QUICK SORT
void quickSort(int a[], int size, double &t, long long &cmp, int output, string data_file) {

}

//RADIX SORT
void radixSort(int a[], int size, double &t, long long &cmp, int output, string data_file) {

}

//SHAKER SORT
void shakerSort_Time(int a[], int n, double &t) {
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

void shakerSort_Compare(int a[], int n, long long &cmp) {
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

void shakerSort(int a[], int size, double &t, long long &cmp, int output, string data_file) {
	if (output == 1) {
		shakerSort_Time(a, size, t);
	}
	else if (output == 2) {
		shakerSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		shakerSort_Time(a, size, t);
		shakerSort_Compare(a, size, cmp);
	}
}

//SHELL SORT
void shellSort(int a[], int size, double &t, long long &cmp, int output, string data_file) {

}

//COUNTING SORT
void countingSort_Time(int input[], int n, double &t) {
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

void countingSort_Compare(int input[], int n, long long &cmp) {
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

void countingSort(int a[], int size, double &t, long long &cmp, int output, string data_file) {
	if (output == 1) {
		countingSort_Time(a, size, t);
	}
	else if (output == 2) {
		countingSort_Compare(a, size, cmp);
	}
	else if (output == 3) {
		countingSort_Time(a, size, t);
		countingSort_Compare(a, size, cmp);
	}
}

//FLASH SORT
void flashSort(int a[], int size, double &t, long long &cmp, int output, string data_file) {

}