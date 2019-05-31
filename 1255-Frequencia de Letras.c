#include <stdio.h>
#include <string.h>

#define max 1000

int main(void)
{
   int i, j, casosTeste, maior, posicaoLetra;
   char palavra[max];
   
   scanf("%d", &casosTeste);
   getchar();
   
   for(i = 0; i < casosTeste; i++)
   {
       int letras[26] = {0};
       maior = -9999;
       fgets(palavra, max, stdin);
       for(j = 0; j < strlen(palavra); j++)
       {
           if((palavra[j] >= 'a' && palavra[j] <= 'z') || (palavra[j] >= 'A' && palavra[j] <= 'Z'))
           {
                posicaoLetra = (palavra[j] & 31) - 1;
                letras[posicaoLetra] += 1;
                if(letras[posicaoLetra] > maior)
                {
                    maior = letras[posicaoLetra];
                }
           }
       }
        
       for(j = 0; j < 26; j++)
       {
           if(letras[j] == maior)
           {
               printf("%c", 97 + j);
           }
       }
       
       printf("\n");
   }
}
