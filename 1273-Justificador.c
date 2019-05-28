#include <stdio.h>
#include <string.h>

#define max 100

// Essa questão pede para alinhar as palavras à direita 

int main(void) 
{
  int i, j, testCases, tamanho[max], maior, espaco;
  char palavra[50][max];

  // le-se o numero de casos de teste inicial
  scanf("%d", &testCases);
  while(testCases > 0)
  {    
    maior = -9999;
    
    // Para cada palavra lida, armazena-se a palavra de maior tamanho
    for(i = 0; i < testCases; i++)
    {
      scanf("%s", palavra[i]);
      tamanho[i] = strlen(palavra[i]);
      
      if(tamanho[i] > maior)
      {
        maior = tamanho[i];
      }
    }

    // Para cada palavra, verifica-se o alinhamento com a maior palavra. O numero de espacos e a diferenca de tamanhos entre cada palavra e a maior
    for(i = 0; i < testCases; i++)
    {
      if(tamanho[i] < maior)
      {
        espaco = maior - tamanho[i];
        
        for(j = espaco; j > 0; j--)
        {
            printf(" ");
        }
         
      }
      printf("%s\n", palavra[i]);
    }

    scanf("%d", &testCases);

    // Imprime uma quebra de linha a cada iteracao, exceto na ultima
    if(testCases != 0)
    {
        printf("\n");
    }
  }

  return 0;
}