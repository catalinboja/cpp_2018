#include <iostream>
#include <string>

using namespace std;

//function for getting the assignment topic - call it and pass your full name, without spaces
//functie pentru a determina subiectul temei - apeleaz-o si trimite numele tau intreg fara spatii

string getHomeworkTopic(string studentName, bool isEnglishClass) {

	const int noWords = 29;

	string words[] = { "employee","basket","pollution",
	"coffee","potato","orange",
	"cabinet","presentation","exam",
	"pizza","budget","problem","player",
	"refrigerator","organization (NGO)",
	"manufacturer","newspaper","insurance",
	"map","maintenance","preference","homework",
	"ad","road sign","concert hall","story","pen",
	"bottle","keyboard" };

	string cuvinte[] = { "angajat", "cos", "poluare",
"cafea", "cartof", "portocala",
"cabinet", "prezentare", "examen",
"pizza", "buget", "problema", "jucator",
"frigider", "organizatie (ONG)",
"producator", "ziar", "asigurare",
"harta", "intretinere", "preferinta", "temele",
"reclama", "semn rutier", "sala de concerte", "poveste", "stilou",
"sticla", "tastatura" };

	int index = 0;
	for (int i = 0; i < studentName.length(); i++) {
		index += studentName[i];
	}
	index = index % noWords;

	if (isEnglishClass)
		return words[index];
	else
		return cuvinte[index];
}

void main() {
	string topic = getHomeworkTopic("CatalinBoja", false);
	cout << endl << "Your project is " << topic;
}