#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DeliveryVan {
	int id;
	string driver;
	string* addresses;
	int noDeliveries;

public:
	DeliveryVan(int Id, string driver) :id(Id) {
		this->driver = driver;
		this->addresses = NULL;
		this->noDeliveries = 0;
	}

	DeliveryVan(int Id, string driver,
		string* route, int nPoints) : id(Id) {
		this->driver = driver;
		//shallow copy
		//this->addresses = route;

		this->addresses = new string[nPoints];
		for (int i = 0; i < nPoints; i++)
			this->addresses[i] = route[i];
		this->noDeliveries = nPoints;

	}

	void addAddress(string address) {
		string* newList = new string[this->noDeliveries + 1];
		for (int i = 0; i < this->noDeliveries; i++)
			newList[i] = this->addresses[i];
		newList[this->noDeliveries] = address;
		this->noDeliveries += 1;
		if (this->addresses != NULL)
			delete[] this->addresses;
		this->addresses = newList;
	}

	void print() {
		cout << endl << this->id << " - " << this->driver;
		cout << endl << "Today route: ";
		for (int i = 0; i < this->noDeliveries; i++)
			cout << endl << i + 1 << ". " << this->addresses[i];
	}

	//the destructor
	~DeliveryVan() {
		//clean memory in HEAP
		delete[] this->addresses;
	}

	//copy constructor
	DeliveryVan(const DeliveryVan& existingVan) :id(existingVan.id) {
		this->driver = existingVan.driver;
		this->noDeliveries = existingVan.noDeliveries;
		//this->addresses = existingVan.addAddress;

		this->addresses = new string[existingVan.noDeliveries];
		for (int i = 0; i < existingVan.noDeliveries; i++)
			this->addresses[i] = existingVan.addresses[i];
		this->noDeliveries = existingVan.noDeliveries;
	}

	void operator=(const DeliveryVan& existingVan) {
		this->id = existingVan.id;
		this->driver = existingVan.driver;
		this->noDeliveries = existingVan.noDeliveries;

		if (this->addresses != NULL)
			delete[] this->addresses;

		this->addresses = new string[existingVan.noDeliveries];
		for (int i = 0; i < existingVan.noDeliveries; i++)
			this->addresses[i] = existingVan.addresses[i];
		this->noDeliveries = existingVan.noDeliveries;
	}

	friend void operator <<(fstream& bFile, DeliveryVan& van);

};

//overloading << for saving object data into a binary file
void operator<<(fstream& bFile, DeliveryVan& van) {
	if (bFile.is_open()) {
		//writting the id
		//bFile << van.id; //DON'T USE << with binary files
		bFile.write((char*)&van.id, sizeof(int));
		//writting the name number of chars + '\0'
		int noChars;
		noChars = van.driver.length() + 1;
		bFile.write((char*)&noChars, sizeof(int));
		//writting the name - with '\0'
		bFile.write(van.driver.data(), noChars);

		//no deliveries
		bFile.write((char*)&van.noDeliveries, sizeof(int));

		for (int i = 0; i < van.noDeliveries; i++) {
			noChars = van.addresses[i].length() + 1;
			bFile.write((char*)&noChars, sizeof(int));
			bFile.write(van.addresses[i].data(), noChars);
		}

	}
}

int main() {

	//playing with the text file
	fstream textFile("input.txt", ios::in);
	if (textFile.is_open()) {
		int number;
		textFile >> number;
		cout << endl << "The value is " << number;
		textFile >> number;
		cout << endl << "The value is " << number;
		textFile >> number;
		cout << endl << "The value is " << number;
		textFile >> number;
		cout << endl << "The value is " << number;
		textFile >> number;
		cout << endl << "The value is " << number;
		textFile >> number;
		cout << endl << "The value is " << number;
		textFile >> number;
		cout << endl << "The value is " << number;
		textFile >> number;
		cout << endl << "The value is " << number;

		//use getline because we have a name with spaces

		char buffer[50];
		textFile.getline(buffer, 50);
		textFile.getline(buffer, 50);
		string name(buffer);
		cout << endl << "The name is " << name;


		textFile >> name;
		cout << endl << "The name is " << name;
		//textFile >> name;
		//cout << endl << "The name is " << name;
		textFile.close();
	}


	//serializing objects
	DeliveryVan van1(1, "John");
	van1.addAddress("Bucuresti");
	van1.addAddress("Ploiesti");
	van1.addAddress("Brasov");

	van1.print();
}