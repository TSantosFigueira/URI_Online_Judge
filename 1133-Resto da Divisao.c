#include <stdio.h>

int main(void) 
{
  int x, y, i, maior, menor;

  scanf("%d %d", &x, &y);

  if(x > y)
  {
      maior = x;
      menor = y;
  }
  else if(y > x)
  {
    maior = y;
    menor = x;
  }

  for(i = menor + 1; i < maior; i++)
  {
    if((i % 5 == 2 || i % 5 == 3))
    {
        printf("%d\n", i);
    } 
  }

  return 0;
}