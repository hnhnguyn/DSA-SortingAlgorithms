#include "SortingAlgorithms.h"
#include "DataGenerator.h"
using namespace std;

int checkAlgoValid(string algo) {
	if (algo == "selection-sort")
		return 1;
	if (algo == "insertion-sort")
		return 2;
	if (algo == "bubble-sort")
		return 3;
	if (algo == "heap-sort")
		return 4;
	if (algo == "merge-sort")
		return 5;
	if (algo == "quick-sort")
		return 6;
	if (algo == "radix-sort")
		return 7;
	if (algo == "shaker-sort")
		return 8;
	if (algo == "shell-sort")
		return 9;
	if (algo == "counting-sort")
		return 10;
	if (algo == "flash-sort")
		return 11;
	return 0;
}

string algorithm(int algo) {
	switch (algo) {
	case 1: return "Selection Sort";
	case 2: return "Insertion Sort";
	case 3: return "Bubble Sort";
	case 4: return "Heap Sort"; 
	case 5: return "Merge Sort";
	case 6: return "Quick Sort";
	case 7: return "Radix Sort";
	case 8: return "Shaker Sort";
	case 9: return "Shell Sort";
	case 10: return "Counting Sort";
	default: return "Flash Sort";
	}
}

string inputOrder(int ord) {
	switch (ord) {
	case 1: return "Randomized";
	case 2: return "Nearly Sorted";
	case 3: return "Sorted";
	default: return "Reverse Sorted";
	}
}

int checkOrderValid(string order) {
	if (order == "-rand")
		return 1;
	if (order == "-nsorted")
		return 2;
	if (order == "-sorted")
		return 3;
	if (order == "-rev")
		return 4;
	return 0;
}

int checkOutputValid(string output) {
	if (output == "-time")
		return 1;
	if (output == "-comp")
		return 2;
	if (output == "-both")
		return 3;
	return 0;
}

void algoGen(int algo, int* a, int size, double &t, long long &cmp, int output, string data_file) {
	switch (algo) {
	case 1: selectionSort(a, size, t, cmp, output, data_file); break;
	case 2: insertionSort(a, size, t, cmp, output, data_file); break;
	case 3: bubbleSort(a, size, t, cmp, output, data_file); break;
	case 4: heapSort(a, size, t, cmp, output, data_file); break;
	case 5: mergeSort(a, size, t, cmp, output, data_file); break;
	case 6: quickSort(a, size, t, cmp, output, data_file); break;
	case 7: radixSort(a, size, t, cmp, output, data_file); break;
	case 8: shakerSort(a, size, t, cmp, output, data_file); break;
	case 9: shellSort(a, size, t, cmp, output, data_file); break;
	case 10: countingSort(a, size, t, cmp, output, data_file); break;
	default: flashSort(a, size, t, cmp, output, data_file); break;
	}
}

void outputAlgo(int output, double t, long long cmp) {
	switch (output) {
	case 1: 
		cout << "Running time: " << t << "ms" << endl;
		break;
	case 2:
		cout << "Comparisons: " << cmp << endl;
		break;
	default:
		cout << "Running time: " << t << "ms" << endl;
		cout << "Comparisons: " << cmp << endl;
		break;
	}
}

void cmd1(int algo, string al, char input_file[], int output);
void cmd2(int algo, string al, int size, int order, char ord[], int output);
void cmd3(int algo, string al, int size, int output);
void cmd3gen(int algo, int a[], int size, int order, int output, double &t, long long &cmp);
void cmd4(int algo1, string al1, int algo2, string al2, char input_file[]);
void cmd5(int algo1, string al1, int algo2, string al2, int size, int order, char ord[]);

void readFile(string file, int* a, int size) {
	ifstream in(file);
	in.ignore();
	for (int i = 0; i < size; i++)
		in >> a[i];
	in.close();
}

void writeFile(string file, int* a, int size) {
	ofstream out(file);
	out << size << '\n';
	for (int i = 0; i < size - 1; i++)
		out << a[i] << " ";
	out << a[size - 1];
	out.close();
}

int main(int argc, char* argv[]) {
	if (argc == 5 || argc == 6) {
		if (string(argv[1]) == "-a") {
			int algo = checkAlgoValid(argv[2]);
			if (algo) {
				if (argc == 6) {
					if (atoi(argv[3]) > 1000000 || atoi(argv[3]) <= 0)
						return 0;
					int order = checkOrderValid(argv[4]), output = checkOutputValid(argv[5]);
					if (order && output) {
						cmd2(algo, argv[2], atoi(argv[3]), order, argv[4], output);
					}
				}
				else if (strstr(argv[3], ".txt")) {
					int output = checkOutputValid(argv[4]);
					if (output)
						cmd1(algo, argv[2], argv[3], output);
				}
				else {
					if (atoi(argv[3]) > 1000000 || atoi(argv[3]) <= 0)
						return 0;
					int output = checkOutputValid(string(argv[4]));
					if (output)
						cmd3(algo, argv[2], atoi(argv[3]), output);
				}
			}
		}
		else if (string(argv[1]) == "-c") {
			int algo1 = checkAlgoValid(argv[2]);
			int algo2 = checkAlgoValid(argv[3]);
			if (algo1 && algo2) {
				if (argc == 5) {
					cmd4(algo1, argv[2], algo2, argv[3], argv[4]);
				}
				else {
					if (atoi(argv[3]) > 1000000 || atoi(argv[3]) <= 0)
						return 0;
					int order = checkOrderValid(argv[5]);
					if (order)
						cmd5(algo1, argv[2], algo2, argv[3], atoi(argv[4]), order, argv[5]);
				}
			}
		}
	}
	return 0;
}

