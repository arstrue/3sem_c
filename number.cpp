#include <iomanip>
#include <string>
#include "number.h"

Number::Number(int a) {
    int temp = a;
    capacity = 0;
    while (temp != 0) {
        temp /= base;
        capacity += 1;
    }

    if (capacity == 0)
        capacity = 1;

    data = new char[capacity];

    for (size_t i = 0; i < capacity; ++i) {
        data[i] = a % base;
        a /= base;
    }

    size = capacity;
}

Number::Number() : Number(0) {}

Number::Number(const Number& n) {
    size = n.size;
    capacity = n.capacity;
    data = new char[capacity];
    for (size_t i = 0; i < size; ++i)
        data[i] = n.data[i];
}

Number::Number(const char* str) {
    int len = std::strlen(str);
    size = (len + len % 2) / 2;
    capacity = size;
    data = new char[capacity];

    char symbol[2];
    for (size_t i = 0; i < size; i++) {
        symbol[1] = str[len - 2 * i - 1];
        if (len - 2 * i - 1 > 0)
            symbol[0] = str[len - 2 * i - 2];
        else
            symbol[0] = '0';
        data[i] = std::stoi(symbol);
    }
}

Number& Number::operator=(const Number& right) {
    size = right.size;
    capacity = right.capacity;
    data = new char[capacity];
    for (size_t i = 0; i < size; ++i)
        data[i] = right.data[i];
    return *this;
}

Number Number::operator+(Number a) {
    Number result;
    size_t i;
    int carry;

    if (size < a.size)
        std::swap(*this, a);
    result.capacity = size + 1;
    result.data = (char*)calloc(result.capacity, sizeof(char));
    result.size = size;

    for (i = 0, carry = 0; i < a.size; ++i) {
        result.data[i] = (data[i] + a.data[i] + carry) % base;
        carry = (data[i] + a.data[i] + carry) / base;
    }
    --i;
    while (++i < size) {
        result.data[i] = (data[i] + carry) % base;
        carry = (data[i] + carry) / base;
    }
    if (carry) {
        result.data[i] = carry;
        ++result.size;
    }

    return result;
}

void Number::operator+=(const Number& a) {
    *this = *this + a;
}

Number Number::operator*(const Number& right) const {
    Number result;
    if (size == 1 && data[0] == 0 || right.size == 1 && right.data[0] == 0)
        return 0;

    result.size = size + right.size - 1;
    result.capacity = capacity + right.capacity;
    int* carry = (int*)std::calloc(result.capacity, sizeof(int));

    result.data = (char*)calloc(result.capacity, sizeof(char));

    for (size_t i = 0; i < size; ++i)
        for (size_t j = 0; j < right.size; ++j) {
            unsigned temp = result.data[i + j] + data[i] * right.data[j] + carry[i + j];
            result.data[i + j] = temp % base;
            carry[i + j + 1] += temp / base;
            carry[i + j] = 0;
        }
    if (carry[result.size]) {
        result.data[result.size] = carry[result.size];
        ++result.size;
    }

    free(carry);
    return result;
}

void Number::operator*=(const Number& a) {
    *this = *this * a;
}

Number::~Number() {
    delete[] data;
}

std::ostream& operator<<(std::ostream& stream, const Number& right) {
    stream << (int)right.data[right.size - 1];

    for (std::size_t i = 0; i < right.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << (int)right.data[right.size - 2 - i];

    return stream;
}

bool Number::isEven() const {
    return data[0] % 2 ? false : true;
}

Number Fibonacci(unsigned i) {
    if (i++ <= 1)
        return --i;

    Number* a = new Number[3]{ 0, 1, 1 }, res;
    for (unsigned k = 3; k < i; ++k) {
        a[0] = a[1];
        a[1] = a[2];
        a[2] = a[0] + a[1];
    }

    res = a[2];
    delete[] a;
    return res;
}

Number factorial(unsigned i) {
    if (i <= 1)
        return 1;

    Number res = 2;
    for (unsigned k = 3; k <= i; k++)
        res *= k;

    return res;
}

bool Number::operator==(const Number& a) const {
    if (size != a.size) 
        return false;
     for (size_t i = 0; i < size; ++i)
        if (data[i] != a.data[i]) 
            return false;
    return true;
}

bool Number::operator!=(const Number& a) const {
    return !(*this == a);
}

bool Number::operator>(const Number& a) const {
    if (size > a.size)
        return true;
    if (size < a.size) 
        return false;
    for (size_t i = 0; i < size; ++i) {
        if (data[size - i - 1] > a.data[size - i - 1])
            return true;
        if (data[size - i - 1] < a.data[size - i - 1])
            return false;
    }
    return false;
}

bool Number::operator<(const Number& a) const {
    return !(*this > a) && *this != a;
}

void Number::div2() {
    for (size_t i = 0, carry = 0, temp; i < size; ++i) {
        temp = data[size - i - 1] + carry * base;
        data[size - i - 1] = temp / 2;
        carry = temp % 2;
    }
    if (!data[size - 1])
        --size;
}

void hailstone(Number n) {
    unsigned steps = 0;
    Number max = n, _n = n;

    while (_n != 1) {
        if (_n > max)
            max = _n;
        ++steps;
        if (_n.isEven())
            _n.div2();
        else
            _n = Number(3) * _n + 1;
    }
    std::cout << "\nn = " << n << "\nsteps = " << steps << "\nmax = " << max << std::endl;
}
