#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DeliveryVan {
	string driver;
	const int id;
	string* route = NULL;;
	int noLocations = 0;

private:
	DeliveryVan() :id(0) {

	}

public:
	DeliveryVan(int Id, string Driver) :id(Id) {
		this->driver = Driver;
	}

	DeliveryVan(int Id, string Driver, string* route,
		int noLocations) :id(Id) {
		this->driver = Driver;
		//shallow copy - avoid it
		//this->route = route;

		this->route = new string[noLocations];
		for (int i = 0; i < noLocations; i++)
			this->route[i] = route[i];

		this->noLocations = noLocations;
	}

	void printInfo() {
		cout << endl << this->id << " - " << this->driver;
		if (this->route != NULL) {
			cout << endl << "Van route is:";
			for (int i = 0; i < this->noLocations; i++)
				cout << "-> " << this->route[i];
		}
	}

	void addNewAddress(string newLocation) {
		string * newRoute = new string[this->noLocations + 1];
		for (int i = 0; i < this->noLocations; i++)
			newRoute[i] = this->route[i];
		newRoute[this->noLocations] = newLocation;
		delete[] this->route;

		this->noLocations += 1;
		this->route = newRoute;
	}

	//the destructor
	~DeliveryVan() {
		if (this->route != NULL)
			delete[] this->route;
	}

	//copy constructor
	DeliveryVan(const DeliveryVan& existing) :id(existing.id) {
		this->driver = existing.driver;

		this->noLocations = existing.noLocations;

		this->route = new string[existing.noLocations];

		for (int i = 0; i < existing.noLocations; i++)
			this->route[i] = existing.route[i];
	}

	void operator=(const DeliveryVan& existing) {
		this->driver = existing.driver;
		this->noLocations = existing.noLocations;

		if (this->route != NULL)
			delete[] this->route;
		this->route = new string[existing.noLocations];

		for (int i = 0; i < existing.noLocations; i++)
			this->route[i] = existing.route[i];
	}

	void serializeObject(fstream& file) {
		if (file.is_open()) {
			//write id
			file.write((char*)(&this->id), sizeof(int));
			//write driver' name
			//write the name length + 1
			int length = this->driver.length()+1;
			file.write((char*)&length, sizeof(int));
			file.write(this->driver.data(), length);
			//write number of locations
			file.write((char*)&this->noLocations, sizeof(int));
			//write locations
			for (int i = 0; i < this->noLocations; i++)
				DeliveryVan::writeString2File(file, this->route[i]);
		}
		else
			throw new exception("File no opened!");
	}

private:
	static void writeString2File(fstream& file, string value) {
		int length = value.length() + 1;
		file.write((char*)&length, sizeof(int));
		file.write(value.data(), length);
	}

public:
	static void writeArray2File(string fileName, DeliveryVan** vans, int noVans) {
		fstream file(fileName, ios::out | ios::binary | ios::trunc);
		if (file.is_open()) {
			//write the number of vans
			file.write((char*)&noVans, sizeof(int));

			for (int i = 0; i < noVans; i++)
				vans[i]->serializeObject(file);

			file.close();
		}
		else
			throw new exception();
	}

	static DeliveryVan** loadArrayFromFile(string fileName, int& noVans) {
		fstream file(fileName, ios::in | ios::binary);
		if (file.is_open()) {
			//read no vans
			file.read((char*)&noVans, sizeof(int));

			DeliveryVan** vans = new DeliveryVan*[noVans];

			for (int i = 0; i < noVans; i++) {
				int id;
				file.read((char*)&id, sizeof(int));
				int nameSize;
				file.read((char*)&nameSize, sizeof(int));
				char buffer[100];
				file.read(buffer, nameSize);
				string name(buffer);
				vans[i] = new DeliveryVan(id, name);
				//read the route
				int noLocations;
				file.read((char*)&noLocations, sizeof(int));

				for (int j = 0; j < noLocations; j++)
				{
					int locationSize;
					file.read((char*)&locationSize, sizeof(int));
					file.read(buffer, locationSize);
					string location(buffer);
					vans[i]->addNewAddress(location);
				}
			}
			file.close();
			return vans;
		}
		else
			throw new exception();
	}

	friend void operator>>(istream& in, DeliveryVan& van);
	friend void operator<<(ostream& out, DeliveryVan& van);
};

void operator>>(istream& in, DeliveryVan& van) {
	cout << endl << "New name: ";
	in >> van.driver;

	//delete the previous route
	if (van.route != NULL)
		delete[] van.route;

	cout << endl << "The locations number: ";
	int noLocations;
	in >> noLocations;

	for (int i = 0; i < noLocations; i++) {
		cout << endl << "New address: ";
		string address;
		in >> address;
		van.addNewAddress(address);
	}
}

void operator<<(ostream& out, DeliveryVan& van) {
	out << endl << van.id << " - " << van.driver;
	if (van.route != NULL) {
		out << endl << "Van route is:";
		for (int i = 0; i < van.noLocations; i++)
			out << "-> " << van.route[i];
	}
}

int main() {
	
	//define a dynamic array of delivery vans
	//DeliveryVan* vans;
	//vans = new DeliveryVan[2];

	/*int noVans = 2;

	DeliveryVan* *vans;
	vans = new DeliveryVan*[noVans];
	vans[0] = new DeliveryVan(1, "John");
	vans[1] = new DeliveryVan(2, "Alice");

	vans[0]->addNewAddress("Bucharest");
	vans[0]->addNewAddress("Ploiesti");
	vans[0]->addNewAddress("Brasov");

	vans[1]->addNewAddress("Bucharest");
	vans[1]->addNewAddress("Constanta");

	for (int i = 0; i < noVans; i++)
		cout << endl << *vans[i];

	DeliveryVan::writeArray2File("Vans.data", vans, noVans);*/

	int noDeliveryVans = 0;
	DeliveryVan** newList =
		DeliveryVan::loadArrayFromFile("Vans.data", noDeliveryVans);

	for (int i = 0; i < noDeliveryVans; i++)
		cout << endl << *newList[i];
}