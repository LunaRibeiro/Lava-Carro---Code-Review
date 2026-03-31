#include <stdio.h>
#include <stdlib.h>

struct Carro {
    char modelo[30];
    char placa[30];
    char cor[30];
};

int decrementarFila(int *tamanhoFila);
int incrementarFila(int *tamanhoFila);
void limparEntrada();
float calcularValor(float preco, float quantidade);
int validarEntradas(float precoEtanol, float precoGasolina, float precoAditivada, float capacidadeFila);
int mostrarMenu();

int main(void) {

    float precoEtanol = 1, precoGasolina = 1, precoAditivada = 1;
    float litrosEtanol = 0, litrosGasolina = 0, litrosAditivada = 0;
    float valorArrecadado = 0;
    float carrosAtendidos = 0;
    float capacidadeFila = 1;

    float etanolRestante = 200, gasolinaRestante = 200, aditivadaRestante = 200;

    int tamanhoFila = 0, opcaoMenu, opcaoRelatorio;
    int capacidadeMaxima = 100;
    int indiceCarro = 0;

    struct Carro carros[100];

    do {
        validarEntradas(precoEtanol, precoGasolina, precoAditivada, capacidadeFila);

        printf("\nDigite o preço do etanol: ");
        scanf("%f", &precoEtanol);

        printf("\nDigite o preço da gasolina: ");
        scanf("%f", &precoGasolina);

        printf("\nDigite o preço da gasolina aditivada: ");
        scanf("%f", &precoAditivada);

        printf("\nInforme o tamanho da fila: ");
        scanf("%f", &capacidadeFila);

    } while (precoEtanol < 0 || precoGasolina < 0 || precoAditivada < 0 || capacidadeFila <= 0);

    do {
        opcaoMenu = mostrarMenu();

        switch (opcaoMenu) {

            case 1:
                if (tamanhoFila < capacidadeFila) {
                    incrementarFila(&tamanhoFila);
                    limparEntrada();

                    printf("\nModelo: ");
                    fgets(carros[indiceCarro].modelo, 30, stdin);

                    printf("\nCor: ");
                    fgets(carros[indiceCarro].cor, 30, stdin);

                    printf("\nPlaca: ");
                    fgets(carros[indiceCarro].placa, 30, stdin);

                    indiceCarro++;
                    printf("\nCarro adicionado\n");
                } else {
                    printf("\nFila cheia\n");
                }
                break;

            case 2:
                if (tamanhoFila > 0) {

                    printf("\nEtanol: ");
                    scanf("%f", &litrosEtanol);
                    etanolRestante -= litrosEtanol;

                    printf("\nGasolina: ");
                    scanf("%f", &litrosGasolina);
                    gasolinaRestante -= litrosGasolina;

                    printf("\nAditivada: ");
                    scanf("%f", &litrosAditivada);
                    aditivadaRestante -= litrosAditivada;

                    carrosAtendidos++;
                    decrementarFila(&tamanhoFila);

                } else {
                    printf("Fila vazia\n");
                }
                break;

            case 4:
                printf("\nCarros atendidos: %.0f\n", carrosAtendidos);
                break;

        }

    } while (opcaoMenu != 5);

    return 0;
}

float calcularValor(float preco, float quantidade) {
    return preco * quantidade;
}

int validarEntradas(float precoEtanol, float precoGasolina, float precoAditivada, float capacidadeFila) {
    if (precoEtanol < 0) printf("Etanol inválido\n");
    if (precoGasolina < 0) printf("Gasolina inválida\n");
    if (precoAditivada < 0) printf("Aditivada inválida\n");
    if (capacidadeFila <= 0) printf("Fila inválida\n");
    return 0;
}

int mostrarMenu() {
    int opcao;
    printf("\n1-Adicionar\n2-Abastecer\n3-Próximo\n4-Relatório\n5-Sair\n");
    scanf("%d", &opcao);
    return opcao;
}

void limparEntrada() {
    int ch;
    while ((ch = fgetc(stdin)) != EOF && ch != '\n') {}
}

int incrementarFila(int *tamanhoFila) {
    (*tamanhoFila)++;
    return *tamanhoFila;
}

int decrementarFila(int *tamanhoFila) {
    (*tamanhoFila)--;
    return *tamanhoFila;
}
