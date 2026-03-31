#include <stdio.h>
#include <stdlib.h>

struct Carro {
    char modelo[30];
    char placa[30];
    char cor[30];
};

void limparEntrada() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int mostrarMenu() {
    int opcao;

    printf("\n================ MENU ================\n");
    printf("1 - Adicionar carro na fila\n");
    printf("2 - Abastecer carro\n");
    printf("3 - Chamar próximo carro\n");
    printf("4 - Relatórios\n");
    printf("5 - Sair\n");
    printf("=====================================\n");
    printf("Escolha uma opção: ");
    
    scanf("%d", &opcao);
    return opcao;
}

int validarEntradas(float etanol, float gasolina, float aditivada, int capacidadeFila) {
    if (etanol < 0 || gasolina < 0 || aditivada < 0 || capacidadeFila <= 0) {
        printf("\nValores inválidos! Tente novamente.\n");
        return 1;
    }
    return 0;
}

int main() {
    float precoEtanol, precoGasolina, precoAditivada;

    float totalEtanol = 0, totalGasolina = 0, totalAditivada = 0;

    // Estoque
    float etanolRestante = 200;
    float gasolinaRestante = 200;
    float aditivadaRestante = 200;

    // Controle da fila
    int capacidadeFila;
    int tamanhoFila = 0;
    int carrosAtendidos = 0;

    // Controle de fila (FIFO)
    int inicioFila = 0;
    int fimFila = 0;

    struct Carro carros[100];

    do {
        printf("\nDigite o preço do etanol: ");
        scanf("%f", &precoEtanol);

        printf("Digite o preço da gasolina: ");
        scanf("%f", &precoGasolina);

        printf("Digite o preço da gasolina aditivada: ");
        scanf("%f", &precoAditivada);

        printf("Informe a capacidade da fila: ");
        scanf("%d", &capacidadeFila);

    } while (validarEntradas(precoEtanol, precoGasolina, precoAditivada, capacidadeFila));

    int opcao;

    do {
        opcao = mostrarMenu();

        switch (opcao) {
            case 1:
                if (tamanhoFila < capacidadeFila) {

                    limparEntrada();

                    printf("\nModelo: ");
                    fgets(carros[fimFila].modelo, 30, stdin);

                    printf("Cor: ");
                    fgets(carros[fimFila].cor, 30, stdin);

                    printf("Placa: ");
                    fgets(carros[fimFila].placa, 30, stdin);

                    fimFila++;
                    tamanhoFila++;

                    printf("\nCarro adicionado à fila!\n");

                } else {
                    printf("\nFila cheia!\n");
                }
                break;

            case 2:
                if (tamanhoFila > 0) {

                    int tipoCombustivel;
                    float litros;

                    printf("\nEscolha o combustível:\n");
                    printf("1 - Etanol\n");
                    printf("2 - Gasolina\n");
                    printf("3 - Aditivada\n");
                    printf("Opção: ");
                    scanf("%d", &tipoCombustivel);

                    printf("Quantidade de litros: ");
                    scanf("%f", &litros);

                    switch (tipoCombustivel) {
                        case 1:
                            totalEtanol += litros;
                            etanolRestante -= litros;
                            printf("Abastecido com Etanol\n");
                            break;

                        case 2:
                            totalGasolina += litros;
                            gasolinaRestante -= litros;
                            printf("Abastecido com Gasolina\n");
                            break;

                        case 3:
                            totalAditivada += litros;
                            aditivadaRestante -= litros;
                            printf("Abastecido com Aditivada\n");
                            break;

                        default:
                            printf("Opção inválida!\n");
                            break;
                    }

                    carrosAtendidos++;
                    tamanhoFila--;
                    inicioFila++;

                } else {
                    printf("\nFila vazia!\n");
                }
                break;
            case 3:
                if (tamanhoFila > 0) {
                    printf("\nChamando próximo carro...\n");
                } else {
                    printf("\nFila vazia!\n");
                }
                break;

            case 4:
                printf("\n=========== RELATÓRIO ===========\n");

                printf("\nLitros vendidos:\n");
                printf("Etanol: %.2f\n", totalEtanol);
                printf("Gasolina: %.2f\n", totalGasolina);
                printf("Aditivada: %.2f\n", totalAditivada);

                printf("\nValor arrecadado:\n");
                printf("Etanol: %.2f\n", totalEtanol * precoEtanol);
                printf("Gasolina: %.2f\n", totalGasolina * precoGasolina);
                printf("Aditivada: %.2f\n", totalAditivada * precoAditivada);

                printf("\nEstoque restante:\n");
                printf("Etanol: %.2f\n", etanolRestante);
                printf("Gasolina: %.2f\n", gasolinaRestante);
                printf("Aditivada: %.2f\n", aditivadaRestante);

                printf("\nCarros atendidos: %d\n", carrosAtendidos);
                printf("=================================\n");
                break;

            case 5:
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while (opcao != 5);

    return 0;
}
