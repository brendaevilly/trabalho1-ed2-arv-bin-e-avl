#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

#include "prototipos.h"

void menu(){
    printf("--- MENU ---\n");
    printf("1 - Cadastrar stream\n");
    printf("2 - Cadastrar categoria\n");
    printf("3 - Cadastrar programa\n");
    printf("4 - Cadastrar apresentador\n");

    printf("\n");

    printf("5 - Mostrar todas as streams cadastradas\n");
    printf("6 - Mostrar todas as streams que tem uma categoria\n");
    printf("7 - Mostrar todas as streams que tem um determinado tipo de categoria\n");
    printf("8 - Mostrar todas as categorias de uma stream\n");

    printf("\n");

    printf("9 - Mostrar todos os programas de uma categoria de uma stream\n");
    printf("10 - Mostrar programas de stream por dia e horário\n");
    printf("11 - Mostrar todos os programas de um determinado dia de uma categoria de uma stream\n");
    printf("12 - Mostrar dados de um programa de uma categoria de uma stream\n");

    printf("\n");

    printf("13 - Mostrar todos os apresentadores de uma stream\n");
    printf("14 - Mostrar apresentadores de uma categoria independente da stream que ele trabalha\n");

    printf("\n");

    printf("15 - Remover programa de uma categoria de uma stream\n");;
    printf("16 - Remover categoria de uma stream\n");
    printf("17 - Alterar stream que um apresentador\n");

    printf("0 - Sair\n");

    printf("\n");
}

void menuAltAP(){
    printf("-- MENU ALTERAR --");
    printf("1 - Remover programa\n");
    printf("2 - Alterar apresentador\n");
}

void menuTipoCatgoria(){
    printf("-- MENU TIPO CATEGORIA --");
    printf("0 - NOTICIA\n");
    printf("1 - ENTRETENIMENTO\n");
    printf("2 - ESPORTE\n");
}

TipoCategoria retornaTipo(int i){
    TipoCategoria tipo;
    if(i == 0) tipo = NOTICIA;
    else if(i == 1) tipo = ENTRETENIMENTO;
    else tipo = ESPORTE;
    return tipo;
}

void menuDiaSemana(){
    printf("-- MENU DIA DA SEMANA --");
    printf("0 - DOMINGO\n");
    printf("1 - SEGUNDA\n");
    printf("2 - TERÇA\n");
    printf("3 - QUARTA\n");
    printf("4 - QUINTA\n");
    printf("5 - SEXTA\n");
    printf("6 - SÁBADO\n");

}

