#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define STRING_LENGTH 50

typedef struct {
    char nome[STRING_LENGTH];
    int tropas;
    char cor[STRING_LENGTH];
} Territorio;

void atacar(Territorio* atacante, Territorio* defensor) {
    if (strcmp(atacante->cor, defensor->cor) == 0) 
    {
        printf("Não podes atacar o proprio territorio!");
    return;
    }
    int dadoAtaque = (rand() % 6) + 1; 
    int dadoDefesa = (rand() % 6) + 1;
    
    
    printf("\nDADOS JOGADOS!\n");


    if (dadoAtaque > dadoDefesa) {   
        int tropasTransferidas = atacante->tropas / 2; // se o ataque foi certeiro, o pais atacante conquista tal territorio e move suas tropas para la.
        printf("\nAtaque certeiro = territorio conquistado! %d tropas movidas para %s.\n", tropasTransferidas, defensor->nome);
        printf("%s (ATAQUE) obteve %d pontos.\n%s (DEFESA) obteve %d pontos.\n", atacante->nome, dadoAtaque, defensor->nome, dadoDefesa);
        snprintf(defensor->nome, STRING_LENGTH, "[ANEXADO] %s", atacante->nome);
        strcpy(defensor->cor, atacante->cor);
        
        defensor->tropas = tropasTransferidas; 
        atacante->tropas -= tropasTransferidas;
    } else {
        if (dadoAtaque < dadoDefesa) 
        {
        printf("%s (ATAQUE) obteve %d pontos.\n%s (DEFESA) obteve %d pontos.\n", atacante->nome, dadoAtaque, defensor->nome, dadoDefesa);
        printf("Aqui nao tem bobo nao! Com isso, %s perdeu uma de suas tropas.\n", atacante->nome);
        atacante->tropas--;
        }
    }
}

void liberarMemoria(Territorio* beligerantes) {
    if (beligerantes != NULL) {
        free(beligerantes);
    }
}

int main() {
    srand(time(NULL)); // Inicializa a semente para os dados serem aleatórios
    int TotalTerritorios;
    int i = 0;

    printf("CADASTRE OS TERRITORIOS\n");
    printf("=======================\n");
    printf("Quantos territorios deseja cadastrar? ");
    scanf("%d", &TotalTerritorios);
    while(getchar() != '\n'); 

    Territorio* beligerantes = (Territorio*) calloc(TotalTerritorios, sizeof(Territorio));

    if (beligerantes == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    while (i < TotalTerritorios) {
        printf("\nTerritorio %d - \n", i + 1);
        printf("NOME: ");
        fgets(beligerantes[i].nome, STRING_LENGTH, stdin);
        beligerantes[i].nome[strcspn(beligerantes[i].nome, "\n")] = 0;

        printf("NUMERO DE TROPAS: ");
        scanf("%d", &beligerantes[i].tropas);
        while(getchar() != '\n');

        printf("COR: ");
        fgets(beligerantes[i].cor, STRING_LENGTH, stdin);
        beligerantes[i].cor[strcspn(beligerantes[i].cor, "\n")] = 0;
        
        i++;
    }

    int op = 1;
    while (op != 0) {
        printf("\n=== MAPA ATUAL ===\n");
        for (int j = 0; j < TotalTerritorios; j++) {
            printf("[%d] %s (%s) - Tropas: %d\n", j + 1, beligerantes[j].nome, beligerantes[j].cor, beligerantes[j].tropas);
        }

        int atk, def;
        printf("\nID Atacante (1-%d) ou 0 para sair: ", TotalTerritorios);
        scanf("%d", &atk);
        if (atk == 0) break;

        printf("ID Defensor (1-%d): ", TotalTerritorios);
        scanf("%d", &def);

        if (atk > 0 && atk <= TotalTerritorios && def > 0 && def <= TotalTerritorios && atk != def) {
            atacar(&beligerantes[atk - 1], &beligerantes[def - 1]);
        } else {
            printf("\nEscolha de IDs invalida!\n");
        }
    }

    liberarMemoria(beligerantes);
    printf("\nJogo finalizado.\n");
    return 0;
}