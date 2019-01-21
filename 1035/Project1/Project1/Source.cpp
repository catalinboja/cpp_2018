#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Student {
public:
	int cod;
	string nume;

	Student(string nume = "Anonim", int cod = 0) {
		this->nume = nume;
		this->cod = cod;
	}
};

void main() {
	//Student studenti[5];
	Student * studenti;
	studenti = new Student[5];

	vector<Student> listaStudenti;
	listaStudenti.push_back(Student("Gigel", 1));
	listaStudenti.push_back(Student("Ana", 2));
	listaStudenti.push_back(Student("Ana", 2));
	listaStudenti.insert(
		listaStudenti.begin(), Student("Ionel", 3));

	for (int i = 0; i < listaStudenti.size(); i++)
		cout << endl << listaStudenti[i].nume;

	set<string> numeStudenti;
	numeStudenti.insert("Gigel");
	numeStudenti.insert("Gigel");
	numeStudenti.insert("Ana");
	numeStudenti.insert("Ionel");

	set<string>::iterator it;
	for (it = numeStudenti.begin(); it != numeStudenti.end(); it++)
		cout << endl << "Nume: " << *it;

}