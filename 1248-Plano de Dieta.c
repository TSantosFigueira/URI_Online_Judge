#include <stdio.h>
#include <string.h>

#define max 1000

/*
    0 - letra nao esta na dieta
    1 - letra esta na dieta
    2 - letra ja foi consumida
*/


int main(void)
{
   char dieta[max], cafe[max], almoco[max];
   int casosTeste, i, j, posicaoLetra, cheater;
   
   scanf("%d", &casosTeste);
   getchar();
   
   for(i = 0; i < casosTeste; i++)
   {
       fgets(dieta, max, stdin);
    
        int letras[26] = {0};
        cheater = 0;
        
        fgets(cafe, max, stdin);
        fgets(almoco, max, stdin);
                
        // Marca as letras da dieta
        for(j = 0; j < strlen(dieta); j++)
        {
            if(dieta[j] != '\n')
            {
                posicaoLetra = (dieta[j] & 31) - 1;
                letras[posicaoLetra] = 1;
            }
        }
        
        // Verifica se as letras do cafe correspondem a dieta
        for(j = 0; j < strlen(cafe); j++)
        {
            if(cafe[j] >= 'A' && cafe[j] <= 'Z')
            {
                posicaoLetra = (cafe[j] & 31) - 1;
                if(letras[posicaoLetra] != 0)
                {
                    letras[posicaoLetra] = 2;
                }
                else
                {
                    cheater = 1;
                    break;
                }
            }
        }
        
        if(cheater == 0)
        {
            for(j = 0; j < strlen(almoco); j++)
            {
                if(almoco[j] >= 'A' && almoco[j] <= 'Z')
                {
                    posicaoLetra = (almoco[j] & 31) - 1;
                    if(letras[posicaoLetra] != 0)
                    {
                        letras[posicaoLetra] = 2;
                    }
                    else
                    {
                        cheater = 1;
                        break;
                    }
                }
            }      
        }
        
        if(cheater == 1) 
        {
            printf("CHEATER");
        }
        else
        {
            for(j = 0; j < 26; j++)
            {
                if(letras[j] == 1)
                {
                    printf("%c", 65 + j);
                }
            }
        }
        printf("\n");
    }
}