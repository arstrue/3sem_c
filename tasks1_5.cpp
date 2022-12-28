#include<vector>
#include<iostream>
#include<span>
#include<cmath>
#include<array>
#include<string>

void test1();
void test2(); 
void test3();
void test4();
void test5();

//task1
int sumEven(const std::vector<int>& v)
{
	int sum = 0;
	for (unsigned i = 0; i < v.size(); i++)
		if (!(v[i] % 2))
			sum += v[i];
	return sum;
}

//task2
std::vector<int> lastDigits1(const std::vector<int>& v)
{
	std::vector<int> tmp_v;
	tmp_v.resize(v.size());
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
	for (int i = 2; i < (sqrt(n)); i++)
		if (n % i == 0)
			return false;
	if ((sqrt(n) - (int)sqrt(n)) < DBL_EPSILON)
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
	int i = 2;
	int j = 0;
	while (n > 1)
	{
		if (!prime(i))
		{
			i++;
			continue;
		}
		j = 0;
		while (n % i == 0)
		{
			n /= i;
			j++;
		}
		if (j > 0)
			vpii.push_back(std::make_pair(i, j));
		i++;
	}

	return vpii;
}

//task4
class Time {
private:
	int mHours, mMinutes, mSeconds;
public:
	Time(int hours, int minutes, int seconds): mHours(hours), mMinutes(minutes), mSeconds(seconds)
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

	//friend std::ostream& std::operator<<(std::ostream& out, Time t);
};

std::ostream& operator<<(std::ostream& out, Time t)
{
	out << t.hours() << ':' << t.minutes() << ':' << t.seconds();
	return out;
}

//task5
template <typename T>
T maximum(const std::vector<T>& v) {
	T max{ v[0] };
	for (int i = 0, size = v.size(); i < size; ++i)
	{
		if (v[i] > max)
			max = v[i];
	}
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

void test1()
{
	std::vector<int> v = { 4, 8, 15, 16, 42 };
	std::cout << "task1\n {4, 8, 15, 16, 42}\n sumEven = " << sumEven(v) << std::endl << std::endl;
}

void test2()
{
	std::cout << "task2\n { 4, 8, 155, 16, 23 }\n";
	std::vector<int> v = { 4, 8, 155, 16, 23 };
	v = lastDigits1(v);
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	v = { 4, 8, 155, 16, 23 };
	lastDigits2(v);
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	v = { 4, 8, 155, 16, 23 };
	lastDigits3(&v);
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	v = { 4, 8, 155, 16, 23 };
	lastDigits4(v);
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";

	std::cout << std::endl;
}

void test3()
{
	std::cout << "\ntask3\n60 ";
	std::vector<std::pair<int, int>> v = factorization(60);
	for (size_t i = 0; i < v.size(); i++)
		std::cout << "{" << v[i].first << ", " << v[i].second << "}, ";

	std::cout << std::endl << "626215995 ";
	v = factorization(626215995);
	for (size_t i = 0; i < v.size(); i++)
		std::cout << "{" << v[i].first << ", " << v[i].second << "}, ";

	std::cout << "1";
	v = factorization(1);
	for (size_t i = 0; i < v.size(); i++)
		std::cout << "{" << v[i].first << ", " << v[i].second << "}, ";

}

void test4()
{
	std::string_view s("14:23:55");
	std::string_view ss("20:20:20");
	Time t(s), t1(ss);
	std::cout << "\n\ntask4\n14:23:55 + 20:20:20 = " << (t + t1) << std::endl << std::endl;
}

void test5()
{
	//std::vector<int16_t> vi = { -23, 0, 43, -100 };
	std::vector<int16_t> vi = { -1 };
	std::vector<float> vf = { -12, 23, 34.5, 0 , 21 };
	std::vector<std::string> vs = { "qw","qwe", "abc" };
	std::vector<std::pair<int, int>> v_p_ii = { {1,2}, {23,-1}, {-3, 2}, {23, 3} };

	std::cout << "task5" << std::endl;
	std::cout << "vi = { -23, 0, 43, -100 }, max(vi) = ";
	std::cout << maximum(vi) << std::endl;
	std::cout << "vf = { -12, 23, 34.5, 0 , 21 }, max(vf) = ";
	std::cout << maximum(vf) << std::endl;
	std::cout << "vs = { \"qw\",\"qwe\", \"abc\" }, max(vs) = ";
	std::cout << maximum(vs) << std::endl;
	std::cout << "v_p_ii = { {1,2}, {23,-1}, {-3, 2}, {23, 3} }, max(v_s_ii) = ";
	std::cout << "{" << maximum(v_p_ii).first << ", " << maximum(v_p_ii).second << "}" << std::endl;
}

