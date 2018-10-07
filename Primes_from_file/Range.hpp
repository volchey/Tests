#ifndef RANGE_H
#define RANGE_H

#include <fstream>
#include <sstream>

class Range
{
public:
	Range() : _low(0), _high(0) {}
	bool	parse(std::string);
	int		get_low() const { return _low; }
	int		get_high() const { return _high; }

private:
	int _low;
	int _high;
};

bool Range::parse(std::string str)
{
	std::string			line;
	std::string 		start;
	std::string 		finish;
	std::stringstream	s;

	s << str;
	s >> start >> _low >> finish;
	if (start.compare("<low>") == 0 && finish.compare("</low>") == 0 && _low)
	{
		s >> start >> _high >> finish;
		if (start.compare("<high>") == 0 && finish.compare("</high>") == 0 && _high)
			return (true);
	}
	_low = 0;
	_high = 0;
	return (false);
}


#endif