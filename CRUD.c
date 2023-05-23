#include <stdio.h>
#include <string.h>

#define MAX_USUARIOS 1000
#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_SEXO 15
#define MAX_ENDERECO 100

int totalUsuarios = 0;
int totalUsuariosExcluidos = 0;
int ids[MAX_USUARIOS];
char nomes[MAX_USUARIOS][MAX_NOME];
char emails[MAX_USUARIOS][MAX_EMAIL];
char sexos[MAX_USUARIOS][MAX_SEXO];
char enderecos[MAX_USUARIOS][MAX_ENDERECO];
double alturas[MAX_USUARIOS];
int vacinas[MAX_USUARIOS];
int usuariosExcluidosIds[MAX_USUARIOS];
char usuariosExcluidosNomes[MAX_USUARIOS][MAX_NOME];
char usuariosExcluidosEmails[MAX_USUARIOS][MAX_EMAIL];
char usuariosExcluidosSexos[MAX_USUARIOS][MAX_SEXO];
char usuariosExcluidosEnderecos[MAX_USUARIOS][MAX_ENDERECO];
double usuariosExcluidosAlturas[MAX_USUARIOS];
int usuariosExcluidosVacinas[MAX_USUARIOS];

void cadastrarUsuario() {
    if (totalUsuarios == MAX_USUARIOS) {
        printf("Limite de usuários atingido.\n");
        return;
    }

    printf("Digite o nome do usuário: ");
    fgets(nomes[totalUsuarios], MAX_NOME, stdin);
    nomes[totalUsuarios][strcspn(nomes[totalUsuarios], "\n")] = '\0';

    printf("Digite o email do usuário: ");
    fgets(emails[totalUsuarios], MAX_EMAIL, stdin);
    emails[totalUsuarios][strcspn(emails[totalUsuarios], "\n")] = '\0';

    printf("Digite o sexo do usuário (Feminino/Masculino/Indiferente): ");
    fgets(sexos[totalUsuarios], MAX_SEXO, stdin);
    sexos[totalUsuarios][strcspn(sexos[totalUsuarios], "\n")] = '\0';

    printf("Digite o endereço do usuário: ");
    fgets(enderecos[totalUsuarios], MAX_ENDERECO, stdin);
    enderecos[totalUsuarios][strcspn(enderecos[totalUsuarios], "\n")] = '\0';

    printf("Digite a altura do usuário (em metros): ");
    scanf("%lf", &alturas[totalUsuarios]);

    printf("O usuário foi vacinado? (1 - Sim / 0 - Não): ");
    scanf("%d", &vacinas[totalUsuarios]);

    ids[totalUsuarios] = totalUsuarios + 1;
    totalUsuarios++;

    printf("Usuário cadastrado com sucesso.\n");
}

