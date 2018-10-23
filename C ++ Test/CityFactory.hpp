#ifndef CITYFACTORY_HPP
#define CITYFACTORY_HPP

#include "CityHotelRoom.hpp"

class CityFactory {
	public:
		CityFactory(){}

		const City * create_city(){
			int input = 0;
			std::cout << "Press 1 - if you want to create city by yourself, 2 - create random city" << std::endl;
			std::cin >> input;
			return (input == 1 ? create_by_user() : create_random());
		}
	private:
		City const * create_random();
		City const * create_by_user();
};

const City * CityFactory::create_random()
{
	std::string			citys_list[7] = {"Kyiv", "Lviv", "Ternopil", "Sumy", "Uzhgorod", "Odessa", "Dnipro"};
	std::string			hotels_list[15] = {"KeepRoom", "Hilton Hotel", "Hotel Ukraina", "Favor Hotel", "Aquarius apartment", "Hotel SunLake", "Nivki Hotel", "Tourist Hotel Complex", "Premier Hotel", "Palace Hotel", "Opera Hotel", "Eagle", "CityHotel", "Alfavito Hotel", "The Star"};
	std::vector<Hotel*> hotels;
	int 				max_hotels_count = rand() % 10;

	for (int i = 0; i < max_hotels_count; ++i)
	{
		int 			max_room_count = rand() % 20;
		std::vector<Room*> rooms;
		for (int j = 0; j < max_room_count; ++j)
			rooms.push_back(new Room(rand() % 2000));
		hotels.push_back(new Hotel(hotels_list[rand() % 15], rooms));
	}
	return (new City(citys_list[rand() % 7], hotels));
}

const City * CityFactory::create_by_user()
{
	std::string city_name;
	int			hotels_count = 0;

	std::cout << "Type the name of your City: ";
	std::cin >> city_name;
	std::cout << "How many hotels should be in your city? ";
	std::cin >> hotels_count;
	std::vector<Hotel*> hotels;
	for (int h = 0; h < hotels_count; ++h)
	{
		std::string hotel_name;
		int 		room_count = 0;

		std::cout << "Type the name of " << h << " hotel: ";
		std::cin >> hotel_name;
		std::cout << "How many rooms should be in this hotel? " ;
		std::cin >> room_count;
		std::vector<Room*> rooms;
		for (int r = 0; r < room_count; ++r)
		{
			int price = 0;

			std::cout << "Type the price of " << r << " room: ";
			std::cin >> price;
			rooms.push_back(new Room(price));
		}
		hotels.push_back(new Hotel(hotel_name, rooms));
	}
	return new City(city_name, hotels);
}

#endif