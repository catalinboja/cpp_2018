#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Student {
public:
	string name;
	int id;
	Student(string name = "John Doe", int id = 0) {
		this->name = name;
		this->id = id;
	}

	//bool const operator < (const Student& stud) {
	//	return this->id < stud.id;
	//}
};

bool operator < (const Student& stud1, const Student& stud2) {
	return stud1.id < stud2.id;
}

class Flower {

 };

void main() {
	//Student students[5];
	//Student *students = new Student[5];


	vector<Student> students;
	students.push_back(Student("Alice", 1));
	students.push_back(Student("Alice", 1));
	students.push_back(Student("Bianca", 2));
	students.push_back(Student("Bob", 3));
	students.insert(students.begin(), Student("Vader", 4));

	for (int i = 0; i < students.size(); i++)
		cout << endl << "Student: " << students[i].name;

	vector<Student>::iterator studentsIterator;
	for (studentsIterator = students.begin();
		studentsIterator != students.end();
		studentsIterator++) {
		cout << endl << "Student name:" << studentsIterator->name;
	}

	//set
	set<Student> studentsSet;
	studentsSet.insert(Student("Alice", 1));
	studentsSet.insert(Student("Alice", 1));
	studentsSet.insert(Student("Bianca", 2));
	studentsSet.insert(Student("Bob", 3));

	set<Student>::iterator it;
	for (it = studentsSet.begin(); it != studentsSet.end(); it++) {
		cout << endl << "Unique student: " << it->name;
	}


}