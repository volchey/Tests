#include "File.hpp"
#include <thread>

std::mutex mtx;

void get_primes(std::string *interval, std::list<Primes*> *list)
{
    Range range;
    if (range.parse(*interval))
    {
        auto * primes = new Primes(range.get_low(), range.get_high());
        primes->calculate();
        mtx.lock();
        list->push_back(primes);
        mtx.unlock();
    }
}

int main(int argc, char **argv)
{
	std::list<std::thread>	threads;
	std::list<Primes*>		list;
	std::string				*interval;

	if (argc > 1)
	{
		File				file(argv[1]);
        while ((interval = file.find_interval()) != NULL)
            threads.push_back(std::thread(get_primes, interval, &list));
		for (auto & t : threads)
			t.join();
		file.put_primes(list);
		for (auto & l : list)
			delete l;
	}
}