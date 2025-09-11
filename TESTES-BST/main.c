#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "prototipos.h"

int main(){
    Arvore *streams = inicializar();

    FILE *baseDeDados;
    baseDeDados = fopen("baseDeDados.txt", "r");
    if(baseDeDados == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    char buffer[16];
    clock_t inicio, fim;
    double tempo, tempoTotal = 0.0;

    while (fgets(buffer, sizeof(buffer), baseDeDados) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        Arvore *nova = alocar(STREAM);
        strcpy(nova->dado.STREAM.nome, buffer);

        inicio = clock();
        inserirArvBin(&streams, nova);
        fim = clock();

        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        tempoTotal += tempo;
    }

    tempoTotal = tempoTotal/10000000.0;
    printf("%f\n", tempoTotal);

    fclose(baseDeDados);

    return 0;
}