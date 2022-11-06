#include <stdio.h>
#include <stdlib.h>

int piramide(int n);
int tociente(int n);
int* fatorar(int n);
int* alocarVetor(int tamanhoDoVetor);
void printarVetor(int *vetor);

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

void printarVetor(int *vetor)
{
    int i;
    for(i = 0; vetor[i] != -1; i++)
    {
        printf("%d", vetor[i]);
        vetor[i+1] != -1 ? printf(", ") : printf(".\n");
    }
}
