#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Contact {
public:
	string nume;
	char telefon[11];
	int varsta;
public:
	Contact(string Nume, const char* Telefon, int Varsta) {
		nume = Nume;
		strcpy(telefon, Telefon);
		varsta = Varsta;
	}

	friend ostream& operator<<(ostream& out, Contact& contact);
};

ostream& operator<<(ostream& out, Contact& contact) {
	out << endl << "Numele: " << contact.nume
		<< ", varsta" << contact.varsta;
	out << endl << "Telefon: " << contact.telefon;
	return out;
}

void main() {
	Contact contact1("Gigel", "1234567890", 22);
	Contact contact2("Ana", "1111122333", 21);

	cout << contact1 << contact2;

	unsigned char byte = 136;
	byte = 1 << 7 | 1 << 3;

	//fstream fisier;
	//fisier.open("Contacte.txt", ios::out | ios::app);

	fstream fisier("Contacte.txt", ios::out | ios::trunc);
	//verificati daca fisierul s-a deschis
	if (fisier.is_open()) {
		cout << endl << "Acesta este un mesaj";
		fisier << "Lista mea de contacte" << endl;

		fisier << contact1 << contact2;

		fisier.close();
	}
	else
	{
		cout << endl << "Avem o problema cu fisierul";
	}

	//fisiere binare
	fstream fisierBinar("Contacte.bin", ios::out
		| ios::binary | ios::trunc);
	if (fisierBinar.is_open()) {
		//NU ASA
		//fisierBinar << "Lista mea de contacte" << endl;
		//fisierBinar << contact1 << contact2;

		fisierBinar.write(contact1.nume.data(), 
			contact1.nume.length());
		fisierBinar.write((char*)&contact1.varsta,
			sizeof(int));
		fisierBinar.write(contact1.telefon,
			strlen(contact1.telefon));



		fisierBinar.close();
	}


}