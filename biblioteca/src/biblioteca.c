#include <stdio.h>
#include "biblioteca.h"

void inicializarSistema() {
    printf("Inicializando sistema\n");
}

void salvarDados(Livro* livros, int totalLivros, Usuario* usuarios, int totalUsuarios, Emprestimo* emprestimos, int totalEmprestimos) {
    FILE* fp;

    fp = fopen("data/livros.dat", "wb");
    if(!fp) {
        printf("Erro ao abrir o arquivo para salvar livros\n");
        return;
    }
    fwrite(&totalLivros, sizeof(int), 1, fp);
    fwrite(livros, sizeof(Livro), totalLivros, fp);
    fclose(fp);

    fp = fopen("data/usuarios.dat", "wb");
    if(!fp) {
        printf("Erro ao abrir o arquivo para salvar usuários\n");
        return;
    }
    fwrite(&totalUsuarios, sizeof(int), 1, fp);
    fwrite(usuarios, sizeof(Usuario), totalUsuarios, fp);
    fclose(fp);

    fp = fopen("data/emprestimos.dat", "wb");
    if(!fp) {
        printf("Erro ao abrir o arquivo para salvar empréstimos\n");
        return;
    }
    fwrite(&totalEmprestimos, sizeof(int), 1, fp);
    fwrite(emprestimos, sizeof(Emprestimo), totalEmprestimos, fp);
    fclose(fp);

    printf("Dados salvos\n\n");
}

void carregarDados(Livro* livros, int* totalLivros, Usuario* usuarios, int* totalUsuarios, Emprestimo* emprestimos, int* totalEmprestimos) {
    FILE* fp;

    fp = fopen("data/livros.dat", "rb");
    if(!fp) {
        printf("Erro ao abrir o arquivo para carregar livros\n");
        return;
    }
    fread(totalLivros, sizeof(int), 1, fp);
    fread(livros, sizeof(Livro), *totalLivros, fp);
    fclose(fp);

    fp = fopen("data/usuarios.dat", "rb");
    if(!fp) {
        printf("Erro ao abrir o arquivo para carregar usuários\n");
        return;
    }
    fread(totalUsuarios, sizeof(int), 1, fp);
    fread(usuarios, sizeof(Usuario), *totalUsuarios, fp);
    fclose(fp);

    fp = fopen("data/emprestimos.dat", "rb");
    if(!fp) {
        printf("Erro ao abrir o arquivo para carregar empréstimos\n");
        return;
    }
    fread(totalEmprestimos, sizeof(int), 1, fp);
    fread(emprestimos, sizeof(Emprestimo), *totalEmprestimos, fp);
    fclose(fp);

    printf("Dados carregados\n\n");
}

