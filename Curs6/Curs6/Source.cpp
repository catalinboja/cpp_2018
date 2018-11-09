#include <iostream>
#include <string>

using namespace std;

//int VARSTA_MINIMA = 14;
//int VARSTA_MAXIM = 90;


class Student {
public:
	string nume = "Anonim";
private:
	int varsta = 0;
	int* note = NULL;
	int nrNote = 0;
	const int ID;

	static int VARSTA_MINIMA;
	static int VARSTA_MAXIMA;
public:

	Student():ID(1) {
	}


	void printInfo() {
		cout << endl << this->nume << ", are varsta " << this->varsta;
		cout << endl << "Note:";
		if (this->note != NULL)
		{
			for (int i = 0; i < this->nrNote; i++)
				cout << this->note[i] << " ";
		}
		else
			cout << endl << "Nu are note";
	}

	//seturi de functii accesor
	//dau drepturi de citire pe atribute private
	int getVarsta() {
		return this->varsta;
	}

	//nu returnam pointeri - pot sa modifice valorile
	//int* getNote() {
	//	return this->note;
	//}

	int getNrNote() {
		return this->nrNote;
	}

	int getNota(int indexNota) {
		if(this->note!=NULL && indexNota >= 0 && indexNota < this->nrNote)
			return this->note[indexNota];
		else
		{
			//cout << endl << "Index gresit";
			//return -1;
			throw new exception("Index gresit");
		}
	}

	//functii ce permit modificarea valorilor campurilor private
	void setVarsta(int varsta) {
		//this->varsta = valoare;
		if (varsta >= Student::VARSTA_MINIMA && varsta <= Student::VARSTA_MAXIMA) {
			this->varsta = varsta;
		}
		else
			throw new exception("Valoare gresita");
	}

	static int getVarstaMaxima() {
		return Student::VARSTA_MAXIMA;
	}
};

int Student::VARSTA_MINIMA = 10;
int Student::VARSTA_MAXIMA = 90;

void main() {
	Student student;

	Student* pStudent = new Student();

	student.printInfo();
	pStudent->printInfo();

	cout << endl << "Varsta studentului " << student.nume
		<< " este " << student.getVarsta();

	if(student.getNrNote() >= 4)
		cout << endl << "Nota a 4-a a studentului " << student.nume
		<< " este " << student.getNota(3);


	int varstaNoua = -23;
	if(varstaNoua > Student::getVarstaMaxima())
		student.setVarsta(varstaNoua);


}