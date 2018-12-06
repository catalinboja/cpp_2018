#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Student {
private:
	string nume = "Anonim";
	int varsta = 0;
private:
	int* note = NULL;
	int nrNote = 0;
public:
	int id;
	static int nrStudenti;

public:

	Student(string nume) :id(0), varsta(23) {
		this->nume = nume;
		Student::nrStudenti += 1;
	}

	Student(string nume, int varsta) : id(Student::nrStudenti) {
		this->nume = nume;
		this->varsta = varsta;
		Student::nrStudenti += 1;
	}

	Student(int Id,string nume, int varsta) : id(Id) {
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
		if (this->note != NULL)
			delete[] this->note;
	}

	//copy constructor
	Student(const Student& existent) :id(existent.id) {

		this->nume = existent.nume;
		this->varsta = existent.varsta;
		this->nrNote = existent.nrNote;
		this->note = new int[existent.nrNote];
		for (int i = 0; i < existent.nrNote; i++)
			this->note[i] = existent.note[i];
	}

	int getVarsta() {
		return this->varsta;
	}

	int getNrNote() {
		return this->nrNote;
	}

	int getNota(int index) {
		if (index >= 0 && index < this->nrNote)
			return this->note[index];
		else
			throw new exception();
	}

	static int getNrStudenti() {
		return Student::nrStudenti;
	}

	string getNume() {
		return this->nume;
	}

	void operator=(const Student& s) {

		this->nume = s.nume;
		this->varsta = s.varsta;
		this->nrNote = s.nrNote;
		if (this->note != NULL)
			delete[] this->note;

		this->note = new int[s.nrNote];
		for (int i = 0; i < s.nrNote; i++)
			this->note[i] = s.note[i];
	}

	void adaugaNota(int nota) {
		int* listaNoua = new int[this->getNrNote() + 1];
		for (int i = 0; i < this->getNrNote(); i++)
			listaNoua[i] = this->note[i];
		listaNoua[this->nrNote] = nota;

		if (this->note != NULL)
			delete[] this->note;

		this->note = listaNoua;
		this->nrNote += 1;
	}

	static Student** incarcaFisier(string numeFisier, int& nrStudenti) {
		fstream fisier(numeFisier, ios::in);
		if (fisier.is_open()) {

			fisier >> nrStudenti;

			Student** lista = new Student*[nrStudenti];
			for (int i = 0; i < nrStudenti; i++) {
				//numele
				//string nume;

				//varianta pentru spatiu
				//fisier >> nume;

				char buffer[100];
				fisier.getline(buffer, 100);
				fisier.getline(buffer, 100);
				string nume(buffer);


				int varsta;
				fisier >> varsta;
				int id;
				fisier >> id;
				int nrNote;
				fisier >> nrNote;

				lista[i] = new Student(id, nume, varsta);
				for (int j = 0; j < nrNote; j++) {
					int  nota;
					fisier >> nota;
					lista[i]->adaugaNota(nota);
				}


			}

			fisier.close();
			return lista;
		}
		else
			throw new exception();
	}

};


int Student::nrStudenti = 0;
ostream& operator<<(ostream& out, Student& stud) {
	out << endl << "----------------------------";
	out << endl << "Numele este :" << stud.getNume();
	out << endl << "Varsta este: " << stud.getVarsta();
	out << endl << "Id-ul este: " << stud.id;
	out << endl << " Notele sunt:";
	for (int i = 0; i < stud.getNrNote(); i++)
		out << " " << stud.getNota(i);
	return out;
}

void operator<<(fstream& out, Student& stud) {
	out << stud.getNume();
	out << endl << stud.getVarsta();
	out << endl << stud.id;
	out << endl;
	out << stud.getNrNote() << endl;
	for (int i = 0; i < stud.getNrNote(); i++)
		out << stud.getNota(i)<< endl;
	//out << endl;
}

void main() {

	//Student stud("Gigel", 22);
	//stud.adaugaNota(7);
	//stud.adaugaNota(8);
	//stud.adaugaNota(9);

	//cout << stud;
	//
	////Student grupa[5]
	//Student* grupa[2];
	////grupa[0] = &stud;
	//grupa[0] = new Student("Gigel", 22);
	//grupa[1] = new Student("Ana", 22);
	//
	//grupa[0]->adaugaNota(7);
	//grupa[0]->adaugaNota(8);
	//grupa[0]->adaugaNota(9);

	//grupa[1]->adaugaNota(9);
	//grupa[1]->adaugaNota(10);

	//int nrStudenti = 2;

	//for (int i = 0; i < nrStudenti; i++)
	//	cout << endl << *grupa[i];

	//////salvare in fisier text
	////fstream fisier("Studenti.txt", ios::out | ios::trunc);
	////if (fisier.is_open()) {

	////	fisier << nrStudenti << endl;
	////	for (int i = 0; i < nrStudenti; i++)
	////		fisier << *grupa[i];

	////	fisier.close();
	////}
	////else
	////	cout << endl << "*********** NU AM deschis fisierul";

	//cout << endl << "*********** citire din fisier *********";
	////citire date fisier text
	//int nrStudenti_2;
	//Student** listaNoua =
	//	Student::incarcaFisier("Studenti.txt", nrStudenti_2);
	//for (int i = 0; i < nrStudenti_2; i++)
	//	cout << endl << *listaNoua[i];

	////VARIANTA GRESITA
	////salvare in fisier binar
	//fstream fisier("Studenti.data", ios::out | ios::trunc | ios::binary);
	//if (fisier.is_open()) {

	//	//fisier << nrStudenti;
	//	fisier.write((char*)&nrStudenti_2, sizeof(int));
	//	for (int i = 0; i < nrStudenti_2; i++)
	//		//NU ESTE OK - vei scrie in fisier adrese
	//		fisier.write((char*)listaNoua[i], sizeof(Student));

	//	fisier.close();
	//}

	//incarca din fisier binar
	fstream fisier;
	fisier.open("Studenti.data", ios::in | ios::binary);
	if (fisier.is_open()) {
		//citest numarul de studenti
		int nrStudentiFisier;
		fisier.read((char*)&nrStudentiFisier, sizeof(int));

		Student** listaNouaFisier = new Student*[nrStudentiFisier];
		for (int i = 0; i < nrStudentiFisier; i++)
			listaNouaFisier[i] = new Student(0, "", 0);
		for (int i = 0; i < nrStudentiFisier; i++)
			fisier.read((char*)listaNouaFisier[i], sizeof(Student));

		fisier.close();

		//afisare
		cout << endl << "*********** citire din fisier binar *********";
		for (int i = 0; i < nrStudentiFisier; i++)
			cout << endl << *listaNouaFisier[i];
	}

}