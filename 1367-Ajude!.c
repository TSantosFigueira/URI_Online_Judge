#include <stdio.h>
#include <string.h>

#define max 1000

int main(void) 
{
  char entrada[max], letra, julgamento[max];
  int i, j, casosTeste, tempo, totalCasos, posicao, tempoTotal;

  scanf("%d", &casosTeste);
  getchar();
  while(casosTeste != 0)
  {
      totalCasos = 0;
      tempoTotal = 0;

      // Por questao de performance, pode-se usar o memset tbm
      int identificador[26] = {0}, pontoExtra[26] = {0};

      for(i = 0; i < casosTeste; i++)
      {
          fgets(entrada, max, stdin);
          sscanf(entrada, "%c %d %s", &letra, &tempo, julgamento);

          // Identifica posicao da letra no alfabeto
          posicao = (letra & 31) - 1;

          if(strcmp(julgamento, "correct") == 0)
          {
            identificador[posicao] = tempo;
          }
          else if(strcmp(julgamento, "incorrect") == 0)
          {
            pontoExtra[posicao] += 20;
          }
          
          // Quantifica se houve um caso correct
          if(identificador[posicao] != 0) totalCasos += 1;
      }
      
      for(i = 0; i < 26; i++)
      {
        if(identificador[i] != 0)
        {
          tempoTotal += identificador[i] + pontoExtra[i];      
        }
      }

      printf("%d %d\n", totalCasos, tempoTotal);
      scanf("%d", &casosTeste);
      getchar();
  }

  return 0;
}