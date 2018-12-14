#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Curier {
	int id;
	string nume = "Anonim";
	string* adrese = NULL;
	int nrLocatii = 0;

public:

	Curier(int Id, string nume) :id(Id) {
		this->nume = nume;
	}

	Curier(int Id, string nume, string* traseu, int nrLocatii) :id(Id) {

		this->nume = nume;
		this->nrLocatii = nrLocatii;
		//shallow copy
		//this->adrese = traseu;
		this->adrese = new string[this->nrLocatii];
		for (int i = 0; i < this->nrLocatii; i++)
			this->adrese[i] = traseu[i];
	}

	void adaugaAdresa(string adresa) {
		string* listaNoua = new string[this->nrLocatii + 1];
		for (int i = 0; i < this->nrLocatii; i++)
			listaNoua[i] = this->adrese[i];

		listaNoua[this->nrLocatii] = adresa;

		delete[] this->adrese;

		this->adrese = listaNoua;

		this->nrLocatii += 1;

	}

	//destructor
	~Curier() {
		delete[] this->adrese;
	}


	Curier(const Curier& existent) :id(existent.id) {
		//existent.nume = this->nume;

		this->nume = existent.nume;

		this->nrLocatii = existent.nrLocatii;

		//shallow copy

		//this->adrese = existent.adrese;

		this->adrese = new string[this->nrLocatii];

		for (int i = 0; i < this->nrLocatii; i++)

			this->adrese[i] = existent.adrese[i];

	}



	//operator =

	void operator=(const Curier& curier) {
		this->nume = curier.nume;
		this->nrLocatii = curier.nrLocatii;

		//evitam memory leak
		if (this->adrese != NULL)
			delete[]  this->adrese;
		this->adrese = new string[this->nrLocatii];
		for (int i = 0; i < this->nrLocatii; i++)
			this->adrese[i] = curier.adrese[i];
	}

	//functie care serializeaza obiectul
	void serializareObiect(fstream& fisier) {
		if (fisier.is_open()) {
			//serializam obiectul
			//scriu id-ul
			fisier.write((char*)&this->id, sizeof(int));
			//scriem numele
			//adaugam dimensiunea numelui + '\0'
			int dimNume = this->nume.length() + 1;
			fisier.write((char*)&dimNume, sizeof(int));
			fisier.write(this->nume.data(), dimNume * sizeof(char));
			//scriu numarul de locatii
			fisier.write((char*)&this->nrLocatii, sizeof(int));
			for (int i = 0; i < this->nrLocatii; i++) {
				int dim = this->adrese[i].length() + 1;
				fisier.write((char*)&dim, sizeof(int));
				fisier.write(this->adrese[i].data(), dim * sizeof(char));
			}
		}
		else
			throw new exception();
	}

	static void salvareListaCurieri(string numeFisier, Curier** curieri, int nrCurieri) {
		fstream fisier(numeFisier, ios::out | ios::binary | ios::trunc);
		if (fisier.is_open()) {
			//scriem numarul de curieri
			fisier.write((char*)&nrCurieri, sizeof(int));
			for (int i = 0; i < nrCurieri; i++)
				curieri[i]->serializareObiect(fisier);
			fisier.close();
		}
		else
			throw new exception();
	}

	static Curier** incarcaDate(string numeFisier, int& nrCurieri) {
		fstream fisier(numeFisier, ios::in | ios::binary);
		if (fisier.is_open()) {
			//citim numarul de curieri
			fisier.read((char*)&nrCurieri, sizeof(int));

			//definim vectorul
			Curier** lista = new Curier*[nrCurieri];

			//citim datele fiecarui curier
			for (int i = 0; i < nrCurieri; i++) {
				int id;
				fisier.read((char*)&id, sizeof(int));
				int dim;
				fisier.read((char*)&dim, sizeof(int));
				char buffer[100];
				fisier.read(buffer, dim);
				string nume(buffer);
				lista[i] = new Curier(id, nume);
				int nrLocatii;
				fisier.read((char*)&nrLocatii, sizeof(int));
				for (int j = 0; j < nrLocatii; j++) {
					int dim;
					fisier.read((char*)&dim, sizeof(int));
					char buffer[100];
					fisier.read(buffer, dim);
					string locatie(buffer);
					lista[i]->adaugaAdresa(locatie);
				}
			}
			fisier.close();
			return lista;
		}
	}

	friend ostream& operator<<(ostream& out, Curier& curier);
};

ostream& operator<<(ostream& out, Curier& curier) {
	out << endl << "Numele curierului: " << curier.nume;
	out << endl << "Id curier: " << curier.id;
	out << endl << "Traseu curier:";
	for (int i = 0; i < curier.nrLocatii; i++)
		out << " -> " << curier.adrese[i];
	return out;
}


int main() {
	//Curier c1(1, "Gigel");
	//Curier curieri[5];
	//Curier *pCurieri = new Curier[5];

	int nrCurieri = 2;
	Curier* *curieri;
	curieri = new Curier*[nrCurieri];

	curieri[0] = new Curier(1, "Gigel");
	curieri[1] = new Curier(2, "Ana");

	curieri[0]->adaugaAdresa("Bucuresti");
	curieri[0]->adaugaAdresa("Ploiesti");
	curieri[0]->adaugaAdresa("Brasov");

	curieri[1]->adaugaAdresa("Bucuresti");
	curieri[1]->adaugaAdresa("Constanta");

	for (int i = 0; i < nrCurieri; i++)
		cout << endl << *curieri[i];

	//salvare date curieri in fisier binar
	Curier::salvareListaCurieri("Curieri.dat", curieri, nrCurieri);


	//citire date fisier binar intr-o lista noua
	cout << endl << "*********************";
	int nrCurieri2;
	Curier** listaNoua = Curier::incarcaDate("Curieri.dat", nrCurieri2);
	for (int i = 0; i < nrCurieri2; i++)
		cout << endl << *listaNoua[i];
}