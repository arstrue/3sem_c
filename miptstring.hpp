#pragma once
#include <iostream>
#include <cstring>
#include <string_view>

namespace mipt
{
    class StringView;
    class String
    {
    private:

        std::size_t mSize{ 0 };
        std::size_t mCapacity{ 0 };
        char* mpData{ nullptr };

    public:

        String(const char* str);
        String();
        String(const String& s);
        String(std::size_t n, char a);
        String(StringView s);
        ~String();
        void reserve(std::size_t capacity);
        void resize(std::size_t size);
        String& operator=(const String& right);
        String operator+(const String& b);
        String& operator+=(const String& right);
        bool operator==(const String& right) const;
        bool operator<(const String& right) const;
        bool operator<=(const String& right) const;
        bool operator!=(const String& right) const;
        bool operator>(const String& right) const;
        bool operator>=(const String& right) const;
        char& operator[](std::size_t i);
        const char& operator[](std::size_t i) const;
        char& at(std::size_t i);
        const char& at(std::size_t i) const;
        void clear();
        void addCharacter(char c);
        std::size_t getSize()        const;
        std::size_t getCapacity()    const;
        const char* cStr()           const;
    };
    std::ostream& operator<<(std::ostream& out, const mipt::String& s);
    std::istream& operator>>(std::istream& in, mipt::String& s);
}