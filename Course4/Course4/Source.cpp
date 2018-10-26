#include <iostream>
#include <string>

using namespace std;

struct Student {
	int age;
	string name;
};

void printStudent(Student s) {

}

class StudentClass {
	int age;
	string name;
	void printStudent() {

	}
};

char* getName() {
	char buffer[10000];
	cout << endl << "Give me your name (any length): ";
	cin >> buffer;
	char* newName = new char[strlen(buffer) + 1];
	strcpy(newName, buffer);
	return newName;
}

void interchageValues(int vb1, int vb2) {
	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;
}
void interchageValues2(int* pVb1, int* pVb2) {
	int temp = *pVb1;
	*pVb1 = *pVb2;
	*pVb2 = temp;
}

void interchageValues3(int& vb1, int& vb2) {
	int temp = vb1;
	vb1 = vb2;
	vb2 = temp;
}

void main() {

	////you can't 
	////char* name = "John";

	//char name[100];
	//name[5] = '\0';
	//int variable;

	//std::cout << std::endl << "The name is " << name;
	//cout << endl << "Give me your name: ";
	////cin >> name;

	//cin.getline(name, 100);

	////cout.flush();

	//std::cout << std::endl << "The name is " << name;
	//cout << endl << "Give me your age: ";
	//cin >> variable;
	//cout << endl << "His age is " << variable;

	//char* newName = new char[50];

	////char buffer[10000];
	////std::cout << std::endl << "The new name is " << newName;

	////cout << endl << "Give me your name (any length): ";
	////cin >> buffer;
	////cout << endl << "The number is " << strlen(buffer + 1);
	////newName = new char[strlen(buffer + 1)];
	////newName = new char[strlen(buffer) +1];
	////strcpy(newName, buffer);

	//newName = getName();

	//std::cout << std::endl << "The new name is " << newName;

	////using string
	//string studentName;
	//cout << endl << "Student name is " << studentName;
	//studentName = "Alice";
	//studentName = "Bianca";
	//cout << endl << "Give me a new name for the student: ";
	//cin >> studentName;
	//cout << endl << "Student name is " << studentName;
	//studentName = studentName + " Alice";
	//cout << endl << "Student name is " << studentName;

	int a = 10;
	int b = 20;
	cout << endl << "a = " << a << " b = " << b;
	int temp = a;
	a = b;
	b = temp;
	cout << endl << "a = " << a << " b = " << b;

	interchageValues(a, b);
	cout << endl << "a = " << a << " b = " << b;

	interchageValues2(&a, &b);
	cout << endl << "a = " << a << " b = " << b;

	interchageValues3(a, b);
	cout << endl << "****** a = " << a << " b = " << b;
}