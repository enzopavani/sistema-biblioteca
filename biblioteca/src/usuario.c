#include <stdio.h>
#include <string.h>
#include "usuario.h"

void adicionarUsuario(Usuario* usuarios, int* totalUsuarios) {
    usuarios[*(totalUsuarios)].id = *(totalUsuarios);

    printf("\n\nNome: ");
    __fpurge(stdin);
    gets(usuarios[*(totalUsuarios)].nome);
    
    printf("Endereço: ");
    __fpurge(stdin);
    gets(usuarios[*(totalUsuarios)].endereço);
    
    printf("Telefone: ");
    __fpurge(stdin);
    gets(usuarios[*(totalUsuarios)].telefone);
    
    printf("E-mail: ");
    __fpurge(stdin);
    gets(usuarios[*(totalUsuarios)].email);
    
    *(totalUsuarios) = *(totalUsuarios) + 1;
    printf("Usuário adicionado.\n\n");
}

void listarUsuarios(Usuario* usuarios, int totalUsuarios) {
    int i;
    printf("\n\nLista de usuários:\n");
    for(i=0; i<totalUsuarios; i++)
        printf("%d. %s\n", usuarios[i].id, usuarios[i].nome);
    printf("Fim\n\n");
}

void buscarUsuario(Usuario* usuarios, int totalUsuarios, char* nome) {
    int i, encontrado = 0;
    printf("Buscando usuário \"%s\"...\n", nome);
    for(i=0; i<totalUsuarios; i++) {
        if(strcmp(usuarios[i].nome, nome) == 0) {
            printf("Encontrado\n");
            encontrado = 1;
            printf("-Id: %d\n", usuarios[i].id);
            printf("-Nome: %s\n", usuarios[i].nome);
            printf("-Endereço: %s\n", usuarios[i].endereço);
            printf("-Telefone: %s\n", usuarios[i].telefone);
            printf("-E-mail: %s\n", usuarios[i].email);
        }
    }
    if(!encontrado)
        printf("Não encontrado\n");
    printf("\n");
}

