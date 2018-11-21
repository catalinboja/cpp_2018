#include <iostream>
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

	Curier(int ceva) : id(100) {
		//this->id = 100;
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

	void afisare() {
		cout << endl << this->id << " - " << this->nume;
		cout << endl << "Traseu curier:";
		for (int i = 0; i < this->nrLocatii; i++)
			cout << " -> " << this->adrese[i];
	}

	//destructor
	~Curier() {
		cout << endl << "Apel destructor !";
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
		//curier.nrLocatii = this->nrLocatii;

		//existent.nume = this->nume;
		this->nume = curier.nume;
		this->nrLocatii = curier.nrLocatii;

		//shallow copy
		//this->adrese = existent.adrese;

		//evitam memory leak
		if (this->adrese != NULL)
			delete[]  this->adrese;
		this->adrese = new string[this->nrLocatii];
		for (int i = 0; i < this->nrLocatii; i++)
			this->adrese[i] = curier.adrese[i];
	}


	void setNume(string nume) {
		this->nume = nume;
	}

	//adauga o noua adresa
	Curier operator+(string adresa) {
		//GRESIT
		//this->adaugaAdresa(adresa);

		Curier rezultat = *this;
		rezultat.adaugaAdresa(adresa);
		return rezultat;
	}

	//la fel pt ==, <, >=, <=
	bool operator>(Curier curier) {
		if (this->nrLocatii > curier.nrLocatii)
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

	string& operator[](int index) {
		if (index >= 0 && index < this->nrLocatii)
			return this->adrese[index];
		else
			throw new exception("Index gresit");
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

void operator>>(istream& in, Curier& curier) {
	cout << "Noul nume: ";
	string nume;
	in >> nume;
	curier.setNume(nume);
	string nouaAdresa;
	cout << endl << "Adresa de adaugat: ";
	in >> nouaAdresa;
	curier.adaugaAdresa(nouaAdresa);
}

Curier operator+(string adresa, Curier curier) {
	return curier + adresa;
}

int main() {
	Curier curier1(1, "Gigel");
	Curier curier2(2, "Ion");

	curier1.adaugaAdresa("Brasov");
	curier1.adaugaAdresa("Sibiu");
	curier1.adaugaAdresa("Cluj");

	curier1.afisare();

	string traseu[] = { "Constanta","Mangalia", "Vama Veche" };
	Curier curier3(3, "Ana", traseu, 3);
	curier3.adaugaAdresa("Bucuresti");

	curier3.afisare();


	//modificarea camp constat si privat
	char* pointer = (char*)&curier3;
	int* pointerInt = (int*)pointer;
	*pointerInt = 99;
	cout << endl << "ID Ana  = " << *pointerInt;
	curier3.afisare();

	//apel explicit constructor copiere
	Curier curier4 = curier3;

	curier1 = curier4;		//void operator=(Curier&, Curier)
							//curier1.operator=(curier4)

	cout << endl << "*************************";
	curier1.afisare();

	cout << curier1 << curier2;	// ostream& operator<<(ostream&, Curier)
	cin >> curier1;		//operator>>(istream&, Curier&)
	cout << curier1;

	curier2 = curier1 + "Iasi";	//operator+(Curier, string)
	curier2 = "Botosani" + curier1;	//operator+(string, Curier)

	//cout << curier2;

	if (curier2 > curier1) {	//bool operator>(Curier, Curier)
		cout << endl << "Curier2 are traseul mai lung";
	}

	if (!curier2) {		//bool operator!(Curier)
		cout << endl << "Curierul 2 nu are traseu";
	}

	int lungimeTraseu = (int)curier2;		//operator int(Curier)

	curier2[1] = "Paris";
	cout << endl << "A 2-a destinatie este " << curier2[1];		//operator[](Curier, int)

	//curier1 = curier2 = curier3; //Curier operator=(Curier, Curier)
	//curier2 = curier4;	//void operator=(Curier, Curier) //curier2.operator=(curier4) 
	//curier4 += "Tulcea"; //void operator+=(Curier, string) //curier4.operator+=(string)
	//if (curier4 > curier3) //bool operator>(Curier, Curier)
	//{
	//	cout << endl << "Curier 4 are traseul mai lung";
	//}
}
