#include <iostream>
using namespace std;

void printArray(int* array, int n, const char* message) {
	cout << endl << message;
	//a mistake
	//array[0] = 1000;
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
}

int main() {

	std::cout << "Hello World !";
	cout << std::endl << "Hello again !";

	int vb;
	cout << endl << " Give me a value:";
	cin >> vb;
	cout << endl << "Vb = " << vb;

	int* pVb1 = &vb;
	int* pVb2 = (int*)vb;

	cout << endl << "Value of vb is " << vb << " or by pointer "
		<< *pVb1;

	//arrays 
	//static - fix size
	//you need to count number of used values
	// tou can't use a n > [10]
	int array1[10];
	cout << endl << "No of elements:";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << endl << "element " << i << " :";
		cin >> array1[i];
	}
	//print it
	printArray(array1, n, "The array is:");
	//printArray(array1, n);
	//cout << endl << "The array is:";
	//for (int i = 0; i < n; i++)
	//	cout << array1[i] << " ";

	//shallow copy
	int *pvb3 = array1;

	//print it
	cout << endl << "The array is again:";
	for (int i = 0; i < n; i++) {
		//cout << pvb3[i] << " ";
		cout << *(pvb3 + i) << " ";
	}

	pvb3[0] = 99;

	cout << endl << "The second array is again:";
	for (int i = 0; i < n; i++)
		cout << pvb3[i] << " ";

	cout << endl << "The first array is:";
	for (int i = 0; i < n; i++)
		cout << array1[i] << " ";

	//dynamic arrays
	//they can have any size
	int m;
	int *array2;
	cout << endl << "No of elements:";
	cin >> m;
	//ask for space
	//array2 = (int*)malloc(m*sizeof(int));
	array2 = new int[m];

	//read the elements
	for (int i = 0; i < m; i++) {
		cout << endl << "element " << i << " :";
		cin >> array2[i];
	}

	cout << endl << "The dynamic array is:";
	for (int i = 0; i < m; i++)
		cout << array2[i] << " ";

	//shallow copy again
	int *pvb4 = array2;

	//for (;;) {
	//	int* temp = new int[5];
	//	//use them
	//	//...
	//	//delete them
	//	delete[] temp;
	//}

	//you can't - it's a constant pointer
	//array1 = new int[10];

	const int constValue = 10;
	//constValue = 20;

	cout << endl << "The End";
}