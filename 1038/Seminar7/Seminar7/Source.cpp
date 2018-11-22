#include <iostream>
#include <string>

using namespace std;

class Curier {
	const int id;
	string nume;
	int kmParcursi;
	string* traseu;
	int nrLocatii;

public:
	Curier(int Id, string Nume):id(Id), kmParcursi(0) {
		this->nume = Nume;
		this->traseu = NULL;
		this->nrLocatii = 0;
	}

	Curier(int Id, string Nume, string* Traseu, int nrAdrese):id(Id) {
		this->kmParcursi = 0;
		this->nrLocatii = nrAdrese;
		this->nume = Nume;
		
		this->traseu = new string[nrAdrese];
		for (int i = 0; i < nrAdrese; i++) {
			this->traseu[i] = Traseu[i];
		}

	}

	Curier(Curier& curier):id(curier.id) {
		this->nume = curier.nume;
		this->kmParcursi = curier.kmParcursi;
		this->traseu = new string[curier.nrLocatii];
		for (int i = 0; i < curier.nrLocatii; i++)
			this->traseu[i] = curier.traseu[i];
		this->nrLocatii = curier.nrLocatii;
	}

	~Curier() {
		if (this->traseu != NULL)
			delete[] this->traseu;
	}

	void operator=(Curier curier) {
		this->nume = curier.nume;
		this->kmParcursi = curier.kmParcursi;
		this->nrLocatii = curier.nrLocatii;
		//this->id = curier.id;

		if (this->traseu != NULL)
			delete[] this->traseu;

		this->traseu = new string[curier.nrLocatii];
		for (int i = 0; i < curier.nrLocatii; i++)
			this->traseu[i] = curier.traseu[i];

	}

	void adaugaLocatie(string locatie) {
		string* traseuNou = new string[this->nrLocatii + 1];
		for (int i = 0; i < this->nrLocatii; i++)
			traseuNou[i] = this->traseu[i];

		if (this->traseu != NULL)
			delete[] this->traseu;

		traseuNou[this->nrLocatii] = locatie;

		this->traseu = traseuNou;

		this->nrLocatii += 1;
	}

	friend ostream& operator<<(ostream& out, Curier& curier);
	friend void operator>>(istream& in, Curier& curier);
};

ostream& operator<<(ostream& out, Curier& curier) {
	out << endl << "Id curier: " << curier.id;
	out << endl << "Nume curier: " << curier.nume;
	out << endl << "KM: " << curier.kmParcursi;
	if (curier.traseu != NULL) {
		out << endl << "Traseu: ";
		for (int i = 0; i < curier.nrLocatii; i++)
			out << " -> " << curier.traseu[i];
	}
	return out;
}

void operator>>(istream& in, Curier& curier) {
	cout << endl << "Noul nume: ";
	in >> curier.nume;
	cout << endl << "Km parcursi: ";
	in >> curier.kmParcursi;

	cout << endl << "Numar locatii de adaugat: ";
	int nr;
	in >> nr;

	for (int i = 0; i < nr; i++) {
		string locatie;
		cout << endl << "Locatie de adaugat:";
		in >> locatie;
		curier.adaugaLocatie(locatie);
	}
}

void main() {

	Curier curier1(1,"Gigel");
	string traseu[] = { "Bucuresti", "Ploiesti", "Brasov" };
	Curier curier2(2, "Ion", traseu, 3);

	Curier curier3 = curier1;

	curier3 = curier2;

	//curier3 = curier2 + "Sibiu";

	cout << curier1 << curier2 << curier3;

	cin >> curier3;

	cout << curier3;
}