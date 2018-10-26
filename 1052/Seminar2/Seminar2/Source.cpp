#include <iostream>

int main() {

	printf("\n Hello World !");

	unsigned char value = 98;
	printf("The char is %c", value);

	value += 90;
	printf("\n The char is %c", value); //strange character
	printf("\n The value is %d", value); //158 

	int vb1 = 10;
	int vb2;

	//pointer
	int *pointer1; //4 bytes
	char *pointer2; //4 bytes

	//pointer1 = (int*)vb1;
	pointer1 = (int*)vb1;


	return 0;

}