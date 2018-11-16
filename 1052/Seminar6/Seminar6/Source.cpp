#include <iostream>
#include <string>

using namespace std;

class Product {
public:
	const int id;
	string description;

	static const float MAX_PRICE;

private:
	int stock = 0;
	float price = 0.0;
	int soldItemsMonthly[12];
	static int currentMonth;
	static int noProducts;



	//default constructor
	Product():id(0) {
		for (int i = 0; i < 12; i++)
			this->soldItemsMonthly[i] = 0;
	}
public:
	//accessor methods
	int getStock() {
		return this->stock;
	}

	float getPrice() {
		return this->price;
	}

	int getMonthlySoldItems(int month) {
		if (month >= 0 && month <= 11) {
			return this->soldItemsMonthly[month];
		}
		else
			throw new exception("Wrong month");
	}

	static int getCurrentMonth() {
		return Product::currentMonth;
	}

	void setPrice(float value) {
		if (value > 0 && value < Product::MAX_PRICE)
			this->price = value;
		else
			throw new exception("Wrong value");
	}

	//constructors
	Product(string description, float price):id(Product::noProducts+=1) {
		this->description = description;
		this->setPrice(price);
		for (int i = 0; i < 12; i++)
			this->soldItemsMonthly[i] = 0;
	}

	Product(string description, 
		float price, int stock) :id(Product::noProducts += 1) {
		this->description = description;
		this->setPrice(price);
		this->stock = stock;
		for (int i = 0; i < 12; i++)
			this->soldItemsMonthly[i] = 0;
	}

	void printInfo() {
		cout << endl << this->id << " - " << this->description;
		cout << endl << "Price: " << this->price;
		cout << endl << "Available stock: " << this->stock;
		cout << endl << "Sales history: ";
		for (int i = 0; i <= Product::currentMonth; i++)
			cout << this->soldItemsMonthly[i] << " ";
	}

	void sell(int noItems) {
		if (this->stock > 0 && noItems > 0
			&& noItems <= 5 && noItems <= this->stock)
		{
			this->stock -= noItems;
			this->soldItemsMonthly[Product::currentMonth] += noItems;
		}
		else
			throw new exception("An error");
	}
};

int Product::noProducts = 0;
int Product::currentMonth = 0;
const float Product::MAX_PRICE = 10000.0;

void main() {
	Product p1("Laptop", 2300);
	Product *refP1 = new Product("Smartphone",1500, 100);

	p1.printInfo();
	refP1->printInfo();

	if(p1.getStock() >= 1)
		p1.sell(1);

	if (refP1->getStock() >= 4)
		refP1->sell(4);
	if (refP1->getStock() >= 3)
		refP1->sell(3);

	refP1->printInfo();

	//Product list[10];
	//Product *list = new Product[10];
	Product * list[10];
	list[0] = &p1;
	list[1] = refP1;
	list[2] = new Product("Toy", 123, 60);
}