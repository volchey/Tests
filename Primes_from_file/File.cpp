#include "File.hpp"
#include <sstream>
#include <cstdlib>

File::File(std::string file_name)
{
	in_file = new std::ifstream(file_name);
	out_file.open(file_name, std::ios_base::app);
}

void File::put_primes()
{
	out_file << "<root>\n <primes> ";
	for (auto l : p_list)
	{
		for (auto p : l)
			out_file << p << " ";
	}
	out_file << "</primes>\n</root>\n";
}
