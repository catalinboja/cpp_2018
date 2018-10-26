#include <iostream>
#include <string>
using namespace std;

void printArray(int* array, int n, const string message) {
	cout << endl << message;
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
}

void reInitStaticArray(int* array, int* n, int MAX_SIZE) {
	cout << endl << "New size is (not bigger than "<<MAX_SIZE<<"): ";
	cin >> *n;
	cout << endl << "The values are ";
	for (int i = 0; i < *n; i++)
	{
		cout << endl << " value " << i << ": ";
		cin >> array[i];
	}
}

//TO DO to update it
void reInitArrayReference(int* array, int& n) {
	cout << endl << "New size is";
	cin >> n;

	cout << endl << "The values are ";
	for (int i = 0; i < n; i++)
	{
		cout << endl << " value " << i << ": ";
		cin >> array[i];
	}
}

void reInitDynamicArrayReference(int*& array, int& n) {
	cout << endl << "New size is";
	cin >> n;

	if (array != NULL)
	{
		//clean the memory leak
		delete[] array;
	}

	//create a new one with the new size
	array = new int[n];

	cout << endl << "The values are ";
	for (int i = 0; i < n; i++)
	{
		cout << endl << " value " << i << ": ";
		cin >> array[i];
	}
}

int main() {

	int array1[10];
	int n1 = 10;

	//reInitStaticArray(array1, &n1,10);
	////reInitArrayReference(array1, n1);
	//printArray(array1, n1,"The static array is:");

	int* array2 = NULL;
	int n2 = 10;

	reInitDynamicArrayReference(array2, n2);
	printArray(array2, n2, "The dynamic array is:");


}