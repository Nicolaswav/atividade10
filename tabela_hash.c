#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

static Nodo* tabela[TAMANHO_TABELA];

int hash(char* chave) {
    int hash = 0;
    while (*chave) {
        hash += *chave++;
    }
    return hash % TAMANHO_TABELA;
}

void inicializar_tabela() {
    for (int i = 0; i < TAMANHO_TABELA; ++i) {
        tabela[i] = NULL;
    }
}

char* hash_table_get(char* chave) {
    int indice = hash(chave);
    Nodo* atual = tabela[indice];
    
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return atual->dado;
        }
        atual = atual->proximo;
    }

    return NULL;
}

void hash_table_put(char* chave, char* dado) {
    int indice = hash(chave);
    Nodo* novo = malloc(sizeof(Nodo));
    novo->chave = strdup(chave);
    novo->dado = strdup(dado);
    novo->proximo = tabela[indice];
    tabela[indice] = novo;
}

int hash_table_contains(char* chave) {
    int indice = hash(chave);
    Nodo* atual = tabela[indice];
    
    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            return 1;  // Chave encontrada
        }
        atual = atual->proximo;
    }

    return 0;  // Chave não encontrada
}

void hash_table_remove(char* chave) {
    int indice = hash(chave);
    Nodo* atual = tabela[indice];
    Nodo* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->chave, chave) == 0) {
            if (anterior == NULL) {
                tabela[indice] = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual->chave);
            free(atual->dado);
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}


