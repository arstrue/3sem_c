#pragma once
#include <iostream>
#include <cstring>
#include <string_view>

namespace mipt
{
    class String;
	class StringView
	{
	private:

		std::size_t mSize{ 0 };
		const char* mpData{ nullptr };

	public:

		StringView(const char* str);

		StringView();

		StringView(const StringView& s);

		StringView(String str);

		const char& operator[](std::size_t i) const;

		const char& at(std::size_t i) const;
		bool operator<(const StringView& right) const;

		std::string_view substr(size_t pos, size_t len);

        std::size_t size() const;
        const char* cStr() const;

        void remove_prefix(size_t n);
        void remove_suffix(size_t n);
	};
	std::ostream& operator<<(std::ostream& out, const mipt::StringView& s);
}