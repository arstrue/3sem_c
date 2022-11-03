#include <iostream>

class Number {
private:
    static const int base = 100;
    std::size_t size;
    std::size_t capacity;
    char* data;

public:
    Number(int a);
    Number();
    Number(const Number& n);
    Number(const char* str);
    ~Number();
    Number& operator=(const Number& right);
    Number operator+(Number a);
    void operator+=(const Number& a);
    bool isEven() const;
    Number operator*(const Number& right) const;
    void operator*=(const Number& a);
    bool operator==(const Number& a) const;
    bool operator!=(const Number& a) const;
    bool operator>(const Number& a) const;
    bool operator<(const Number& a) const;
    void div2();

    friend std::ostream& operator<<(std::ostream& stream, const Number& right);
};