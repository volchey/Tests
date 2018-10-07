#ifndef FILE_H
# define FILE_H

#include "Primes.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <list>
#include "Primes.hpp"

class File
{
public:
	File(std::string file_name);
	void 			put_primes(std::list<Primes*>);
	std::string*	find_interval();
	std::ifstream	*get_in_file() { return in_file; }
	std::string		get_str_file() { return str_file; }

private:
	std::ifstream				*in_file;
	std::string					str_file;
	std::ofstream				out_file;
};

void	File::put_primes(std::list<Primes*> list)
{
	out_file << "<root>\n <primes> ";
	for (auto l : list)
	{
		for (auto p : l->get_list())
			out_file << p << " ";
	}
	out_file << "</primes>\n</root>\n";
}

File::File(std::string file_name)
{
	in_file = new std::ifstream(file_name);
	str_file.assign( (std::istreambuf_iterator<char>(*in_file)),
						(std::istreambuf_iterator<char>()));
	delete in_file;
	in_file = new std::ifstream(file_name);
	out_file.open(file_name, std::ios_base::app);
}

std::string* File::find_interval()
{
	std::string			line;
	std::string			*result = new std::string();

	if (in_file->is_open())
	{
		while (getline(*in_file, line))
		{
			if (line.find("<interval>") != std::string::npos)
			{
				getline(*in_file, *result);
				getline(*in_file, line);
				result->append(line);
				return (result);
			}
		}
	}
	return (NULL);
}

#endif