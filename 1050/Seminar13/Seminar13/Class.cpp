#include <iostream>
#include <string>

using namespace std;

class BadIPException : public exception {

};

class BadPortException : public exception {
public:
	BadPortException(string details) : exception(details.data()) {

	}
};

void connect(char* serverIP, int port) {
	if (port < 10 || port > 250)
		throw BadPortException("The port is not in the accepted range");
	string ip(serverIP);
	if (ip.find(".") == -1)
		throw new BadIPException();
	cout << endl << "Connecting to server  !";
}

void main(int argc, char** argv) {
	//except to receive 
	//1 username
	//2 password
	//3 ip of the server
	//4 the server port
	if (argc != 5)
		cout << endl << "You need to pass the username password server_ip server_port[10:250]";
	else
	{
		try {
			cout << endl << "Hello " << argv[1];
			cout << endl << "Trying to connect to " << argv[3] << ":" << argv[4];
			int port = atoi(argv[4]);
			cout << endl << "The port as a number is " << port;
			connect(argv[3], port);
			int array[3];
			array[3000] = 99;
			cout <<  endl << "Yahoo !!!! We finished it";
		}
		catch (BadIPException ex) {
			cout << endl << " The IP is not ok!";
		}
		catch (BadIPException* ex) {
			cout << endl << " The IP is not ok!";
		}
		catch (BadPortException ex) {
			cout << endl << " The IP is wrong. Reason " << ex.what();
		}
		catch (...) {
			cout << endl << "You got an exception !";
		}
	}
}