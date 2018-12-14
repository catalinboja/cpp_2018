#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
	string name;
	float price;
	bool isKidsSafe;
public:
	Product() {
		cout << endl << "Product default ctor";
		name = "Empty";
		price = 0;
		isKidsSafe = false;
	}
public:
	Product(string name, float price = 0, bool isSafe=false) {
		cout << endl << "Product arguments ctor";
		this->name = name;
		this->price = price;
		this->isKidsSafe = isSafe;
	}

	string getDescription() {
		string description = this->name + " has a price of "
			+ std::to_string(this->price) + "\n";
		if (this->isKidsSafe)
			description += "Is safe for kids \n";
		else
			description += "It's not safe for small kids";
		return description;
	}

	~Product() {
		cout << endl << "Product destructor";
	}
};

class DiscountedProduct: public Product {
	float discountPercentage;
	int maxItems;


public:

	DiscountedProduct(): Product("Nothing") {
		this->discountPercentage = 0;
		this->maxItems = 1;
		this->price = 0;
	}

	//overriding the base class method
	string getDescription() {
		//string description = this->name + " has a price of "
		//	+ std::to_string(this->price) + "\n";
		//if (this->isKidsSafe)
		//	description += "Is safe for kids \n";
		//else
		//	description += "It's not safe for small kids";
		string description = this->Product::getDescription();

		description += "\n The discount is " + to_string(this->discountPercentage) + "%";
		description += "\n You can buy at most " + to_string(this->maxItems) + " items";
		
		return description;
	}

	void print() {
		cout << endl << this->getDescription();
		cout << endl << "The discount is " << this->discountPercentage << "%";
		cout << endl << "You can buy at most " << this->maxItems << " items";
	}

	~DiscountedProduct() {
		cout << endl << "DiscountedProduct destructor";
	}
};

int main() {
	//Product product;
	//cout << endl << product.getDescription();

	Product p1("RC Rally Car", 200);
	Product p2("Doll", 130, true);
	Product p3("Tablet", 999);
	Product p4("Free Candy");

	//cout << endl << p4.getDescription();
	//cout << endl << p1.getDescription();

	DiscountedProduct dp;

	cout << endl << dp.getDescription();
	//dp.print();

	//upcasting
	p4 = dp;
	//downcasting
	//dp = p2;

	//an array of products
	Product products[3];
	products[0] = p1;
	products[1] = p2;
	products[2] = dp;

	cout << endl << "*****************************";
	for (int i = 0; i < 3; i++)
		cout << products[i].getDescription();


	Product* pproducts[3];
	pproducts[0] = &p1;
	pproducts[1] = &p2;
	pproducts[2] = &dp;

	cout << endl << "*****************************";
	for (int i = 0; i < 3; i++)
		if (i != 2)
			cout << pproducts[i]->getDescription();
		else
			cout << ((DiscountedProduct*)pproducts[i])->getDescription();
}