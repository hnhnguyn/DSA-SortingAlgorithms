#pragma once
#include<cstdlib>
#include<chrono> 
#include "DataGenerator.h"

void readFile(string file, int a[], int size);

//SELECTION SORT

void selectionSort_Time(int a[], int n, double& t);
void selectionSort_Compare(int a[], int n, long long& cmp);
void selectionSort(int a[], int size, double& t, long long& cmp, int output, string data_file);

//INSERTION SORT

void insertionSort_Time(int a[], int n, double& t);
void insertionSort_Compare(int a[], int n, long long& cmp);
void insertionSort(int a[], int size, double& t, long long& cmp, int output, string data_file);

//BUBBLE SORT

void bubbleSort_Time(int a[], int n, double& t);
void bubbleSort_Compare(int a[], int n, long long& cmp);
void bubbleSort(int a[], int size, double& t, long long& cmp, int output, string data_file);

//HEAP SORT

void heapRebuild_Time(int pos, int A[], int n);
void heapConstruct_Time(int A[], int n);
void heapSort_Time(int A[], int n, double& t);
void heapRebuild_Compare(int pos, int A[], int n, long long& cmp);
void heapConstruct_Compare(int A[], int n, long long& cmp);
void heapSort_Compare(int A[], int n, long long& cmp);
void heapSort(int a[], int size, double& t, long long& cmp, int output, string data_file);

//MERGE SORT

void merge_Time(int A[], int left, int mid, int right);
void mergeSort_Time(int A[], int left, int right);
void mergeSort_Time(int A[], int left, int right, double& t);
void merge_Compare(int A[], int left, int mid, int right, long long& cmp);
void mergeSort_Compare(int A[], int left, int right, long long& cmp);
void mergeSort(int a[], int size, double& t, long long& cmp, int output, string data_file);

//QUICK SORT

int partition_Time(int* arr, int low, int high);
int median_Time(int* arr, int low, int high);
void quickSort_Time(int* arr, int low, int high);
void quickSort_Time(int* arr, int n, double& t);
int partition_Compare(int* arr, int low, int high, long long& cmp);
int median_Compare(int* arr, int low, int high, long long& cmp);
void quickSort_Compare(int* arr, int low, int high, long long& cmp);
void quickSort_Compare(int* arr, int n, long long& cmp);
void quickSort(int a[], int size, double& t, long long& cmp, int output, string data_file);

//RADIX SORT

int getMax_Time(int array[], int n);
void countSort_Time(int array[], int size, int place);
void radixSort_Time(int array[], int size, double& t);
int getMax_Compare(int array[], int n, long long& cmp);
void countSort_Compare(int array[], int size, int place, long long& cmp);
void radixSort_Compare(int array[], int size, long long& cmp);
void radixSort(int a[], int size, double& t, long long& cmp, int output, string data_file);

//SHAKER SORT

void shakerSort_Time(int a[], int n, double& t);
void shakerSort_Compare(int a[], int n, long long& cmp);
void shakerSort(int a[], int size, double& t, long long& cmp, int output, string data_file);

//SHELL SORT

void shellSort_Time(int array[], int n, double& t);
void shellSort_Compare(int array[], int n, long long& cmp);
void shellSort(int a[], int size, double& t, long long& cmp, int output, string data_file);

//COUNTING SORT

void countingSort_Time(int input[], int n, double& t);
void countingSort_Compare(int input[], int n, long long& cmp);
void countingSort(int a[], int size, double& t, long long& cmp, int output, string data_file);

//FLASH SORT

void flashSort(int a[], int size, double& t, long long& cmp, int output, string data_file);