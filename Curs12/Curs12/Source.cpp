#include <iostream>
#include <string>

using namespace std;

class ProdusAbstract {
	virtual void getPret() = 0;
};

class Produs: public ProdusAbstract {
protected:
	string denumire;
	float pret;

public:

	void getPret() {

	}

	Produs(string denumire, float pret = 0) {
		this->denumire = denumire;
		this->pret = pret;
	}

	Produs() {
		this->denumire = "";
		this->pret = 0;
	}

	virtual void printDescriere() {
		cout << endl << "***********Produs*********";
		cout << endl << this->denumire << " cu pretul " << this->pret;

	}
};

class ProdusLaPromotie: public Produs {
	float discount;

	ProdusLaPromotie(): Produs("",0) {
		this->discount = 0;
	}
public:
	ProdusLaPromotie(string denumire, float pret, float discount)
		:Produs(denumire, pret) {
		this->discount = discount;
	}


	//supra-definire
	void printDescriere() {

		this->Produs::printDescriere();

		//cout << endl << "***********Produs in promotie*********";
		// << endl << this->denumire << " cu pretul " << this->pret;
		cout << endl << "MEGA discount de " << this->discount << " % ";
	}

};

int main() {
	Produs p1("Jucarie", 100);
	Produs p2("Smartphone", 2389);

	p1.printDescriere();
	p2.printDescriere();

	ProdusLaPromotie promotie1("Masina teleghidata",230, 25);
	ProdusLaPromotie promotie2("Papusa", 85, 30);

	promotie1.printDescriere();
	promotie2.printDescriere();

	//up-casting
	//p1 = promotie1;

	//down-casting
	//promotie2 = p2;

	cout << endl << "*********************************************";

	Produs produse[4];
	produse[0] = p1;
	produse[1] = p2;
	produse[2] = promotie1;
	produse[3] = promotie2;

	for (int i = 0; i < 4; i++) {
		produse[i].printDescriere();
	}

	cout << endl << "*********************************************";

	Produs* pProduse[4];
	pProduse[0] = &p1;
	pProduse[1] = &p2;
	pProduse[2] = &promotie1;
	pProduse[3] = &promotie2;

	for (int i = 0; i < 4; i++) {
		pProduse[i]->printDescriere();
	}

	//ProdusAbstract pa;
}