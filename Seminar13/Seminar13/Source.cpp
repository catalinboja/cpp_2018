#include <iostream>
#include <string>
using namespace std;

class ExceptiePort : public exception {

};

class ExceptieIp : public exception {

};

void conectareServer(char* ipServer, char* portServer) {
	int port = atoi(portServer);
	if (port < 20 || port > 100) {
		//throw new std::exception("Portul nu este in intervalul [20, 100]");
		throw new ExceptiePort();
	}
	string ip(ipServer);
	if (ip.find(".") == -1) {
		//throw new exception("Ip-ul nu este corect");
		throw new ExceptieIp();
	}

	cout << endl << "Conectat cu succes la " << ipServer << ":" << port;
}


enum tipStudent {elev, student, masterand, doctorand};

class Student {
public:
	int varsta;
	tipStudent tip;
};

//int main(int argc, char** argv)
int main(int argc, char* argv[]) {

	Student s;
	s.varsta = 0;
	s.tip = tipStudent::student;
	cout << endl << "Tipul studentului este " << s.tip;

	std::cout << std::endl << argv[0];
	//programul primeste prin argumentele fct main
	//1 nume utilizator
	//2 parola
	//3 adresa IP a serverului -> 10.0.0.1
	//4 portul serverului -> 22
	if (argc == 5) {
		try {

			//int valori[5];
			//cout << endl << valori[3000000];

			std::cout << std::endl << "Hello " << argv[1];
			std::cout << std::endl << "Ne vom conecta la " << argv[3]
				<< " pe portul " << argv[4];

			conectareServer(argv[3], argv[4]);
			cout << endl << "Deconectare server !";
		}

		catch (ExceptieIp* ex) {
			cout << endl << "IP-ul nu este ok";
		}
		catch (ExceptiePort* ex) {
			cout << endl << "Portul nu este ok";
		}
		catch (exception* ex) {
			cout << endl << "O exceptie cu mesajul " << ex->what();
		}
		catch (...) {
			cout << endl << "Ceva nu este ok";
		}

	}
	else
		std::cout << "Aplicatia nu primeste valorile asteptate!";
}