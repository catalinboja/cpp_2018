#include <iostream>
#include <string>

using namespace std;

class LabTest {
	string subject;
	char date[11];		//date pattern dd/mm/YYYY
	float duration;
	int *grades;
	int noStudents;
public:

	LabTest(string Subject, const char* Date, float Duration) :duration(Duration) {
		this->subject = Subject;
		this->setDate(Date);
		this->grades = NULL;
		this->noStudents = 0;
	}

	LabTest(const LabTest& test) {
		this->subject = test.subject;
		this->duration = test.duration;
		this->noStudents = test.noStudents;
		strcpy(this->date, test.date);
		if (test.grades != NULL) {
			this->grades = new int[this->noStudents];
			for (int i = 0; i < this->noStudents; i++)
				this->grades[i] = test.grades[i];
		}
		else
		{
			this->grades = NULL;
		}
	}

	~LabTest() {
		if (this->grades != NULL)
			delete[] this->grades;
	}

	void setDate(const char* Date) {
		if (Date != NULL && strlen(Date) == 10 && Date[2] == '/')
			strcpy(this->date, Date);
		else
			throw new exception("Bad date !");
	}

	//overloading
	void info() {
		cout << endl << "This is a test data";
	}
	void info(string message) {
		cout << endl << message <<  "This is a test data";
	}

	void info( int value) {
		cout << endl << value << "This is a test data for "<<this->subject;
	}

	static void generalInfo() {
		cout << endl << "This is a class static method";
	}

	void addGrade(int grade) {
		int* newGrades = new int[this->noStudents + 1];
		for (int i = 0; i < this->noStudents; i++) {
			newGrades[i] = this->grades[i];
		}
		newGrades[this->noStudents] = grade;
		if (this->grades != NULL)
			delete[] this->grades;
		this->grades = newGrades;
		this->noStudents += 1;
	}

	void operator=(LabTest test) {
		this->subject = test.subject;
		this->duration = test.duration;
		this->noStudents = test.noStudents;
		strcpy(this->date, test.date);
		if (test.grades != NULL) {

			//avoiding a memory leak
			if (this->grades != NULL)
				delete[] this->grades;

			this->grades = new int[this->noStudents];
			for (int i = 0; i < this->noStudents; i++)
				this->grades[i] = test.grades[i];
		}
		else
		{
			this->grades = NULL;
		}
	}

	string getSubject() {
		return this->subject;
	}

	//static void operator<<(ostream&, LabTest) {

	//}

	//option1
	LabTest operator+(int value) {
		LabTest result = *this;
		result.addGrade(value);
		return result;
	}

	//an exception to private
	friend ostream&  operator<<(ostream& output, LabTest test);
	friend void operator>>(istream&input, LabTest& test);
};

ostream& operator<<(ostream& output, LabTest test) {
	output << endl << "The test name is: " << test.getSubject();
	output << endl << "The test duration is: " << test.duration;

	return output;
}

void operator>>(istream&input, LabTest& test) {
	cout << endl << "Give a new subject";
	input >> test.subject;
	//other values
}

//LabTest operator+(LabTest test,  int value) {
//	LabTest result = test;
//	result.addGrade(value);
//	return result;
//}

LabTest operator+(int value, LabTest test) {
	return test + value;
}

void main() {
	LabTest test1("OOP C++", "26/11/2018", 1.5);
	LabTest test2("OOP C++", "28/11/2018", 1.5);

	test2.addGrade(9);
	test2.addGrade(10);

	LabTest test3 = test2;

	test3 = test2;	//by default is doing a copy&paste
					// void operator=(LabTest&, LabTest)
					//test3.operator=(test2)

	int vb1 = 10;
	int vb2 = 20;
	int vb3 = vb1 + vb2;	//int vb3 =  int operator+(int, int)


	test1.info();
	//test1.generalInfo();
	LabTest::generalInfo();

	cout << test1 << test2;		//void operator<<(ostream&, LabTest)

	cin >> test1;

	//test1 = test1 + 9; //add another grade
	test1 = 9 + test1;
	//test1 += 8;	//add another grade	operator+=
	//test1++;	//increment all grades by 1	operator++

	//if (test1 > test2)	//operator>
	//	cout << endl << "Test 1 has a bigger average (grades)";

	//float averageGrade = test1;

	//if (!test1)
	//	cout << endl << "There are no grades available";

}