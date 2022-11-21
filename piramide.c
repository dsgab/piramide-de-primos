#include <stdio.h>
#include <stdlib.h>
#include "./fatorar.c"

int piramide(int n);
int tociente(int n);

int main(void)
{
    int numeroLinha, resultado = -1;

    printf("Escolha uma linha da pirâmide para calcular o número de termos: ");
    scanf("%d", &numeroLinha);
    resultado = piramide(numeroLinha);
    printf("A quantidade de termos é: %d\n", resultado);

    return 0;
}

int piramide(int n)
{
    if(n == 1) return 2;
    return tociente(n) + piramide(n-1);
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