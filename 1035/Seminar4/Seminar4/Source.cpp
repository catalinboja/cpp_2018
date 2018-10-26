#include <iostream>
#include <string>
using namespace std;

void afisareVector(int* v, int n, const string mesaj) {
	cout << endl << mesaj;
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
}

void redimensionareVector(int* vector, int *n) {
	cout << endl << "Noua dimensiune este: ";
	cin >> *n;
	for (int i = 0; i < *n; i++) {
		cout << endl << "valoare " << i + 1 << ": ";
		cin >> vector[i];
	}
}

void redimensionareVectorReferinta(int* vector, 
	int& n, int MAX) {
	cout << endl << 
		"Noua dimensiune este (dar nu mai mult decat "<<
		MAX<<"): ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << endl << "valoare " << i + 1 << ": ";
		cin >> vector[i];
	}
}

void redimensionareVectorDinamic(int*& vector, int *n) {
	cout << endl << "Noua dimensiune este: ";
	cin >> *n;


	//evitare memory leak
	//se sterge vectorul anterior
	if(vector!= NULL)
		delete[] vector;

	vector = new int[*n];

	for (int i = 0; i < *n; i++) {
		cout << endl << "valoare " << i + 1 << ": ";
		cin >> vector[i];
	}
}

int main() {

	////vector static
	//int vector1[10];
	//int n1 = 10;

	////redimensionareVector(vector1, &n1);
	//redimensionareVectorReferinta(vector1, n1, 10);
	//afisareVector(vector1, n1, "Vector 1:");

	//vector dinamic
	int* vector2 = NULL;
	int n2 = 0;

	redimensionareVectorDinamic(vector2, &n2);

	afisareVector(vector2, n2, "Vector 2:");

	const char* cuvant = "abecedar";
	char* cuvant2;
	cuvant2 = cuvant;

}