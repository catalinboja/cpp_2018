#include <iostream>
#include <string>

using namespace std;

namespace Ceva {
	void nimic() {

	}
}

namespace Altceva {
	int vb1;
	class Test {

	};
	void nimic() {

	}
}

class ExceptieANegativ : public exception {

};

class ExceptieBNegativ : public exception {
public:
	ExceptieBNegativ(string mesaj) :exception(mesaj.data()) {

	}
};
int sumaNumerePozitive(int a, int b) {
	if (a < 0)
		throw new ExceptieANegativ();
	if (b < 0)
		throw ExceptieBNegativ("B este negativ");
	return a + b;
}

void main() {
	Ceva::nimic();
	Altceva::nimic();

	try {
		cout << endl << "Suma dintre 2 si 3 este "
			<< sumaNumerePozitive(2, 3);
		cout << endl << "Suma dintre -2 si 3 este "
			<< sumaNumerePozitive(-2, 3);
		cout << endl << "SFARSIT";
	}

	catch (ExceptieANegativ* ex) {
		cout << endl << "A este negativ";
	}
	catch (ExceptieBNegativ ex) {
		cout << endl << "B este negativ cu mesaj " << ex.what();
	}
	catch (...) {
		cout << endl << " Am prins o exceptie !";
	}
}