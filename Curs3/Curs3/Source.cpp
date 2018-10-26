#include <iostream>
using namespace std;

void afisareVector(int* vector, int n, const char* mesaj);

int main() {

	std::cout << "Hello World !";
	cout << std::endl << " Hello World iar!";

	//statici
	int vector[10];
	int n1 = 10;

	//initializare
	for (int i = 0; i < n1; i++) {
		vector[i] = i + 1;
	}

	//dinamic
	//1. definire
	int* vectorDinamic;
	int n2 = 50;
	//2. creare
	//vectorDinamic = (int*)malloc(50*sizeof(int));
	vectorDinamic = new int[n2];


	//afisare vectori
	//cout << endl << "Primul vector este:";
	//for (int i = 0; i < n1; i++) {
	//	cout << vector[i] << " ";
	//}
	afisareVector(vector, n1, "Primul vector: ");


	cout << endl << "Al 2-lea vector este:";
	for (int i = 0; i < n2; i++) {
		cout << vectorDinamic[i] << " ";
	}

	int* vector3 = vector;

	vector3 += 3;

	cout << endl << "Primul vector este:";
	for (int i = 0; i < n1; i++) {
		//cout << vector3[i] << " ";
		cout << *(vector3+i) << " ";
	}

	//shallow copy
	int* vector4 = vector;

	cout << endl << endl<< "Al 4-lea vector este:";
	for (int i = 0; i < n1; i++) {
		cout << vector4[i] << " ";
	}

	vector4[0] = 99;

	cout << endl << "Primul vector este:";
	for (int i = 0; i < n1; i++) {
		cout << vector[i] << " ";
	}

	cout << endl << "Vector este " << vector;

	//ruleaza la infinit - dar fara memory leak
	//for (;;) {
	//	int* vectorMic = new int[5];
	//	delete[] vectorMic;
	//}

	cout << endl << "SFARSIT";

}

void afisareVector(int* vector, int n, const char* mesaj) {
	//strcpy(mesaj,"Nimic!");
	//mesaj[0] = 'A';
	cout << endl << mesaj;
	for (int i = 0; i < n; i++) {
		cout << vector[i] << " ";
	}
}