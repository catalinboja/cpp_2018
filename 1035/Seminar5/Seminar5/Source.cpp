#include <iostream>
#include <string>
using namespace std;

class Student {
private:
public:
	string nume = "Anonim";
	char facultate[50] = "CSIE";
	char* grupa = NULL;
private:
	int varsta = 0;
	int* note = NULL;
	int nrNote = 0;
public:
	void infoStudent() {
		cout << endl << "Numele studentului este " << this->nume;
		cout << endl << "Facultatea studentului este " << this->facultate;
		if (this->grupa != NULL)
			cout << endl << "Grupa studentului este " << this->grupa;
		else
			cout << endl << "Nu are grupa";
		cout << endl << "Varsta studentului este " << this->varsta;
		cout << endl << "Note:";
		for (int i = 0; i < this->nrNote; i++) {
			cout << this->note[i] << " ";
		}
	}

	void citesteDate() {
		cout << endl << "Nume:";
		cin >> this->nume;
		cout << endl << "Facultatea:";
		cin >> this->facultate;
		cout << endl << "Grupa: ";
		char buffer[1000];
		cin >> buffer;
		this->grupa = new char[strlen(buffer) + 1];
		strcpy(this->grupa, buffer);
		cout << endl << "Varsta :";
		cin >> this->varsta;
		cout << endl << "Numar note:";
		cin >> this->nrNote;
		this->note = new int[this->nrNote];
		for (int i = 0; i < this->nrNote; i++) {
			cout << endl << "Nota " << i + 1 << ": ";
			cin >> this->note[i];
		}
	}

	//functii accesor
	int getNrNote() {
		return this->nrNote;
	}

	//NU este ok - mai bine era vectorul public
	//int* getNote() {
	//	return this->note;
	//}
	int getNota(int index) {
		if(index >= 0 && index < this->nrNote)
			return note[index];
		else
		{
			//cout << endl << "Nota nu exista";
			//return -1;
			throw new exception("Index gresit");
		}
	}

	void setVarsta(int varsta) {
		if (varsta > 0)
			//shadowing
			//varsta = varsta;
			this->varsta = varsta;
		else
			throw new exception("Varsta gresita!");
	}
};

void main() {
	int vb;
	cout << endl << "Valoare este" << vb;

	Student student1;
	cout << endl << "Numele studentului este " << student1.nume;
	cout << endl << "Facultatea studentului este " << student1.facultate;

	student1.citesteDate();
	student1.infoStudent();
	cout << endl << student1.nume << " are " <<
		student1.getNrNote() << " note.";

	//int* pointerNote = student1.getNote();
	//pointerNote[0] = 99;
	cout << endl << " Prima nota este "
		//<< student1.getNote()[0];
		//<< pointerNote[0];
		<< student1.getNota(0);
	student1.infoStudent();
}
