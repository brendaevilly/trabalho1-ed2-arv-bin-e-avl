#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "prototipos.h"

int main(){
    Arvore *streams = inicializar();
    char buffer[16];
    clock_t inicio, fim;
    double tempo, tempoMicro;

    char nomeST[50] = "445778484", nomeCT[50] = "272054180";

    for(int i=0; i<30; i++){
        FILE *baseDeDados;
        baseDeDados = fopen("DbsParaTestes/dbAleatoria.txt", "r");
        if(baseDeDados == NULL){
            printf("Erro ao abrir o arquivo!\n");
            exit(1);
        }

        // STs
        while (fgets(buffer, sizeof(buffer), baseDeDados) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';

            Arvore *nova = alocar(STREAM);
            strcpy(nova->dado.STREAM.nome, buffer);
            nova->dado.STREAM.categorias = NULL;

            inserirArvBin(&streams, nova);
        }

        // CTs
        rewind(baseDeDados);

        while (fgets(buffer, sizeof(buffer), baseDeDados) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';

            Categorias *cat = alocarCategoria();
            strcpy(cat->nome, buffer);
            cadastrarCategoria(cat, nomeST, streams);
        }

        //PGs
        rewind(baseDeDados);

        Arvore *arv = buscarNaArvore(streams, nomeST);

        while (fgets(buffer, sizeof(buffer), baseDeDados) != NULL) {
            buffer[strcspn(buffer, "\n")] = '\0';

            Arvore *novo = alocar(PROGRAMA);
            strcpy(novo->dado.PROGRAMA.nome, buffer);

            inserirArvBin(&(arv->dado.STREAM.categorias->programa), novo);
        }

        inicio = clock();
        mostrarProgsDeCategDeST(nomeST, streams, nomeCT);
        fim = clock();

        tempo = ((double)(fim - inicio))/CLOCKS_PER_SEC;
        tempoMicro = tempo * 1000000.0;

        printf("| %.10f |", tempo);
        printf(" %.2f |\n", tempoMicro);

        
        fclose(baseDeDados);
    }
    
    

    return 0;
}