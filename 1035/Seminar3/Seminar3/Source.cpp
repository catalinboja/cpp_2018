#include <iostream>
using namespace std;

void afisareVector(int* vector, int n, const char* mesaj);

void initializareVector(int* vector, int n) {
	for (int i = 0; i < n; i++)
		vector[i] = i + 1;
}

void redimensionareVector(int* vector, int& n) {
	cout << endl << "Noua dimensiune este:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << endl << "Valoare " << i << ": ";
		cin >> vector[i];
	}
}

int main() {

	int vector2[8];
	int n2 = 8;

	cout << endl << vector2;

	int vector1[5];
	int n1 = 5;



	int n3 = 5;
	int* vector3;
	vector3 = new int[n3];

	initializareVector(vector1, n1);
	initializareVector(vector2, n2);
	initializareVector(vector3, n3);

	afisareVector(vector1, n1, "Vector 1:");
	afisareVector(vector2, n2, "Vector 2:");
	afisareVector(vector3, n3, "Vector 3:");

	cout << endl << "********* Redimensionare *******";
	//redimensionareVector(vector1, n1);
	afisareVector(vector1, n1, "Vector 1 nou:");
	afisareVector(vector2, n2, "Vector 2 vechi:");

}

void afisareVector(int* vector, int n, const char* mesaj) {
	cout << endl << mesaj;
	for (int i = 0; i < n; i++)
		cout << vector[i] << " ";
}