void cmd1(int algo, string al, char input_file[], int output) {
	ifstream in(input_file);
	int size;
	in >> size;
	in.close();
	if (size <= 1000000) {
		int* a = new int[size];
		readFile(input_file, a, size);
		double t = 0;
		long long cmp = 0;
		algoGen(algo, a, size, t, cmp, output, input_file);
		writeFile("output.txt", a, size);
		cout << "ALGORITHM MODE" << endl;
		cout << "Algorithm: " << algorithm(algo) << endl;
		cout << "Input file: " << input_file << endl;
		cout << "Input size: " << size << endl;
		for (int i = 0; i < 25; i++)
			cout << "-";
		cout << endl;
		outputAlgo(output, t, cmp);
	}
}

void cmd2(int algo, string al, int size, int order, char ord[], int output) {
	int* a = new int[size];
	double t = 0;
	long long cmp = 0;
	GenerateData(a, size, order - 1);
	writeFile("input.txt", a, size);
	algoGen(algo, a, size, t, cmp, output, "input.txt");
	writeFile("output.txt", a, size);
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << algorithm(algo) << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: " << inputOrder(order) << endl;
	for (int i = 0; i < 25; i++)
		cout << "-";
	cout << endl;
	outputAlgo(output, t, cmp);
}

void cmd3(int algo, string al, int size, int output) {
	int* a = new int[size];
	double t = 0;
	long long cmp = 0;
	cout << "ALGORITHM MODE" << endl;
	cout << "Algorithm: " << algorithm(algo) << endl;
	cout << "Input size: " << size << endl << endl;
	cmd3gen(algo, a, size, 0, output, t, cmp);
	cmd3gen(algo, a, size, 1, output, t, cmp);
	cmd3gen(algo, a, size, 2, output, t, cmp);
	cmd3gen(algo, a, size, 3, output, t, cmp);
}

void cmd3gen(int algo, int a[], int size, int order, int output, double &t, long long &cmp) {
	GenerateData(a, size, order);
	string input_file;
	switch (order) {
	case 0:
		input_file = "input_1.txt";
		writeFile("input_1.txt", a, size);
		cout << "Input order: Randomize" << endl;
		break;
	case 1:
		input_file = "input_2.txt";
		writeFile("input_2.txt", a, size);
		cout << "Input order: Nearly Sorted" << endl;
		break;
	case 2:
		input_file = "input_3.txt";
		writeFile("input_3.txt", a, size);
		cout << "Input order: Sorted" << endl;
		break;
	default:
		input_file = "input_4.txt";
		writeFile("input_4.txt", a, size);
		cout << "Input order: Reverse" << endl;
		break;
	}
	algoGen(algo, a, size, t, cmp, output, input_file);
	for (int i = 0; i < 25; i++)
		cout << "-";
	cout << endl;
	outputAlgo(output, t, cmp);
	cout << endl;
}

void cmd4(int algo1, string al1, int algo2, string al2, char input_file[]) {
	ifstream in(input_file);
	int size;
	in >> size;
	in.close();
	if (size <= 1000000) {
		int* a = new int[size];
		double t1 = 0, t2 = 0;
		long long cmp1 = 0, cmp2 = 0;
		readFile(input_file, a, size);
		algoGen(algo1, a, size, t1, cmp1, 3, input_file);
		readFile(input_file, a, size);
		algoGen(algo2, a, size, t2, cmp2, 3, input_file);
		cout << "COMPARISON MODE" << endl;
		cout << "Algorithm: " << algorithm(algo1) << " | " << algorithm(algo2) << endl;
		cout << "Input file: " << input_file << endl;
		cout << "Input size: " << size << endl;
		for (int i = 0; i < 25; i++)
			cout << "-";
		cout << endl;
		cout << "Running time: " << t1 << " | " << t2 << endl;
		cout << "Comparisons: " << cmp1 << " | " << cmp2 << endl;
	}
}

void cmd5(int algo1, string al1, int algo2, string al2, int size, int order, char ord[]) {
	int* a = new int[size];
	double t1 = 0, t2 = 0;
	long long cmp1 = 0, cmp2 = 0;
	GenerateData(a, size, order - 1);
	writeFile("input.txt", a, size);
	algoGen(algo1, a, size, t1, cmp1, 3, "input.txt");
	readFile("input.txt", a, size);
	algoGen(algo2, a, size, t2, cmp2, 3, "input.txt");
	cout << "COMPARISON MODE" << endl;
	cout << "Algorithm: " << algorithm(algo1) << " | " << algorithm(algo2) << endl;
	cout << "Input size: " << size << endl;
	cout << "Input order: " << inputOrder(order) << endl;
	for (int i = 0; i < 25; i++)
		cout << "-";
	cout << endl;
	cout << "Running time: " << t1 << " | " << t2 << endl;
	cout << "Comparisons: " << cmp1 << " | " << cmp2 << endl;
}