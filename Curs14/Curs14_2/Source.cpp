#include <iostream>
#include <string>
#include <vector>

using namespace std;

int aduna(int a, int b) {
	return a + b;
}

float adunaFloat(float a, float b) {
	return a + b;
}

//template <typename X, typename Y, typename Z>
//Z adunaOrice(X a,Y b, int vb) {
//	X rezTemp;
//	return a + b;
//}

template <typename T>
T adunaOrice(T a, T b) {
	return a + b;
}


class Student {

};

class Frigider {

};

class Floare {

};


class Cutie {
public:
	float greutate;
	void* continut;
};

template<typename T, typename R>
class CutieGenerica {
public:
	float greutate;
	T continut;
	R culoare;

	R getCuloare() {
		return this->culoare;
	}

	void setCuloare(R valoare) {
		this->culoare = valoare;
	}

	bool compara(CutieGenerica &cutie) {
		if (this->continut > cutie.continut)
			return true;
		else
			false;
	}
};

//specializarea metodei compara pentru char*
template<>
bool CutieGenerica<char*, string>::compara(CutieGenerica<char*, string> &cutie) {
	if (strcmp(this->continut, cutie.continut) == 1)
		return true;
	else
		false;
}

void main() {
	int vb1 = 10;
	int vb2 = 20;
	int rez = aduna(vb1, vb2);

	cout << endl << "Suma este " << rez;

	int rez2 = adunaOrice<int>(vb1, vb2);

	cout << endl << "Suma este " << rez2;

	float f1 = 2.3;
	float f2 = 3.4;
	float rez3 = adunaOrice<float>(f1, f2);

	cout << endl << "Suma este " << rez3;

	string nume1 = "Popescu ";
	string nume2 = "Gigel";
	string final = adunaOrice<string>(nume1, nume2);
	cout << endl << "Numele este " << final;

	Floare floare;
	Frigider frigider;
	Student student;

	Cutie cutie;
	cutie.continut = &floare;
	cutie.continut = &frigider;

	Cutie cutieCuFlori;
	//cutieCuFlori.continut = &frigider;
	//Floare* floareNoua = (Floare*)cutieCuFlori.continut;

	CutieGenerica<Floare*, string> cutieFlori;
	//cutieFlori.continut = &frigider;
	cutieFlori.continut = &floare;


	CutieGenerica<Frigider*, string> cutieFrigider;
	cutieFrigider.continut = &frigider;

	CutieGenerica<char*, string> cutieScrisoare;


	Student *listaStudenti;
	listaStudenti = new Student[4];

	vector<Student> studenti;
	Student stundent1;
	Student stundent2;
	studenti.push_back(stundent1);
	studenti.push_back(stundent2);
}