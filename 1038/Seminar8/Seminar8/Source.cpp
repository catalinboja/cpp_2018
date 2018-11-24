#include <iostream>
#include <string>

using namespace std;

class Curier {
	const int id;
	string nume;
	int kmParcursi;
	string* traseu;
	int nrLocatii;
	char* nrInmatriculare;

public:
	Curier(int Id, string Nume) :id(Id), kmParcursi(0) {
		this->nume = Nume;
		this->traseu = NULL;
		this->nrLocatii = 0;
		this->nrInmatriculare = NULL;
	}

	Curier(int Id, string Nume, string* Traseu, int nrAdrese) :id(Id) {
		this->kmParcursi = 0;
		this->nrLocatii = nrAdrese;
		this->nume = Nume;

		this->traseu = new string[nrAdrese];
		for (int i = 0; i < nrAdrese; i++) {
			this->traseu[i] = Traseu[i];
		}
	}

	Curier(int Id, string Nume, const char* nrInmatriculare):id(Id) {
		this->nume = Nume;
		this->nrInmatriculare = new char[strlen(nrInmatriculare) + 1];
		strcpy(this->nrInmatriculare, nrInmatriculare);
		this->traseu = NULL;
		this->nrLocatii = 0;
	}

	void setNumarAuto(const char* nrAuto) {
		if (this->nrInmatriculare != NULL)
			delete[] this->nrInmatriculare;
		this->nrInmatriculare = new char[strlen(nrAuto) + 1];
		strcpy(this->nrInmatriculare, nrAuto);
	}

	Curier(const Curier& curier) :id(curier.id) {
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

	Curier operator+(string oras) {
		Curier copie = *this;
		copie.adaugaLocatie(oras);
		return copie;
	}

	void adaugaKm(int valoare) {
		this->kmParcursi += valoare;
	}

	bool operator>(Curier curier) {
		if (this->nrLocatii > curier.nrLocatii)
			return true;
		else
			return false;
	}

	bool operator==(Curier curier) {
		if (this->nume.compare(curier.nume) == 0)
			return true;
		else
			return false;
	}

	bool operator!() {
		if (this->nrLocatii == 0)
			return true;
		else
			return false;
	}

	explicit operator int() {
		return this->nrLocatii;
	}

	bool operator()(string oras) {
		bool trecePrinOras = false;
		for (int i = 0; i < this->nrLocatii; i++) {
			if (this->traseu[i].compare(oras) == 0) {
				trecePrinOras = true;
				break;
			}
		}
		return trecePrinOras;
	}

	string& operator[](int index) {
		if (index >= 0 && index < this->nrLocatii)
			return this->traseu[index];
		else
			throw new exception("Index gresit");
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

Curier operator+(int valoare, Curier curier) {
	Curier copie = curier;
	copie.adaugaKm(valoare);
	return copie;
}

void operator+=(Curier& curier, int valoare) {
	curier.adaugaKm(valoare);
}

void main() {

	Curier curier1(1, "Gigel");
	string traseu[] = { "Bucuresti", "Ploiesti", "Brasov" };
	Curier curier2(2, "Ion", traseu, 3);

	Curier curier3 = curier1;

	curier3 = curier2;

	//curier3 = curier2 + "Sibiu";

	cout << curier1 << curier2 << curier3;

	cin >> curier3;

	cout << curier3;

	curier2 = curier3 + "Oradea";
	//curier2 = 100 + curier3;
	curier2 += 50;

	cout << endl << "************ dupa + **********";
	cout << curier2 << curier3;

	cout << endl << "************ comparatie ******";

	if (curier2 > curier3) {
		cout << endl << "Curier 2 are un traseu mai lung";
	}

	if (curier2 == curier3) {
		cout << endl << "Curierii au acelasi nume";
	}

	Curier curier4(4, "Alina", "b23bit");
	if (!curier4)
		cout << endl << "Curierul nu are traseu";

	int nrOrase = (int)curier2;		//operator int
	cout << endl << "Numar orase: " << nrOrase;

	bool trecePrinSuceava = curier2("Suceava");
	if (trecePrinSuceava)
		cout << endl << "Curierul trece prin Suceava";

	string primulOras = curier2[0];
	cout << endl << "Primul oras din traseu este " << primulOras;

	curier2[0] = "Giurgiu";
	cout << curier2;
;}