
// Есть вектор данных из 0 и 1. 
// Нужно найти место с самым плохим распределением, и вывести индекс для вставки 1 равноудаленно от других значений.
// Например [1,0,0,0,0,0,0,0,1,0,1] - результат 4. после вставки получится вектор [1,0,0,0,1,0,0,0,1,0,1].

#include <iostream>
#include <vector>

int main()
{
  std::vector<int> data = {1,0,0,0,0,0,0,0,1,0,1};
  int result = 0;
  int count = 0;
  int max = 0;

  for (auto i = data.begin(); i != data.end(); ++i)
  {
  	for (auto j = i + 1; j != data.end() && *j == *i; ++j)
  	{
  		++count;
  	}
  	if (count > max)
  		max = count + 1;
  	count = 0;
  }

  result = (max / 2) + 1;

  std::cout << max << "\n";
  std::cout << result << "\n";
}
