#include <iostream>
#include <string>

using namespace std;

class DeliveryVan {
	const int id;
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
		string* route, int nPoints): id(Id) {
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
	DeliveryVan(const DeliveryVan& existingVan):id(existingVan.id) {
		this->driver = existingVan.driver;
		this->noDeliveries = existingVan.noDeliveries;
		//this->addresses = existingVan.addAddress;

		this->addresses = new string[existingVan.noDeliveries];
		for (int i = 0; i < existingVan.noDeliveries; i++)
			this->addresses[i] = existingVan.addresses[i];
		this->noDeliveries = existingVan.noDeliveries;
	}

};

void main() {
	cout << endl << "The size of a DeliveryVan is "
		<< sizeof(DeliveryVan);		//influenced by memory alignment

	DeliveryVan van1(1,"John");
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
	char* aPointer = (char*)&van1;
	int* pointerToPrivateId = (int*)aPointer;
	*pointerToPrivateId = 777;
	cout << endl << "The id is: "<< *pointerToPrivateId;

	van1.print();

	//clone an object - copy constructor
	DeliveryVan van3 = van2;

	van3.print();

	//van1 = van2;	//van1.operator=(van2)
	//van3 = van1 + van2; // van3 = van1.operator+(van2)
	//van3 = van1 + "Cluj"; //van1.operator+("Cluj")
	//van4 += 45; //van4.operator+=(45);

}