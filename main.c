#include <stdio.h>
#include "tabela_hash.h"

int main() {
    inicializar_tabela();

    hash_table_put("chave1", "valor1");
    hash_table_put("chave2", "valor2");
    hash_table_put("chave3", "valor3");

    printf("Valor associado � chave2: %s\n", hash_table_get("chave2"));

    if (hash_table_contains("chave3")) {
        printf("A tabela cont�m a chave3.\n");
    } else {
        printf("A tabela n�o cont�m a chave3.\n");
    }

    hash_table_remove("chave1");

    if (hash_table_contains("chave1")) {
        printf("A tabela cont�m a chave1.\n");
    } else {
        printf("A tabela n�o cont�m a chave1.\n");
    }

    return 0;
}

