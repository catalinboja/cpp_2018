#include <iostream>
using namespace std;

void printArray(int* array, int n, const char* message);

//a function that inits an array
void initArray(int* array, int n, int value) {
	for (int i = 0; i < n; i++) {
		array[i] = value;
	}
}

//IT'S WRONG
//DON'T USE IT
int resizeArray(int* array, int n) {
	int newSize;
	cout << endl << "New size is:";
	cin >> newSize;
	//delete[] array;

	//array = new int[newSize];

	cout << endl << "Values:";
	for (int i = 0; i < newSize; i++) {
		cout << endl << "value " << i + 1 << ": ";
		cin >> array[i];
	}

	return newSize;

}

int main() {
	std::cout << endl << "Hello World !";

	int array1[5];
	int n1 = 5;

	int array2[10];
	int n2 = 10;

	int n3 = 5;
	int* array3 = new int[n3];

	//init the arrays
	initArray(array1, n1, 1);
	initArray(array2, n2, 20);
	initArray(array3, n3, 50);

	cout << endl << "Array 1:";
	for (int i = 0; i < n1; i++)
		cout << array1[i] << " ";

	//they have the same type
	//array3 = array1;

	printArray(array2, n2, "Array 2:");
	printArray(array3, n3, "Array 3:");

	//resize them
	n1 = resizeArray(array2, n2);

	printArray(array1, n1, "Array 1:");
	printArray(array2, n2, "Array 2:");
}

//function for printing an array
void printArray(int* array, int n, const char* message) {

	//message[0] = 'A';
	cout << endl << message;
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
}