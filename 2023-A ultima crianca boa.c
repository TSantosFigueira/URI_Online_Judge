#include <stdio.h>
#include <string.h>

#define max 1000

void lower_string(char []);

int main()
{
    int i, j, posicao;
    char nome[max], entradas[26][max] = {""}, original[max], current[max];
    
    while(fgets(nome, max , stdin))
    {
        // Identifica posicao da letra no alfabeto
        posicao = (nome[0] & 31) - 1;
        
        // Se nao houver palavra, salva a entrada
        if (strcmp(entradas[i], "") == 0)
        {
            strcpy(entradas[posicao], nome);
        }
        else
        {
            // Se houver palavra salva, determina quem alfabeticamente eh a ultima
            strcpy(original, entradas[posicao]);
            strcpy(current, nome);
            
            // Coloca ambas as palavras em caracteres minusculos
            lower_string(current);
            lower_string(original);
            
            if(strcmp(current, original) > 0)
            {
                strcpy(entradas[posicao], nome);
            }
        }
    }
    
    // Imprime de tras para frente
    for(i = 25; i >= 0; i--)
    {     
        if (strcmp(entradas[i], "") != 0){
            printf("%s", entradas[i]);
            break;
        } 
    } 

    return 0;
}

// Transforma todos os caracters da string em minusculo
void lower_string(char s[]) 
{
   int c = 0;
   
   while (s[c] != '\0') 
   {
      if (s[c] >= 'A' && s[c] <= 'Z') 
      {
         s[c] = s[c] + 32;
      }
      c++;
   }
 }