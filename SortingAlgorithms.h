#pragma once
#include<cstdlib>
#include<chrono> 
#include "DataGenerator.h"

void readFile(string file, int* a, int size);
void selectionSort(int a[], int size, double &t, long long &cmp, int output, string data_file);
void insertionSort(int a[], int size, double &t, long long &cmp, int output, string data_file);
void bubbleSort(int a[], int size, double &t, long long &cmp, int output, string data_file);
void heapSort(int a[], int size, double &t, long long &cmp, int output, string data_file);
void mergeSort(int a[], int size, double &t, long long &cmp, int output, string data_file);
void quickSort(int a[], int size, double &t, long long &cmp, int output, string data_file);
void radixSort(int a[], int size, double &t, long long &cmp, int output, string data_file);
void shakerSort(int a[], int size, double &t, long long &cmp, int output, string data_file);
void shellSort(int a[], int size, double &t, long long &cmp, int output, string data_file);
void countingSort(int a[], int size, double &t, long long &cmp, int output, string data_file);
void flashSort(int a[], int size, double &t, long long &cmp, int output, string data_file);