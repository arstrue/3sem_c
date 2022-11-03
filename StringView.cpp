#include <iostream>
#include <cstring>
#include <string_view>
#include "miptstring.hpp"
#include "StringView.hpp"

namespace mipt
{
	StringView::StringView(const char* str)
	{
		mSize = std::strlen(str);
		mpData = str;
	}

	StringView::StringView() : StringView("") {}

	StringView::StringView(const StringView& s)
	{
		mSize = s.mSize;
		mpData = s.mpData;
	}

	StringView::StringView(mipt::String str)
	{
		mSize = str.getSize();
		mpData = &str.at(0);
	}

	const char& StringView::operator[](std::size_t i) const
	{
		return mpData[i];
	}

	const char& StringView::at(std::size_t i) const
	{
		if (i >= mSize)
			throw std::out_of_range{ "mipt::StringView::at: index >= this->size()" };
		return mpData[i];
	}

	bool StringView::operator<(const StringView& right) const
	{
		std::size_t i = 0;
		while (i < mSize && i < right.mSize && mpData[i] == right.mpData[i])
			i++;

		return mpData[i] < right.mpData[i];
	}

	std::string_view StringView::substr(size_t pos, size_t len)
	{
		std::string_view strv{ &mpData[pos], len };
		return strv;
	}

	void StringView::remove_prefix(size_t n) {
		mSize -= n;
	}
	void StringView::remove_suffix(size_t n) {
		mSize -= n;
		mpData += n;
	}

	std::size_t StringView::size() const { return mSize; }
	const char* StringView::cStr() const { return mpData; }

	std::ostream& operator<<(std::ostream& out, const mipt::StringView& s) {
		size_t size = s.size();
		for (int i = 0; i < size; ++i)
			out << s[i];
		return out;
	}
}