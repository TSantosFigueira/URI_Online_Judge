#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max 200

int main(void) 
{
  char sentence[max];
  int i, currentLetter;

  while(fgets(sentence, max, stdin) != NULL)
  {
    currentLetter = 0;
    for(i = 0; i < strlen(sentence); i++)
    {
      if((sentence[i] >= 'a' && sentence[i] <= 'z')  || (sentence[i] >= 'A' && sentence[i] <= 'Z'))
      {
        if(currentLetter % 2 == 0)
        {
          sentence[i] = toupper(sentence[i]);        
        }
        else if(currentLetter % 2 != 0)
        {
          sentence[i] = tolower(sentence[i]);
        }
        currentLetter += 1;
      }
    }
    printf("%s", sentence);
  }

  return 0;
}