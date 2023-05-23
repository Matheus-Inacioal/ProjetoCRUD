#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int validarEmail(const char *email) {
    int temArroba = 0;
    int tamanho = strlen(email);
    for (int i = 0; i < tamanho; i++) {
        if (email[i] == '@') {
            temArroba = 1;
            break;
        }
    }
    return temArroba;
}

int validarSexo(const char *sexo) {
    return strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Indiferente") == 0;
}

int validarAltura(double altura) {
    return altura >= 1.0 && altura <= 2.0;
}

int validarVacina(int vacina) {
    return vacina == 0 || vacina == 1;
}

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
    while (!validarEmail(emails[totalUsuarios])) {
        printf("Email inválido. Digite novamente: ");
        fgets(emails[totalUsuarios], MAX_EMAIL, stdin);
        emails[totalUsuarios][strcspn(emails[totalUsuarios], "\n")] = '\0';
    }

    printf("Digite o sexo do usuário (Feminino/Masculino/Indiferente): ");
    fgets(sexos[totalUsuarios], MAX_SEXO, stdin);
    sexos[totalUsuarios][strcspn(sexos[totalUsuarios], "\n")] = '\0';
    while (!validarSexo(sexos[totalUsuarios])) {
        printf("Sexo inválido. Digite novamente: ");
        fgets(sexos[totalUsuarios], MAX_SEXO, stdin);
        sexos[totalUsuarios][strcspn(sexos[totalUsuarios], "\n")] = '\0';
    }

    printf("Digite o endereço do usuário: ");
    fgets(enderecos[totalUsuarios], MAX_ENDERECO, stdin);
    enderecos[totalUsuarios][strcspn(enderecos[totalUsuarios], "\n")] = '\0';

    printf("Digite a altura do usuário (em metros): ");
    scanf("%lf", &alturas[totalUsuarios]);
    while (!validarAltura(alturas[totalUsuarios])) {
        printf("Altura inválida. Digite novamente: ");
        scanf("%lf", &alturas[totalUsuarios]);
    }

    printf("O usuário foi vacinado? (1 - Sim / 0 - Não): ");
    scanf("%d", &vacinas[totalUsuarios]);
    while (!validarVacina(vacinas[totalUsuarios])) {
        printf("Opção inválida. Digite novamente: ");
        scanf("%d", &vacinas[totalUsuarios]);
    }

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
    while (!validarEmail(emails[indice])) {
        printf("Email inválido. Digite novamente: ");
        fgets(emails[indice], MAX_EMAIL, stdin);
        emails[indice][strcspn(emails[indice], "\n")] = '\0';
    }

    printf("Digite o novo sexo do usuário (Feminino/Masculino/Indiferente): ");
    fgets(sexos[indice], MAX_SEXO, stdin);
    sexos[indice][strcspn(sexos[indice], "\n")] = '\0';
    while (!validarSexo(sexos[indice])) {
        printf("Sexo inválido. Digite novamente: ");
        fgets(sexos[indice], MAX_SEXO, stdin);
        sexos[indice][strcspn(sexos[indice], "\n")] = '\0';
    }

    printf("Digite o novo endereço do usuário: ");
    fgets(enderecos[indice], MAX_ENDERECO, stdin);
    enderecos[indice][strcspn(enderecos[indice], "\n")] = '\0';

    printf("Digite a nova altura do usuário (em metros): ");
    scanf("%lf", &alturas[indice]);
    while (!validarAltura(alturas[indice])) {
        printf("Altura inválida. Digite novamente: ");
        scanf("%lf", &alturas[indice]);
    }

    printf("O usuário foi vacinado? (1 - Sim / 0 - Não): ");
    scanf("%d", &vacinas[indice]);
    while (!validarVacina(vacinas[indice])) {
        printf("Opção inválida. Digite novamente: ");
        scanf("%d", &vacinas[indice]);
    }

    printf("Usuário editado com sucesso.\n");
}

void buscarUsuarioPorEmail() {
    char email[MAX_EMAIL];
    printf("Digite o email do usuário a ser buscado: ");
    getchar();
    fgets(email, MAX_EMAIL, stdin);
    email[strcspn(email, "\n")] = '\0';
    while (!validarEmail(email)) {
        printf("Email inválido. Digite novamente: ");
        fgets(email, MAX_EMAIL, stdin);
        email[strcspn(email, "\n")] = '\0';
    }

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
    int opcao;
    srand(time(NULL));

    do {
        printf("----- SISTEMA DE CADASTRO DE USUÁRIOS -----\n");
        printf("1 - Cadastrar novo usuário\n");
        printf("2 - Editar usuário\n");
        printf("3 - Buscar usuário por email\n");
        printf("4 - Imprimir usuários cadastrados\n");
        printf("5 - Realizar backup\n");
        printf("6 - Restaurar dados\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                editarUsuario();
                break;
            case 3:
                buscarUsuarioPorEmail();
                break;
            case 4:
                imprimirUsuarios();
                break;
            case 5:
                realizarBackup();
                break;
            case 6:
                restaurarDados();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Digite novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}