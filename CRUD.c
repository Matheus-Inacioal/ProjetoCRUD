#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 100
#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_SEXO 10
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
    scanf(" %[^\n]s", nomes[totalUsuarios]);

    printf("Digite o email do usuario: ");
    scanf(" %[^\n]s", emails[totalUsuarios]);

    printf("Digite o sexo do usuario: ");
    scanf(" %[^\n]s", sexos[totalUsuarios]);

    printf("Digite o endereco do usuario: ");
    scanf(" %[^\n]s", enderecos[totalUsuarios]);

    printf("Digite a altura do usuario (em metros): ");
    scanf("%lf", &alturas[totalUsuarios]);

    printf("O usuario foi vacinado? (1 - Sim / 0 - Nao): ");
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
    scanf(" %[^\n]s", nomes[indice]);

    printf("Digite o novo email do usuario: ");
    scanf(" %[^\n]s", emails[indice]);

    printf("Digite o novo sexo do usuario: ");
    scanf(" %[^\n]s", sexos[indice]);

    printf("Digite o novo endereco do usuario: ");
    scanf(" %[^\n]s", enderecos[indice]);

    printf("Digite a nova altura do usuario (em metros): ");
    scanf("%lf", &alturas[indice]);

    printf("O usuario foi vacinado? (1 - Sim / 0 - Nao): ");
    scanf("%d", &vacinas[indice]);

    printf("Usuario editado com sucesso.\n");
}

void excluirUsuario() {
    int id;
    printf("Digite o ID do usuario que deseja excluir: ");
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

    // Deslocar os elementos à direita do usuário a ser excluído
    for (int i = indice; i < totalUsuarios - 1; i++) {
        ids[i] = ids[i + 1];
        strcpy(nomes[i], nomes[i + 1]);
        strcpy(emails[i], emails[i + 1]);
        strcpy(sexos[i], sexos[i + 1]);
        strcpy(enderecos[i], enderecos[i + 1]);
        alturas[i] = alturas[i + 1];
        vacinas[i] = vacinas[i + 1];
    }

    totalUsuarios--;

    printf("Usuario excluido com sucesso.\n");
}

void listarUsuarios() {
    if (totalUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    printf("Lista de usuarios cadastrados:\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d\n", ids[i]);
        printf("Nome: %s\n", nomes[i]);
        printf("Email: %s\n", emails[i]);
        printf("Sexo: %s\n", sexos[i]);
        printf("Endereco: %s\n", enderecos[i]);
        printf("Altura: %.2lf metros\n", alturas[i]);
        printf("Vacinado: %s\n", vacinas[i] ? "Sim" : "Nao");
        printf("-------------------------\n");
    }
}

void fazerBackup() {
    if (totalUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    int backupIds[MAX_USUARIOS];
    char backupNomes[MAX_USUARIOS][MAX_NOME];
    char backupEmails[MAX_USUARIOS][MAX_EMAIL];
    char backupSexos[MAX_USUARIOS][MAX_SEXO];
    char backupEnderecos[MAX_USUARIOS][MAX_ENDERECO];
    double backupAlturas[MAX_USUARIOS];
    int backupVacinas[MAX_USUARIOS];

    for (int i = 0; i < totalUsuarios; i++) {
        backupIds[i] = ids[i];
        strcpy(backupNomes[i], nomes[i]);
        strcpy(backupEmails[i], emails[i]);
        strcpy(backupSexos[i], sexos[i]);
        strcpy(backupEnderecos[i], enderecos[i]);
        backupAlturas[i] = alturas[i];
        backupVacinas[i] = vacinas[i];
    }

    printf("Backup dos usuarios cadastrados:\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d\n", backupIds[i]);
        printf("Nome: %s\n", backupNomes[i]);
        printf("Email: %s\n", backupEmails[i]);
        printf("Sexo: %s\n", backupSexos[i]);
        printf("Endereco: %s\n", backupEnderecos[i]);
        printf("Altura: %.2lf metros\n", backupAlturas[i]);
        printf("Vacinado: %s\n", backupVacinas[i] ? "Sim" : "Nao");
        printf("-------------------------\n");
    }
}

int main() {
    char opcao;

    do {
        printf("----- Sistema de Cadastro -----\n");
        printf("1 - Cadastrar usuario\n");
        printf("2 - Editar usuario\n");
        printf("3 - Excluir usuario\n");
        printf("4 - Listar usuarios\n");
        printf("5 - Fazer backup dos usuarios\n");
        printf("0 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                cadastrarUsuario();
                break;
            case '2':
                editarUsuario();
                break;
            case '3':
                excluirUsuario();
                break;
            case '4':
                listarUsuarios();
                break;
            case '5':
                fazerBackup();
                break;
            case '0':
                printf("Saindo do sistema.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

        printf("\n");
    } while (opcao != '0');

    return 0;
}
