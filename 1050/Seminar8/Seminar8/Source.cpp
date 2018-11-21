#include <iostream>
#include <string>

using namespace std;

class DeliveryVan {
	const int id;
	string driver;
	string* addresses;
	int noDeliveries;
	int kilometers = 0;

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

	void resetRoute() {
		if (this->addresses != NULL)
			delete[] this->addresses;
		this->addresses = NULL;
		this->noDeliveries = 0;
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
		this->kilometers = existingVan.kilometers;

		this->addresses = new string[existingVan.noDeliveries];
		for (int i = 0; i < existingVan.noDeliveries; i++)
			this->addresses[i] = existingVan.addresses[i];
		this->noDeliveries = existingVan.noDeliveries;
	}

	//overload =
	//van1 = van2
	void operator=(DeliveryVan van) {
		this->driver = van.driver;
		this->noDeliveries = van.noDeliveries;
		//this->addresses = existingVan.addAddress;

		this->kilometers = van.kilometers;

		//clean up a possible memory leak
		if (this->addresses != NULL)
			delete[] this->addresses;

		this->addresses = new string[van.noDeliveries];
		for (int i = 0; i < van.noDeliveries; i++)
			this->addresses[i] = van.addresses[i];
		this->noDeliveries = van.noDeliveries;
	}

	//setter for name
	void setName(string name) {
		this->driver = name;
	}

	//for km
	void setMilleage(int km) {
		this->kilometers = km;
	}

	//operator +
	DeliveryVan operator+(DeliveryVan van) {
		DeliveryVan result = van;
		result.kilometers += this->kilometers;
		for (int i = 0; i < this->noDeliveries; i++)
			result.addAddress(this->addresses[i]);
		return result;
	}


	//the same logic for ==, <=, >=, <
	bool operator>(DeliveryVan van) {
		if (this->noDeliveries > van.noDeliveries)
			return true;
		else
			return false;
	}

	int getNoLocations() {
		return this->noDeliveries;
	}

	string& operator[](int index) {
		if (index >= 0 && index < this->noDeliveries) {
			return this->addresses[index];
		}
		else
			throw new exception("Wrong index");
	}

	friend ostream& operator<<(ostream& out, const DeliveryVan& van);

};

ostream& operator<<(ostream& out, const DeliveryVan& van) {
	out << endl << "The drivers name: " << van.driver;
	out << endl << "The van id is: " << van.id;
	out << endl << "The milleage is: " << van.kilometers;
	out << endl << "Today route: ";
	for (int i = 0; i < van.noDeliveries; i++)
		out << endl << i + 1 << ". " << van.addresses[i];
	return out;
}

void operator>>(istream& in, DeliveryVan& van) {
	cout << endl << "New driver name: ";
	string newName;
	in >> newName;
	van.setName(newName);
	cout << endl << "New milleage: ";
	int km;
	in >> km;
	van.setMilleage(km);
	cout << endl << "An additional destination: ";
	string newDestination;
	in >> newDestination;
	van.addAddress(newDestination);
}

bool operator!(DeliveryVan van) {
	if(van.getNoLocations() == 0)
		return false;
	else
		return true;
}

void main() {
	cout << endl << "The size of a DeliveryVan is "
		<< sizeof(DeliveryVan);		//influenced by memory alignment

	DeliveryVan van1(1, "John");
	van1.addAddress("Piata Romana 6");
	van1.addAddress("Piata Universitatii");
	van1.addAddress("Calea Dorobanti 15-17");

	string route[] = { "Piata Romana","Ploiesti", "Brasov" };
	DeliveryVan van2(2, "Alice", route, 3);
	//DeliveryVan van2(2, "Alice", { "Piata Romana","Ploiesti", "Brasov" }, 3);

	van2.addAddress("Sibiu");


	van1.print();
	van2.print();

	// cout << endl << van2.id;
	//char* aPointer = (char*)&van1;
	//int* pointerToPrivateId = (int*)aPointer;
	//*pointerToPrivateId = 777;
	//cout << endl << "The id is: " << *pointerToPrivateId;

	//van1.print();

	//clone an object - copy constructor
	DeliveryVan van3 = van2;

	van3.print();

	van1 = van2;	//van1.operator=(van2)

	cout << endl << "***************************";

	cin >> van1;

	cout << van1 << van2;


	van3 = van1 + van2; 

	cout << endl << "************* after + **********";
	cout << van3;

	if (van3 > van2)
		cout << endl << "Van3 route is longer";
	else
		cout << endl << "Van2 route is longer or equal";

	if (!van3) {
		cout << endl << "Van3 has no route";
	}

	van3[1] = "Pitesti";
	cout << endl << "The second location is " << van3[1];

	//create a new van with van2 driver and aggregate rotues and milleage
	// van3 = van1.operator+(van2)

	//van3 = van1 + "Cluj"; //van1.operator+("Cluj")
	//van4 += 45; //van4.operator+=(45);

}