void editarUsuario() {
    int id;
    printf("Digite o ID do usuário a ser editado: ");
    scanf("%d", &id);

    int indice = -1;
    for (int i = 0; i < totalUsuarios; i++) {
        if (ids[i] == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Usuário não encontrado.\n");
        return;
    }

    printf("Digite o novo nome do usuário: ");
    getchar();
    fgets(nomes[indice], MAX_NOME, stdin);
    nomes[indice][strcspn(nomes[indice], "\n")] = '\0';

    printf("Digite o novo email do usuário: ");
    fgets(emails[indice], MAX_EMAIL, stdin);
    emails[indice][strcspn(emails[indice], "\n")] = '\0';

    printf("Digite o novo sexo do usuário (Feminino/Masculino/Indiferente): ");
    fgets(sexos[indice], MAX_SEXO, stdin);
    sexos[indice][strcspn(sexos[indice], "\n")] = '\0';

    printf("Digite o novo endereço do usuário: ");
    fgets(enderecos[indice], MAX_ENDERECO, stdin);
    enderecos[indice][strcspn(enderecos[indice], "\n")] = '\0';

    printf("Digite a nova altura do usuário (em metros): ");
    scanf("%lf", &alturas[indice]);

    printf("O usuário foi vacinado? (1 - Sim / 0 - Não): ");
    scanf("%d", &vacinas[indice]);

    printf("Usuário editado com sucesso.\n");
}

void excluirUsuario() {
    int id;
    printf("Digite o ID do usuário a ser excluído: ");
    scanf("%d", &id);

    int indice = -1;
    for (int i = 0; i < totalUsuarios; i++) {
        if (ids[i] == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        printf("Usuário não encontrado.\n");
        return;
    }

    // Movendo os dados do usuário excluído para o vetor de usuários excluídos
    usuariosExcluidosIds[totalUsuariosExcluidos] = ids[indice];
    strcpy(usuariosExcluidosNomes[totalUsuariosExcluidos], nomes[indice]);
    strcpy(usuariosExcluidosEmails[totalUsuariosExcluidos], emails[indice]);
    strcpy(usuariosExcluidosSexos[totalUsuariosExcluidos], sexos[indice]);
    strcpy(usuariosExcluidosEnderecos[totalUsuariosExcluidos], enderecos[indice]);
    usuariosExcluidosAlturas[totalUsuariosExcluidos] = alturas[indice];
    usuariosExcluidosVacinas[totalUsuariosExcluidos] = vacinas[indice];
    totalUsuariosExcluidos++;

    // Removendo o usuário do vetor de usuários
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

    printf("Usuário excluído com sucesso.\n");
}

void buscarUsuarioPorEmail() {
    char email[MAX_EMAIL];
    printf("Digite o email do usuário a ser buscado: ");
    getchar();
    fgets(email, MAX_EMAIL, stdin);
    email[strcspn(email, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(emails[i], email) == 0) {
            printf("ID: %d\n", ids[i]);
            printf("Nome: %s\n", nomes[i]);
            printf("Email: %s\n", emails[i]);
            printf("Sexo: %s\n", sexos[i]);
            printf("Endereço: %s\n", enderecos[i]);
            printf("Altura: %.2lf\n", alturas[i]);
            printf("Vacina: %s\n", vacinas[i] ? "Sim" : "Não");
            printf("\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Usuário não encontrado.\n");
    }
}

void imprimirUsuarios() {
    printf("Total de usuários cadastrados: %d\n\n", totalUsuarios);

    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d\n", ids[i]);
        printf("Nome: %s\n", nomes[i]);
        printf("Email: %s\n", emails[i]);
        printf("Sexo: %s\n", sexos[i]);
        printf("Endereço: %s\n", enderecos[i]);
        printf("Altura: %.2lf\n", alturas[i]);
        printf("Vacina: %s\n", vacinas[i] ? "Sim" : "Não");
        printf("\n");
    }
}

void realizarBackup() {
    // Faz uma cópia dos usuários cadastrados para o backup
    memcpy(usuariosExcluidosIds, ids, sizeof(ids));
    memcpy(usuariosExcluidosNomes, nomes, sizeof(nomes));
    memcpy(usuariosExcluidosEmails, emails, sizeof(emails));
    memcpy(usuariosExcluidosSexos, sexos, sizeof(sexos));
    memcpy(usuariosExcluidosEnderecos, enderecos, sizeof(enderecos));
    memcpy(usuariosExcluidosAlturas, alturas, sizeof(alturas));
    memcpy(usuariosExcluidosVacinas, vacinas, sizeof(vacinas));

    totalUsuariosExcluidos = totalUsuarios;

    printf("Backup realizado com sucesso.\n");
}

void restaurarDados() {
    // Restaura os dados do backup para os usuários cadastrados
    memcpy(ids, usuariosExcluidosIds, sizeof(ids));
    memcpy(nomes, usuariosExcluidosNomes, sizeof(nomes));
    memcpy(emails, usuariosExcluidosEmails, sizeof(emails));
    memcpy(sexos, usuariosExcluidosSexos, sizeof(sexos));
    memcpy(enderecos, usuariosExcluidosEnderecos, sizeof(enderecos));
    memcpy(alturas, usuariosExcluidosAlturas, sizeof(alturas));
    memcpy(vacinas, usuariosExcluidosVacinas, sizeof(vacinas));

    totalUsuarios = totalUsuariosExcluidos;

    printf("Dados restaurados com sucesso.\n");
}

int main() {
    char opcao;

    do {
        printf("=== MENU ===\n");
        printf("1 - Cadastrar usuário\n");
        printf("2 - Editar usuário\n");
        printf("3 - Excluir usuário\n");
        printf("4 - Buscar usuário por email\n");
        printf("5 - Imprimir usuários cadastrados\n");
        printf("6 - Realizar backup dos usuários cadastrados\n");
        printf("7 - Restaurar dados\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);
        printf("\n");

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
                buscarUsuarioPorEmail();
                break;
            case '5':
                imprimirUsuarios();
                break;
            case '6':
                realizarBackup();
                break;
            case '7':
                restaurarDados();
                break;
            case '0':
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != '0');

    return 0;
}