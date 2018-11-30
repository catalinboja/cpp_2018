#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Contact {
	string name;
	char phone[11];		//10 for the digits and 1 for \0
	int age;
public:
	Contact(string Name, const char* Phone, int Age) {
		name = Name;
		age = Age;
		strcpy(phone, Phone);
	}

	friend ostream& operator<<(ostream& out, Contact& contact);
	friend fstream& operator<<(fstream& out, Contact& contact);
};

ostream& operator<<(ostream& out, Contact& contact) {
	out << "The contact name is " << contact.name << ", age "<<contact.age;
	out << endl << "The phone number is " << contact.phone << endl;
	return out;
}

fstream& operator<<(fstream& out, Contact& contact) {
	out << contact.name;
	out << endl << contact.age;
	out << endl << contact.phone << endl;
	return out;
}



void main() {
	Contact contact1("John", "1234567890", 22);
	Contact contact2("Alice", "1111122233", 22);

	cout << contact1 << contact2;

	
	//text files
	fstream contactsFile("contacts2.txt", ios::out | ios::app);
	if (contactsFile.is_open()) {
		contactsFile << contact1;
		contactsFile << contact2;

		contactsFile.close();
	}

	//read the contacts text file
	//fstream contactsFile;
	contactsFile.open("contacts.txt", ios::in);
	if (contactsFile.is_open()) {
		char line[100];
		//string line;

		while (!contactsFile.getline(line, 100).eof()) {
			cout << endl << "The first line is " << line;
			string sLine(line);

			//determine which line is - the phone or the name
			//int noLetters = strlen("The contact");
			//string startingMessage = sLine.substr(0, noLetters);
			//if (startingMessage.compare("The contact") == 0)
			
			if (sLine.find("contact") != -1) {
				int indexName = strlen("The contact name is ");
				int counter = 0;
				for (int i = 0; sLine[indexName + i] != ','; i++, counter++);
				string name = sLine.substr(indexName, counter);
				cout << endl << "The name is " << name;
			}
		}

		contactsFile.close();
	}

	//read the contacts2 text file
	contactsFile.open("contacts2.txt", ios::in);
	if (contactsFile.is_open()) {
		char line[100];
		//string line;

		while (!contactsFile.getline(line, 100).eof()) {
			string name(line);
			cout << endl << "The name is " << name;
			contactsFile.getline(line, 100);
			string age(line);
			int ageValue = atoi(age.data());
			cout << endl << "The age is " << ageValue;
			contactsFile.getline(line, 100);
			string phone(line);
			cout << endl << "The phone is " << phone;
		}

		contactsFile.close();
	}

}