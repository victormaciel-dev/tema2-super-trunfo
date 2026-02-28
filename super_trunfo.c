#include <stdio.h>
#include <string.h>

/*
  Tema 2 - Super Trunfo (Países/Cidades) em C

  Objetivo do desafio:
  - Cadastrar cartas (cidades) com dados básicos: estado, código, nome, população, PIB, área, pontos turísticos.
  - Calcular propriedades derivadas: densidade populacional e PIB per capita.
  - Demonstrar uso de variáveis, entrada/saída, operadores matemáticos e relacionais,
    e modificadores de tipo (int, long long, double etc).

  Observação:
  - Não é um jogo completo com disputa/rodadas.
  - É um sistema de cadastro + exibição com cálculos, conforme o enunciado.
*/

typedef struct {
    char estado[50];
    char codigo[20];
    char cidade[100];

    long long populacao;   // pode ser grande
    double pib;            // em bilhões ou unidade informada pelo aluno
    double area;           // km²
    int pontosTuristicos;

    double densidade;      // populacao / area
    double pibPerCapita;   // pib / populacao (ajustado conforme unidade)
} Carta;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void lerLinha(const char *msg, char *dest, int tamanho) {
    printf("%s", msg);
    if (fgets(dest, tamanho, stdin) != NULL) {
        dest[strcspn(dest, "\n")] = '\0'; // remove \n
    }
}

Carta cadastrarCarta(int numero) {
    Carta c;
    printf("\n==============================\n");
    printf(" Cadastro da Carta %d\n", numero);
    printf("==============================\n");

    lerLinha("Estado (ex: SP): ", c.estado, sizeof(c.estado));
    lerLinha("Codigo da carta (ex: A01): ", c.codigo, sizeof(c.codigo));
    lerLinha("Nome da cidade: ", c.cidade, sizeof(c.cidade));

    printf("Populacao (somente numeros): ");
    scanf("%lld", &c.populacao);
    limparBuffer();

    printf("PIB (ex: 123.45): ");
    scanf("%lf", &c.pib);
    limparBuffer();

    printf("Area em km2 (ex: 321.99): ");
    scanf("%lf", &c.area);
    limparBuffer();

    printf("Numero de pontos turisticos: ");
    scanf("%d", &c.pontosTuristicos);
    limparBuffer();

    // Cálculos derivados (operadores matemáticos + tipos)
    // Proteção contra divisão por zero
    if (c.area > 0) {
        c.densidade = (double)c.populacao / c.area;
    } else {
        c.densidade = 0.0;
    }

    if (c.populacao > 0) {
        // Aqui estamos assumindo que PIB foi informado em "reais" ou "bilhões" conforme você escolher.
        // Se você digitar PIB em reais, o per capita sai em reais.
        // Se você digitar PIB em bilhões, o per capita sai em bilhões por pessoa (não faz sentido),
        // então o ideal é informar PIB em reais.
        c.pibPerCapita = c.pib / (double)c.populacao;
    } else {
        c.pibPerCapita = 0.0;
    }

    return c;
}

void exibirCarta(Carta c, int numero) {
    printf("\n==============================\n");
    printf(" Carta %d - SUPER TRUNFO\n", numero);
    printf("==============================\n");
    printf("Estado: %s\n", c.estado);
    printf("Codigo: %s\n", c.codigo);
    printf("Cidade: %s\n", c.cidade);

    printf("Populacao: %lld\n", c.populacao);
    printf("PIB: %.2f\n", c.pib);
    printf("Area (km2): %.2f\n", c.area);
    printf("Pontos Turisticos: %d\n", c.pontosTuristicos);

    printf("Densidade Populacional: %.2f hab/km2\n", c.densidade);
    printf("PIB per Capita: %.6f\n", c.pibPerCapita);
}

/*
  Demonstração de operadores relacionais:
  Compara duas cartas em alguns critérios e indica “qual é maior”.
  (Não é a disputa completa do Super Trunfo, mas mostra o uso de > < == etc.)
*/
void compararCartas(Carta a, Carta b) {
    printf("\n==============================\n");
    printf(" Comparacoes (Operadores Relacionais)\n");
    printf("==============================\n");

    // População
    if (a.populacao > b.populacao) {
        printf("Populacao: %s vence (%lld > %lld)\n", a.cidade, a.populacao, b.populacao);
    } else if (a.populacao < b.populacao) {
        printf("Populacao: %s vence (%lld < %lld)\n", b.cidade, a.populacao, b.populacao);
    } else {
        printf("Populacao: Empate (%lld == %lld)\n", a.populacao, b.populacao);
    }

    // PIB
    if (a.pib > b.pib) {
        printf("PIB: %s vence (%.2f > %.2f)\n", a.cidade, a.pib, b.pib);
    } else if (a.pib < b.pib) {
        printf("PIB: %s vence (%.2f < %.2f)\n", b.cidade, a.pib, b.pib);
    } else {
        printf("PIB: Empate (%.2f == %.2f)\n", a.pib, b.pib);
    }

    // Densidade (aqui normalmente “menor densidade” não é regra, mas é só demonstração)
    if (a.densidade > b.densidade) {
        printf("Densidade: %s tem maior densidade (%.2f > %.2f)\n", a.cidade, a.densidade, b.densidade);
    } else if (a.densidade < b.densidade) {
        printf("Densidade: %s tem maior densidade (%.2f < %.2f)\n", b.cidade, a.densidade, b.densidade);
    } else {
        printf("Densidade: Empate (%.2f == %.2f)\n", a.densidade, b.densidade);
    }

    // Pontos turísticos
    if (a.pontosTuristicos >= b.pontosTuristicos) {
        printf("Pontos Turisticos: %s tem mais ou igual (%d >= %d)\n", a.cidade, a.pontosTuristicos, b.pontosTuristicos);
    } else {
        printf("Pontos Turisticos: %s tem mais (%d > %d)\n", b.cidade, b.pontosTuristicos, a.pontosTuristicos);
    }
}

int main() {
    printf("#############################################\n");
    printf("# Tema 2 - Super Trunfo (Cadastro de Cartas) #\n");
    printf("#############################################\n");

    // Cadastro de 2 cartas (padrão de muitos desafios)
    Carta carta1 = cadastrarCarta(1);
    Carta carta2 = cadastrarCarta(2);

    // Exibição das cartas
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    // Comparações (operadores relacionais)
    compararCartas(carta1, carta2);

    printf("\nPrograma finalizado com sucesso!\n");
    return 0;
}
