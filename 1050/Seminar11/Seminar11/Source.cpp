#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
	string name = "";
	float price;
	bool isKidsSafe = false;
public:
	static int MAX;

public:
	Product() {
		name = "";
		price = 0;
		isKidsSafe = false;
		cout << endl << "Product ctor - job done";
	}

	Product(string name, float price = 0, bool isSafe = false) {
		this->price = price;
		this->name = name;
		this->isKidsSafe = isSafe;
	}

	string getName() {
		return this->name;
	}

	string getDescription() {
		string description = "The product name is " + this->name + "\n";
		
		description += ("The price is " + to_string(this->price) + "\n");
		if (this->isKidsSafe)
			description += "Is kids safe \n";
		else
			description += "Don't give it to children under 3 years old \n";
		return description;
	}

	float getPrice() {
		return this->price;
	}

	~Product() {
		cout << endl << "Product destructor";
	}
};

int Product::MAX = 0;

//inheritance
class DiscountedProduct: public Product {
private:
	float discountPercentage;	
	int maxItems;
public:
	DiscountedProduct(string name = "", float price = 0.0,
		float discount = 0): Product(name,price) {
		cout << endl << "DiscountedProduct ctor - starting";
		this->discountPercentage = discount;
		this->maxItems = 0;
		//this->name = name;
		//this->price = price;
		//this->isKidsSafe = false;
	}

	//overriding the base class method
	string getDescription() {

		string description = this->Product::getDescription();

		description += "The discount is " +
			to_string(this->discountPercentage) + "% \n";
		description += "The maximum items is " +
			to_string(this->maxItems) + "\n";
		
		return description;
	}

	~DiscountedProduct() {
		cout << endl << "DiscountedProduct destructor";
	}
};

int main() {

	int MAX;
	Product product;
	Product toy1("Remote Controlled Car", 230);
	Product toy2("Doll", 34);
	Product toy3("Big Ball", 12, true);

	cout << toy1.getDescription();
	cout << toy2.getDescription();
	cout << toy3.getDescription();

	DiscountedProduct promotion_1;
	cout << promotion_1.getDescription();

	DiscountedProduct promotion_2("Lego",100,50);
	cout << promotion_2.getDescription();

	//cout << MAX;
	//cout << Product::MAX;

	char gen = 'M';
	if (gen == 77)
		cout << endl << "Este baiat";
}