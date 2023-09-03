#include <stdio.h>
using namespace std;

int main()
{
	freopen("p11.in", "r", stdin);
	
   int Size = 20;
   int matrix[Size][Size];

  for (int y = 0; y < Size; y++)
    for (int x = 0; x < Size; x++)
      scanf("%d", &matrix[x][y]);

   int best = 0;
  for ( int y = 0; y < Size; y++)
    for ( int x = 0; x < Size; x++)
    {
      if (x + 3 < Size)
      {
         int current = matrix[x][y] * matrix[x+1][y] * matrix[x+2][y] * matrix[x+3][y];
        if (best < current)
          best = current;
      }
      if (y + 3 < Size)
      {
         int current = matrix[x][y] * matrix[x][y+1] * matrix[x][y+2] * matrix[x][y+3];
        if (best < current)
          best = current;
      }
      if (x + 3 < Size && y + 3 < Size)
      {
         int current = matrix[x][y] * matrix[x+1][y+1] * matrix[x+2][y+2] * matrix[x+3][y+3];
        if (best < current)
          best = current;
      }
      if (x + 3 < Size && y >= 3)
      {
         int current = matrix[x][y] * matrix[x+1][y-1] * matrix[x+2][y-2] * matrix[x+3][y-3];
        if (best < current)
          best = current;
      }
    }

  printf("%d\n", best);
  return 0;
}
