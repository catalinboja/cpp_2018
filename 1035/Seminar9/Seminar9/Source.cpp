#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class  Contact {
public:
	string nume;
	char telefon[11];
	int varsta;

	Contact(string nume, const char* tel, int varsta) {
		this->nume = nume;
		this->varsta = varsta;
		strcpy(this->telefon, tel);
	}
};

ostream& operator<<(ostream& out, Contact& contact) {
	out << "Nume contact :" << contact.nume
		<< " cu varsta " << contact.varsta;
	out << endl << "Tel: " << contact.telefon << endl;
	return out;
}

int main() {
	Contact contact1("Gigel", "1234567890", 22);
	Contact contact2("Ana", "1111122333", 21);

	cout << contact1 << contact2;

	//salvam datele in fisier text
	fstream fisier("Contacte.txt", ios::out | ios::trunc);
	if (fisier.is_open()) {
		fisier << contact1 << contact2;

		fisier.close();
	}
	else
		cout << endl << "******** Nu gasesc fisierul *******";

	//citire date din fisierul text
	fisier.open("Contacte.txt", ios::in);
	if (fisier.is_open()) {

		char buffer[100];
		while (!fisier.getline(buffer, 100).eof()) {
			string linie(buffer);

			//fisier >> linie;	//nu merge 
			cout << endl << "Linie din fisier: " << linie;

			if (linie.find("contact",0)!= -1) {

				int locatieNume = linie.find(":", 0);
				if (locatieNume >= 0) {
					int contor = 0;
					for (contor = 0;
						linie[locatieNume + contor] != ' ';
						contor++);
					//extragem numele
					string nume = linie.substr(locatieNume + 1,
						contor);
					cout << endl << "Numele este :" << nume;
				}
			}

		}
		fisier.close();
	}
}