#include <stdio.h>
#include <string.h>

#define max 10000

int main(void) 
{
  
  int i, j;
  char input[max], output[max], number[max], digit;

  while(fgets(input, sizeof(input), stdin))  
  {
    
    sscanf(input, "%c  %s", &digit, number);

    if(digit == '0' && strcmp(number, "0") == 0) break;

    j = 0;
    
    for(i = 0; i < strlen(number); i++)
    {
      if(number[i] != digit)
      {
        output[j] = number[i];
        j += 1;
      }
    }
    
    while(output[0] == '0' && strlen(output) > 0)
    {
        for(i = 0; i < strlen(output); i++)
        {
            output[i] = output[i + 1];
        }
        output[i] = '\0';
    }

    if(strlen(output) == 0) printf("0\n");
    else printf("%s\n", output);
    memset(output,0,strlen(output));
  }

  return 0;
}