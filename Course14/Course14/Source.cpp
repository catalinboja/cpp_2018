#include <iostream>
#include <string>

using namespace std;

int sum(int a, int b) {
	return a + b;
}

template<typename T>
T sumTemplate(T a, T b) {
	return a + b;
}

class Fridge {

};

class Flower {

};
template<typename T, typename R>
class Box {
public:
	float weight;
	T *content;
	R color;

	T* getContent() {
		return this->content;
	}

	void setContent(T* value) {
		this->content = value;
	}

	void setContent(T value) {
		this->content = &value;
	}

	bool compare(Box<T,R> &box) {
		if (this->content > box.content)
			return true;
		else
			return false;
	}
};

template<>
bool Box<char, char>::compare(Box<char, char> &box) {
	if (strcmp(this->content,box.content) == 1)
		return true;
	else
		return false;
}

void main() {
	int vb1 = 10;
	int vb2 = 20;

	int result = sumTemplate<int>(vb1, vb2);

	string name1 = "Test";
	string name2 = "Test2";
	string finalName = sumTemplate<string>(name1, name2);

	cout << endl << "Final value is " << result;
	cout << endl << "Final value is " << finalName;

	Flower f;
	Fridge fridge;
	//using the template class
	Box<Flower, char> flowerBox;
	flowerBox.content = &f;
	//flowerBox.content = &fridge;
	Box<Fridge, char> fridgeBox;
	fridgeBox.content = &fridge;

}