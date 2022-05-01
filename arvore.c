#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int valor;
    struct no *direita, *esquerda;
} NoArv;

void inserir(NoArv **raiz, int num){
    NoArv *aux = *raiz;
    while(aux){
        if(num < aux->valor){
            raiz = &aux-> esquerda;
        }else{
            raiz = &aux-> direita;
        }
        aux = *raiz;
    }
    aux = malloc(sizeof(NoArv));
    aux->valor = num;
    aux->esquerda = NULL;
    aux->direita = NULL;
    *raiz = aux;
    
}

// Altura da arvore
int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir){
            return esq + 1;
        }else{
            return dir + 1;
        }
    }
}

// Buscar
NoArv* buscar(NoArv *raiz, int num){
    if(raiz){
        if(num == raiz->valor){
            return raiz;
        }else if(num < raiz->valor){
            buscar(raiz->esquerda, num);
        }else{
            buscar(raiz->direita, num);
        }
    }
        return NULL;
}


// Impressão ordenada
void imprimir_versao_1(NoArv *raiz)
{
    if (raiz)
    {
        imprimir_versao_1(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimir_versao_1(raiz->direita);
    }
}
// Impressão desordenada
void imprimir_versao_2(NoArv *raiz)
{
    if (raiz)
    {
        printf("%d ", raiz->valor);
        imprimir_versao_2(raiz->esquerda);
        imprimir_versao_2(raiz->direita);
    }
}

int main()
{
    NoArv *busca, *raiz = NULL;
    int opcao, valor;

    do
    {
        printf("\n\t0 - Sair\n\t1 -Inserir\n\t2 - Imprimir\n\t3 - Busca\n\t4 - Altura\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("\n\tDigite um valor: ");
            scanf("%d", &valor);
            inserir(&raiz, valor);
            printf("\n\tinfo: %d", valor);
            printf("\n\tAltura do no: %d\n", altura(raiz));
            break;
        case 2:
            printf("\n\tImpressao ordenada:\n");
            imprimir_versao_1(raiz);
            printf("\n");
            printf("\n\tImpressao desordenada:\n");
            imprimir_versao_2(raiz);
            printf("\n");
            break;
        case 3:
            printf("\n\tDigite valor para buscar: ");
            scanf("%d", &valor);
            busca = buscar(raiz, valor);
            if(busca)
                printf("\n\tValor encontrado: %d\n", busca->valor);
            else
                printf("\n\tValor nao encontrado");            
            break;
        case 4:
            printf("\n\tAltura total: %d\n\n", altura(raiz));
            break;
        }

    } while (opcao != 0);
    return 0;
}
