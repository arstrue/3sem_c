#include <iostream>
#include <cstring>

//task1
namespace myspace {
	void printNTimes(const char* str, int n = 10) {
		for (int i = 0; i < n; i++)
			std::cout << str;
	}
}

//task2
int cubeV(int x) {
	return x * x * x;
}

//task3
int cubeR(int& x) {
	return x * x * x;
}

//task4
void countLetters(const char* str, int& numLetters, int& numDigits, int& numOther) {
	int len = strlen(str);
	numDigits = 0;
	numLetters = 0;
	for (int i = 0; i < len; i++) {
		if (isdigit(str[i]))
			numDigits++;
	}
	for (int i = 0; i < len; i++) {
		if (isalpha(str[i]))
			numLetters++;
	}
	numOther = len - numDigits - numLetters;
}

struct Book
{
	char title[100];
	int pages;
	float price;
};

//task5
void addPrice(Book& b, float x) {
	b.price += x;
}

//task 6
bool isExpensive(const Book& b) {
	if (b.price > static_cast <float> (1000))
		return true;
	return false;
}

int main() {
	myspace::printNTimes("stdy", 3);
	std::cout << std::endl;//task1

	std::cout << cubeV(3) << std::endl;//task2

	int a = 4;
	int& b = a;
	std::cout << cubeR(b) << std::endl;//task3

	int d, l, o;
	countLetters("4se)", l, d, o);//task4
	std::cout << l << " " << d << " " << o << std::endl;

	//task6
	Book book = { "aaa", 23, 1000 };
	std::cout << isExpensive(book) << std::endl;

	return 0;
}


