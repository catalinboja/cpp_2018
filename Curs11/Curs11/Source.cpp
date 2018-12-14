#include <iostream>
#include <string>

using namespace std;

class Note {
public:
	int* note;
	int nrNote;

	//Note() {
	//	cout << endl << "Hello Constructorul din Note";
	//	this->note = NULL;
	//	this->nrNote = 0;
	//}

	Note(int nrNote, int valoareInitiala) {
		cout << endl << "Hello Constructorul cu argumente din Note";
		this->note = new int[nrNote];
		for (int i = 0; i < nrNote; i++)
			this->note[i] = valoareInitiala;
		this->nrNote = nrNote;
	}

	friend void operator<<(ostream& out, Note& note);
};

void operator<<(ostream& out, Note& note) {
	out << endl << "Notele sunt:";
	for (int i = 0; i < note.nrNote; i++)
		out << " " << note.note[i];;
}

class Student {
protected:
	string nume;
	int varsta;
	Note note;		//compunere = o relatie de tip has a


public:
	Student(): note(5,10) {
		cout << endl << "Hello Constructorul din Student";
		this->varsta = 0;
		this->nume = "Anonim";
	}

	Student(string nume, int varsta, int nrNoteInitiale = 0) 
		: note(nrNoteInitiale, 10) {
		this->nume = nume;
		this->varsta = varsta;
	}

	void getInfo() {
		cout << endl << "Sunt un Student";
	}

	friend void operator<<(ostream& out, Student& s);
};

void operator<<(ostream& out, Student& s) {
	out << endl << s.nume << " are varsta " << s.varsta;
	out << s.note;
}

class Facultate {
	Student studenti[100];
};

class SuperStudent: public Student {
public:
	bool areBursa;
	string adresa;

	SuperStudent() {
		this->areBursa = false;
		this->adresa = "Bucuresti";
		this->nume = "Super Anonim";
	}

	SuperStudent(string nume, int varsta, bool areBursa, string adresa,
		int nrNoteInitiale = 0) : Student(nume, varsta, nrNoteInitiale) {
		cout << endl << "Hello Constructorul din SuperStudent";
		//this->nume = nume;
		//this->varsta = varsta;
		this->areBursa = areBursa;
		this->adresa = adresa;
	}

	void ceva() {
		this->getInfo();

	}
};

int main() {
	//Student student;
	//Student *pStudent;

	//cout << student;

	//Student student2("Gigel", 19, 3);
	//cout << student2;
	//Student student3("Alina", 20);
	//Student student4("Ionel", 18);
	//Student student;
	//student.getInfo();


	//SuperStudent superStudent;
	//superStudent.getInfo();

	SuperStudent superStudent2("Gigel",21,true,"Iasi",5);
	superStudent2.getInfo();
}