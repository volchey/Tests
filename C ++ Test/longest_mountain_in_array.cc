
// Есть набор данных. Локальный пик - это подмассив в котором значения идут сначала в порядке возрастания, а потом спадания.
// Нужно посчитать длину самого большого пика.
// Например [2,1,4,7,3,2,5] - результат 5 (1 < 4 < 7 > 3 > 2).

#include <iostream>
#include <vector>

void  get_mountain(std::vector<int> &data, std::vector<int>::iterator &i, int &count)
{
  while (i != data.end() && *i > *(i - 1))
  {
    i++;
    count++;
  }
  while (i != data.end() && *i < *(i - 1))
  {
    i++;
    count++;
  }
}

int main()
{
  std::vector<int> data = {2,1,4,7,3,2,5};
  int result = 0;
  int count = 0;
  auto i = data.begin() + 1;

  while (i != data.end())
  {
    if (*i >= *(i - 1))
      get_mountain(data, i, count);
    if (count > result)
      result = count;
    count = 0;
    if (i != data.end())
      i++;
  }
  result++;

  std::cout << result << "\n";
}
