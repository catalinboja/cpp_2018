#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	string nume = "Anonim";
	int varsta = 0;
	const int id;
private:
	int* note = NULL;
	int nrNote = 0;
public:
	static int nrStudenti;

public:
	//constructorul default
	//Student() {
	//	cout << endl << "Apel constructor default";
	//}

	Student(string nume) :id(0), varsta(23) {
		this->nume = nume;
		Student::nrStudenti += 1;
	}

	Student(string nume, int varsta) : id(Student::nrStudenti) {
		this->nume = nume;
		this->varsta = varsta;
		Student::nrStudenti += 1;
	}

	Student(int varsta, string nume) : id(Student::nrStudenti) {
		this->nume = nume;
		this->varsta = varsta;
		Student::nrStudenti += 1;
	}

	Student(string nume, int varsta, int nrNote) : id(Student::nrStudenti) {
		this->nume = nume;
		this->varsta = varsta;

		this->nrNote = nrNote;
		this->note = new int[this->nrNote];
		for (int i = 0; i < this->nrNote; i++)
			this->note[i] = 0;


		Student::nrStudenti += 1;
	}

	//destructor
	~Student() {
		cout << endl << "Apel destructor";
		if (this->note != NULL)
			delete[] this->note;
	}

	//copy constructor
	Student(const Student& existent):id(existent.id) {
		//existent.varsta = 45;
		cout << endl << "Apel constructor copiere";
		this->nume = existent.nume;
		this->varsta = existent.varsta;
		this->nrNote = existent.nrNote;
		//shallow copy
		//this->note = existent.note;
		this->note = new int[existent.nrNote];
		for (int i = 0; i < existent.nrNote; i++)
			this->note[i] = existent.note[i];
	}
};

int Student::nrStudenti = 0;

void printInfo(Student stud) {
	cout << endl << "Numele studentului este " << stud.nume;
	cout << endl << "Varsta studentului este " << stud.varsta;
}

void printInfo2(Student* stud) {
	cout << endl << "Numele studentului este " << stud->nume;
	cout << endl << "Varsta studentului este " << stud->varsta;
}

Student ceva() {
	Student s("Anonim", 21);
	return s;
}

void main() {
	//Student s;
	Student s1("Gigel",22);
	Student *pS1 = new Student("Ana",23);
	Student s3("Vader", 22, 5);

	cout << endl << "Numar studenti: " << Student::nrStudenti;

	//for (;;) {
	//	Student *ps = new Student("Anonim",20,5);
	//	//delete[] ps->note;
	//	delete ps;
	//}

	printInfo(s3);
	//printInfo2(&s3);

	ceva();

	//apel constructor de copiere
	Student s4 = s3;
	Student s5(s3);

	//s4 = s4 + 10;	//operator+
	//s4 += 9;		//s4.operator+=(9)
	//s1 = s2 + s3;	//s2.operator+(s3)
	//s1 = s2;		//s1.operator=(s2);

}