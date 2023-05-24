#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USUARIOS 1000
#define MAX_NOME 100
#define MAX_EMAIL 100
#define MAX_SEXO 15
#define MAX_ENDERECO 100

// Função para gerar um ID aleatório
int gerarId() {
    return rand() % 1000 + 1;
}

// Função para adicionar um usuário
void adicionarUsuario(int ids[], char nomes[][MAX_NOME], char emails[][MAX_EMAIL], char sexos[][MAX_SEXO], char enderecos[][MAX_ENDERECO], double alturas[], int vacinas[], int *totalUsuarios) {
    if (*totalUsuarios >= MAX_USUARIOS) {
        printf("Limite maximo de usuarios atingido.\n");
        return;
    }
    
    int novoId = gerarId();
    ids[*totalUsuarios] = novoId;
    
    printf("Digite o nome completo do usuario: ");
    fgets(nomes[*totalUsuarios], MAX_NOME, stdin);
    nomes[*totalUsuarios][strcspn(nomes[*totalUsuarios], "\n")] = '\0'; // Remove o caractere de nova linha
    
    printf("Digite o email do usuario: ");
fgets(emails[*totalUsuarios], MAX_EMAIL, stdin);
emails[*totalUsuarios][strcspn(emails[*totalUsuarios], "\n")] = '\0'; // Remove o caractere de nova linha

    // Validar se o email contém o caractere "@"
        if (strchr(emails[*totalUsuarios], '@') == NULL) {
            printf("Email invalido. Certifique-se de incluir o caractere '@' no email.\n");
            return;
}   
    
    printf("Digite o sexo do usuario (Feminino/Masculino/Indiferente): ");
fgets(sexos[*totalUsuarios], MAX_SEXO, stdin);
sexos[*totalUsuarios][strcspn(sexos[*totalUsuarios], "\n")] = '\0'; // Remove o caractere de nova linha

// Validar se o sexo é válido
if (strcmp(sexos[*totalUsuarios], "Feminino") != 0 && strcmp(sexos[*totalUsuarios], "Masculino") != 0 && strcmp(sexos[*totalUsuarios], "Indiferente") != 0) {
    printf("Sexo invalido. Certifique-se de digitar 'Feminino', 'Masculino' ou 'Indiferente'.\n");
    return;
}

    printf("Digite o endereco do usuario: ");
    fgets(enderecos[*totalUsuarios], MAX_ENDERECO, stdin);
    enderecos[*totalUsuarios][strcspn(enderecos[*totalUsuarios], "\n")] = '\0'; // Remove o caractere de nova linha
    
    printf("Digite a altura do usuario (em metros): ");
if (scanf("%lf", &alturas[*totalUsuarios]) != 1) {
    printf("Altura invalida. Certifique-se de digitar um valor numerico.\n");
    return;
}

    printf("Digite a altura do usuario (em metros): ");
if (scanf("%lf", &vacinas[*totalUsuarios]) != 1 || (vacinas[*totalUsuarios] != 0 && vacinas[*totalUsuarios] != 1)) {
    printf("Altura invalida. Certifique-se de digitar apenas 0 ou 1.\n");
    return;
}
    
    
    getchar(); // Limpa o buffer do teclado
    
    (*totalUsuarios)++;
    
    printf("Usuario adicionado com sucesso.\n");
}

