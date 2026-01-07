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

int ehMaisNova(struct Pessoa p1, struct Pessoa p2) {
    if (p1.nascimento.ano > p2.nascimento.ano)
        return 1;
    else if (p1.nascimento.ano == p2.nascimento.ano) {
        if (p1.nascimento.mes > p2.nascimento.mes)
            return 1;
        else if (p1.nascimento.mes == p2.nascimento.mes &&
                 p1.nascimento.dia > p2.nascimento.dia)
            return 1;
    }
    return 0;
}

int main() {
    struct Pessoa pessoas[2];
    int i;

    for (i = 0; i < 2; i++) {
        printf("\n=== Cadastro da Pessoa %d ===\n", i + 1);

        printf("Nome: ");
        getchar(); // limpa o buffer
        fgets(pessoas[i].nome, 50, stdin);

        // remover o '\n' do final do nome
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

    int indiceMaisAlta = 0;
    if (pessoas[1].altura > pessoas[0].altura)
        indiceMaisAlta = 1;

    printf("\n\n===== PESSOA MAIS ALTA =====\n");
    printf("Nome: %s\n", pessoas[indiceMaisAlta].nome);
    printf("Data de Nascimento: %02d/%02d/%04d\n",
           pessoas[indiceMaisAlta].nascimento.dia,
           pessoas[indiceMaisAlta].nascimento.mes,
           pessoas[indiceMaisAlta].nascimento.ano);
    printf("Altura: %.2f m\n", pessoas[indiceMaisAlta].altura);

    int indiceMaisNova = 0;
    if (ehMaisNova(pessoas[1], pessoas[0]))
        indiceMaisNova = 1;

    printf("\n\n===== PESSOA MAIS NOVA =====\n");
    printf("Nome: %s\n", pessoas[indiceMaisNova].nome);
    printf("Data de Nascimento: %02d/%02d/%04d\n",
           pessoas[indiceMaisNova].nascimento.dia,
           pessoas[indiceMaisNova].nascimento.mes,
           pessoas[indiceMaisNova].nascimento.ano);
    printf("Altura: %.2f m\n", pessoas[indiceMaisNova].altura);

    return 0;
}
