#include <string>
#include <string_view>
#include "miptstring.hpp"

using std::string;
using std::string_view;

//1st task
string capitalize(string s)
{
	string ss = "";
	if(not(s.length()))
		return ss;

	ss = s;
	if ('a' <= s[0] and s[0] <= 'z')
	{
		ss[0] = ss[0] + ('A' - 'a');
		return ss;
	}
	ss[0] = ss[0] - ('A' - 'a');
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
	bool flag = true;
	int start = 0, sum = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if ('0' <= s[i] and s[i] <= '9' and flag)
		{
			flag = false;
			start = i;
		}
		else if (not('0' <= s[i] and s[i] <= '9') and not(flag))
		{
			sum += stoi(s.substr(start, i - start));
			flag = true;
		}
	}
	bool flag1 = true;
	bool flag2 = true;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '[')
			flag1 = false;
		if (s[i] == ']')
			flag2 = false;
	}
	
	if (flag1 or flag2)
		throw std::invalid_argument("");
	else
		return sum;
}

//task6
int* n = new int(132);
string* s1 = new string("Cats and Dogs");
int* n1 = new int[5]{ 10, 20, 30, 40, 50 };
string* s2 = new string[3]{ "Cat", "Dog", "Mouse" };
string_view* s3 = new string_view[3]{ s2[0],s2[1] ,s2[2] };

//task7
mipt::String str1 = "Cat";
mipt::String* str2 = new mipt::String("Cat");
char x[sizeof(mipt::String)];
mipt::String* str3 = new(x) mipt::String("Elephant");

int main()
{
	delete n;
	delete s1;
	delete[] n1;
	delete[] s2;
	delete[] s3;
	std::cout << *str3;
	str3->~String();
}
