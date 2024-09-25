#include <stdio.h>
#include <string.h>
#include "emprestimo.h"

void realizarEmprestimo(Emprestimo* emprestimos, int* totalEmprestimos, Livro* livros, int totalLivros, Usuario* usuarios, int totalUsuarios) {
    int idLivro, idUsuario;
    char dataEmprestimo[11], dataDevolucao[11];

    printf("Id do livro: ");
    scanf("%d", &idLivro);
    printf("Id do usuário: ");
    scanf("%d", &idUsuario);
    printf("Data de empréstimo: ");
    scanf("%s", dataEmprestimo);
    printf("Data de devolução: ");
    scanf("%s", dataDevolucao);

    int livroIndex = -1, i;
    for(i=0; i<totalLivros; i++)
        if(livros[i].id == idLivro) {
            livroIndex = i;
            break;
        }
    if(livroIndex == -1) {
        printf("Livro não encontrado\n\n");
        return;
    }
    if(!livros[livroIndex].disponivel) {
        printf("Livro não disponível para empréstimo\n\n");
        return;
    }

    int usuarioIndex = -1;
    for(i=0; i<totalUsuarios; i++)
        if(usuarios[i].id == idUsuario) {
            usuarioIndex = i;
            break;
        }
    if(usuarioIndex == -1) {
        printf("Usuário não encontrado\n\n");
        return;
    }

    emprestimos[*(totalEmprestimos)].idLivro = idLivro;
    emprestimos[*(totalEmprestimos)].idUsuario = idUsuario;
    strcpy(emprestimos[*(totalEmprestimos)].dataEmprestimo, dataEmprestimo);
    strcpy(emprestimos[*(totalEmprestimos)].dataDevolucao, dataDevolucao);
    *(totalEmprestimos) = *(totalEmprestimos) + 1;

    livros[livroIndex].disponivel = 0;

    printf("Empréstimo realizado com sucesso\n\n");
}

void devolverEmprestimo(Emprestimo* emprestimos, int* totalEmprestimos, Livro* livros, int totalLivros, int idLivro) {
    int i, livroIndex = -1, emprestimoIndex = -1;

    for(i=0; i<*(totalEmprestimos); i++)
        if(emprestimos[i].idLivro == idLivro) {
            emprestimoIndex = i;
            break;
        }
    if(emprestimoIndex == -1) {
        printf("Empréstimo não encontrado\n\n");
        return;
    }

    for(i=0; i<totalLivros; i++)
        if(livros[i].id == idLivro) {
            livroIndex = i;
            break;
            }
    if(livroIndex == -1) {
        printf("Livro não encontrado\n\n");
        return;
    }

    livros[livroIndex].disponivel = 1;

    for(i=emprestimoIndex; i<*(totalEmprestimos)-1; i++)
        emprestimos[i] = emprestimos[i+1];

    *(totalEmprestimos) = *(totalEmprestimos) - 1;

    printf("Devolução realizada com sucesso\n\n");
}

void listarEmprestimos(Emprestimo* emprestimos, int totalEmprestimos, Livro* livros, Usuario* usuarios) {
    int i;
    char livro[100], usuario[100], data[11];
    printf("\n\nLista de empréstimos:\n");
    for(i=0; i<totalEmprestimos; i++) {
        printf("Empréstimo [%d]\n", i + 1);
        strcpy(usuario, usuarios[emprestimos[i].idUsuario].nome);
        printf("-Usuário: %s\n", usuario);
        strcpy(livro, livros[emprestimos[i].idLivro].titulo);
        printf("-Livro: %s\n", livro);
        strcpy(data, emprestimos[i].dataEmprestimo);
        printf("-Data de empréstimo: %s\n", data);
        strcpy(data, emprestimos[i].dataDevolucao);
        printf("-Data de devolução: %s\n", data);
    }
    printf("Fim\n\n");
}

