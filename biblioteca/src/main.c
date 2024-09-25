#include <stdio.h>
#include "biblioteca.h"

int main() {
    Livro livros[100];
    Usuario usuarios[100];
    Emprestimo emprestimos[100];
    int totalLivros = 0, totalUsuarios = 0, totalEmprestimos = 0;
    int emprestimoBusca = -1;
    char keyBusca[100];

    inicializarSistema();

    int opt = -1;
    while(opt != 0) {
        printf("\n ### Menu da Biblioteca ###\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Buscar Livro\n");
        printf("4. Adicionar Usuário\n");
        printf("5. Listar Usuários\n");
        printf("6. Buscar Usuário\n");
        printf("7. Realizar Empréstimo\n");
        printf("8. Devolver Empréstimo\n");
        printf("9. Listar Empréstimos\n");
        printf("10. Salvar Dados\n");
        printf("11. Carregar Dados\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opt);

        switch(opt) {
            case 1:
                adicionarLivro(livros, &totalLivros);
                break;
            case 2:
                listarLivros(livros, totalLivros);
                break;
            case 3:
                printf("\n\nTitulo do livro: ");
                __fpurge(stdin);
                gets(keyBusca);
                buscarLivro(livros, totalLivros, keyBusca);
                break;
            case 4:
                adicionarUsuario(usuarios, &totalUsuarios);
                break;
            case 5:
                listarUsuarios(usuarios, totalUsuarios);
                break;
            case 6:
                printf("\n\nNome do usuário: ");
                __fpurge(stdin);
                gets(keyBusca);
                buscarUsuario(usuarios, totalUsuarios, keyBusca);
                break;
            case 7:
                realizarEmprestimo(emprestimos, &totalEmprestimos, livros, totalLivros, usuarios, totalUsuarios);
                break;
            case 8:
                printf("ID do livro a ser devolvido: ");
                scanf("%d", &emprestimoBusca);
                devolverEmprestimo(emprestimos, &totalEmprestimos, livros, totalLivros, emprestimoBusca);
                break;
            case 9:
                listarEmprestimos(emprestimos, totalEmprestimos, livros, usuarios);
                break;
            case 10:
                salvarDados(livros, totalLivros, usuarios, totalUsuarios, emprestimos, totalEmprestimos);
                break;
            case 11:
                carregarDados(livros, &totalLivros, usuarios, &totalUsuarios, emprestimos, &totalEmprestimos);
                break;
            case 0:
                printf("Saindo\n\n");
                break;
            default:
                printf("Opção inválida. Tente novamente\n\n");
        }
    }
    return 0;
}
