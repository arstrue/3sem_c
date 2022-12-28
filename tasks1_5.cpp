#include <vector>
#include <iostream>
#include <span>
#include <cmath>
#include <array>
#include <string>
#include <numeric>

void test1();
void test2();
void test3();
void test4();
void test5();

//task1
int sumEven(const std::vector<int>& v)
{
	return std::accumulate(v.begin(), v.end(), 0, [](int a, int b) { return b % 2 ? a : a + b; });
}

//task2
std::vector<int> lastDigits1(const std::vector<int>& v)
{
	std::vector<int> tmp_v(v.size());
	for (size_t i = 0; i < tmp_v.size(); i++)
		tmp_v[i] = v[i] % 10;
	return tmp_v;
}

void lastDigits2(std::vector<int>& v)
{
	for (size_t i = 0; i < v.size(); i++)
		v[i] = v[i] % 10;
}

void lastDigits3(std::vector<int>* pv)
{
	for (size_t i = 0; i < pv->size(); i++)
		(*pv)[i] = (*pv)[i] % 10;
}

void lastDigits4(std::span<int> sp)
{
	for (size_t i = 0; i < sp.size(); i++)
		sp[i] = sp[i] % 10;
}

//task3
bool prime(int n)
{
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

std::vector<std::pair<int, int>> factorization(int n)
{
	std::vector<std::pair<int, int>> vpii;
	if (n == 1)
	{
		vpii.push_back(std::make_pair(1, 1));
		return vpii;
	}
	int i = 2, j;
	while (n > 1)
	{
		if (prime(i))
		{
			j = 0;
			while (n % i == 0)
			{
				n /= i;
				j++;
			}
			if (j > 0)
				vpii.push_back(std::make_pair(i, j));
		}
		i++;
	}
	return vpii;
}

//task4
class Time {
private:
	int mHours, mMinutes, mSeconds;
public:
	Time(int hours, int minutes, int seconds) : mHours(hours), mMinutes(minutes), mSeconds(seconds)
	{
	}

	Time(std::string_view s)// ñòðîêà â ôîðìàòå "hh:mm:ss"
	{
		std::string ss(s);
		mHours = std::stoi((ss.std::string::substr(0, 2)));
		mMinutes = std::stoi((ss.std::string::substr(3, 2)));
		mSeconds = std::stoi((ss.std::string::substr(6, 2)));
	}

	Time operator+(Time b) const
	{
		Time tmp(this->hours(), this->minutes(), this->seconds());
		int s = tmp.mSeconds;
		tmp.mSeconds = (tmp.mSeconds + b.seconds()) % 60;
		int m = tmp.mMinutes;
		tmp.mMinutes = (tmp.mMinutes + b.minutes() + (s + b.seconds()) / 60) % 60;
		tmp.mHours = (tmp.mHours + b.hours() + (m + b.minutes()) / 60) % 24;
		return tmp;
	}

	int hours() const
	{
		return mHours;
	}
	int minutes() const
	{
		return mMinutes;
	}
	int seconds() const
	{
		return mSeconds;
	}
};

std::ostream& operator<<(std::ostream& out, Time t)
{
	out << t.hours() << ':' << t.minutes() << ':' << t.seconds();
	return out;
}

//task5
template <typename T>
T maximum(const std::vector<T>& v) 
{
	T max{ v[0] };
	for (size_t i = 0; i < v.size(); ++i)
		if (v[i] > max)
			max = v[i];
	return max;
}

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();

	return 0;
}

template <typename T>
void print(std::vector<T>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		if (i == 0)
			std::cout << '{';
		std::cout << v[i];
		if (i == v.size() - 1)
			std::cout << '}';
		else
			std::cout << ", ";
	}
}

template <>
void print(std::vector<std::pair<int, int>>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		if (i == 0)
			std::cout << '{';
		std::cout << '{' << v[i].first << ", " << v[i].second << '}';
		if (i == v.size() - 1)
			std::cout << '}';
		else
			std::cout << ", ";
	}
}

template <>
void print(std::vector<std::string>& v) {
	for (size_t i = 0; i < v.size(); i++) {
		if (i == 0)
			std::cout << '{';
		std::cout << '"' << v[i] << '"';
		if (i == v.size() - 1)
			std::cout << '}';
		else
			std::cout << ", ";
	}
}

void test1()
{
	std::vector<int> v = { 4, 8, 15, 16, 42 };
	print(v);
	std::cout << std::endl << "sumEven = " << sumEven(v) << std::endl << std::endl;
}

void test2()
{
	std::vector<int> v = { 4, 8, 155, 16, 23 };
	print(v);
	std::cout << ':' << std::endl;

	v = lastDigits1(v);
	print(v);
	std::cout << std::endl;

	v = { 4, 8, 155, 16, 23 };
	lastDigits2(v);
	print(v);
	std::cout << std::endl;

	v = { 4, 8, 155, 16, 23 };
	lastDigits3(&v);
	print(v);
	std::cout << std::endl;

	v = { 4, 8, 155, 16, 23 };
	lastDigits4(v);
	print(v);
	std::cout << std::endl << std::endl;
}

void test3()
{
	int n = 60;
	std::cout << n << ": ";
	std::vector<std::pair<int, int>> v = factorization(n);
	print(v);
	std::cout << std::endl;

	n = 626215995;
	std::cout << n << ": ";
	v = factorization(n);
	print(v);
	std::cout << std::endl;

	n = 107;
	std::cout << n << ": ";
	v = factorization(n);
	print(v);
	std::cout << std::endl;

	n = 1;
	std::cout << n << ": ";
	v = factorization(n);
	print(v);
	std::cout << std::endl << std::endl;
}

void test4()
{
	Time t{ static_cast<std::string_view>("14:23:55") }, 
		t1{ static_cast<std::string_view>("20:20:20") };
	std::cout << t << " + " << t1 << " = " << t + t1 << std::endl << std::endl;
}

void test5()
{
	std::vector<int> vi = { -1 };
	std::vector<float> vf = { -12, 23, 34.5, 0, 21 };
	std::vector<std::string> vs = { "qw", "qwe", "abc" };
	std::vector<std::pair<int, int>> v_p_ii = { {1, 2}, {23, -1}, {-3, 2}, {23, 3} };

	std::cout << "vi = ";
	print(vi);
	std::cout << ", max(vi) = " << maximum(vi) << std::endl;

	std::cout << "vf = ";
	print(vf);
	std::cout << ", max(vf) = " << maximum(vf) << std::endl;

	std::cout << "vs = ";
	print(vs);
	std::cout << ", max(vs) = " << '"' << maximum(vs) << '"' << std::endl;

	std::cout << "v_p_ii = ";
	print(v_p_ii);
	std::cout << ", max(v_p_ii) = " 
		<< "{" << maximum(v_p_ii).first << ", " 
		<< maximum(v_p_ii).second << "}" << std::endl;
}
