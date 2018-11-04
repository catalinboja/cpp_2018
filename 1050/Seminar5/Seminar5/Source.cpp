#include <iostream>
#include <string>
using namespace std;

class Student {
public: 
	string name = "Anonymous";
	int age = 0;
	char faculty[50] = "CSIE";
	char* group = NULL;
private:
	int* grades = NULL;
	int noGrades = 0;

public:
	void printInfo() {
		cout << endl << "Student data:";
		cout << endl << "Name: " << this->name;
		cout << endl << "Age: " << age;
		cout << endl << "Faculty: " << this->faculty;
		if(this->group!=NULL)
			cout << endl << "Group ID: " << this->group;

		if (this->grades != NULL) {
			cout << endl << " The grades are:";
			for (int i = 0; i < this->noGrades; i++)
				cout << this->grades[i] << " ";
		}
		else {
			cout << endl << "No grades !";
		}
	}

	void readStudentData() {
		cout << endl << "The name is ";
		cin >> this->name;
		cout << endl << "The faculty is ";
		cin >> this->faculty;
		cout << endl << "The group ID:";
		char buffer[1000];
		cin >> buffer;
		this->group = new char[strlen(buffer) + 1];
		strcpy(this->group, buffer);
		cout << endl << "The age is";
		cin >> this->age;
		cout << endl << "The number of grades:";
		cin >> this->noGrades;
		this->grades = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			cout << endl << " Grade " << i << " is ";
			cin >> this->grades[i];
		}
	}

	//accessor functions
	int getNoGrades() {
		return this->noGrades;
	}


	//it's not safe - it's like making grades public
	//int* getGrades() {
	//	return this->grades;
	//}

	int getGrade(int index) {
		if (index >= 0 && index < this->noGrades) {
			return this->grades[index];
		}
		else
		{
			//cout << "!!!!! Wrong index";
			//return -1;
			throw new exception("Wrong index");
		}
	}

	void setAge(int age) {
		if (age > 0) {
			//shadowing
			this->age = age;
		}
		else
			throw new exception("Negative value");
	}

};

int main() {
	Student student1;
	student1.readStudentData();
	student1.printInfo();

	//student1.grades[0] = -10;

	cout << endl << "Number of grades for " << student1.name << " is " <<
		student1.getNoGrades();

	//int * grades = student1.getGrades();
	//grades[0] = 10;
	cout << endl << "The first grade for " << student1.name << " is " <<
		//student1.getGrades()[0];
		//grades[0];
		student1.getGrade(0);
}