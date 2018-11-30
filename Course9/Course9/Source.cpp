#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Contact {
public:
	string name;
	long phone;

	Contact(string Name, long Phone) {
		name = Name;
		phone = Phone;
	}
};

int main() {
	//text file example
	fstream myFile("contacts.txt", ios::out | ios::trunc);
	//test if the file had been opened
	if (myFile.is_open()) {
		myFile << "John - " << 12345678 << endl;
		myFile << "Alice - " << 222222222  << endl;
		myFile << "Bob - " << 111111111<<"\n";

	}
	else
		cout << endl << "Houston we have a problem with the file";

	//don't forget to close it
	myFile.close();

	//binary file example
	fstream myFile2("contacts.dat", ios::binary | ios::trunc | ios::out);
	if (myFile2.is_open()) {

		Contact contact1("John", 6);
		Contact contact2("Alice", 8);
		Contact contact3("Bob", 9);

		//never use  <<
		//myFile2 << "John - " << 6 << endl;
		//myFile2 << "Alice - " << 8 << endl;
		//myFile2 << "Bob - " << 9 << "\n";
		myFile2.write(contact1.name.data(), contact1.name.length());
		myFile2.write((char*)&contact1.phone, sizeof(long));

		myFile2.write(contact2.name.data(), contact2.name.length());
		myFile2.write((char*)&contact2.phone, sizeof(long));

		myFile2.write(contact3.name.data(), contact3.name.length());
		myFile2.write((char*)&contact3.phone, sizeof(long));
	}
	myFile2.close();
}