#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Contact {
public:
	string name;
	char phone[11];
	int age;

	Contact(string Name, const char* Phone, int Age) {
		name = Name;
		strcpy(phone, Phone);
		age = Age;
	}

};

ostream& operator<<(ostream& out, Contact& contact) {
	out << "Contact name:" << contact.name << ", age "
		<< contact.age;
	out << endl << "Phone: " << contact.phone << endl;
	return out;
}

fstream& operator<<(fstream& out, Contact& contact) {
	out << contact.name << endl;
	out	<< contact.age << endl;
	out << contact.phone << endl;
	return out;
}

int main() {
	Contact contact1("John", "1234567890", 22);
	Contact contact2("Alice", "1111122333", 23);

	cout << contact1 << contact2;

	fstream file;
	file.open("Contacts2.txt", ios::out | ios::trunc);

	//fstream file("Contacts.txt", ios::out | ios::app);

	if (file.is_open()) {

		file << contact1 << contact2;

		file.close();
	}
	else
		cout << endl << "*********** Houston we have a problem with the file";

	file.open("Contacts.txt", ios::in);
	if (file.is_open()) {

		char buffer[100];

		while (!file.getline(buffer, 100).eof()) {
			string line(buffer);

			if (line.find("Contact", 0) != -1) {
				int nameStart = line.find(":");
				int nameEnd = line.find(",", nameStart);
				string name =
					line.substr(nameStart, nameEnd - nameStart);
				cout << endl << "The name is: " << name;
			}

			cout << endl << "The line is: " << line;
		}
		file.close();
	}

	file.open("Contacts2.txt", ios::in);
	if (file.is_open()) {
		char buffer[100];

		while (!file.getline(buffer, 100).eof()) {
			string name(buffer);
			file.getline(buffer, 100);
			string age(buffer);
			int ageValue = atoi(age.data());
			file.getline(buffer, 100);
			string phone(buffer);

			cout << endl << name << " - " << ageValue
				<< " - " << phone;
		}

		file.close();
	}

}