#include <iostream>
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

	int operator()(string location) {
		int counter = 0;
		for (int i = 0; i < this->noLocations; i++) {
			if (this->route[i].compare(location) == 0)
				counter += 1;
		}
		return counter;
	}


	explicit operator int() {
		return this->noLocations;
	}

	string& operator[](int index) {
		if (index >= 0 && index < this->noLocations)
			return this->route[index];
		else
			throw new exception("Wrong index");
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
	//DeliveryVan van1(1, "Bob");
	//DeliveryVan *pVan = new DeliveryVan(2, "Alice");

	////an array of vans
	////DeliveryVan fleet[5];
	////DeliveryVan *pFleet = new DeliveryVan[5];

	//DeliveryVan *fleet[5];
	////fleet[0] = &van1;
	//fleet[0] = NULL;
	//fleet[1] = pVan;
	//fleet[2] = new DeliveryVan(3, "Vader");
	//fleet[3] = new DeliveryVan(4, "John");
	//fleet[4] = new DeliveryVan(5, "Bianca");



	//van1.printInfo();
	//fleet[2]->printInfo();

	////string* route = 
	////new string[]{ "Bucharest", "Ploiesti", "Brasov" };

	//string route[] = { "Bucharest", "Ploiesti", "Brasov" };

	//DeliveryVan van2(50, "Alex", route, 3);

	//van2.printInfo();


	//van1.addNewAddress("Constanta");
	//van1.addNewAddress("Mangalia");

	//van1.printInfo();

	//van2.addNewAddress("Sibiu");
	//van2.printInfo();

	////delete the array
	//for (int i = 0; i < 5; i++)
	//	if (fleet[i] != NULL)
	//		delete fleet[i];

	////clone van2
	//DeliveryVan van4 = van2;

	//create a dynamic array of vans - any number
	//DeliveryVan** fleet2;
	//int noVans;
	//cout << endl << "Number of vans in your fleet:";
	//cin >> noVans;
	//fleet2 = new DeliveryVan*[noVans];
	//for (int i = 0; i < noVans; i++) {
	//	int id;
	//	cout << endl << "New van ID: ";
	//	cin >> id;
	//	fleet2[i] = new DeliveryVan(id, "");
	//	cin >> *fleet2[i];
	//}


	////print the vans
	//for (int i = 0; i < noVans; i++) {
	//	cout << *fleet2[i];
	//}

	DeliveryVan van1(1, "John");
	van1.addNewAddress("Bucharest");
	van1.addNewAddress("Ploiesti");
	van1.addNewAddress("Bucharest");

	cout << van1; 

	//function operator ()
	int noGivenLocations = van1("Bucharest");

	cout << endl << "Bucharest : " << noGivenLocations;

	int noLocations = (int)van1;

	//int vb1 = 10 + van1;

	cout << endl << "The 2nd location is " << van1[1];
	van1[1] = "Pitesti";
}