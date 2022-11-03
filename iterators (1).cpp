#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <string_view>

//task 1
void slide() {
	std::cout << "n elements & ^Z\n";
	std::vector<int> v;

	std::istream_iterator<int> iterat( std::cin ), eof;
	std::copy(iterat, eof, std::back_inserter(v));

	std::vector<int>::iterator it = std::max_element(v.begin(), v.end());
	std::sort(v.begin(), it);
	std::sort(it, v.end(), std::greater{});

	std::ostream_iterator<int> iter{ std::cout, " " };
	std::copy(v.cbegin(), v.cend(), iter);
	std::cout << std::endl << std::endl;
}	

//task 2
void vect_str_reverse(std::vector <std::string>& a) {
	std::vector <std::string> b (a.size());
	std::vector <std::string>::reverse_iterator it = b.rbegin();
	int n = 0;
	std::copy_if(a.begin(), a.end(), it, [&](std::string) {std::reverse(a[n].begin(), a[n].end()); ++n; return true; });
	std::swap(a, b);
	b.clear();
}

//task 3
bool uppercase(const std::string& s) {
	int n = 0;
	std::string b;
	std::copy_if(s.cbegin(), s.cend(), std::back_inserter(b), [&](char) {return islower(s[n++]) ? false : true; });
	return b == s ? true : false;
}

//task 4
bool isIdentifier(std::string_view s) {
	if (!std::isalpha(s[0]) && s[0] != '_')
		return false;
	int n = 0;
	std::string b;
	std::copy_if(s.cbegin(), s.cend(), std::back_inserter(b), [&](char) {return isalnum(s[n++]) || s[n - 1] == '_' ? true : false; });
	return b == s ? true : false;
}

//task 5
void space(std::string& s) {
	int n = 0;
	std::string a;
	std::copy_if(s.cbegin(), s.cend(), std::back_inserter(a), [&](char) {return s[n++] != ' ' ? true : false; });
	n = 0;
	std::string b;
	std::copy_if(s.cbegin(), s.cend(), std::back_inserter(b), [&](char) {return s[n++] == ' ' ? true : false; });
	a.append(b.begin(), b.end());
	s = a;
}

void test_task1();
void test_task2();
void test_task3();
void test_task4();
void test_task5();

int main() {
	//task 1
	test_task1();

	//task 2
	test_task2();

	//task 3
	test_task3();

	//task 4
	test_task4();

	//task 5
	test_task5();

	return 0;
}

void test_task1() {
	slide();
}

void test_task2() {
	std::vector <std::string> a{ "cat", "dog", "mouse", "elephant" }, b{ "a", "bc" };
	std::ostream_iterator<std::string> iter{ std::cout, " " };
	std::copy(a.begin(), a.end(), iter);
	vect_str_reverse(a);
	std::cout << "-> ";
	std::copy(a.begin(), a.end(), iter);
	std::cout << std::endl;
	std::copy(b.begin(), b.end(), iter);
	vect_str_reverse(b);
	std::cout << "-> ";
	std::copy(b.begin(), b.end(), iter);
	std::cout << std::endl << std::endl;
}

void test_task3() {
	std::array<std::string, 4> s{ "Cats and Dogs!", "CATS AND DOGS!", "ABc123!#?", "ABC123!#?" };
	if (uppercase(s[0]))
		std::cout << s[0] << " true\n";
	else
		std::cout << s[0] << " false\n";
	if (uppercase(s[1]))
		std::cout << s[1] << " true\n";
	else
		std::cout << s[1] << " false\n";
	if (uppercase(s[2]))
		std::cout << s[2] << " true\n";
	else
		std::cout << s[2] << " false\n";
	if (uppercase(s[3]))
		std::cout << s[3] << " true\n";
	else
		std::cout << s[3] << " false\n";
	std::cout << std::endl;
}

void test_task4() {
	std::array<std::string, 6> s{ "a", "isIdentifier", "_name123", "hello world", "123name", "my-name" };
	if (isIdentifier(s[0]))
		std::cout << s[0] << " true\n";
	else
		std::cout << s[0] << " false\n";
	if (isIdentifier(s[1]))
		std::cout << s[1] << " true\n";
	else
		std::cout << s[1] << " false\n";
	if (isIdentifier(s[2]))
		std::cout << s[2] << " true\n";
	else
		std::cout << s[2] << " false\n";
	if (isIdentifier(s[3]))
		std::cout << s[3] << " true\n";
	else
		std::cout << s[3] << " false\n";
	if (isIdentifier(s[4]))
		std::cout << s[4] << " true\n";
	else
		std::cout << s[4] << " false\n";
	if (isIdentifier(s[5]))
		std::cout << s[5] << " true\n";
	else
		std::cout << s[5] << " false\n";
	std::cout << std::endl;
}

void test_task5() {
	std::array<std::string, 2> s{ "cats and dogs", "   cats and  dogs" };
	std::cout << '"' << s[0] << '"' << " -> ";
	space(s[0]);
	std::cout << '"' << s[0] << '"' << '\n';
	std::cout << '"' << s[1] << '"' << " -> ";
	space(s[1]);
	std::cout << '"' << s[1] << '"' << '\n';
}