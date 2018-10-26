#include <iostream>
#include <malloc.h>

int main() {
	int* pointer;
	int variable = 100;
	char smallNumber = 99;

	//init the pointer with the variable address
	pointer = (int*)variable;
	pointer = (int*)200;

	pointer = &variable;

	//changing the value
	variable = 300;
	*pointer = 400;

	printf("Pointer value is %x", pointer);

	//define an array
	//a static one on the main stack
	int array[100];

	//define a dynamic array
	//in HEAP

	//C style
	int * array2 = (int*)malloc(200*sizeof(int));
	//free them up
	free(array);

	//C++ style
	int* array3 = new int[200];
	//clean them up
	delete[] array3;

	return 0;
}