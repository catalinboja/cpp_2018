#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Flower {
public: 
	string type;
	float price = 0;

	Flower(string Type = "None", float Price = 0) {
		type = Type;
		price = Price;
	}

	operator string() {
		return this->type;
	}
};

void main() {


	Flower flowers[5];
	Flower *flowersDynamic = new Flower[5];

	vector<Flower> flowersVector;
	flowersVector.push_back(Flower("Rose", 23));
	flowersVector.push_back(Flower("Tulip", 5));
	flowersVector.push_back(Flower("Margaret", 5));
	flowersVector.insert(flowersVector.begin(), Flower("Tulip", 5));
	for (int i = 0; i < flowersVector.size(); i++)
		cout << endl << flowersVector[i].type;

	set<Flower> flowersSet;

	set<string> names;
	names.insert("Gigel");
	names.insert("Ana");
	names.insert("Ana");
	names.insert("Ana");
	names.insert("Ana");

	set<string>::iterator it;
	for (it = names.begin(); it != names.end(); it++)
		cout << endl << *it;


	flowersSet.insert(Flower("Rose", 23));
	flowersSet.insert(Flower("Tulip", 5));
	flowersSet.insert(Flower("Margaret", 5));
	flowersSet.insert(Flower("Tulip", 5));

	set<Flower>::iterator itf;
	for (itf = flowersSet.begin(); itf != flowersSet.end(); itf++) {
		cout << endl << itf->type;
	}
}