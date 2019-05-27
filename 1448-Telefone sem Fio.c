#include <stdio.h>
#include <string.h>

int main()
{
  char fraseOriginal[120], fraseTime1[120], fraseTime2[120], temp;
  int casosTeste, pontosTime1, pontosTime2, tamanhoFrase, instancia, j;
  int primeiroErroTime1, primeiroErroTime2, erroTime1, erroTime2;

  scanf("%d",&casosTeste);
  getchar();
  for (instancia = 0; instancia < casosTeste; instancia ++)
  {

      fgets(fraseOriginal, 120, stdin);
      fgets(fraseTime1, 120, stdin);
      fgets(fraseTime2, 120, stdin);

      tamanhoFrase = strlen(fraseOriginal) - 1;

      pontosTime1 = 0;
      pontosTime2 = 0;
      erroTime1 = 0;
      erroTime2 = 0;


      for(j = 0; j < tamanhoFrase; j++)
      {
          if(fraseOriginal[j] == fraseTime1[j])
          {
              pontosTime1 = pontosTime1 + 1;
          }
          else
          {
              if(erroTime1 == 0)
              {
                  primeiroErroTime1 = j;
                  erroTime1 = 1;
              }
          }

          if(fraseOriginal[j] == fraseTime2[j])
          {
              pontosTime2 = pontosTime2 + 1;
          }
          else
          {
              if(erroTime2 == 0)
              {
                 primeiroErroTime2 = j;
                 erroTime2 = 1;
              }
          }

          if(primeiroErroTime1 == primeiroErroTime2)
          {
            erroTime1 = 0;
            erroTime2 = 0;
          }
      }

      printf("Instancia %d\n", instancia + 1);
      if(pontosTime1 == pontosTime2 && erroTime1 == 1 && erroTime2 == 1 && primeiroErroTime1 > primeiroErroTime2)
      {
        printf("time 1\n");
      }
      else if(pontosTime1 == pontosTime2 && erroTime1 == 1 && erroTime2 == 1 && primeiroErroTime1 < primeiroErroTime2)
      {
          printf("time 2\n");
      }
      else if(pontosTime1 == pontosTime2)
      {
        printf("empate\n");
      }
      else if(pontosTime1 > pontosTime2){
        printf("time 1\n");
      }
      else{
        printf("time 2\n");
      }

      printf("\n");
    }
    return 0;
}
