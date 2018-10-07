#ifndef PRIMES_H
#define PRIMES_H

#include "Range.hpp"
#include <list>

class Primes
{
public:
	Primes(int low, int high) : _low(low), _high(high) {};
	~Primes() { _list.clear(); }
	bool			is_prime(int value);
	void			calculate();
	std::list<int>	get_list() { return _list; }

private:
	int				_low;
	int				_high;
	std::list<int>	_list;
};

bool Primes::is_prime(int value)
{
	for (int i = 2; i * i <= value; i++)
	{
		if (value % i == 0)
			return (false);
	}
	return (true);
}

void Primes::calculate()
{
	for (int i = _low; i < _high; ++i)
	{
		if (is_prime(i))
			_list.push_back(i);
	}
}

#endif