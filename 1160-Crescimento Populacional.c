#include <stdio.h>

int main(void) 
{
  int i, casosTeste, populacaoA, populacaoB, anoAtual;
  double crescimentoA, crescimentoB;

  scanf("%d", &casosTeste);
  
  for(i = 0; i < casosTeste; i++)
  {
    anoAtual = 0;
    
    scanf("%d %d %lf %lf", &populacaoA, &populacaoB, &crescimentoA, &crescimentoB);
    
    while(populacaoA <= populacaoB)
    {
      populacaoA = populacaoA + (int)((populacaoA * crescimentoA) / 100.0f);
      populacaoB = populacaoB + (int)((populacaoB * crescimentoB) / 100.0f);
      anoAtual += 1;

      if(anoAtual > 100) break;
    }
    
    if(anoAtual > 100) printf("Mais de 1 seculo.\n");
    else printf("%d anos.\n", anoAtual);
  }

  return 0;
}