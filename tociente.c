#include <stdio.h>
#include <stdlib.h>
#include "./fatorar.c"

int tociente(int n);

int main(void)
{
    int numeroTociente, resultado = -1;

    printf("Escolha um número para calcular o seu tociente: ");
    scanf("%d", &numeroTociente);
    resultado = tociente(numeroTociente);
    printf("O resultado é: %d\n", resultado);

    return 0;
}

int tociente(int n)
{
    int i, numerador = 1, denominador = 1, nFatores;
    int *vetorDeFatores;
    fatorar(n, &vetorDeFatores, &nFatores);

    for(i = 0; i < nFatores; i++)
    {
        numerador *= vetorDeFatores[i] - 1;
        denominador *= vetorDeFatores[i];
    }
    free(vetorDeFatores);
    
    return n * numerador / denominador;
}