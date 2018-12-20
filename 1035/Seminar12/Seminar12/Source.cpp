#include <iostream>
#include <string>

using namespace std;


class Cont {
public:
	virtual void Depune(double suma) = 0;
	virtual void Extrage(double suma) = 0;
	virtual void Transfer(double suma, Cont* destinatie) = 0;
	virtual double getSold() = 0;
	virtual void getTip() {
		cout << endl << "CONT Generic !";
	}
};

class FonduriInsuficienteException: public exception {

};

class TransferIlegalException : public exception {
public:
	TransferIlegalException(string mesaj): exception(mesaj.data()) {
	}
};

class ContBancar: public Cont {
protected:
	string iban;
	double sold;
public:
	double getSold() {
		return this->sold;
	}

	void Depune(double suma) {
		if (suma > 0)
			this->sold += suma;
		else
			throw new TransferIlegalException("Incerci sa depui 0 lei sau <0");
	}
};


class ContCredit : public ContBancar {
	static double MAX_CREDIT;
public:
	ContCredit(string IBAN) {
		this->iban = IBAN;
		this->sold = ContCredit::MAX_CREDIT;
	}
	void Extrage(double suma) {
		if (suma <= 0)
			throw new TransferIlegalException("Suma <= 0");
		if (this->sold - suma < 0)
			throw new FonduriInsuficienteException();
		this->sold -= suma;
	}

	void Transfer(double suma, Cont* destinatie) {
		if (this == destinatie)
			throw new TransferIlegalException("Acelasi cont");
		this->Extrage(suma);
		destinatie->Depune(suma);
	}

	void getTip() {
		cout << endl << "Linie de CREDIT !";
	}
};

double ContCredit::MAX_CREDIT = 10000;

class ContDepozit : public ContBancar {
	static double SUMA_MINIMA;
public:
	ContDepozit(string IBAN, double suma){
		if (suma < ContDepozit::SUMA_MINIMA)
			throw new TransferIlegalException("Suma insuficienta");
		this->sold = 0;
		this->Depune(suma);
		this->iban = IBAN;
	}

	void Extrage(double suma) {
		if (suma <= 0)
			throw new TransferIlegalException("Suma <= 0");
		if (this->sold - suma < ContDepozit::SUMA_MINIMA)
			throw new FonduriInsuficienteException();
		this->sold -= suma;
	}

	void Transfer(double suma, Cont* destinatie) {
		if (this == destinatie)
			throw new TransferIlegalException("Acelasi cont");
		this->Extrage(suma);
		destinatie->Depune(suma);
	}

	void getTip() {
		cout << endl << "DEPOZIT !";
	}

};

double ContDepozit::SUMA_MINIMA = 100;


void main() {
	//Cont cont;
	//utilizare clasa abstracta ca tip pointer/referinta
	Cont* pCont;

	//ContBancar contBancar;

	ContCredit credit1("MyBank01");
	ContCredit credit2("MyBank02");

	ContDepozit depozit1("Banca0001", 3000);
	ContDepozit depozit2("Banca0002", 560);

	credit2.Transfer(500, &depozit2);

	cout << endl << "Valoare credit " << credit2.getSold();
	cout << endl << "Valoare depozit " << depozit2.getSold();

	Cont* conturi[4];
	conturi[0] = &credit1;
	conturi[1] = &depozit1;
	conturi[2] = &credit2;
	conturi[3] = &depozit2;

	for (int i = 0; i < 4; i++)
		conturi[i]->getTip();

}