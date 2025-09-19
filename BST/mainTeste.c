#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "prototipos.h"

int main(){
    //Arvore *streams = inicializar();

    FILE *baseDeDados;
    baseDeDados = fopen("DbsParaTestes/dbAleatoria.txt", "w");
    if(baseDeDados == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    /*
    char buffer[16];
    clock_t inicio, fim;
    double tempo, tempoMicro, somaTempo = 0.0, somaTempoMicro = 0.0;

    while (fgets(buffer, sizeof(buffer), baseDeDados) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        Arvore *nova = alocar(STREAM);
        strcpy(nova->dado.STREAM.nome, buffer);

        inicio = clock();
        inserirArvBin(&streams, nova);
        fim = clock();

        tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        tempoMicro = tempo * 1000000.0;

        somaTempo += tempo;
        somaTempoMicro += tempoMicro;
    }

    fclose(baseDeDados);

    printf("| %.10f |", somaTempo / 50000.0);
    printf(" %.2f |\n", somaTempoMicro / 50000.0);
    */
    
    for(int i=0; i<50000; i++){
        fprintf(baseDeDados, "%d\n", rand() % 500000000);
    }
        
    fclose(baseDeDados);
   

    return 0;
}