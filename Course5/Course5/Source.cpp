#include <iostream>
#include <string>
using namespace std;

struct Student {
	std::string name;
	int age;
	string faculty;
	int* grades;
	int noGrades;
};

Student readStudentData() {
	Student student;
	cout << endl << "The name:";
	cin >> student.name;
	cout << endl << "The age:";
	cin >> student.age;
	cout << endl << "The faculty:";
	cin >> student.faculty;
	return student;
}

void printStudent(Student student) {
	cout << endl << student.name << " has a age of " << student.age << " and is at "
		<< student.faculty;
}

class SuperStudent {

private:
public:
	std::string name;
	string faculty;
private:
	int* grades;
	int noGrades;
	int age;
public:
	void readSuperStudentData() {
		cout << endl << "The name:";
		cin >> this->name;
		cout << endl << "The age:";
		cin >> this->age;
		cout << endl << "The faculty:";
		cin >> this->faculty;
		cout << endl << " Grades number:";
		cin >> this->noGrades;
		grades = new int[this->noGrades];
		for (int i = 0; i < this->noGrades; i++) {
			cout << endl << "Grade " << i + 1 << " is ";
			cin >> this->grades[i];
		}
	}


	void printStudent() {
		cout << endl << this->name << " has a age of " << this->age << " and is at "
			<< this->faculty;
	}
};

//you can't
//SuperStudent readSuperStudentData() {
//	SuperStudent student;
//	cout << endl << "The name:";
//	cin >> student.name;
//	cout << endl << "The age:";
//	cin >> student.age;
//	cout << endl << "The faculty:";
//	cin >> student.faculty;
//	return student;
//}

void main() {

	//Student student1;
	//student1 = readStudentData();
	//student1.age = 19;
	//printStudent(student1);

	SuperStudent superS;
	//superS.age = 19;
	superS.name = "John";
	superS.faculty = "CSIE";
	//superS.noGrades = 0;	compiler error

	SuperStudent superS2;

	superS.readSuperStudentData();//SuperStudent::readSuperStudentData(&superS)
	superS2.readSuperStudentData();
	superS.printStudent();
	superS2.printStudent();

}