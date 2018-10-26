#include <iostream>
#include <string>
using namespace std;

char* citireNume() {
	char* numeStudent;
	//numeStudent = new char[30];

	char buffer[10000];

	cout << endl << "Vreau un nume pentru student: ";
	cin >> buffer;
	numeStudent = new char[strlen(buffer) + 1];
	strcpy(numeStudent, buffer);

	return numeStudent;
}

void interschimbare(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void interschimbare2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void interschimbare3(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

int main() {

	//recomandare: de evitat
	//char nume[50] = "Gigel";
	char nume[30];

	//nume[3] = '\0';
	nume[3] = 0;

	//cout << endl << "Numele este " << nume;
	//cout << endl << "Vreau un nume nou: ";
	////pentru a citi si spatiu
	//cin.getline(nume, 30);
	////cin >> nume;
	//cout << endl << "Numele nou este " << nume;
	//int varsta;
	//cout << endl << "Varsta este:";
	//cin >> varsta;
	//cout << endl << "Varsta citita este:"<<varsta;

	//siruri de caractere dinamice
	char* numeStudent;
	//numeStudent = new char[30];

	/*char buffer[10000];

	cout << endl << "Vreau un nume pentru student: ";
	cin >> buffer;
	numeStudent = new char[strlen(buffer)+1];
	strcpy(numeStudent, buffer);*/

	//numeStudent = citireNume();
	//cout << endl << "Numele studentului este " << numeStudent;

	//string numeProfesor;
	//numeProfesor = "Popescu";
	//numeProfesor = "Ionescu";
	//numeProfesor = numeProfesor + " Gigel";
	//cout << endl << "Nume prof:" << numeProfesor;
	//cout << endl << "Un prof nou:";
	//cin >> numeProfesor;
	//cout << endl << "Nume prof:" << numeProfesor;


	int vb1 = 10;
	int vb2 = 20;

	cout << endl << "vb1 = " << vb1 << " si vb2 =" << vb2;

	int temp = vb1; 
	vb1 = vb2; 
	vb2 = temp;

	cout << endl << "vb1 = " << vb1 << " si vb2 =" << vb2;

	interschimbare(vb1, vb2);

	cout << endl << "vb1 = " << vb1 << " si vb2 =" << vb2;

	interschimbare2(&vb1, &vb2);

	cout << endl << "(2) vb1 = " << vb1 << " si vb2 =" << vb2;

	interschimbare3(vb1, vb2);

	cout << endl << "(3) vb1 = " << vb1 << " si vb2 =" << vb2;
	//return 0;

}