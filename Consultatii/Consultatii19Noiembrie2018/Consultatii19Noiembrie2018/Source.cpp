#include <iostream>
#include <string>

using namespace std;

//supraincarcare operatori
//constructori/destructor/constructor copiere
//constante
//statice

class MasinaElectrica {
public:
	static float PRET_KW;
	const int id;

	int capacitateAcumulator = 0;
	int nivelAcumulator = 0;
	float vitezaMaxima = 0;

	void info(int valoare) {
		cout << endl << "Viteza maxima este " << this->vitezaMaxima;
	}

	static void metodaStatica(int valoare) {
		cout << endl << " O metoda statica";
	}


public:

	MasinaElectrica():id(5) {

	}

	MasinaElectrica(int Id, float VitezaMaxima):id(Id),vitezaMaxima(VitezaMaxima) {

	}

	MasinaElectrica(const MasinaElectrica & masina):id(masina.id) {
		//masina->vitezaMaxima = 0;
		this->nivelAcumulator = masina.nivelAcumulator;
		this->vitezaMaxima = masina.vitezaMaxima;
		this->capacitateAcumulator = masina.capacitateAcumulator;
	}

	void operator+=(int valoare) {
		this->vitezaMaxima += valoare;
	}

	//void operator+=(MasinaElectrica& m, int valoare) {
	//	this->vitezaMaxima += valoare;
	//}

	//static void operator+=(MasinaElectrica& m, int valoare) {
	//	m.vitezaMaxima += valoare;
	//}
};



float MasinaElectrica::PRET_KW = 6.78;

void main() {

	cout << endl << "Pret KW:" <<  MasinaElectrica::PRET_KW;

	MasinaElectrica masina1;
	MasinaElectrica masina2(1, 100.0);

	MasinaElectrica::metodaStatica(99);
	masina2.info(99);

	//vectori de obiecte
	//MasinaElectrica lista[5];
	//MasinaElectrica *lista = new MasinaElectrica[5];

	MasinaElectrica *pointer;
	pointer = new MasinaElectrica(2,70);

	int nrMasini;
	cout << endl << "Care este numarul de masini ?";
	cin >> nrMasini;


	MasinaElectrica* lista[5];
	lista[0] = new MasinaElectrica(3, 50);

	MasinaElectrica* *lista2;
	lista2 = new MasinaElectrica* [nrMasini];
	lista2[0] = new MasinaElectrica(4, 50);

	MasinaElectrica masina3 = masina1;

	int vb1 = 10;
	int vb2 = 20;
	int vb3 = vb1 + vb2; //int operator+(int a, int b)
	if (!vb1)		//boolean operator!(int valoare)
		cout << endl << "Este 0";
	vb2 += 5;	//void operator+=(int&, int)
	vb3 = vb2 += 6; //int operator+=(int&, int)
	if (vb1 > vb2)		//boolean operator>(int, int)
		cout << endl << "Vb1 este mai mare";

	masina1 += 56;		//creste viteza maxima
	//masina1.operator+=(56)

	//masina2 = 5 + masina1; // operator+(int, masina)
	//masina2 = masina1 + 5;

}