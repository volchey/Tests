#ifndef USER_HPP
#define USER_HPP
#include "CityHotelRoom.hpp"

class User {
	public:
		User() {};
		int bookHotel(City const *city)
		{
			std::vector<Hotel*> hotels = city->get_hotels_list();
			int 	number = 0;
			Hotel *target_hotel;

			if (hotels.size() <= 0)
				return 0;
			std::cout << "There are " << hotels.size() << " hotels in " << city->get_name() << std::endl;
			print_hotels(hotels);
			std::cin >> number;

			try
			{	target_hotel = hotels.at(number);	}
			catch (std::exception &e)
			{
				std::cout << "There is no hotel with number: " << number << std::endl;
				exit(1);
			}

			std::vector<Room*> rooms;
			Room *target_room;

			rooms = target_hotel->get_rooms();
			if (rooms.size() <= 0)
				return (0);
			std::cout << "There are " << rooms.size() << " rooms in " << target_hotel->get_name() << std::endl;
			print_rooms(rooms);
			number = 0;
			std::cin >> number;

			try
			{	target_room = rooms.at(number);	}
			catch (std::exception &e)
			{
				std::cout << "There is no room with number: " << number << std::endl;
				exit(1);
			}

			return target_room->get_price();
		}

		void print_hotels(std::vector<Hotel*> hotels)
		{
			int number = 0;

			for (auto i = hotels.begin(); i != hotels.end(); ++i)
			{
				std::cout << number << ": " << (*i)->get_name() << std::endl;
				++number;
			}
			std::cout << "Select a number of the hotel: ";
		}

		void print_rooms(std::vector<Room*> rooms)
		{
			int number = 0;

			for (auto i = rooms.begin(); i != rooms.end(); ++i)
			{
				std::cout << number << ": price = " << (*i)->get_price() << std::endl;
				++number;
			}
			std::cout << "Select a number of the room: ";
		}
};

#endif