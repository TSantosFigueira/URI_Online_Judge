#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define max 100000

int main(void) 
{
  char cpf[12] = "", texto1[max], texto2[max], num1[max] = "", num2[max] = "";
  int i, j, indexNum1, indexNum2, ponto, posUltimoNumero1, numCount;
  
  scanf("%s", texto1);
  scanf("%s", texto2);

  indexNum1 = 0;
  indexNum2 = 0;
  ponto = 0;
  j = 0;
  numCount = 0;

  // CPF
  for(i = 0; i < strlen(texto1); i++)
  {
    if(texto1[i] >= '0' && texto1[i] <= '9')
    {
        cpf[j] = texto1[i];
        j += 1;

        if(j == 11)
        {
          posUltimoNumero1 = i + 1;
          break;
        } 
    }
  }

  // Numero 1
  for(i = posUltimoNumero1; i < strlen(texto1); i ++)
  {
    if(texto1[i] >= '0' && texto1[i] <= '9')
    {
        // Le numeros apos o ponto (maximo de dois numeros)
        if(ponto == 1 && numCount < 2)
        {
            num1[indexNum1] = texto1[i];
            indexNum1 += 1;
            numCount += 1;
        }
        // Le os numeros normalmente, caso nao haja ponto
        else if(ponto == 0)
        {
            num1[indexNum1] = texto1[i];
            indexNum1 += 1;
        }
    }

    else if(texto1[i] == '.')
    {
        if(ponto == 0)
        {
            num1[indexNum1] = texto1[i];
            ponto = 1;
            indexNum1 += 1;
        }
        // Ignora todo o resto, caso haja um segundo numero
        else break;
    } 
  }

  ponto = 0;
  numCount = 0;

  // Numero 2
  for(i = 0; i < strlen(texto2); i++)
  {
    if(texto2[i] >= '0' && texto2[i] <= '9')
    {
        if(ponto == 1 && numCount < 2)
        {
          num2[indexNum2] = texto2[i];
          indexNum2 += 1;
          numCount += 1;
        }
        else if (ponto == 0)
        {
            num2[indexNum2] = texto2[i];
            indexNum2 += 1;
        }
    }

    else if(texto2[i] == '.')
    {
        if(ponto == 0)
        {
          num2[indexNum2] = texto2[i];
          ponto = 1;
          indexNum2 += 1;
        }
        // Ignora todo o resto, caso haja um segundo numero
        else break;
    } 
  }

  //printf("\n%s --> Size %d", num1, strlen(num1));
  //printf("\nNumero 2: %s  --> Size %d", num2, strlen(num2));
  
  // Converte os numeros de string para double
  double number1 = atof(num1);
  double number2 = atof(num2);
  
  printf("cpf %s\n", cpf);
  printf("%.2lf\n", number1 + number2);
  
  return 0;
}