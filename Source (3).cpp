#include <string>
#include <string_view>
#include "miptstring.hpp"
#include "StringView.hpp"

using std::string;
using std::string_view;



//1st task
string capitalize(string s)
{
	string ss = "";
	if(s.empty())
		return ss;

	ss = s;
	if (islower(s[0]))
		ss[0] = toupper(s[0]);
	if (isupper(s[0]))
		ss[0] = tolower(s[0]);

	return ss;
}

//2nd task
string repeat1(string_view s)
{
	string ss;
	ss.resize(2 * s.length());
	for (int i = 0; i < 2 * s.length(); i++)
		ss[i] = s[i % s.length()];
	return ss;
}

void repeat2(string& s)
{
	int len = s.length();
	s.resize(2 * len);
	for (int i = 0; i < 2 * len; i++)
		s[i] = s[i % len];
}

void repeat3(string* s)
{
	int len = s->length();
	s->resize(2 * len);
	for (int i = 0; i < 2 * len; i++)
		(*s)[i] = (*s)[i % len];
}

string* repeat4(string_view s)
{
	string* ss = new string();
	ss->resize(2 * s.length());
	for (int i = 0; i < 2 * s.length(); i++)
		(*ss)[i] = s[i % s.length()];
	return ss;
}

//3rd task
string operator*(string s, int n)
{
	string ss;
	ss.resize(n * s.length());
	for (int i = 0; i < n * s.length(); i++)
		ss[i] = s[i % s.length()];
	return ss;
}

//task4
void truncateToDot(string& s)
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] == '.')
		{
			s.resize(i);
		}
}

//task5
int sumOfString(string s)
{
	if (s.empty())
		throw std::invalid_argument("");

	bool flag = false, flag1 = true, notdigit = true;
	int start = 0, sum = 0;
	for (int i = 1; i < s.length(); i++)
	{
		if (isdigit(s[i]) && notdigit)
		{
			notdigit = false;
			start = i;
		}
		else if (!isdigit(s[i]) && !notdigit)
		{
			if (s[i] != ',' && i != s.length() - 1) {
				flag = true;
				break;
			}
			sum += stoi(s.substr(start, i - start));
			notdigit = true;
		}
		else if (!isdigit(s[i]) && notdigit && (i == s.length() - 1 || s[i] != ' ' || s[i - 1] != ',' || !isdigit(s[i + 1]))) {
			flag = true;
			break;
		}
	}

	if (s.length() == 2)
		flag = false;
	if (s[0] == '[' && s[s.length() - 1] == ']')
		flag1 = false;

	if (flag || flag1)
		throw std::invalid_argument("");
	else
		return sum;
}

//task6
int* n = new int(132);
string* s1 = new string("Cats and Dogs");
int* n1 = new int[5]{ 10, 20, 30, 40, 50 };
string* s2 = new string[3]{ "Cat", "Dog", "Mouse" };
string_view* s3 = new string_view[3]{ s2[0], s2[1], s2[2] };

//task7
mipt::String str1 = "Cat";
mipt::String* str2 = new mipt::String("Dog");
char x[sizeof(mipt::String)];
mipt::String* str3 = new(x) mipt::String("Elephant");

int main()
{
	//task 1
	string* str = new string[3]{ "", "Cat", "dog" };
	for (int i = 0; i < 3; ++i)
		std::cout << '"' << str[i] << '"' << " -> " << '"' << capitalize(str[i]) << '"' << std::endl;
	std::cout << std::endl;

	//task 2
	string_view r1 = "Apple", r4 = "Banana";
	string r2 = "Pineapple", r3 = "Watermelon";
	std::cout << '"' << r1 << '"' << " -> " << '"' << repeat1(r1) << '"' << std::endl;
	std::cout << '"' << r2 << '"' << " -> ";
	repeat2(r2);
	std::cout << '"' << r2 << '"' << std::endl;
	std::cout << '"' << r3 << '"' << " -> ";
	repeat3(&r3);
	std::cout << '"' << r3 << '"' << std::endl;
	string* r4_0 = repeat4(r4);
	std::cout << '"' << r4 << '"' << " -> " << '"' << *r4_0 << '"' << std::endl << std::endl;
	delete r4_0;

	//task 3
	string s = "Multiplying";
	std::cout << '"' << s << '"' << " -> " << '"' << s * 5 << '"' << std::endl << std::endl;

	//task 4
	string* t = new string[3]{ "cat.dog.mouse.elephant.tiger.lion", "wikipedia.org", ".com" };
	for (int i = 0; i < 3; ++i) {
		std::cout << '"' << t[i] << '"' << " -> ";
		truncateToDot(t[i]);
		std::cout << '"' << t[i] << '"' << std::endl;
	}
	std::cout << std::endl;

	//task 5
	string* sum = new string[4]{ "[10, 20, 30, 40, 50]", "[4, 8, 15, 16, 23, 42]" , "[20]", "[]"};
	for (int i = 0; i < 4; ++i) {
		std::cout << '"' << sum[i] << '"' << ": ";
		int k = sumOfString(sum[i]);
		std::cout << k << std::endl;
	}
	std::cout << std::endl;

	//task 6
	std::cout << *n << '\n' << '"' << *s1 << '"' << '\n';
	for (int i = 0; i < 5; ++i)
		std::cout << n1[i] << ' ';
	std::cout << std::endl;
	for (int i = 0; i < 3; ++i)
		std::cout << '"' << s2[i] << '"' << ' ';
	std::cout << std::endl;
	for (int i = 0; i < 3; ++i)
		std::cout << '"' << s3[i] << '"' << ' ';
	std::cout << std::endl << std::endl;
	delete n;
	delete s1;
	delete[] n1;
	delete[] s2;
	delete[] s3;

	//task 7
	std::cout << "Stack: " << str1 << "\nHeap: " << *str2 << "\nPlacement new: " << *str3 << std::endl;
	delete str2;
	str3->~String();

	return 0;
}