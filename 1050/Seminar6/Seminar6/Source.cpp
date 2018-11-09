#include <iostream>
#include <string>
using namespace std;

#pragma pack(push, 1)
class Product {
public:
	string name;
private:
	float price = 0;
	int stock = 0;
	int monthlySells[12];

	static int NO_MONTHS;
	static int CURRENT_MONTH;

public:
	void printInfo() {
		cout << endl << "Product " << this->name << "\t| stock: " << this->stock
			<< "\t| price: " << this->price;
		cout << endl << "Montly sales:";
		for (int i = 0; i < Product::NO_MONTHS; i++)
			cout << this->monthlySells[i] << " ";

	}

private:
	//constructor
	Product() {
		//for (int i = 0; i < NO_MONTHS; i++) {
		//	this->monthlySells[i] = 0;
		//}
		this->resetMontlySells();
	}

	void resetMontlySells() {
		for (int i = 0; i < NO_MONTHS; i++) {
			this->monthlySells[i] = 0;
		}
	}

public:
	//constructor with arguments
	Product(string name, float price) {
		//shadowing
		//name = name;
		this->name = name;
		this->price = price;
		this->resetMontlySells();
	}
};

#pragma pack(pop)

//are global variables - not your statics
//int NO_MONTHS = 12;
//int CURRENT_MONTH = 1;

int Product::NO_MONTHS = 12;
int Product::CURRENT_MONTH = 1;

void main() {
	//Product p1;
	Product p1("Smartphone",1500);

	cout << endl << sizeof(p1);
	//Product* refP = new Product();
	Product* refP = new Product("Laptop", 45000);

	p1.printInfo();
	refP->printInfo();

	//Product list[10];
	//Product* refList = new Product[20];

	//an array of pointers to Products
	Product** listOfPointersToProducts = new Product*[20];
	for( int i =0;i<20;i++)
		listOfPointersToProducts[i] = new Product("Not known", 1);
}