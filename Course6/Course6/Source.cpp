#include <iostream>
#include <string>
using namespace std;




class Student {
public:
	string name = "John Doe";
private:
	int age = 0;
	int * grades = NULL;
	int noGrades = 0;
	const int ID = 0;
	const double someValue = 0;

	static int MIN_AGE;
	static int MAX_AGE;
	static int contor;

	//constructor
	Student() :ID(Student::contor += 1), someValue(100) {
		cout << endl << "Class constructor";
		this->age = Student::MIN_AGE;
		//this->ID = 1; - you can't
	}

public:

	Student(string name) :ID(Student::contor += 1), someValue(100) {
		this->name = name;
		cout << endl << "Class constructor";
		this->age = Student::MIN_AGE;
		//this->ID = 1; - you can't
	}

	Student(string name, int age) :ID(Student::contor += 1), someValue(100) {
		this->name = name;
		cout << endl << "Class constructor";
		this->setAge(age);
		//this->ID = 1; - you can't
	}

	void printInfo() {
		cout << endl << this->ID << " - " 
			<< this->name << " has an age of " << this->age;
		if (this->grades == NULL)
			cout << endl << "There are no grades";
	}

	//accessor functions
	//give read access on private stuff
	int getAge() {
		return this->age;
	}

	//avoid returning pointers - they can change the values there
	//int* getGrades() {
	//	return this->grades;
	//}
	
	int getNoGrades() {
		return this->noGrades;
	}

	int getGrade(int index) {
		if(this->grades!=NULL && index >=0 && index < this->noGrades)
			return this->grades[index];
		else
		{
			//cout << endl << "Bad index";
			//return -1;
			throw new exception("Bad index");
		}
	}

	//methods for changing private attributes
	void setAge(int value) {
		if (value >= MIN_AGE && value <= MAX_AGE)
			this->age = value;
		else
			throw new exception("Bad value");
	}

	static int getMinAge() {
		return Student::MIN_AGE;
	}

	static int getMaxAge() {
		return Student::MAX_AGE;
	}

};	//the end of tha class

//init the Student statics
int Student::MIN_AGE = 14;
int Student::MAX_AGE = 100;
int Student::contor = 0;

void main() {
	//Student student;
	//Student *pStudent;	//this is only a reference/pointer
	//pStudent = new Student();

	Student student("John");
	Student *pStudent;	//this is only a reference/pointer
	pStudent = new Student("Alice",23);

	student.printInfo();
	pStudent->printInfo();

	if(student.getNoGrades() >= 4)
		cout << endl << "1st grade of student is " << student.getGrade(3);

	int newAge = 110;
	if(newAge >= Student::getMinAge() && newAge <= Student::getMaxAge())
		student.setAge(newAge);

}