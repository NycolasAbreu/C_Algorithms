#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 64

void menu();
void sozinho();
void le_arquivo(char *arquivo, char *palavra_aleatoria);

int main()
{
    srand((unsigned)time(NULL));
    menu();

    return 0;
}

void sozinho()
{
    char repete = 's';

    while (repete == 's' || repete == 'S')
    {

        char palavra[TAM];
        int tamanho, tentativas = 0, maxtentativas = 10;
        char mascara[TAM], letra;
        int i, j, x;

        le_arquivo("Palavras.txt", palavra);
        tamanho = strlen(palavra);

        for (i = 0; i < tamanho; i++)
            mascara[i] = '_';

        mascara[i] = '\0'; //  Ecerra a mascara antes do máximo

        while ((maxtentativas - tentativas > 0) && (strcmp(mascara, palavra)))
        {
            system("cls");
            printf("\nA palavra eh : %s com %d letras", mascara, tamanho);
            printf("\n%d Tentativas", maxtentativas - tentativas);
            printf("\nDigite uma Letra:");
            scanf(" %c", &letra);

            for (j = 0; j < (tamanho); j++)
            {
                if (palavra[j] == letra)
                {
                    mascara[j] = palavra[j];
                    x = j;
                }
            }
            if (palavra[x] != letra)
            {
                tentativas++;
            }
        }

        if (strcmp(mascara, palavra))
        {
            system("cls");
            printf("\nErrou");
            printf("\nA palavra era %s\n", palavra);
            printf("\nDeseja jogar novamente? S/N\n");
            scanf(" %c", &repete);
        }
        else
        {
            system("cls");
            printf("\nParabens");
            printf("\nA palavra era %s\n", palavra);
            printf("\nDeseja jogar novamente? S/N\n");
            scanf(" %c", &repete);
        }
    }
}

void menu()
{
    int op = 0;

    while (op < 1 || op > 3)
    {
        system("cls");
        printf("Jogo da forca");
        printf("\n1 - Jogar");
        printf("\n2 - Sobre");
        printf("\n3 - Sair");
        printf("\nDigite qual opcao deseja:");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("\nIniciando o jogo");
            sozinho();
            break;
        case 2:
            printf("\nEste jogo foi desenvolvido por Nycolas Abreu, seguindo o curso C e C++ - Iniciante Ao Avancado\n");
            system("pause");
            menu();
        case 3:
            printf("\nSaindo");
            break;

        default:
            break;
        }
    }
}

void le_arquivo(char *arquivo, char *palavra_aleatoria)
{
    char palavra[TAM];
    int n_linhas = 0, aleatorio, i, tamanho;

    FILE *fp = fopen(arquivo, "r");

    if (!fp)
    {
        perror("Funcao: le_arquivo");
        exit(EXIT_FAILURE);
    }

    while (fgets(palavra, sizeof(palavra), fp) != NULL) // Le todas as linhas até achar o final
    {
        n_linhas++;
    }

    rewind(fp);

    aleatorio = (rand() % n_linhas);

    for (i = 0; i < aleatorio; i++)
    {
        fgets(palavra_aleatoria, TAM, fp);
    }

    palavra_aleatoria = strtok(palavra_aleatoria, "\n");

    fclose(fp);
}