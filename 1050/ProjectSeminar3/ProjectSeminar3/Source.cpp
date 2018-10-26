#include <iostream>
using namespace std;

void printArray(int* v, int lenght, const char* message);

void initArray(int* array, int n) {
	cout << endl << "Give me some values" << n << " of them:";
	for (int i = 0; i < n; i++)
	{
		cout << endl << "element " << i << ":";
		cin >> array[i];
	}
}


//DONT'T MEMORIZE IT - IT'S WRONG
void createArray(int* emptyArray, int length) {
	cout << endl << "Give us the number of elements:";
	cin >> length;

	//ask for the values
	for (int i = 0; i < length; i++) {
		cout << endl << "element " << i << ":";
		cin >> emptyArray[i];
	}
}

int main() {

	int array[10];
	int array2[10];
	int n1 = 10;

	int* aPointer = array;


	int n2 = 5;
	int* dArray = new int[n2];

	//initArray(array, n1);
	//initArray(dArray, n2);

	createArray(array2, n1);
	createArray(dArray, n2);

	printArray(array2, n1, "The first one:");
	printArray(array, n1, "The first one:");
	printArray(dArray, n2, "The second one:");

	//
	//return 0;
}

void printArray(int* v, int lenght,const char* message) {

	//delete[] message;
	//message = new char[100];
	
	//compiler error
	//message[0] = 'B';

	cout << endl << message;
	for (int i = 0; i < lenght; i++) {
		cout << v[i] << " ";
	}
}