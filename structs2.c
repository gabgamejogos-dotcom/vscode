#include <stdio.h>


struct Data {
    int dia;
    int mes;
    int ano;
};


struct Pessoa {
    char nome[50];
    struct Data nascimento;
    float altura;
};


int converterData(struct Data d) {
    return (d.ano * 10000) + (d.mes * 100) + d.dia;
}

int main() {
    struct Pessoa pessoas[2];
    int i;

    
    for (i = 0; i < 2; i++) {
        printf("\n=== Cadastro da Pessoa %d ===\n", i + 1);

        printf("Nome: ");
        getchar(); // limpa o buffer
        fgets(pessoas[i].nome, 50, stdin);

       
        int j = 0;
        while (pessoas[i].nome[j] != '\0') {
            if (pessoas[i].nome[j] == '\n') {
                pessoas[i].nome[j] = '\0';
                break;
            }
            j++;
        }

        printf("Dia de nascimento: ");
        scanf("%d", &pessoas[i].nascimento.dia);

        printf("Mês de nascimento: ");
        scanf("%d", &pessoas[i].nascimento.mes);

        printf("Ano de nascimento: ");
        scanf("%d", &pessoas[i].nascimento.ano);

        printf("Altura (em metros): ");
        scanf("%f", &pessoas[i].altura);
    }

    printf("\n\n===== LISTA DE PESSOAS CADASTRADAS =====\n");
    for (i = 0; i < 2; i++) {
        printf("\nPessoa %d:\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Data de Nascimento: %02d/%02d/%04d\n",
               pessoas[i].nascimento.dia,
               pessoas[i].nascimento.mes,
               pessoas[i].nascimento.ano);
        printf("Altura: %.2f m\n", pessoas[i].altura);
        }                         