#include <stdio.h>
#include <string.h>

int main() {
    int codigo[20];
    char nome[20][50];
    float preco[20];
    int quantidade[20];
    int total = 0, contador = 0;
    int opcao;
    int consulta = 0;
    int alteracao = 0;
    int posicao;
    int novoCodigo;
    int repetido;

    do {
        printf("O que deseja fazer:\n1 - Cadastrar\n2 - Consultar\n3 - Listar\n4 - Alterar\n5 - Excluir\n0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao < 0 || opcao > 5) {
            printf("Opcao inexistente.\n");
        }

        switch (opcao) {
            case 1:
                if (total >= 20) {
                    printf("Limite maximo de cadastros atingido.\n");
                    break;
                }

                printf("Digite o codigo: ");
                scanf("%d", &novoCodigo);

                repetido = 0;

                for (int i = 0; i < total; i++) {
                    if (codigo[i] == novoCodigo) {
                        repetido = 1;
                        break;
                    }
                }

                if (repetido == 1) {
                    printf("Ja existe um cadastro com esse codigo.\n");
                    break;
                }

                codigo[total] = novoCodigo;

                printf("Digite o nome: ");
                scanf("%49s", nome[total]);
                printf("Digite o preco: ");
                scanf("%f", &preco[total]);
                printf("Digite a quantidade: ");
                scanf("%d", &quantidade[total]);

                total++;
                break;

            case 2:
                printf("Digite o codigo que deseja consultar: ");
                scanf("%d", &consulta);

                posicao = -1;

                for (int i = 0; i < total; i++) {
                    if (codigo[i] == consulta) {
                        posicao = i;
                        break;
                    }
                }

                if (posicao == -1) {
                    printf("Cadastro inexistente.\n");
                } else {
                    printf(
                        "\ncodigo: %d\nnome: %s\npreco: %.2f\nquantidade: %d\n\n",
                        codigo[posicao], nome[posicao],
                        preco[posicao], quantidade[posicao]
                    );
                }
                break;

            case 3:
                if (total == 0) {
                    printf("Nenhum cadastro registrado.\n");
                    break;
                }

                contador = 0;

                while (total >= contador + 1) {
                    printf(
                        "\ncodigo: %d\nnome: %s\npreco: %.2f\nquantidade: %d\n\n",
                        codigo[contador], nome[contador],
                        preco[contador], quantidade[contador]
                    );
                    contador++;
                }
                break;

            case 4:
                printf("Digite o codigo que deseja alterar: ");
                scanf("%d", &consulta);

                posicao = -1;

                for (int i = 0; i < total; i++) {
                    if (codigo[i] == consulta) {
                        posicao = i;
                        break;
                    }
                }

                if (posicao == -1) {
                    printf("Cadastro inexistente.\n");
                    break;
                }

                printf("\n1 - codigo\n2 - nome\n3 - preco\n4 - quantidade\nO que deseja alterar: ");
                scanf("%d", &alteracao);

                switch (alteracao) {
                    case 1:
                        printf("Digite o codigo: ");
                        scanf("%d", &novoCodigo);

                        repetido = 0;

                        for (int i = 0; i < total; i++) {
                            if (codigo[i] == novoCodigo && i != posicao) {
                                repetido = 1;
                                break;
                            }
                        }

                        if (repetido == 1) {
                            printf("Ja existe outro cadastro com esse codigo.\n");
                            break;
                        }

                        codigo[posicao] = novoCodigo;
                        printf("Cadastro alterado.\n");
                        break;

                    case 2:
                        printf("Digite o nome: ");
                        scanf("%49s", nome[posicao]);
                        printf("Cadastro alterado.\n");
                        break;

                    case 3:
                        printf("Digite o preco: ");
                        scanf("%f", &preco[posicao]);
                        printf("Cadastro alterado.\n");
                        break;

                    case 4:
                        printf("Digite a quantidade: ");
                        scanf("%d", &quantidade[posicao]);
                        printf("Cadastro alterado.\n");
                        break;

                    default:
                        printf("Opcao inexistente.\n");
                }
                break;

            case 5:
                printf("Digite o codigo que deseja excluir: ");
                scanf("%d", &consulta);

                posicao = -1;

                for (int i = 0; i < total; i++) {
                    if (codigo[i] == consulta) {
                        posicao = i;
                        break;
                    }
                }

                if (posicao == -1) {
                    printf("Cadastro inexistente. Nao foi possivel excluir.\n");
                    break;
                }

                for (int i = posicao; i < total - 1; i++) {
                    codigo[i] = codigo[i + 1];
                    strcpy(nome[i], nome[i + 1]);
                    preco[i] = preco[i + 1];
                    quantidade[i] = quantidade[i + 1];
                }

                total--;
                printf("Cadastro excluido.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}