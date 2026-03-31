#include <stdio.h>
#include <stdlib.h>

struct Tcarro {
    char modelo[30];
    char placa[30];
    char cor[30];
};

int fun_decre(int *fila);
int fun_incre(int *fila);
void flush_in();
float calcValor(float preco, float qtd);
int fun_invalidos(float prEta, float prGas, float prAdit, float tFila);
int fun_escreva();

int main(void) {

    float prEta = 1, prGas = 1, prAdit = 1;
    float qtdEta = 0, qtdGas = 0, qtdAdit = 0;
    float valRec, cAtendido = 0, tFila = 1;

    float etaRestante = 200, gasRestante = 200, aditRestante = 200;

    int fila = 0, relatorio, menu;
    int tam = 100;
    int cont = 0;

    struct Tcarro carros[tam];

    do {
        fun_invalidos(prEta, prGas, prAdit, tFila);

        printf("\nDigite o preço do etanol: ");
        scanf("%f", &prEta);

        printf("\nDigite o preço da gasolina: ");
        scanf("%f", &prGas);

        printf("\nDigite o preço da gasolina aditivada: ");
        scanf("%f", &prAdit);

        printf("\nInforme o tamanho da fila: ");
        scanf("%f", &tFila);

    } while (prEta < 0 || prGas < 0 || prAdit < 0 || tFila <= 0);

    do {
        menu = fun_escreva();

        switch (menu) {

            case 1:
                if (fila < tFila) {
                    fun_incre(&fila);
                    flush_in();

                    printf("\nModelo: ");
                    fgets(carros[cont].modelo, 30, stdin);

                    printf("\nCor: ");
                    fgets(carros[cont].cor, 30, stdin);

                    printf("\nPlaca: ");
                    fgets(carros[cont].placa, 30, stdin);

                    cont++;
                    printf("\nCarro adicionado\n");
                } else {
                    printf("\nFila cheia\n");
                }
                break;

            case 2:
                if (fila > 0) {
                    printf("\nEtanol: ");
                    scanf("%f", &qtdEta);
                    etaRestante -= qtdEta;

                    printf("\nGasolina: ");
                    scanf("%f", &qtdGas);
                    gasRestante -= qtdGas;

                    printf("\nAditivada: ");
                    scanf("%f", &qtdAdit);
                    aditRestante -= qtdAdit;

                    cAtendido++;
                    fun_decre(&fila);

                } else {
                    printf("Fila vazia\n");
                }
                break;

            case 4:
                printf("Carros atendidos: %.0f\n", cAtendido);
                break;

        }

    } while (menu != 5);

    return 0;
}

float calcValor(float preco, float qtd) {
    return preco * qtd;
}

int fun_invalidos(float prEta, float prGas, float prAdit, float tFila) {
    if (prEta < 0) printf("Etanol inválido\n");
    if (prGas < 0) printf("Gasolina inválida\n");
    if (prAdit < 0) printf("Aditivada inválida\n");
    if (tFila <= 0) printf("Fila inválida\n");
    return 0;
}

int fun_escreva() {
    int opcao;
    printf("\n1-Adicionar\n2-Abastecer\n3-Próximo\n4-Relatório\n5-Sair\n");
    scanf("%d", &opcao);
    return opcao;
}

void flush_in() {
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n') {}
}

int fun_incre(int *fila) {
    (*fila)++;
    return *fila;
}

int fun_decre(int *fila) {
    (*fila)--;
    return *fila;
}
