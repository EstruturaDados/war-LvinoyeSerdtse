#include <stdio.h>
#include <string.h>
#define STRING_LENGTH 50 // definindo de maneira fixa o numero total de caracteres para ser referenciado 
// criando a struct 'Territorio'
typedef struct {
char nome[STRING_LENGTH];
int tropas;
char cor[STRING_LENGTH];
}Territorio;
// Criando um array de 5 slots para cada gravação usando a struct 'Territorio' nele
Territorio beligerantes[5];
int i = 0;
int main()
{
    printf("CADASTRE OS TERRITORIOS\n");
    printf("=======================");
    while (i<5) // esse contador garante que, assim que 5 cadastros sejam feitos, o loop se feche.
     {
        printf("\n%d - ", i+1);
        printf("NOME DO TERRITORIO:");
        fgets(beligerantes[i].nome, STRING_LENGTH, stdin);
        beligerantes[i].nome[strcspn(beligerantes[i].nome, "\n")] = 0; // com isso eu garanto que a leitura da entrada seja feita corretamente apos dar o enter.

        printf("\nNUMERO DE TROPAS:");
        scanf("%d", &beligerantes[i].tropas);
        while(getchar()!= '\n'); // motivo identico ao qual esta na linha 22, porem, se tratando de um inteiro (int) e nao string (cadeia de caracteres), assim fica mais facil.

        printf("\nCOR DO TERRITORIO:");
        fgets(beligerantes[i].cor, STRING_LENGTH, stdin);
        beligerantes[i].cor[strcspn(beligerantes[i].cor, "\n")] = 0;
        
        i++; // incremento. i começa como 0, realiza operações enquanto é lido como 4, e na sexta vez, em que ele vira 5, o codigo pula, assim realizando as 5 vezes que mirei.
    }
    printf("=======================\n");
    printf("TERRITORIOS BELIGERANTES:\n");
// imprimindo os territorios cadastrados.
    for (i = 0; i<5; i++) 
    {
        printf("=======================\n");
        printf("%d - ", i+1); // fiz isso so para aparecer um "contador" antes do nome do territorio.
        printf("NOME DO TERRITORIO: %s\n", beligerantes[i].nome);
        printf("NUMERO DE TROPAS: %d\n", beligerantes[i].tropas);
        printf("COR DO TERRITORIO: %s\n", beligerantes[i].cor);
    }
return 0;
}