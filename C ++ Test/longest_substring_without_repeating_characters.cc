
// Нужно найти самую длинную подстроку с неповторяющимися символами.
// Например "abcabcbb" - результат "abc" с длинной 3.

#include <iostream>
#include <vector>

void check_repeating(std::string &text, int i, std::string &buf, int &count)
{
	while (i < text.size() - 1 && buf.find(text[i]) == std::string::npos)
	{
		buf.push_back(text[i]);
		++i;
		++count;
	}
}

int main()
{
	std::string text = "pwwkew"; // "abcabcbb", "bbbbbb"
	int max_length = 0;
	int count = 0;
	std::string sub = "";
	std::string buf = "";

	for (int i = 0; (i < text.size() - 1); ++i)
	{
		check_repeating(text, i, buf, count);
		if (max_length < count)
		{
			max_length = count;
			sub = buf;
		}
		buf.clear();
		count = 0;
	}
	std::cout << "max substring is \"" << sub << "\" with length: " << max_length << "\n";
}
