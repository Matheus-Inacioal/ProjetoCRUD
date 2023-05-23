#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 1000
#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_SEXO 15
#define MAX_ENDERECO 100

int totalUsuarios = 0;
int ids[MAX_USUARIOS];
char nomes[MAX_USUARIOS][MAX_NOME];
char emails[MAX_USUARIOS][MAX_EMAIL];
char sexos[MAX_USUARIOS][MAX_SEXO];
char enderecos[MAX_USUARIOS][MAX_ENDERECO];
double alturas[MAX_USUARIOS];
int vacinas[MAX_USUARIOS];

void cadastrarUsuario() {
    if (totalUsuarios == MAX_USUARIOS) {
        printf("Limite de usuarios atingido.\n");
        return;
    }

    printf("Digite o ID do usuario: ");
    scanf("%d", &ids[totalUsuarios]);

    printf("Digite o nome do usuario: ");
    getchar(); // Limpa o buffer do teclado
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

    printf("O usuario foi vacinado? (1 - Sim / 0 - Não): ");
    scanf("%d", &vacinas[totalUsuarios]);

    totalUsuarios++;

    printf("Usuario cadastrado com sucesso.\n");
}

void editarUsuario() {
    int id;
    printf("Digite o ID do usuario que deseja editar: ");
    scanf("%d", &id);

    int indice = -1;
    for (int i = 0; i < totalUsuarios; i++) {
        if (ids[i] == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }

    printf("Digite o novo nome do usuario: ");
    getchar(); // Limpa o buffer do teclado
    fgets(nomes[indice], MAX_NOME, stdin);
    nomes[indice][strcspn(nomes[indice], "\n")] = '\0';

    printf("Digite o novo email do usuario: ");
    fgets(emails[indice], MAX_EMAIL, stdin);
    emails[indice][strcspn(emails[indice], "\n")] = '\0';

    printf("Digite o novo sexo do usuario (Feminino/Masculino/Indiferente): ");
    fgets(sexos[indice], MAX_SEXO, stdin);
    sexos[indice][strcspn(sexos[indice], "\n")] = '\0';

    printf("Digite o novo endereço do usuario: ");
    fgets(enderecos[indice], MAX_ENDERECO, stdin);
    enderecos[indice][strcspn(enderecos[indice], "\n")] = '\0';

    printf("Digite a nova altura do usuario (em metros): ");
    scanf("%lf", &alturas[indice]);

    printf("O usuario foi vacinado? (1 - Sim / 0 - Não): ");
    scanf("%d", &vacinas[indice]);

    printf("Usuario editado com sucesso.\n");
}

int main() {
    char opcao;
    do {
        printf("Selecione uma opçao:\n");
        printf("1 - Cadastrar usuario\n");
        printf("2 - Editar usuario\n");
        printf("3 - Excluir usuario\n");
        printf("4 - Buscar usuario pelo email\n");
        printf("5 - Imprimir usuarios cadastrados\n");
        printf("6 - Fazer backup dos usuarios cadastrados\n");
        printf("7 - Fazer restauraçao dos dados\n");
        printf("0 - Sair\n");
        printf("Opçao: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrarUsuario();
                break;
            case '2':
                editarUsuario();
                break;
            case '3':
                // Implementar função de excluir usuário
                break;
            case '4':
                // Implementar função de buscar usuário por email
                break;
            case '5':
                // Implementar função de imprimir usuários cadastrados
                break;
            case '6':
                // Implementar função de fazer backup dos usuários cadastrados
                break;
            case '7':
                // Implementar função de fazer restauração dos dados
                break;
            case '0':
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção invalida. Tente novamente.\n");
        }

        printf("\n");

    } while (opcao != '0');

    return 0;
}
