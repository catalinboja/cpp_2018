#include <iostream>
#include <malloc.h>

void main() {

	int vb1 = 97;
	vb1 += 130;

	unsigned char c = 'a'; //cod ASCII 97
	c += 130;
	printf("\n Valoare caracter = %c", c); // pi
	printf("\n Valoare caracter = %d", c); // 227

	int vb2;

	int vector[50];

	vector[0] = 100;
	
	//void *pointer1;
	//void *pointer2;h

	//adresa vb1
	//int *pointer1 = (int*)vb1;
	int *pointer1 = &vb1;

	*pointer1 = 99;
	printf("\n Valoare vb1 = %d", vb1); // 

	//alocare spatiu malloc
	int * vector2 = (int*)malloc(200 * sizeof(int));
	free(vector);

	vector2 = new int[200];
	delete[] vector
}