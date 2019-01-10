#include <iostream>
#include <string>

using namespace std;

namespace Course13 {
	void doNothing() {

	}
}

namespace Other {
	void doNothing() {

	}
}

class NegativeAException : public exception {

};

class NegativeBException : public exception {

};

int sumPositiveValues(int a, int b) {
	if (a < 0)
		throw new NegativeAException();
	if (b < 0)
		throw NegativeBException();
	return a + b;
}

//int main(int argc, char* argv[])
int main(int noArguments, char* argValues[]) {

	Course13::doNothing();
	Other::doNothing();

	//get the app name and the path
	cout << endl << argValues[0];

	//get a filename when the app starts
	if (noArguments > 1) {
		cout << endl << "No of arguments = " << noArguments;
		cout << endl << "The 1st file is = " << argValues[1];
		string fileName = string(argValues[1]);
	}

	try {
		cout << endl << "trying to add 2 with 3";
		cout << endl << "the sum is " << sumPositiveValues(2, 3);
		cout << endl << "trying to add -2 with 3";
		cout << endl << "the sum is " << sumPositiveValues(3, -3);
	}

	catch (runtime_error ex) {
		cout << endl << "You got a runtime error";
	}
	catch (NegativeAException* ex) {
		cout << endl << "You got a negative A error";
	}
	catch (NegativeBException ex) {
		cout << endl << "You got a negative B error";
	}
	catch (...) {
		cout << endl << "You got an error";
	}
}