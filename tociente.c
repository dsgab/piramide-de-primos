#include <stdio.h>
#include <stdlib.h>

int tociente(int n);
int* fatorar(int n);
int* alocarVetor(int tamanhoDoVetor);

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
    int i, numerador = 1, denominador = 1;
    int *vetorDeFatores = alocarVetor(n/2 + 1);
    vetorDeFatores = fatorar(n);

    for(i = 0; vetorDeFatores[i] != -1; i++)
    {
        numerador *= vetorDeFatores[i] - 1;
        denominador *= vetorDeFatores[i];
    }
    free(vetorDeFatores);
    
    return n * numerador / denominador;
}

int* fatorar(int n)
{
    int divisorPrimo = 2, i = 0, ultimoDivisor = 0;
    int *vetorDePrimos = alocarVetor(n/2 + 1);

    if(n == 1)
    {
        vetorDePrimos[i] = 1;
        vetorDePrimos[i+1] = -1;
        return vetorDePrimos;
    }

    while(n > 1)
    {
        if(n % divisorPrimo == 0)
        {
            n /= divisorPrimo;
            if(ultimoDivisor != divisorPrimo)
            {
                vetorDePrimos[i] = divisorPrimo;
                i++;
            }
            ultimoDivisor = divisorPrimo;
        }
        else divisorPrimo++;
    }
    vetorDePrimos[i] = -1;

    return vetorDePrimos;
}

int* alocarVetor(int tamanhoDoVetor)
{
    return (int*) malloc(tamanhoDoVetor * sizeof(int));
}
