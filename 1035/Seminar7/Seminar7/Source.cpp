#include <iostream>
#include <string>

using namespace std;

class Curier {
	const int id;
	string nume = "Anonim";
	string* adrese = NULL;
	int nrLocatii = 0;
public:
	Curier(int Id, string nume):id(Id) {
		this->nume = nume;
	}

	Curier(int ceva): id(100){
		//this->id = 100;
	}

	Curier(int Id, string nume, string* traseu, int nrLocatii):id(Id) {
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

	Curier(const Curier& existent):id(existent.id) {
		//existent.nume = this->nume;
		this->nume = existent.nume;
		this->nrLocatii = existent.nrLocatii;
		//shallow copy
		//this->adrese = existent.adrese;
		this->adrese = new string[this->nrLocatii];
		for (int i = 0; i < this->nrLocatii; i++)
			this->adrese[i] = existent.adrese[i];
	}
};

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

	char* pointer = (char*)&curier3;
	int* pointerInt = (int*)pointer;
	*pointerInt = 99;
	cout << endl << "ID Ana  = " << *pointerInt;
	curier3.afisare();

	//apel explicit constructor copiere
	Curier curier4 = curier3;

	//curier1 = curier2 = curier3; //Curier operator=(Curier, Curier)
	//curier2 = curier4;	//void operator=(Curier, Curier) //curier2.operator=(curier4) 
	//curier4 += "Tulcea"; //void operator+=(Curier, string) //curier4.operator+=(string)
	//if (curier4 > curier3) //bool operator>(Curier, Curier)
	//{
	//	cout << endl << "Curier 4 are traseul mai lung";
	//}
}


