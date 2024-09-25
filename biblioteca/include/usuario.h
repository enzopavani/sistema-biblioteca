#ifndef USUARIO_H
#define USUARIO_H

typedef struct {
    int id;
    char nome[100];
    char endereço[200];
    char telefone[15];
    char email[100];
} Usuario;

void adicionarUsuario(Usuario* usuarios, int *totalUsuarios);
void listarUsuario(Usuario* usuarios, int totalUsuarios);
void buscarUsuario(Usuario* usuarios, int totalUsuarios, char* nome);
void salvarUsuario(Usuario* usuarios, int totalUsuarios, char* filename);
void carregarUsuario(Usuario* usuarios, int totalUsuarios, char* filename);

#endif
