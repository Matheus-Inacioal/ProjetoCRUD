#include <stdio.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_EMAIL 50
#define MAX_SEXO 15
#define MAX_ENDERECO 100
#define MAX_USUARIOS 1000

// Função para gerar um novo ID
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
    
    while (1) {
        printf("Digite o nome completo do usuario: ");
        fgets(nomes[*totalUsuarios], MAX_NOME, stdin);
        nomes[*totalUsuarios][strcspn(nomes[*totalUsuarios], "\n")] = '\0'; // Remove o caractere de nova linha
        
        if (strlen(nomes[*totalUsuarios]) > 0) {
            break;
        }
        
        printf("Nome invalido. Por favor, tente novamente.\n");
    }
    
    while (1) {
        printf("Digite o email do usuario: ");
        fgets(emails[*totalUsuarios], MAX_EMAIL, stdin);
        emails[*totalUsuarios][strcspn(emails[*totalUsuarios], "\n")] = '\0'; // Remove o caractere de nova linha

        // Validar se o email contem o caractere "@"
        if (strchr(emails[*totalUsuarios], '@') != NULL) {
            break;
        }
        
        printf("Email invalido. Certifique-se de incluir o caractere '@' no email.\n");
    }
    
    while (1) {
        printf("Digite o sexo do usuario (Feminino/Masculino/Indiferente): ");
        fgets(sexos[*totalUsuarios], MAX_SEXO, stdin);
        sexos[*totalUsuarios][strcspn(sexos[*totalUsuarios], "\n")] = '\0'; // Remove o caractere de nova linha

        // Validar se o sexo e valido
        if (strcmp(sexos[*totalUsuarios], "Feminino") == 0 || strcmp(sexos[*totalUsuarios], "Masculino") == 0 || strcmp(sexos[*totalUsuarios], "Indiferente") == 0) {
            break;
        }
        
        printf("Sexo invalido. Certifique-se de digitar 'Feminino', 'Masculino' ou 'Indiferente'.\n");
    }
    
    while (1) {
        printf("Digite o endereco do usuario: ");
        fgets(enderecos[*totalUsuarios], MAX_ENDERECO, stdin);
        enderecos[*totalUsuarios][strcspn(enderecos[*totalUsuarios], "\n")] = '\0'; // Remove o caractere de nova linha
        
        if (strlen(enderecos[*totalUsuarios]) > 0) {
            break;
        }
        
        printf("Endereco invalido. Por favor, tente novamente.\n");
    }
    
    while (1) {
    printf("Digite a altura do usuario em metros (entre 1 e 2): ");
    if (scanf("%lf", &alturas[*totalUsuarios]) == 1 && (alturas[*totalUsuarios] >= 1 && alturas[*totalUsuarios] <= 2)) {
        break;
    }
    
    printf("Altura invalida. Por favor, tente novamente.\n");
}

    while (1) {
        printf("Digite o status de vacinacao do usuario (1 - Tomou as vacinas / 2 - Nao tomou as vacinas): ");
        if (scanf("%d", &vacinas[*totalUsuarios]) == 1 && (vacinas[*totalUsuarios] == 1 || vacinas[*totalUsuarios] == 2)) {
            break;
        }
        
        printf("Opcao invalida. Por favor, tente novamente.\n");
    }
    
    (*totalUsuarios)++;
    
    printf("Usuario adicionado com sucesso. ID: %d\n", novoId);
}

// Função para exibir informações de um usuário
void exibirUsuario(int id, int ids[], char nomes[][MAX_NOME], char emails[][MAX_EMAIL], char sexos[][MAX_SEXO], char enderecos[][MAX_ENDERECO], double alturas[], int vacinas[], int totalUsuarios) {
    int i;
    for (i = 0; i < totalUsuarios; i++) {
        if (ids[i] == id) {
            printf("ID: %d\n", ids[i]);
            printf("Nome: %s\n", nomes[i]);
            printf("Email: %s\n", emails[i]);
            printf("Sexo: %s\n", sexos[i]);
            printf("Endereco: %s\n", enderecos[i]);
            printf("Altura: %.2lf metros\n", alturas[i]);
            printf("Status de Vacinacao: %s\n", vacinas[i] == 1 ? "Tomou as vacinas" : "Nao tomou as vacinas");
            return;
        }
    }
    
    printf("Usuario nao encontrado com o ID: %d\n", id);
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
    
    int opcao;
    int id;
    
    do {
        printf("Selecione uma opcao:\n");
        printf("1 - Adicionar usuario\n");
        printf("2 - Exibir informacoes de um usuario\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                adicionarUsuario(ids, nomes, emails, sexos, enderecos, alturas, vacinas, &totalUsuarios);
                break;
                
            case 2:
                printf("Digite o ID do usuario: ");
                scanf("%d", &id);
                exibirUsuario(id, ids, nomes, emails, sexos, enderecos, alturas, vacinas, totalUsuarios);
                break;
                
            case 0:
                printf("Saindo...\n");
                break;
                
            default:
                printf("Opcao invalida. Por favor, tente novamente.\n");
                break;
        }
        
        printf("\n");
    } while (opcao != 0);
    
    return 0;
}
