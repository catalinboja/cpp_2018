#include <iostream>
#include <string>

using namespace std;

class Product {
	string name;
	float price;
	bool isKidsSafe;
private:
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
};

class DiscountedProduct: public Product {

public:

	DiscountedProduct(): Product("Nothing") {

	}

	void print() {
		cout << endl << this->getDescription();
	}
};

int main() {
	//Product product;
	//cout << endl << product.getDescription();

	//Product p1("RC Rally Car", 200);
	//Product p2("Doll", 130, true);
	//Product p3("Tablet", 999);
	//Product p4("Free Candy");

	//cout << endl << p4.getDescription();
	//cout << endl << p1.getDescription();

	DiscountedProduct dp;
	cout << endl << dp.getDescription();
	dp.print();
}