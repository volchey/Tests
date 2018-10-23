#ifndef CITYHOTELROOM_HPP
#define CITYHOTELROOM_HPP

#include <iostream>
#include <vector>
#include <ctime>

class Room {
	public:
		Room(int new_price) : price(new_price){}
		int get_price() const { return price; }
	private:
		int price;

};

class Hotel {
	public:
		Hotel(std::string new_hotel, std::vector<Room*> rooms) : hotel_name(new_hotel), room_list(rooms){}
		std::string get_name() const { return hotel_name; }
		std::vector<Room*> get_rooms() const { return room_list; }
	private:
		std::string	hotel_name;
		std::vector<Room*> room_list;

};

class City {
	public:
		City(std::string new_name, std::vector<Hotel*> hotels) :
		city_name(new_name),
		hotels_list(hotels)
		{}
		std::vector<Hotel*> get_hotels_list() const { return hotels_list; }
		std::string			get_name() const { return city_name; }
	private:
		std::string	city_name;
		std::vector<Hotel*> hotels_list;

};

#endif