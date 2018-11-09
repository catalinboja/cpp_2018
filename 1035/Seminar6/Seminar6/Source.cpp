#include <iostream>
#include <string>
using namespace std;

class Produs {
public:
	string denumire = "Nedefinit";
	float pret = 0;
	const int ID;
	const int ceva;

private:
	int stoc = 0;
	int volumVanzariZilnice[365];

	static int contor;
	static int ziuaCurenta;
	static int STOC_MAXIM;
public:

	//constructor implicit
	//constructor fara parametri
	Produs():ID(Produs::contor),ceva(0){
		//this->ID = 0; //este prea tarziu
		Produs::contor++;
	}

	//constructor cu parametri
	Produs(string denumire, 
		float pret, int stoc) :ID(Produs::contor), ceva(0) {
		this->denumire = denumire;
		this->stoc = stoc;
		this->pret = pret;
		Produs::contor++;
	}

	void printInfo() {
		cout << endl << this->ID << "\t"<< this->denumire
			<< "\t " << this->pret << " RON \t " << this->stoc;
		cout << endl << "Vanzari pana in prezent:";
		for (int i = 0; i < Produs::ziuaCurenta; i++)
			cout << this->volumVanzariZilnice[i] << " ";
	}

	//functii accesor
	int getVanzariZilnice(int ziua) {
		if (ziua >= 0 && ziua < 365) {
			return this->volumVanzariZilnice[ziua];
		}
		else
			throw new exception("Ziua nu exista");
	}

	void setVanzariAzi(int volum) {
		if (volum > 0 && volum <= this->stoc) {
			this->volumVanzariZilnice[Produs::ziuaCurenta] =
				volum;
			this->stoc -= volum;
		}
		else
			throw new exception("Valoare gresita");
	}

	void setStoc(int valoare) {
		if (valoare > 0 && valoare <= Produs::STOC_MAXIM) {
			this->stoc = valoare;
		}
		else
			throw new exception("Valoare gresita");
	}

	static void trecemLaZiuaUrmatoare() {
		Produs::ziuaCurenta += 1;
	}
};

int Produs::STOC_MAXIM = 100;
int Produs::ziuaCurenta = 0;
int Produs::contor = 0;

void main() {
	//Produs produs;
	Produs produs("Smartphone", 1500, 100);

	//Produs *refProdus = new Produs();
	Produs *refProdus = new Produs("Laptop", 3500, 30);

	//produs.setStoc(60);
	//refProdus->setStoc(60);


	produs.setVanzariAzi(23);
	refProdus->setVanzariAzi(10);

	Produs::trecemLaZiuaUrmatoare();

	produs.printInfo();
	refProdus->printInfo();

	Produs produse[20];
	Produs *listaProduse = new Produs[10];
}
