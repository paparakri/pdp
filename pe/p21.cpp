#include <iostream>
#include <set>
using namespace std;

 int getSum( int x)
{

   int divisorSum = 1;
  for ( int divisor = 2; divisor * divisor <= x; divisor++)
    if (x % divisor == 0)
    {
      divisorSum += divisor;
      auto otherDivisor = x / divisor;
      if (otherDivisor != divisor)
        divisorSum += otherDivisor;
    }

  return divisorSum;
}

int main()
{
  set< int> amicables;

    int MaxAmicable = 100000;
  for ( int i = 2; i <= MaxAmicable; i++)
  {
    auto sibling = getSum(i);

    if (i == getSum(sibling) && i != sibling)
    {
      amicables.insert(i);
      amicables.insert(sibling);
    }
  }

   int tests;
  cin >> tests;
  while (tests--)
  {
     int x;
    cin >> x;

     int sum = 0;
    for (auto i : amicables)
    {
      if (i > x)
        break;

      sum += i;
    }

    cout << sum << endl;
  }
  return 0;
}
