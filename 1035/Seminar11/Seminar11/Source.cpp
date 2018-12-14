#include <iostream>
#include <string>

using namespace std;

class Produs {
protected:
	string denumire;
	float pret;
	bool esteSigurPentruCopii;
private:
	Produs() {
		cout << endl << "Constructor default Produs";
		denumire = "";
		pret = 0;
		esteSigurPentruCopii = false;
	}
public:
	Produs(string denumire, float pret = 0, bool esteSigur = false) {
		cout << endl << "Constructor cu argumente Produs";
		this->denumire = denumire;
		this->pret = pret;
		this->esteSigurPentruCopii = esteSigur;
	}

	string getDescriere() {
		string descriere = "\n Produsul " + this->denumire
			+ " are pretul " + to_string(this->pret) + "\n";
		if (this->esteSigurPentruCopii)
			descriere += "Recomandat pentru toate varstele";
		else
			descriere += "Nerecomandat copiilor mici (sub 3 ani)";
		return descriere;
	}

	~Produs() {
		cout << endl << "apel destructor Produs";
	}
};

class ProdusCuDiscount: public Produs {
private:
	float procentDiscount;
	int cantitateMaxima;
public:
	ProdusCuDiscount(): Produs("Nimic") {
		cout << endl << "Constructor default ProdusCuDiscount";
		this->procentDiscount = 0;
		this->cantitateMaxima = 1;
	}

	ProdusCuDiscount(
		string denumire, float pret,
		float discount, int cantitate)
		: Produs(denumire,pret,false) {
		//this->denumire = denumire;
		//this->pret = pret;
		//this->esteSigurPentruCopii = false;
		this->procentDiscount = discount;
		this->cantitateMaxima = cantitate;
	}

	//string getDescriereCuDiscount() {
	//	string descriere = this->getDescriere();
	//	descriere += "Discount de " +
	//		to_string(this->procentDiscount) + "% \n";
	//	descriere += "Cantitate maxima " +
	//		to_string(this->cantitateMaxima) + "\n";
	//	return descriere;
	//}

	//supradefinire
	string getDescriere() {
		string descriere = this->Produs::getDescriere();
		descriere += "Discount de " +
			to_string(this->procentDiscount) + "% \n";
		descriere += "Cantitate maxima " +
			to_string(this->cantitateMaxima) + "\n";
		return descriere;
	}

	~ProdusCuDiscount() {
		cout << endl << "apel destructor ProdusCuDiscount";
	}
};


int main() {
	//Produs p1;
	//cout << p1.getDescriere();

	Produs p2("Minge mare", 35, true);
	Produs p3("Drona", 100);
	Produs p4("Minge promo");

	cout << p2.getDescriere();
	cout << p3.getDescriere();
	cout << p4.getDescriere();

	cout << endl << "***********************";
	ProdusCuDiscount pd1;
	cout << pd1.getDescriere();
	ProdusCuDiscount pd2("Tableta", 999, 10, 1);
	cout << pd2.getDescriere();
	//cout << pd1.getDescriereCuDiscount();

}