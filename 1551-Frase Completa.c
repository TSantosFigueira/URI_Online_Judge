#include <stdio.h>
#include <string.h>

#define size 2000

int main()
{
    int i, j, casosTeste, totalLetras, posicaoLetra;
    char palavra[size];
    
    scanf("%d", &casosTeste);
    getchar();
    
    for(i = 0; i < casosTeste; i++)
    {
        fgets(palavra, size, stdin);
        totalLetras = 0;
        int letrasUsadas[26] = {0};
        
        for(j = 0; j < strlen(palavra); j++)
        {
            if(palavra[j] >= 'a' && palavra[j] <= 'z')
            {
              posicaoLetra = (palavra[j] & 31) - 1;
              totalLetras += !letrasUsadas[posicaoLetra];
              letrasUsadas[posicaoLetra] = 1;
            }
        }
        
        if(totalLetras == 26) printf("frase completa");
        else if(totalLetras >= 13) printf("frase quase completa");
        else printf("frase mal elaborada");
        printf("\n");
    } 
    return 0;
}