DiaSemana retornaDia(int i){
    DiaSemana dia;
    if(i == 0) dia = DOMINGO;
    else if(i == 1) dia = SEGUNDA;
    else if(i == 2) dia = TERCA;
    else if(i == 3) dia = QUARTA;
    else if(i == 4) dia = QUINTA;
    else if(i == 5) dia = SEXTA;
    else dia = SABADO;

    return dia;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int parada = 1;

    Arvore *streams = inicializar();
    Apresentador *apresentadores = NULL;

    int op, opTipoCT, verifica;
    char nomeCat[50], nomeST[50], nomeAP[50], nomePG[50];

    while(parada = 1){
            menu();

        printf("\nOpção: "); scanf("%d", &op);
        switch (op){
            case 1:
                Arvore *nova;
                if(!(nova = alocar(nova, STREAM))) exit(1);
                preencherDado(STREAM, &nova);

                if((verifica = inserirArvBin(&streams, nova))) 
                    printf("Stream inserida na árvore com sucesso.\n");
                else printf("Essa stream já existe na árvore, logo não foi possível inserir.\n");
                
                break;
            case 2:
                menuTipoCatgoria();
                printf("\nOpção: "); scanf("%d", &opTipoCT);
                if(op > -1 && op < 3){

                    Categorias *nova;
                    if(!(nova = alocarCategoria(nova))) exit(1);
                    TipoCategoria tipo = retornaTipo(op);

                    printf("\nNome da categoria: "); scanf(" %[^\n]", nomeCat);
                    nova = criaCategoria(tipo, nomeCat);
                    printf("\nNome da stream: "); scanf(" %[^\n]", nomeST);
                    verifica = cadastrarCategoria(nova, nomeST, streams);

                    if(verifica) printf("\nCategoria cadastrada com sucesso!\n");
                    else rintf("\nNão foi possível cadastrar categoria, tente novamente e verifique suas informações.\n");

                }else printf("Opção de categoria inválida.\n");
                break;
            case 3:
                Arvore *novo;
                if(!(novo = alocar(novo, PROGRAMA))) exit(1);
                preencherDado(PROGRAMA, &novo);

                printf("\nStream do programa: "); scanf("^ [%\n]", nomeST);
                printf("\nNome da categoria: "); scanf("^ [%\n]", nomeCat);

                verifica = validarApresentador(apresentadores, novo->dado.PROGRAMA.nome, nomeST, nomeCat);

                Arvore *stream = buscarNaArvore(streams, nomeST);
                Arvore *res;
                existeApresentadorEmCategorias(stream->dado.STREAM.categorias, novo->dado.PROGRAMA.NomeApresentador, &res);

                if(verifica && !res){
                    int i = inserirArvBin(&(stream->dado.STREAM.categorias->programa), novo);
                    
                    if(!i) printf("Não foi possível inserir esse programa pois o mesmo já existe na stream!\n");
                    else printf("Programa inserido com sucesso!\n");
                }else printf("Apresentador inválido!\n");
                break;
            case 4:
                printf("\nNome do apresentador: "); scanf("^ [%\n]", nomeAP);
                printf("\nStream do apresentador: "); scanf("^ [%\n]", nomeST);
                printf("\nCategoria do apresentador: "); scanf("^ [%\n]", nomeCat);

                Apresentador *novo = criaApresentador(nomeAP, nomeCat, nomeST);
                if(novo){
                    verifica = inserirApresentadorOrdenado(&apresentadores, novo);
                    if(verifica) printf("Apresentador adicionado a lista com sucesso!\n");
                    else printf("Não foi possível adicionar esse apresentador a lista!\n");
                }else printf("Erro ao criar apresentador!\n");
                break;
            case 5:
                imprimirArvore(streams);
                break;
            case 6:
                printf("\nNome da categoria: "); scanf("^ [%\n]", nomeCat);
                mostrarStsQueTemCategoria(nomeCat, streams);
                break;
            case 7:
                menuTipoCatgoria();
                int opCat;
                printf("\nOpção: "); scanf("%d", &opCat);
                if(opCat > -1 && opCat < 3){
                    TipoCategoria tipo = retornaTipo(opCat);
                    imprimeStreamsPorCategoria(streams, tipo);
                }else printf("Opção de categoria inválida!\n");
                break;
            case 8:
                printf("\nNome da stream: "); scanf("^ [%\n]", nomeST);
                mostrarCategoriasDeST(nomeST, streams);
                break;
            case 9:
                printf("\nNome da stream: "); scanf("^ [%\n]", nomeST);
                printf("\nNome da categoria: "); scanf("^ [%\n]", nomeCat);
                mostrarProgsDeCategDeST(nomeST, streams, nomeCat);
                break;
            case 10:
                menuDiaSemana();
                int opDia;
                printf("\nOpção: "); scanf("%d", opDia);
                if(opDia > -1 && opDia < 7){
                    printf("\nNome da stream: "); scanf("^ [%\n]", nomeST);
                    DiaSemana dia = retornaDia(opDia);
                    char horario; 
                    printf("\nHorário: "); scanf("^ [%\n]", horario);

                    mostrarProgramasDeStreamPorDiaSemanaHorario(streams, nomeST, horario, dia);
                }else printf("Opção de dia inválida!\n");
                break;
            case 11:
                menuDiaSemana();
                int opDia;
                printf("\nOpção: "); scanf("%d", opDia);
                if(opDia > -1 && opDia < 7){
                    printf("\nNome da stream: "); scanf("^ [%\n]", nomeST);
                    printf("\nNome da categoria: "); scanf("^ [%\n]", nomeCat);
                    DiaSemana dia = retornaDia(opDia);
                    
                    mostrarProgramasDeCategoriaPorDiaSemana(streams, nomeST, nomeCat, dia);
                }else printf("Opção de dia inválida!\n");
                break;
            case 12:
                printf("\nNome da stream: "); scanf("^ [%\n]", nomeST);
                printf("\nNome da categoria: "); scanf("^ [%\n]", nomeCat);
                printf("\nNome do programa: "); scanf("^ [%\n]", nomePG);

                mostrarDadosdeumProgramadeumaCategoriadeumaStream(streams, nomeST, nomeCat, nomePG);
                break;
            case 13:
                printf("\nNome da stream: "); scanf("^ [%\n]", nomeST);
                mostrarApresentadoresDeStream(apresentadores, nomeST);
                break;
            case 14:
                break;
            case 15:
                printf("\nNome da stream: "); scanf("^ [%\n]", nomeST);
                printf("\nNome da categoria: "); scanf("^ [%\n]", nomeCat);
                printf("\nNome do programa: "); scanf("^ [%\n]", nomePG);

                verifica = removerProgramaDeCateDeST(streams, nomeST, nomeCat, nomePG);
                if(verifica) printf("\nRemovido com sucesso!\n");
                else printf("\nNão foi possível remover!\n");
                break;
            case 16:
                printf("\nNome da stream: "); scanf("^ [%\n]", nomeST);
                printf("\nNome da categoria: "); scanf("^ [%\n]", nomeCat);

                verifica = removerCategDeST(streams, nomeST, nomeCat);
                if(verifica) printf("\nRemovida com sucesso!\n");
                else printf("\nNão foi possível remover!\n");
                break;
            case 17:
                menuAltAP();
                int opAlt;
                printf("\nOpção: "); scanf("%d", &opAlt);

                printf("\nNome do apresentador: "); scanf("^ [%\n]", nomeAP);
                Apresentador *ap = buscaApresentador(apresentadores, nomeAP);

                if(ap){
                    printf("\nNome da nova stream: "); scanf("^ [%\n]", nomeST);
                    printf("\nNome da nova categoria: "); scanf("^ [%\n]", nomeCat);
                    Arvore *novoPG;
                    preencherDado(PROGRAMA, &novoPG);
                    if(opAlt == 1){
                        verifica = alterarStreamDeApresentador_removePrograma(streams, ap, nomeST, novoPG, nomeCat);
                    }else if(opAlt == 2){
                        char sub[50];
                        printf("\nNome do apresentador substituto: "); scanf("^ [%\n]", sub);
                        Apresentador *substituto = buscaApresentador(apresentadores, sub);
                        if(sub){
                            verifica = alterarStreamDeApresentador_substituiApresentadorPrograma(streams, apresentadores, ap, substituto, nomeST, novoPG, nomeCat);
                        }else printf("\nO apresentador substituto não existe!\n");
                    }else printf("\nOpção inválida!\n"); 
                }else printf("\nApresentador não existe!\n");
                break;
            case 0:
                parada = 0;
                break;

            default:
                printf("Escolha uma opção válida!\n");
                break;
        }
    }

 

    return 0;
}