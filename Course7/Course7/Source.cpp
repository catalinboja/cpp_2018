#include <iostream>
#include <string>

using namespace std;

class Student {
public:
	string name;
	int age = 0;
	const int id;
	static int noStudents;
private:
	int* grades = NULL;
	int noGrades = 0;

	//default constructor
private:
	Student():id(0) {
		cout << endl << "Default constructor";
		Student::noStudents += 1;
	}

public:
	//constructor that asks for the name
	Student(string name):id(Student::noStudents) {
		this->name = name;
		Student::noStudents += 1;
	}

	//constructor that asks for the name and age
	Student(string name, int age) :id(Student::noStudents) {
		this->name = name;
		this->age = age;
		Student::noStudents += 1;
	}

	//constructor that asks for the name and age
	Student(int age, string name) :id(Student::noStudents) {
		this->name = name;
		this->age = age;
		Student::noStudents += 1;
	}

	//constructor that asks for the name, age and ID
	Student(string name, int age, int Id) :id(Id) {
		this->name = name;
		this->age = age;
		Student::noStudents += 1;
	}

	//constructor that asks for the name, age and ID
	Student(string name, int age, int Id, int noGrades) :id(Id) {
		this->name = name;
		this->age = age;
		Student::noStudents += 1;

		this->noGrades = noGrades;
		this->grades = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++)
			this->grades[i] = 0;
	}

	//destructor - for cleaning up memory leaks
	~Student() {
		cout << endl << "The class destructor !";
		if (this->grades != NULL)
			delete[] this->grades;
	}

	//copy constructor
	Student(const Student& student):id(student.id) {

		cout << endl << "Copy constructor";
		//student.age = 100;
		this->name = student.name;
		this->age = student.age;
		this->noGrades = student.noGrades;
		//this->grades = student.grades;
		this->grades = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			this->grades[i] = student.grades[i];
		}

	}

	//overload operators
	Student operator=(Student student) {
		cout << endl << "Copy constructor";
		//student.age = 100;
		this->name = student.name;
		this->age = student.age;
		this->noGrades = student.noGrades;
		//this->grades = student.grades;

		if (this->grades != NULL)
			delete[] this->grades;

		this->grades = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			this->grades[i] = student.grades[i];
		}
	}

};

int Student::noStudents = 0;

void printStudent(Student student) {
	cout << endl << "The student name is " << student.name;
	cout << endl << "The student age is " << student.age;
	cout << endl << "The student age is " << student.id;
}

Student createStudent() {
	Student student("Clone", 22, 101);
	return student;
}

void printStudent2(Student* student) {
	cout << endl << "The student name is " << student->name;
	cout << endl << "The student age is " << student->age;
	cout << endl << "The student age is " << student->id;
}

void main() {
	//Student stud1;
	//Student *pStudent = new Student();

	Student stud1("John");
	Student stud2("Alice", 23);
	Student stud3("Bob", 23, 101);
	Student stud4("Vader", 22, 102,8);

	//for (;;) {
	//	Student *pStud5 = new Student("John Doe", 22, 102, 8);
	//	//delete[] pStud5->grades;
	//	delete pStud5;
	//}

	//printStudent(stud2);
	printStudent(stud4);
	//printStudent2(&stud4);

	//call copy constructor
	Student clone = stud4;

	//operator=(stud1,stud4);

	stud1 = stud4;
	stud1.operator=(stud4);

	//operator+(2, 3);


}