#include<iostream>
#include<string>

using namespace std;

class AbstractProduct {
	virtual int getPrice() = 0;
};

class Product {
protected:
	string description;
	float price;
	int stock;
public:
	virtual void printDescription() {
		cout << endl << "Product " << this->description;
		cout << endl << "Price " << this->price;
		cout << endl << "Available items " << this->stock;
	}

	Product() {
		this->description = "Nothing";
		this->price = 0;
		this->stock = 0;
	}

	Product(string description, float price = 0, int stock = 1) {
		this->description = description;
		this->price = price;
		this->stock = stock;
	}

	int getPrice() {
		return this->price;
	}

};

class SalesProduct : public Product, public AbstractProduct {
	float discountPercentage;
private:
	SalesProduct():Product("",0,0) {
		this->discountPercentage = 0;
	}
public:
	SalesProduct(string description, float price,
		float discount, int stock = 1) :Product(description, price, stock) {
		this->discountPercentage = discount;
	}

	//overriding
	void printDescription() {
		//cout << endl << "Product " << this->description;
		//cout << endl << "Price " << this->price;
		//cout << endl << "Available items " << this->stock;
		this->Product::printDescription();
		cout << endl << "Discount " << this->discountPercentage << "%";
	}

	int getPrice() {
		return this->price*this->discountPercentage / 100;
	}
};

class RefurbishedProduct: public Product {
	float discount;
	int limitedWarranty;
};

class Toy : public Product{
	int minimumAge;
};


int  main() {
	Product p1("Generic toy");
	Product p2("Phone", 1800, 10);

	//p1.printDescription();
	//p2.printDescription();

	SalesProduct sp1 = SalesProduct("RC Tank",100,10,5);
	SalesProduct sp2 = SalesProduct("Tablet", 300, 15, 50);

	//sp1.printDescription();
	//sp2.printDescription();

	//up-casting
	//p1 = sp1;

	//down-casting
	//sp2 = p2;

	Product products[4];
	products[0] = p1;
	products[1] = p2;
	products[2] = sp1;	//upcasting at object level
	products[3] = sp2;

	for (int i = 0; i < 4; i++)
		products[i].printDescription();

	cout << endl << "***************************";

	Product* pProducts[4];
	pProducts[0] = &p1;
	pProducts[1] = &p2;
	pProducts[2] = &sp1; //upcasting at pointer level
	pProducts[3] = &sp2;
	for (int i = 0; i < 4; i++)
		//early-binding without virtual
		//late-binding with
		pProducts[i]->printDescription();


	//AbstractProduct ap;
}