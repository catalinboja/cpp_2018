#include<iostream>
#include <string>
#include <thread>
using namespace std;

class Student {
public:
	string name = "Anonymous";
	char faculty[50] = "CSIE";
	char* groupName = NULL;
private:
	int age = 0;
	int *grades = NULL;
	int noGrades = 0;

public:
	void printInfo() {
		cout << endl << "The student name is " << this->name;
		cout << endl << "The student faculty is " << this->faculty;
		if (this->groupName != NULL)
			cout << endl << "The student grup ID is " << this->groupName;
		else
			cout << endl << "There is no group";
		cout << endl << "The student age is " << this->age;
		cout << endl << "The grades are:";
		for (int i = 0; i < this->noGrades; i++) {
			cout << this->grades[i] << " ";
		}
	}

	void readData() {
		cout << endl << "The name is: ";
		cin >> this->name;
		cout << endl << "The faculty is: ";
		cin >> this->faculty;
		cout << endl << "Group id: ";
		char buffer[1000];
		cin >> buffer;
		this->groupName = new char[strlen(buffer) + 1];
		strcpy(this->groupName, buffer);
		cout << endl << "The age is: ";
		cin >> this->age;
		cout << endl << "The grades number is: ";
		cin >> this->noGrades;
		this->grades = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++)
		{
			cout << "Grade " << i + 1 << " is: ";
			cin >> this->grades[i];
		}
	}

	//accessor methods
	int getAge() {
		return this->age;
	}

	//int* getGrades() {
	//	return this->grades;
	//}
	int getGrade(int index) {
		if (index >= 0 && index < this->noGrades)
			return this->grades[index];
		else
		{
			//cout << endl << "Wrong index";
			//return -1;
			throw new exception("Wrong index");
		}
	}
};

void main() {
	Student student1;
	cout << endl << "The student name is " << student1.name;
	cout << endl << "The student faculty is " << student1.faculty;
	student1.printInfo();
	student1.readData();
	student1.printInfo();

	cout << endl << student1.name 
		<< " has an age of " << student1.getAge();

	//int* pointer = student1.getGrades();
	//pointer[1] = 10;

	cout << endl << "First grade of  " << student1.name
		//<< " is " << student1.getGrades()[0];
		//<< " is " << pointer[0];
		<< " is " << student1.getGrade(0);

	student1.printInfo();
	std::this_thread::sleep_for(std::chrono::seconds(3));
	cout << endl << "Sfarsit";
}