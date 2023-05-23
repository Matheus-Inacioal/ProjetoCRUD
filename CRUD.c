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
        printf("Limite de usuarios atingido.\n");
        return;
    }

    printf("Digite o nome do usuario: ");
    fgets(nomes[totalUsuarios], MAX_NOME, stdin);
    nomes[totalUsuarios][strcspn(nomes[totalUsuarios], "\n")] = '\0';

    printf("Digite o email do usuario: ");
    fgets(emails[totalUsuarios], MAX_EMAIL, stdin);
    emails[totalUsuarios][strcspn(emails[totalUsuarios], "\n")] = '\0';
    while (!validarEmail(emails[totalUsuarios])) {
        printf("Email invalido. Digite novamente: ");
        fgets(emails[totalUsuarios], MAX_EMAIL, stdin);
        emails[totalUsuarios][strcspn(emails[totalUsuarios], "\n")] = '\0';
    }

    printf("Digite o sexo do usuario (Feminino/Masculino/Indiferente): ");
    fgets(sexos[totalUsuarios], MAX_SEXO, stdin);
    sexos[totalUsuarios][strcspn(sexos[totalUsuarios], "\n")] = '\0';
    while (!validarSexo(sexos[totalUsuarios])) {
        printf("Sexo invalido. Digite novamente: ");
        fgets(sexos[totalUsuarios], MAX_SEXO, stdin);
        sexos[totalUsuarios][strcspn(sexos[totalUsuarios], "\n")] = '\0';
    }

    printf("Digite o endereco do usuario: ");
    fgets(enderecos[totalUsuarios], MAX_ENDERECO, stdin);
    enderecos[totalUsuarios][strcspn(enderecos[totalUsuarios], "\n")] = '\0';

    printf("Digite a altura do usuario (em metros): ");
    scanf("%lf", &alturas[totalUsuarios]);
    while (!validarAltura(alturas[totalUsuarios])) {
        printf("Altura invalida. Digite novamente: ");
        scanf("%lf", &alturas[totalUsuarios]);
    }

    printf("Digite o status de vacinacao do usuario (0 - Nao vacinado / 1 - Vacinado): ");
    scanf("%d", &vacinas[totalUsuarios]);
    while (!validarVacina(vacinas[totalUsuarios])) {
        printf("Status de vacinacao invalido. Digite novamente: ");
        scanf("%d", &vacinas[totalUsuarios]);
    }

    ids[totalUsuarios] = totalUsuarios + 1;
    totalUsuarios++;

    printf("Usuario cadastrado com sucesso.\n");
}

void excluirUsuario() {
    if (totalUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    int id;
    printf("Digite o ID do usuario a ser excluido: ");
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

    strcpy(usuariosExcluidosNomes[totalUsuariosExcluidos], nomes[indice]);
    strcpy(usuariosExcluidosEmails[totalUsuariosExcluidos], emails[indice]);
    strcpy(usuariosExcluidosSexos[totalUsuariosExcluidos], sexos[indice]);
    strcpy(usuariosExcluidosEnderecos[totalUsuariosExcluidos], enderecos[indice]);
    usuariosExcluidosAlturas[totalUsuariosExcluidos] = alturas[indice];
    usuariosExcluidosVacinas[totalUsuariosExcluidos] = vacinas[indice];

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
    totalUsuariosExcluidos++;

    printf("Usuario excluido com sucesso.\n");
}

void listarUsuarios() {
    if (totalUsuarios == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    printf("----- Usuarios Cadastrados -----\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d\n", ids[i]);
        printf("Nome: %s\n", nomes[i]);
        printf("Email: %s\n", emails[i]);
        printf("Sexo: %s\n", sexos[i]);
        printf("Endereco: %s\n", enderecos[i]);
        printf("Altura: %.2lf\n", alturas[i]);
        printf("Status de vacinacao: %s\n", vacinas[i] == 0 ? "Nao vacinado" : "Vacinado");
        printf("------------------------\n");
    }
}

void listarUsuariosExcluidos() {
    if (totalUsuariosExcluidos == 0) {
        printf("Nenhum usuario excluido.\n");
        return;
    }

    printf("----- Usuarios Excluidos -----\n");
    for (int i = 0; i < totalUsuariosExcluidos; i++) {
        printf("Nome: %s\n", usuariosExcluidosNomes[i]);
        printf("Email: %s\n", usuariosExcluidosEmails[i]);
        printf("Sexo: %s\n", usuariosExcluidosSexos[i]);
        printf("Endereco: %s\n", usuariosExcluidosEnderecos[i]);
        printf("Altura: %.2lf\n", usuariosExcluidosAlturas[i]);
        printf("Status de vacinacao: %s\n", usuariosExcluidosVacinas[i] == 0 ? "Nao vacinado" : "Vacinado");
        printf("------------------------\n");
    }
}

int main() {
    int opcao;

    srand(time(0));

    do {
        printf("----- Menu -----\n");
        printf("1. Cadastrar usuario\n");
        printf("2. Excluir usuario\n");
        printf("3. Listar usuarios cadastrados\n");
        printf("4. Listar usuarios excluidos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrarUsuario();
                break;
            case 2:
                excluirUsuario();
                break;
            case 3:
                listarUsuarios();
                break;
            case 4:
                listarUsuariosExcluidos();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }

        printf("\n");

    } while (opcao != 0);

    return 0;
}