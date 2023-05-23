#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#define MAX_NOME 100
#define MAX_EMAIL 100
#define MAX_SEXO 15
#define MAX_ENDERECO 200
#define MAX_USUARIOS 1000

int ids[MAX_USUARIOS];
char nomes[MAX_USUARIOS][MAX_NOME];
char emails[MAX_USUARIOS][MAX_EMAIL];
char sexos[MAX_USUARIOS][MAX_SEXO];
char enderecos[MAX_USUARIOS][MAX_ENDERECO];
double alturas[MAX_USUARIOS];
int vacinas[MAX_USUARIOS];
int totalUsuarios = 0;

void adicionarUsuario() {
    if (totalUsuarios == MAX_USUARIOS) {
        printf("Limite máximo de usuários alcançado.\n");
        return;
    }

    int id = rand() % 1000;
    for (int i = 0; i < totalUsuarios; i++) {
        if (ids[i] == id) {
            id = rand() % 1000;
            i = -1;
        }
    }
    ids[totalUsuarios] = id;

    printf("Digite o nome completo do usuario: ");
    fgets(nomes[totalUsuarios], MAX_NOME, stdin);
    nomes[totalUsuarios][strcspn(nomes[totalUsuarios], "\n")] = '\0';

    printf("Digite o email do usuario: ");
    fgets(emails[totalUsuarios], MAX_EMAIL, stdin);
    emails[totalUsuarios][strcspn(emails[totalUsuarios], "\n")] = '\0';

    printf("Digite o sexo do usuario (Feminino/Masculino/Indiferente): ");
    fgets(sexos[totalUsuarios], MAX_SEXO, stdin);
    sexos[totalUsuarios][strcspn(sexos[totalUsuarios], "\n")] = '\0';

    printf("Digite o endereço do usuario: ");
    fgets(enderecos[totalUsuarios], MAX_ENDERECO, stdin);
    enderecos[totalUsuarios][strcspn(enderecos[totalUsuarios], "\n")] = '\0';

    printf("Digite a altura do usuario (em metros): ");
    scanf("%lf", &alturas[totalUsuarios]);

    printf("O usuario foi vacinado? (1 - Sim / 0 - Nao): ");
    scanf("%d", &vacinas[totalUsuarios]);

    totalUsuarios++;

    printf("Usuario adicionado com sucesso.\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));

    char opcao;

    do {
        printf("============== Gerenciador de Usuarios ==============\n");
        printf("1 - Adicionar usuario\n");
        printf("2 - Editar usuario\n");
        printf("3 - Excluir usuario\n");
        printf("4 - Buscar usuario por email\n");
        printf("5 - Imprimir usuarios\n");
        printf("6 - Fazer backup dos usuarios\n");
        printf("7 - Restaurar usuarios do backup\n");
        printf("0 - Sair do programa\n");
        printf("=====================================================\n");
        printf("Escolha uma opçao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                adicionarUsuario();
                break;
            case '2':
                // Implementar a função editarUsuario();
                break;
            case '3':
                // Implementar a função excluirUsuario();
                break;
            case '4':
                // Implementar a função buscarUsuarioPorEmail();
                break;
            case '5':
                // Implementar a função imprimirUsuarios();
                break;
            case '6':
                // Implementar a função fazerBackup();
                break;
            case '7':
                // Implementar a função fazerRestauracao();
                break;
            case '0':
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção invalida.\n");
                break;
        }

        printf("\n");
    } while (opcao != '0');

    return 0;
}
