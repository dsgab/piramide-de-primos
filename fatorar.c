#include <stdio.h>
#include <stdlib.h>

typedef struct _FATOR
{
    int fator;
    struct _FATOR* proximo;
}
FATOR;

FATOR* novoFator(int fator)
{
    FATOR* novoFator = (FATOR*) malloc(sizeof(FATOR));
    novoFator->fator = fator;
    return novoFator;
}

void adicionar(FATOR** fatores, FATOR* fator)
{
    fator->proximo = *fatores;
    *fatores = fator;
}

void excluir(FATOR* fatores)
{
    FATOR* ultimo = NULL;
    FATOR* atual;
    for(atual = fatores; atual != NULL; atual = atual->proximo)
    {
        if(ultimo != NULL) free(ultimo);
        ultimo = atual;;
    }
    if(ultimo != NULL) free(ultimo);
}

int* novoVetor(int tamanho)
{
    return (int*) malloc(tamanho *sizeof(int));
}

void fatorar(int inN, int** outFatores, int* outNFatores)
{
    FATOR* fatores = NULL;
    int candidato = 2;
    int nFatores = 0;
    int* vetorFatores;
    FATOR* fator;
    int fatoresPostos = 0;
    while(candidato <= inN)
    {
        if(inN % candidato == 0)
        {
            adicionar(&fatores, novoFator(candidato));
            nFatores++;
            while(inN % candidato == 0)
            {
                inN /= candidato;
            }
        }
        else candidato++;
    }
    vetorFatores = novoVetor(nFatores);
    for(fator = fatores; fator != NULL; fator = fator->proximo)
    {
        vetorFatores[nFatores-1-fatoresPostos] = fator->fator;
        fatoresPostos++;
    }
    excluir(fatores);
    *outFatores = vetorFatores;
    *outNFatores = nFatores;
}

void printarVetor(int* vetor, int tamanho)
{
    int i;
    for(i = 0; i < tamanho; i++)
    {
        printf("%d\n", vetor[i]);
    }
}