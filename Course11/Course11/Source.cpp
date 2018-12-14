#include<iostream>
#include<string>

using namespace std;

class Grades {
public:
	int* grades;
	int noGrades;
public:
	Grades() {
		cout << endl << "The grades object is created";
		this->grades = NULL;
		this->noGrades = 0;
	}

	Grades(int initialNumber) {
		this->grades = new int[initialNumber];
		cout << endl << "The grades object is created by the argument based constructor";
		this->noGrades = 0;
		for (int i = 0; i < initialNumber; i++)
			*this += 0;
		
	}

	//TO DO define operator = and Copy Constructor
	void operator=(Grades& gradesObject) {
		if (this->grades != NULL)
			delete[] this->grades;
		this->grades = new int[gradesObject.noGrades];
		for (int i = 0; i < gradesObject.noGrades; i++)
			this->grades[i] = gradesObject.grades[i];
		this->noGrades = gradesObject.noGrades;
	}

	Grades(Grades& gradesObject) {
		this->grades = new int[gradesObject.noGrades];
		for (int i = 0; i < gradesObject.noGrades; i++)
			this->grades[i] = gradesObject.grades[i];
		this->noGrades = gradesObject.noGrades;
	}

	~Grades() {
		delete[] this->grades;
	}

	void operator+=(int grade) {
		int* newGrades = new int[this->noGrades+1];
		for (int i = 0; i < this->noGrades; i++)
			newGrades[i] = this->grades[i];
		newGrades[this->noGrades] = grade;

		delete[] this->grades;
		this->noGrades += 1;
		this->grades = newGrades;
	}
};

void operator<<(ostream& out, Grades& gradesObject) {
	out << endl << "The grades are:";
	for (int i = 0; i < gradesObject.noGrades; i++)
		out << " " << gradesObject.grades[i];
}

class Student {
protected:
	string name;
	int age;
	Grades grades;	//has-a relation -> composition

private:
	Student() {
		cout << endl << "Student() default ctr";
		this->name = "John Doe";
		this->age = 14;
	}
public:
	Student(string name, int age) :age(age) {
		this->name = name;
	}

	Student(string name, int age, int noGrades) 
		:age(age), grades(noGrades) {
		cout << endl << "The student object is created";
		this->name = name;

		//for (int i = 0; i < noGrades; i++)
		//	this->grades += 0;
	}

	void printInfo() {
		cout << *this;
	}

	int getAge() {
		return this->age;
	}

	friend void operator<<(ostream& out, Student& student);
};

void operator<<(ostream& out, Student& student) {
	out << endl << student.name << " with age = " << student.age;
	out << student.grades;
}



class Faculty
{
	string name;
	string country;
	int typeId;

	Student students[100];	//composition

};

//extend the Student class by adding new attributes
class SuperStudent: public Student {
private:
	string address;
	string bachelorProgram;
	int id;
public:
	SuperStudent():Student("Alice", 21, 10) {
		cout << endl << "SuperStudent() default ctr";
		//this->age = 19;
	}

	void doSomething() {

		this->printInfo();
	}

};

void main() {
	//Grades grades;
	//Grades *pGrades;

	Student student("John", 22, 4);

	cout << student;

	student.printInfo();

	//play with the new class
	cout << endl << "**********************";
	SuperStudent superStudent;
	//superStudent.printInfo();
	superStudent.doSomething();

	cout << superStudent;


}

