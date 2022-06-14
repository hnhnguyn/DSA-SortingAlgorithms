#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

template <class T>
void HoanVi(T& a, T& b);

void GenerateRandomData(int a[], int n);

void GenerateSortedData(int a[], int n);

void GenerateReverseData(int a[], int n);

void GenerateNearlySortedData(int a[], int n);

void GenerateData(int a[], int n, int dataType);