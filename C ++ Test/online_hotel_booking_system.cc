
// Дизайн системы бронирования отелей.
// Пользователь должен иметь возможность найти отель в выбранном городе и забронировать его.
#include "User.hpp"
#include "CityFactory.hpp"

int main()
{
	User user;
	City const *city;
	CityFactory factory;

	srand(time(0));
	city = factory.create_city();

	int room_price = user.bookHotel(city);
	std::cout << "The fee for this service is 10\% of the room price" << std::endl;
	std::cout << "Total amount = " << (room_price + (room_price / 10)) << "\n";
}



