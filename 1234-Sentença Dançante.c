#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max 200

// Questao pede para alterar a palavra de acordo com a definicao de dancante

int main(void) 
{
  char sentence[max];
  int i, currentLetter;

  // Le enquanto a entrada nao e vazia
  while(fgets(sentence, max, stdin) != NULL)
  {
    currentLetter = 0;
    
    // Para cada palavra, alterna entre maiuscula e minuscula de acordo com o indice
    for(i = 0; i < strlen(sentence); i++)
    {
      // Se for uma letra (maiuscula ou minuscula)
      if((sentence[i] >= 'a' && sentence[i] <= 'z')  || (sentence[i] >= 'A' && sentence[i] <= 'Z'))
      {
        // Caso seja par, transforma em maiuscula
        if(currentLetter % 2 == 0)
        {
          sentence[i] = toupper(sentence[i]);        
        }
        // Caso seja impar, transforma em minuscula
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
