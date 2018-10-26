#include <iostream>
#include <string>
using namespace std;

void printArray(int* array, int n, const string message) {
	cout << endl << message;
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
}

void resizeArray(int* array, int n) {
	cout << endl << "New size is:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << endl << "Value " << i << " is: ";
		cin >> array[i];
	}
}

int resizeArray2(int* array, int n) {
	cout << endl << "New size is:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << endl << "Value " << i << " is: ";
		cin >> array[i];
	}
	return n;
}

void resizeArray3(int* array, int& n, int MAX_SIZE) {
	cout << endl << "New size is (not bigger than "<<MAX_SIZE<<"):";
	cin >> n;
	//TO DO: validate the input
	for (int i = 0; i < n; i++) {
		cout << endl << "Value " << i << " is: ";
		cin >> array[i];
	}
}

void resizeArray4(int* array, int* n) {
	cout << endl << "New size is:";
	cin >> *n;
	for (int i = 0; i < *n; i++) {
		cout << endl << "Value " << i << " is: ";
		cin >> array[i];
	}
}

void resizeDynamicArray(int*& array, int* n) {
	cout << endl << "New size is:";
	cin >> *n;

	//clean up
	delete[] array;

	array = new int[*n];

	for (int i = 0; i < *n; i++) {
		cout << endl << "Value " << i << " is: ";
		cin >> array[i];
	}

}

int main() {

	//int array1[10];
	//int n1 = 10;

	//resizeArray3(array1, n1, 10);
	//printArray(array1, n1, "Static array is:");


	int *array2 = new int[5];
	int n2 = 5;

	resizeDynamicArray(array2, &n2);
	printArray(array2, n2, "Dynamic array is:");

}