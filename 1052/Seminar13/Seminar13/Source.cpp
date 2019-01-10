#include <iostream>
#include <string>

using namespace std;


class PortException : public exception {

};

class IpException : public exception {

};

class LogInterface {
public:
	virtual void log() = 0;
};

class HttpClient: public LogInterface {
public:
	void log() {
		cout << endl << "This is a HTTP Client";
	}
};

class Server: public LogInterface {
	string userName;
	string passWord;
	string IP;
	string port;

	HttpClient client;
public:
	Server(string user, string pass, 
		string ip = "127.0.0.1", string port = "80") {
		this->userName = user;
		this->passWord = pass;
		this->IP = ip;
		this->port = port;
	}

	void connect() {
		cout << endl << "Trying to connect to " << this->IP;
		int portNumber = atoi(this->port.data());
		if (portNumber == 0)
			//throw new exception("The port number is not ok");
			throw new PortException();
		if (IP.find(".") == -1)
			//throw new exception("The IP is not ok");
			throw new IpException();
		cout << endl << "The connection was OK";
	}

	void log() {
		cout << endl << "This is server " << this->IP;
	}
};

//int main(int argc, char** argv)
int main(int noArguments, char* argv[]) {
	cout << endl << "The 1st argument is " << argv[0];

	//the app receives
	// 1. username
	// 2. password
	// 3. server IP
	// 4. server Port
	if (noArguments == 5) {
		string username(argv[1]);
		string pass(argv[2]);
		string serverIP(argv[3]);
		string serverPort(argv[4]);
		cout << endl << "Hello " << username;

		//LogInterface log;
		LogInterface *pLog;
		HttpClient client;

		LogInterface* networkComponents[2];
		networkComponents[0] = &client;
		networkComponents[1] = new Server(username, pass, serverIP, serverPort);

		for (int i = 0; i < 2; i++)
			networkComponents[i]->log();

		//we know that is a server - it's risky
		Server *pserver = (Server*)networkComponents[1];
		try {
			pserver->connect();
		}
		catch (PortException* ex) {
			cout << endl << "The port is not ok";
		}
		catch (IpException* ex) {
			cout << endl << "The IP is not ok";
		}
		catch (exception* ex) {
			cout << endl << " Houston we have a problem " << ex->what();
		}
	}
	else
	{
		cout << endl << "We need the required info: user pass ip port";
	}


}