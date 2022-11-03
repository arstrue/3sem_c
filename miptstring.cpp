#include <iostream>
#include <cstring>
#include "miptstring.hpp"
#include "StringView.hpp"

namespace mipt {

    String::String(const char* str)
    {
        std::size_t strSize = std::strlen(str);
        resize(strSize);
        std::memcpy(mpData, str, mSize);

        //std::cout << "mipt::String Constructor (" << mpData << ")" << std::endl;
    }

    String::String() : String("") {}
    String::String(const String& s) : String(s.cStr()) {}

    String::String(std::size_t n, char a)
    {
        resize(n);

        for (std::size_t i = 0; i < mSize; ++i)
            mpData[i] = a;

        //std::cout << "mipt::String Constructor (" << mpData << ")" << std::endl;
    }

    String::String(StringView s) : String(&s.at(0))
    {
        resize(s.size());
        /*for (std::size_t i = 0; i < mSize; ++i)
            mpData[i] = s[i];*/

        //std::cout << "mipt::String Constructor (" << mpData << ")" << std::endl;
    }

    String::~String()
    {
        //std::cout << "mipt::String Destructor (" << mpData << ")" << std::endl;
        delete[] mpData;
    }

    void String::reserve(std::size_t capacity)
    {
        if (capacity <= mCapacity)
            return;

        mCapacity = std::max(2 * mCapacity, capacity);
        char* newData = new char[mCapacity]; // errorCheckedMalloc(mCapacity);

        if (mpData)
            std::memcpy(newData, mpData, mSize + 1);

        delete[] mpData;
        mpData = newData;
    }


    void String::resize(std::size_t size)
    {
        reserve(size + 1);
        mSize = size;
        mpData[mSize] = '\0';
    }


    String& String::operator=(const String& right)
    {
        if (this == &right)
            return *this;

        mSize = right.mSize;
        resize(mSize);

        std::memcpy(mpData, right.mpData, mSize + 1);

        return *this;
    }


    String String::operator+(const String& b)
    {
        String result;
        result.resize(mSize + b.mSize);

        std::memcpy(result.mpData, mpData, mSize);
        std::memcpy(result.mpData + mSize, b.mpData, b.mSize);
        result.mpData[result.mSize] = '\0';

        return result;
    }

    String& String::operator+=(const String& right)
    {
        *this = *this + right;
        return *this;
    }

    bool String::operator==(const String& right) const
    {
        if (mSize != right.mSize)
            return false;

        std::size_t i = 0;
        while (i < mSize && mpData[i] == right.mpData[i])
            i++;

        return i == mSize;
    }

    bool String::operator<(const String& right) const
    {
        std::size_t i = 0;
        while (i < mSize && i < right.mSize && mpData[i] == right.mpData[i])
            i++;

        return mpData[i] < right.mpData[i];
    }

    bool String::operator<=(const String& right) const
    {
        std::size_t i = 0;
        while (i < mSize && i < right.mSize && mpData[i] == right.mpData[i])
            i++;

        return mpData[i] <= right.mpData[i];
    }

    bool String::operator!=(const String& right) const
    {
        return !(*this == right);
    }

    bool String::operator>(const String& right) const
    {
        return !(*this <= right);
    }

    bool String::operator>=(const String& right) const
    {
        return !(*this < right);
    }

    char& String::operator[](std::size_t i)
    {
        return mpData[i];
    }

    const char& String::operator[](std::size_t i) const
    {
        return mpData[i];
    }

    char& String::at(std::size_t i)
    {
        if (i >= mSize)
            throw std::out_of_range{ "mipt::String::at: index >= this->size()" };
        return mpData[i];
    }

    const char& String::at(std::size_t i) const
    {
        if (i >= mSize)
            throw std::out_of_range{ "mipt::String::at: index >= this->size()" };
        return mpData[i];
    }

    void String::clear()
    {
        delete[] mpData;

        mSize = 0;
        mCapacity = 1;
        mpData = new char[mCapacity];
        mpData[0] = '\0';
    }

    void String::addCharacter(char c)
    {
        if (mSize + 1 == mCapacity)
            reserve(2 * mCapacity);

        mpData[mSize] = c;
        resize(mSize + 1);
    }


    std::size_t String::getSize()        const { return mSize; }
    std::size_t String::getCapacity()    const { return mCapacity; }
    const char* String::cStr()           const { return mpData; }

    std::ostream& operator<<(std::ostream& out, const mipt::String& s)
    {
        out << s.cStr();
        return out;
    }

    std::istream& operator>>(std::istream& in, mipt::String& s)
    {
        s.clear();
        while (true)
        {
            char x = in.get();
            if (std::isspace(x))
                break;
            s.addCharacter(x);
        }
        return in;
    }
}