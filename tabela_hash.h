#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define TAMANHO_TABELA 100

typedef struct Nodo {
    char* chave;
    char* dado;
    struct Nodo* proximo;
} Nodo;

void inicializar_tabela();
char* hash_table_get(char* chave);
void hash_table_put(char* chave, char* dado);
int hash_table_contains(char* chave);
void hash_table_remove(char* chave);

#endif

