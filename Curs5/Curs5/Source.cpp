#include <iostream>
#include <string>
using namespace std;

struct Student {
	string nume;
	int varsta;
	char facultate[100];
};

void printStudent(Student stud) {
	cout << endl << stud.nume << " are varsta " << stud.varsta
		<< " si este la facultatea " << stud.facultate;
}

Student citireStudent() {
	Student s;
	cout << endl << "Nume student:";
	cin >> s.nume;
	cout << endl << "Varsta: ";
	cin >> s.varsta;
	cout << endl << "Facultate: ";
	//s.facultate = new char[80];  NU se poate
	cin >> s.facultate;
	return s;
}

class SuperStudent {
private:
public:
	string nume;
	int varsta;
	char facultate[100];

private:
	int* note;
	int nrNote;
public:
	string adresa;

	void printSuperStudent() {
		cout << endl << this->nume << " are varsta " << this->varsta
			<< " si este la facultatea " << this->facultate;
		cout << endl << "Notele sunt:";
		for (int i = 0; i < this->nrNote; i++) {
			cout << endl << this->note[i] << " ";
		}
	}

	void citireStudent() {
		cout << endl << "Nume student:";
		cin >> this->nume;
		cout << endl << "Varsta: ";
		cin >> this->varsta;
		cout << endl << "Facultate: ";
		//s.facultate = new char[80];  NU se poate
		cin >> this->facultate;
	
	}
};


void main() {

	//Student student;
	//student = citireStudent();
	//printStudent(student);
	//cout << endl << " Doar numele lui:" << student.nume;


	SuperStudent super1;
	SuperStudent super2;
	cout << endl << " Doar numele super studentului:" << super1.nume;
	//cout << endl << " Nr note super student:" << super1.nrNote;



	super1.citireStudent();

	super1.printSuperStudent();
	super2.printSuperStudent();
}