#include <iostream>
#include <fstream>
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

	static LabTest** reloadTextData(string fileName, int& noTests) {
		fstream file(fileName, ios::in);
		if (file.is_open()) {

			char buffer[100];
			//file >> noTests;
			file.getline(buffer, 100);
			noTests = atoi(buffer);

			LabTest** tests = new LabTest*[noTests];

			
			int iterator = 0;
			while (!file.getline(buffer, 100).eof()) 
			{
				string courseName(buffer);
				file.getline(buffer, 100);
				float duration = atof(buffer);
				char date[11];
				file.getline(date, 11);
				tests[iterator] = new LabTest(courseName, date, duration);
				//.read the number of grades
				file.getline(buffer, 100);
				int noStudents = atoi(buffer);
				//get the grades
				for (int i = 0; i < noStudents; i++) {
					file.getline(buffer, 100);
					int grade = atoi(buffer);
					tests[iterator]->addGrade(grade);
				}
				iterator += 1;

			}


			file.close();
			return tests;
		}
		else
			throw new exception("Missing file");
	}

	//serialize an object into a binary file/stream 


	//an exception to private
	friend ostream& operator<<(ostream& output, LabTest test);
	friend fstream& operator<<(fstream& file, LabTest& test);
};

ostream& operator<<(ostream& output, LabTest test) {
	output << endl << "The test name is: " << test.getSubject();
	output << endl << "The test duration is: " << test.duration;
	output << endl << "The test date is: " << test.date;
	output << endl << "Number of students taking the test: " << test.noStudents;
	output << endl << "Grades: ";
	for (int i = 0; i < test.noStudents; i++)
		output << " " << test.grades[i];

	return output;
}

fstream& operator<<(fstream& file, LabTest& test) {
	//one line - one value
	file << test.getSubject();
	file << endl << test.duration;
	file << endl << test.date;
	file << endl << test.noStudents;
	for (int i = 0; i < test.noStudents; i++)
		file << endl << test.grades[i];
	file << endl;
	return file;
}


int main() {
	///*LabTest test1("OOP", "27/11/2018", 1);
	//test1.addGrade(9);
	//test1.addGrade(10);
	//test1.addGrade(8);

	//cout << test1;*/

	//LabTest* tests[2];
	////tests[0] = &test1;		//avoid getting addresses of stack objects
	//tests[0] = new LabTest("OOP", "27/11/2018", 1);
	//tests[1] = new LabTest("DS", "27/11/2018", 2);
	//tests[0]->addGrade(9);
	//tests[0]->addGrade(10);
	//tests[0]->addGrade(8);

	//tests[1]->addGrade(8);
	//tests[1]->addGrade(7);

	//for (int i = 0; i < 2; i++)
	//	cout << endl << *tests[i];

	////generating a text report
	//fstream report;
	//report.open("Tests.txt", ios::out | ios::trunc);
	//int noTests = 2;

	//if (report.is_open()) {

	//	report << noTests << endl;
	//	for (int i = 0; i < 2; i++)
	//		report << *tests[i];
	//	report.close();
	//}
	//else
	//	cout << endl << "********* The file is not there !";


	////read the data from the text file
	//int noTests2;
	//LabTest ** newTest = LabTest::reloadTextData("Tests.txt", noTests2);

	//cout << endl << "*****************";
	//for (int i = 0; i < noTests2; i++)
	//	cout << *newTest[i];

	////working with binary files
	////THE WRONG VERSION - you need to serialize


	//fstream bFile("Test.data", ios::out | ios::binary | ios::trunc);
	//if (bFile.is_open()) {

	//	for (int i = 0; i < noTests2; i++) {
	//		//you write addresses
	//		bFile.write((char*)newTest[i], sizeof(LabTest));
	//	}

	//	bFile.close();
	//}

	//read the binary



	fstream bFile;
	int noTests2 = 2;
	bFile.open("Test.data", ios::in | ios::binary);
	LabTest ** newTestBinary = new LabTest*[2];
	for (int i = 0; i < noTests2; i++) {
		newTestBinary[i] = new LabTest("", "00/00/0000", 0);
	}
	if (bFile.is_open()) {

		for (int i = 0; i < noTests2; i++) {
			bFile.read((char*)newTestBinary[i], sizeof(LabTest));
		}

		bFile.close();
	}


	cout << endl << "***************** AFTER BINARY reading";
	for (int i = 0; i < noTests2; i++)
		cout << *newTestBinary[i];


	//LabTest** tests;
}