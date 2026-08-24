#include<stdio.h>
#include<stdbool.h>

typedef struct {
    int peca;
    int lado;
    int direcaoVertical;
    int direcaoHorizontal;
    int casas;
    const char* direcaoVerticalChar;
    const char* direcaoHorizontalChar;
} EstadoJogo;

EstadoJogo estado;
int indexDirecao = 1, maxCasas = 7;

bool EscolhaErrada(int escolha, int escolhaMax)
{
    return escolha <= 0 || escolha > escolhaMax;
}
void EscolhaDePeca()
{
    do
    {
        printf("Escolha a peça!\n");
        printf("1. Torre\n");
        printf("2. Bispo\n");
        printf("3. Rainha\n");
        printf("4. Cavalo\n");
        scanf("%d", &estado.peca);
    }
    while (EscolhaErrada(estado.peca, 4));

    switch (estado.peca)
    {
        case 1:
        printf("Você escolheu a Torre\n");
        break;
        case 2:
        printf("Você escolheu o Bispo\n");
        break;

        case 3:
        printf("Você escolheu a Rainha\n");
        break;
        case 4:
        printf("Você escolheu o Cavalo\n");
        break;
    }
}
void EscolhaDoLado()
{
    if(estado.peca == 1)
    {
        do
        {
            printf("Para qual lado irá mover\n");
            printf("1. Cima ou Baixo\n");
            printf("2. Direita ou Esquerda\n");
            scanf("%d", &estado.lado);
        } while (EscolhaErrada(estado.lado, 2));
    }
}
void EscolhaVertical()
{
    if(estado.peca != 1 || estado.lado == 1)
    {
        do
        {
            printf("Para onde irá mover verticalmente\n");
            printf("1. Cima\n");
            printf("2. Baixo\n");
            scanf("%d", &estado.direcaoVertical);
        } while (EscolhaErrada(estado.direcaoVertical, 2));

        if(estado.direcaoVertical == 1)
            estado.direcaoVerticalChar = "Cima\n";
        else if(estado.direcaoVertical == 2)
            estado.direcaoVerticalChar = "Baixo\n";
        printf("Escolheu %s\n", estado.direcaoVerticalChar);
    }
}
void EscolhaHorizontal()
{
    if(estado.peca != 1 || estado.lado == 2)
    {
        do
        {
            printf("Para onde irá mover horizontalmente\n");
            printf("1. Direita\n");
            printf("2. Esquerda\n");
            scanf("%d", &estado.direcaoHorizontal);
        } while (EscolhaErrada(estado.direcaoHorizontal, 2));

        if(estado.direcaoHorizontal == 1)
            estado.direcaoHorizontalChar = "Direita\n";
        else if(estado.direcaoHorizontal == 2)
            estado.direcaoHorizontalChar = "Esquerda\n";
    }
}
void AndarNumeroDeCasas()
{
    switch (estado.peca)
    {
        //Cavalo
        case 4:
        for(int i = 0; i < 2; i++)
        {
            printf("%s", estado.direcaoVerticalChar);
        }
        printf("%s", estado.direcaoHorizontalChar);

        break;

        //Peças normais
        default:
        do
        {
            printf("Mova o número de casas que deseja de 1 até 7!\n");
            scanf("%d", &estado.casas);
        } while (EscolhaErrada(estado.casas, maxCasas));
        for(int i = 0; i < estado.casas; i++)
        {
            if(estado.direcaoHorizontal != 0) printf("%s", estado.direcaoHorizontalChar);
            if(estado.direcaoVertical != 0) printf("%s", estado.direcaoVerticalChar);
            printf("\n");
        }
        break;
    }
}
int main()
{
    EscolhaDePeca();
    EscolhaDoLado();
    EscolhaVertical();
    EscolhaHorizontal();
    AndarNumeroDeCasas();
    return 0;
}
