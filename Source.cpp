#include<vector>
#include<iostream>
#include<span>
#include<cmath>

void test1();

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
	for (int i = 0; i < tmp_v.size(); i++)
		tmp_v[i] = v[i] % 10;
	return tmp_v;
}

void lastDigits2(std::vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] % 10;
}

void lastDigits3(std::vector<int>* pv)
{
	for (int i = 0; i < pv->size(); i++)
		(*pv)[i] = (*pv)[i] % 10;
}

void lastDigits4(std::span<int> sp)
{
	for (int i = 0; i < sp.size(); i++)
		sp[i] = sp[i] % 10;
}

//task3
bool prime(int n)//впомогательна€ фунци€ определ€юща€ простое ли число
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

int main()
{
	//test1();
	std::vector<std::pair<int, int>> v = factorization(1);
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i].first << " " << v[i].second << "\n";
	return 0;
}

void test1()
{
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
}