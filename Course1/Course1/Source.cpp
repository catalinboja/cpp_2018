#include <iostream>
#include <string.h>


void main() {
	printf("Hello World !");
	int vb1 = 100;
	vb1 = 200;
	int vb2;
	short int vb3 = 34;
	char vb4 = -101;
	//vb4 = 'e';
	vb4 = 0xFF;
	vb4 = 200;

	int *pointer;
	//it's a variable
	//the value it's an adress  to a location in RAM 
	//	(process stack + used HEAP)
	//pointer = (int*)vb1;
	pointer = &vb1;
	*pointer = 99;

	int value = *pointer;

	printf("vb1 = %d", vb1);
	//int result = vb1 + vb2;
}