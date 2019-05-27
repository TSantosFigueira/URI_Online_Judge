#include <stdio.h>
#include <string.h>

#define size 100

int main()
{
    int casosTeste, i, j, possibilidadeAtual;
    char palavra1[size], palavra2[size], palavraIncompleta[size], letrasPossivel[4];
    
    scanf("%d", &casosTeste);
    
    for(i = 0; i < casosTeste; i++)
    {
        scanf("%s", palavra1);
        scanf("%s", palavra2);
        scanf("%s", palavraIncompleta);
        
        possibilidadeAtual = 0;
        
        //printf("%s %s %s\n", palavra1, palavra2, palavraIncompleta);
        
        for(j = 0; j < strlen(palavraIncompleta); j ++)
        {
            if(palavraIncompleta[j] == '_')
            {
                if(possibilidadeAtual == 0)
                {
                    letrasPossivel[0] = palavra1[j];
                    letrasPossivel[1] = palavra2[j];
                }
                else
                {
                    letrasPossivel[2] = palavra1[j];
                    letrasPossivel[3] = palavra2[j];
                }
                possibilidadeAtual += 1;
            }
        }
        
        if(letrasPossivel[0] == letrasPossivel[2] || letrasPossivel[0] == letrasPossivel[3]) printf("Y\n");
        else if(letrasPossivel[1] == letrasPossivel[2] || letrasPossivel[1] == letrasPossivel[3]) printf("Y\n");
        else printf("N\n");
    }
    
    return 0;
}