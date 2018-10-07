#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Range.hpp"
#include "Primes.hpp"
#include "File.hpp"
#include <istream>

TEST_CASE( "is prime", "[Prime]")
{
	Primes	prime(1, 50);
	int		true_arr[16] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	int		false_arr[34] = {4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22, 24, 25, 26, 27, 28, 30, 32, 33, 34, 35, 36, 38, 39, 40, 42, 44, 45, 46, 48, 49, 50};

	for (auto i : true_arr)
		REQUIRE(prime.is_prime(i) == true);
	for (auto i : false_arr)
		REQUIRE(prime.is_prime(i) == false);
}

TEST_CASE( "parse range", "[Range]")
{
	Range *range = new Range();

	SECTION( "correct format string ")
	{
		range->parse("<low> 200</low>\n<high> 300</high>");
		REQUIRE(range->get_low() == 200);
		REQUIRE(range->get_high() == 300);
	}
	SECTION( "incorrect low format" )
	{
		range->parse("<low 200</low>\n<high> 300</high>");
		REQUIRE(range->get_low() == 0);
		REQUIRE(range->get_high() == 0);
	}
	SECTION ( "many spaces is normal" )
	{
		range->parse("<low> 200                </low>\n<high>    300</high>");
		REQUIRE(range->get_low() == 200);
		REQUIRE(range->get_high() == 300);
	}
	SECTION ( "incorrect high format ")
	{
		range->parse("<low> 200</low>\n<high> 300</h igh>");
		REQUIRE(range->get_low() == 0);
		REQUIRE(range->get_high() == 0);
	}
	delete range;
}