// Função para editar um usuário
void editarUsuario(int ids[], char nomes[][MAX_NOME], char emails[][MAX_EMAIL], char sexos[][MAX_SEXO], char enderecos[][MAX_ENDERECO], double alturas[], int vacinas[], int totalUsuarios) {
    if (totalUsuarios == 0) {
        printf("Nao ha usuarios cadastrados.\n");
        return;
    }
    
    int id;
    printf("Digite o ID do usuario que deseja editar: ");
    scanf("%d", &id);
    
    int index = -1;
    for (int i = 0; i < totalUsuarios; i++) {
        if (ids[i] == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }
    
    getchar(); // Limpa o buffer do teclado
    
    printf("Digite o novo nome completo do usuario: ");
    fgets(nomes[index], MAX_NOME, stdin);
    nomes[index][strcspn(nomes[index], "\n")] = '\0'; // Remove o caractere de nova linha
    
    printf("Digite o novo email do usuario: ");
    fgets(emails[index], MAX_EMAIL, stdin);
    emails[index][strcspn(emails[index], "\n")] = '\0'; // Remove o caractere de nova linha
    
    printf("Digite o novo sexo do usuario (Feminino/Masculino/Indiferente): ");
    fgets(sexos[index], MAX_SEXO, stdin);
    sexos[index][strcspn(sexos[index], "\n")] = '\0'; // Remove o caractere de nova linha
    
    printf("Digite o novo endereco do usuario: ");
    fgets(enderecos[index], MAX_ENDERECO, stdin);
    enderecos[index][strcspn(enderecos[index], "\n")] = '\0'; // Remove o caractere de nova linha
    
    printf("Digite a nova altura do usuario (em metros): ");
    scanf("%lf", &alturas[index]);
    
    printf("O usuario foi vacinado? (1 - Sim / 0 - Nao): ");
    scanf("%d", &vacinas[index]);
    
    getchar(); // Limpa o buffer do teclado
    
    printf("Usuario editado com sucesso.\n");
}

// Função para excluir um usuário
void excluirUsuario(int ids[], char nomes[][MAX_NOME], char emails[][MAX_EMAIL], char sexos[][MAX_SEXO], char enderecos[][MAX_ENDERECO], double alturas[], int vacinas[], int *totalUsuarios) {
    if (*totalUsuarios == 0) {
        printf("Nao ha usuarios cadastrados.\n");
        return;
    }
    
    int id;
    printf("Digite o ID do usuario que deseja excluir: ");
    scanf("%d", &id);
    
    int index = -1;
    for (int i = 0; i < *totalUsuarios; i++) {
        if (ids[i] == id) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }
    
    for (int i = index; i < (*totalUsuarios) - 1; i++) {
        ids[i] = ids[i + 1];
        strcpy(nomes[i], nomes[i + 1]);
        strcpy(emails[i], emails[i + 1]);
        strcpy(sexos[i], sexos[i + 1]);
        strcpy(enderecos[i], enderecos[i + 1]);
        alturas[i] = alturas[i + 1];
        vacinas[i] = vacinas[i + 1];
    }
    
    (*totalUsuarios)--;
    
    printf("Usuario excluido com sucesso.\n");
}

// Função para buscar um usuário pelo email
void buscarUsuarioPorEmail(int ids[], char nomes[][MAX_NOME], char emails[][MAX_EMAIL], char sexos[][MAX_SEXO], char enderecos[][MAX_ENDERECO], double alturas[], int vacinas[], int totalUsuarios) {
    if (totalUsuarios == 0) {
        printf("Nao ha usuarios cadastrados.\n");
        return;
    }
    
    char email[MAX_EMAIL];
    printf("Digite o email do usuario que deseja buscar: ");
    fgets(email, MAX_EMAIL, stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove o caractere de nova linha
    
    int index = -1;
    for (int i = 0; i < totalUsuarios; i++) {
        if (strcmp(emails[i], email) == 0) {
            index = i;
            break;
        }
    }
    
    if (index == -1) {
        printf("Usuario nao encontrado.\n");
        return;
    }
    
    printf("ID: %d\n", ids[index]);
    printf("Nome completo: %s\n", nomes[index]);
    printf("Email: %s\n", emails[index]);
    printf("Sexo: %s\n", sexos[index]);
    printf("Endereco: %s\n", enderecos[index]);
    printf("Altura: %.2f\n", alturas[index]);
    printf("Vacina: %s\n", vacinas[index] == 1 ? "Sim" : "Nao");
}

// Função para imprimir todos os usuários cadastrados
void imprimirUsuarios(int ids[], char nomes[][MAX_NOME], char emails[][MAX_EMAIL], char sexos[][MAX_SEXO], char enderecos[][MAX_ENDERECO], double alturas[], int vacinas[], int totalUsuarios) {
    if (totalUsuarios == 0) {
        printf("Nao ha usuarios cadastrados.\n");
        return;
    }
    
    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d\n", ids[i]);
        printf("Nome completo: %s\n", nomes[i]);
        printf("Email: %s\n", emails[i]);
        printf("Sexo: %s\n", sexos[i]);
        printf("Endereco: %s\n", enderecos[i]);
        printf("Altura: %.2f\n", alturas[i]);
        printf("Vacina: %s\n", vacinas[i] == 1 ? "Sim" : "Nao");
        printf("----------------------\n");
    }
}

// Função para fazer backup dos usuários cadastrados
void fazerBackup(int ids[], char nomes[][MAX_NOME], char emails[][MAX_EMAIL], char sexos[][MAX_SEXO], char enderecos[][MAX_ENDERECO], double alturas[], int vacinas[], int totalUsuarios, int backupIds[], char backupNomes[][MAX_NOME], char backupEmails[][MAX_EMAIL], char backupSexos[][MAX_SEXO], char backupEnderecos[][MAX_ENDERECO], double backupAlturas[], int backupVacinas[], int *totalBackupUsuarios) {
    if (totalUsuarios == 0) {
        printf("Nao ha usuarios cadastrados.\n");
        return;
    }
    
    for (int i = 0; i < totalUsuarios; i++) {
        backupIds[i] = ids[i];
        strcpy(backupNomes[i], nomes[i]);
        strcpy(backupEmails[i], emails[i]);
        strcpy(backupSexos[i], sexos[i]);
        strcpy(backupEnderecos[i], enderecos[i]);
        backupAlturas[i] = alturas[i];
        backupVacinas[i] = vacinas[i];
    }
    
    *totalBackupUsuarios = totalUsuarios;
    
    printf("Backup realizado com sucesso.\n");
}

int main() {
    int ids[MAX_USUARIOS];
    char nomes[MAX_USUARIOS][MAX_NOME];
    char emails[MAX_USUARIOS][MAX_EMAIL];
    char sexos[MAX_USUARIOS][MAX_SEXO];
    char enderecos[MAX_USUARIOS][MAX_ENDERECO];
    double alturas[MAX_USUARIOS];
    int vacinas[MAX_USUARIOS];
    int totalUsuarios = 0;
    
    int backupIds[MAX_USUARIOS];
    char backupNomes[MAX_USUARIOS][MAX_NOME];
    char backupEmails[MAX_USUARIOS][MAX_EMAIL];
    char backupSexos[MAX_USUARIOS][MAX_SEXO];
    char backupEnderecos[MAX_USUARIOS][MAX_ENDERECO];
    double backupAlturas[MAX_USUARIOS];
    int backupVacinas[MAX_USUARIOS];
    int totalBackupUsuarios = 0;
    
    srand(time(0));
    
    int opcao;
    do {
        printf("----- Menu -----\n");
        printf("1. Adicionar usuario\n");
        printf("2. Editar usuario\n");
        printf("3. Excluir usuario\n");
        printf("4. Buscar usuario por email\n");
        printf("5. Imprimir usuarios cadastrados\n");
        printf("6. Fazer backup dos usuarios cadastrados\n");
        printf("7. Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado
        
        switch (opcao) {
            case 1:
                adicionarUsuario(ids, nomes, emails, sexos, enderecos, alturas, vacinas, &totalUsuarios);
                break;
            case 2:
                editarUsuario(ids, nomes, emails, sexos, enderecos, alturas, vacinas, totalUsuarios);
                break;
            case 3:
                excluirUsuario(ids, nomes, emails, sexos, enderecos, alturas, vacinas, &totalUsuarios);
                break;
            case 4:
                buscarUsuarioPorEmail(ids, nomes, emails, sexos, enderecos, alturas, vacinas, totalUsuarios);
                break;
            case 5:
                imprimirUsuarios(ids, nomes, emails, sexos, enderecos, alturas, vacinas, totalUsuarios);
                break;
            case 6:
                fazerBackup(ids, nomes, emails, sexos, enderecos, alturas, vacinas, totalUsuarios, backupIds, backupNomes, backupEmails, backupSexos, backupEnderecos, backupAlturas, backupVacinas, &totalBackupUsuarios);
                break;
            case 7:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
        
        printf("----------------------\n");
    } while (opcao != 7);
    
    return 0;
}