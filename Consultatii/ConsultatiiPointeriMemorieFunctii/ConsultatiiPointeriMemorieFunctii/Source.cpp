#include<iostream>
using namespace std;

//int variabilaGlobala;

void functie() {
	int vb1 = 20;
}

//atentie ! intoarce o adresa a unei variabile de pe stiva
//int* citireVector() {
//	int vector[100];
//	int n = 100;
//	cout << endl << "Numar elemente:";
//	cin >> n;
//	cout << endl << "Elementele sunt:";
//	for (int i = 0; i < n; i++) {
//		cout << endl << "Element " << i << ": ";
//		cin >> vector[i];
//	}
//	return vector;
//}


int* citireVector(int* adresaDimensiune) {
	int* vector;
	int n;
	cout << endl << "Numar elemente:";
	cin >> n;
	*adresaDimensiune = n;

	vector = new int[n];

	cout << endl << "Elementele sunt:";
	for (int i = 0; i < n; i++) {
		cout << endl << "Element " << i << ": ";
		cin >> vector[i];
	}
	return vector;
}

void citireVector2(int* *adresaPointerVector,int* adresaDimensiune) {
	int* adresaIntUrmatDeAltii;
	int n;
	cout << endl << "Numar elemente:";
	cin >> n;
	*adresaDimensiune = n;

	adresaIntUrmatDeAltii = new int[n];
	*adresaPointerVector = adresaIntUrmatDeAltii;

	cout << endl << "Elementele sunt:";
	for (int i = 0; i < n; i++) {
		cout << endl << "Element " << i << ": ";
		cin >> adresaIntUrmatDeAltii[i];
	}

}



void afisareVector(int* vector, int n) {
	//int vector[100];
	//int n = 100;
	cout << endl << "Vectorul este:";
	for (int i = 0; i < n; i++) {
		cout << vector[i] << " ";
	}
}

void alocareSpatiu(int* *adresaPointerMain,int nrElemente) {
	int* adresaSpatiu = new int[nrElemente];
	for (int i = 0; i < nrElemente; i++)
		adresaSpatiu[i] = i;
	*adresaPointerMain = adresaSpatiu;
}
void citireNumar(int *adresaNumar) {
	int valoare;
	cout << endl << "Numarul este:";
	cin >> valoare;
	*adresaNumar = valoare;
}

void citireNumarCuReferinta(int& adresaNumar) {
	int valoare;
	cout << endl << "Numarul este:";
	cin >> valoare;
	adresaNumar = valoare;
}

void alocareSpatiuCuReferinta(int* &adresaPointerMain, int nrElemente) {
	int* adresaSpatiu = new int[nrElemente];
	for (int i = 0; i < nrElemente; i++)
		adresaSpatiu[i] = i;
	adresaPointerMain = adresaSpatiu;
}

void citireNumere(int& a, int& b, int& c) {
	cout << endl << "vb1 =";
	cin >> a;
	cout << endl << "vb2 =";
	cin >> b;
	cout << endl << "vb3 =";
	cin >> c;
}

int sumaElemente(int* vector, int n) {
	int suma = 0;
	for (int i = 0; i < n; i++) {
		//suma += *(vector + i);
		suma += vector[i];
	}
	return suma;
}

int minimElemente(int* vector, int n) {
	int minim = vector[0];
	for (int i = 0; i < n; i++) {
		//suma += *(vector + i);
		if (minim > vector[i])
			minim = vector[i];
	}
	return minim;
}

int oriceOperatie(int* vector, int n, int tipOperatie) {
	if (tipOperatie == 1)
		return sumaElemente(vector, n);
	if(tipOperatie == 2)
		return minimElemente(vector, n);
}

int oriceOperatie(int* vector, int n,int (*pointerFunctie)(int*,int)) {
	return pointerFunctie(vector, n);
}

void main() {
	//int vb1 = 10;
	//int* pointerVb = &vb1;

	//cout << endl << "Adresa lui vb1 este " << &vb1;
	//cout << endl << "Adresa lui vb1 este " << pointerVb;

	//vb1 = 20;
	//*pointerVb = 30;

	//cout << endl << "Valoare lui vb1 este " << vb1;
	//cout << endl << "Valoare lui vb1 este " << *pointerVb;

	//int* pointer;
	//int dimensiuneVectorCitit;

	//pointer =  citireVector(&dimensiuneVectorCitit);

	//afisareVector(pointer, dimensiuneVectorCitit);
	//afisareVector(&vb1,1);

	//int numarCitit;
	//citireNumar(&numarCitit);
	//citireNumarCuReferinta(numarCitit);
	//cout << endl << "Numarul este:" << numarCitit;

	//int* numereInHeap;
	//alocareSpatiu(&numereInHeap,10);
	//cout << endl << "Spatiul alocat este:";
	//for (int i = 0; i < 10; i++)
	//	cout << numereInHeap[i];

	int vb1, vb2, vb3;
	//cout << endl << "vb1 =";
	//cin >> vb1;
	//cout << endl << "vb2 =";
	//cin >> vb2;
	//cout << endl << "vb3 =";
	//cin >> vb3;
	citireNumere(vb1, vb2, vb3);

	cout << endl << "vb1 = " << vb1 <<
		"vb2 = " << vb2 << " vb3 = " << vb3;

	int v[10];

	int (*pointerFunctie)(int*, int);
	pointerFunctie = sumaElemente;
	pointerFunctie = minimElemente;
	pointerFunctie(v, 10);

	oriceOperatie(v, 10, sumaElemente);
}