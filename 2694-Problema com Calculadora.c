#include <stdio.h>
#include <string.h>

#define max 20

int convertToNumber(char num)
{
  return num - 48;
}

int main(void) 
{
  int i, testCases, sum;
  char number[max];

  scanf("%d", &testCases);
  getchar();
  for(i = 0; i < testCases; i++)
  {
      scanf("%s", number);
      
      sum = 0;
      sum += 10 * (convertToNumber(number[2]));
      sum += convertToNumber(number[3]);

      sum += 100 * (convertToNumber(number[5]));
      sum += 10 * (convertToNumber(number[6]));
      sum += convertToNumber(number[7]);

      sum += 10 * (convertToNumber(number[11]));
      sum += convertToNumber(number[12]);

      printf("%d\n", sum);
  }

  return 0;
}