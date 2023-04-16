/* Funcoes utilizadas para verificar a alocao de memoria e liberta-la */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structs.h"
#include "memoria.h"

/*-----------------------------------------------------------------------------
| Nome da funcao: free_paragem_struct
| Tipo: void
| Argumentos: paragem_struct *p
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da
| estrutura paragem.
+----------------------------------------------------------------------------*/

void free_paragem_struct(paragem_struct *p){
    free(p->nome);
    free_lista_nomes(p->carreiras);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: free_carreira_struct
| Tipo: void
| Argumentos: carreira_struct *c
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da
| estrutura carreira.
+----------------------------------------------------------------------------*/

void free_carreira_struct(carreira_struct *c){
    free(c->nome);
    free_lista_ligacoes(c->paragens);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: free_ligacao_struct
| Tipo: void
| Argumentos: ligacao_struct *l
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da
| estrutura ligacao.
+----------------------------------------------------------------------------*/

void free_ligacao_struct(ligacao_struct *l){
    free(l->origem);
    free(l->destino);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: free_lista_nomes
| Tipo: void
| Argumentos: lista_nomes *topo_n
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da lista
| de nomes.
+----------------------------------------------------------------------------*/

void free_lista_nomes(lista_nomes_carreiras *topo_n){
    
    lista_nomes_carreiras *aux_n = topo_n->prox_n;
    lista_nomes_carreiras *prox_n = NULL;

    /* Percorre a lista de nomes e desaloca a memoria alocada para cada
    elemento */
    while (aux_n != NULL) {
        prox_n = aux_n->prox_n;
        free(aux_n->nome);
        free(aux_n);
        aux_n = prox_n;
    }

    /* Liberta o topo */
    free(topo_n);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: free_lista_ligacoes
| Tipo: void
| Argumentos: lista_ligacoes *topo_l
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da lista
| de ligacoes.
+----------------------------------------------------------------------------*/

void free_lista_ligacoes(lista_ligacoes *topo_l){

    lista_ligacoes *aux_l = topo_l->prox_l;
    lista_ligacoes *prox_l = NULL;

    /* Percorre a lista de ligacoes e desaloca a memoria alocada para cada
    elemento */
    while (aux_l != NULL) {
        prox_l = aux_l->prox_l;
        free_ligacao_struct(&aux_l->ligacao);
        free(aux_l);
        aux_l = prox_l;
    }

    /* Liberta o topo */
    free(topo_l);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: free_lista_paragens
| Tipo: void
| Argumentos: lista_paragens *topo_p
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da lista
| de paragens.
+----------------------------------------------------------------------------*/

void free_lista_paragens(lista_paragens *topo_p) {

    lista_paragens *aux_p = topo_p->prox_p;
    lista_paragens *prox_p = NULL;

    /* Percorre a lista de paragens e desaloca a memoria alocada para cada
    elemento */
    while (aux_p != NULL) {
        prox_p = aux_p->prox_p;
        free_paragem_struct(&aux_p->paragem);
        free(aux_p);
        aux_p = prox_p;
    }
    /* Liberta o topo */
    free(topo_p);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: free_lista_carreiras
| Tipo: void
| Argumentos: lista_carreiras *topo_c
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da lista
| de paragens.
+----------------------------------------------------------------------------*/

void free_lista_carreiras(lista_carreiras *topo_c){

    lista_carreiras *aux_c = topo_c->prox_c;
    lista_carreiras *prox_c = aux_c->prox_c;
    
    /* Percorre a lista de carreiras e desaloca a memoria alocada para cada
    elemento */
    while (aux_c != NULL) {
        prox_c = aux_c->prox_c;
        free_carreira_struct(&aux_c->carreira);
        free(aux_c);
        aux_c = prox_c;
    }
    /* Liberta o topo */
    free(topo_c);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: free_memoria
| Tipo: void
| Argumentos: lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da lista
| de paragens.
+----------------------------------------------------------------------------*/

void free_memoria(lista_carreiras *topo_c, lista_paragens *topo_p){

    /* Liberta a memoria alocada para a lista de carreiras */
    free_lista_carreiras(topo_c);
    /* Liberta a memoria alocada para a lista de carreiras */
    free_lista_paragens(topo_p);

}

/*-----------------------------------------------------------------------------
| Nome da funcao: erro_alocacao_c
| Tipo: void
| Argumentos: lista_carreiras *lista, lista_carreiras *topo_c, 
|    lista_paragens *topo_p
| Funcao: Funcao responsavel por testar a alocacao de memoria.
+----------------------------------------------------------------------------*/

void erro_alocacao_c(lista_carreiras *lista, lista_carreiras *topo_c, 
    lista_paragens *topo_p){
    
    if(lista == NULL){
        printf("No memory.\n");
        free_memoria(topo_c, topo_p);
        exit(0);
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: erro_alocacao_p
| Tipo: void
| Argumentos: lista_paragens *lista, lista_carreiras *topo_c, 
|    lista_paragens *topo_p
| Funcao: Funcao responsavel por testar a alocacao de memoria.
+----------------------------------------------------------------------------*/

void erro_alocacao_p(lista_paragens *lista, lista_carreiras *topo_c, 
    lista_paragens *topo_p){

    if(lista == NULL){
        printf("No memory.\n");
        free_memoria(topo_c, topo_p);
        exit(0);
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: erro_alocacao_s
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por testar a alocacao de memoria.
+----------------------------------------------------------------------------*/

void erro_alocacao_s(char *nome, lista_carreiras *topo_c, 
    lista_paragens *topo_p){

    if(nome == NULL){
        printf("No memory.\n");
        free_memoria(topo_c, topo_p);
        exit(0);
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: erro_alocacao_n
| Tipo: void
| Argumentos: lista_nomes_carreiras *lista, lista_carreiras *topo_c, 
|    lista_paragens *topo_p
| Funcao: Funcao responsavel por testar a alocacao de memoria.
+----------------------------------------------------------------------------*/

void erro_alocacao_n(lista_nomes_carreiras *lista, lista_carreiras *topo_c, 
    lista_paragens *topo_p){

    if(lista == NULL){
        printf("No memory.\n");
        free_memoria(topo_c, topo_p);
        exit(0);
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: erro_alocacao_l
| Tipo: void
| Argumentos: lista_ligacoes *lista, lista_carreiras *topo_c, 
    lista_paragens *topo_p
| Funcao: Funcao responsavel por testar a alocacao de memoria.
+----------------------------------------------------------------------------*/

void erro_alocacao_l(lista_ligacoes *lista, lista_carreiras *topo_c, 
    lista_paragens *topo_p){

    if(lista == NULL){
        printf("No memory.\n");
        free_memoria(topo_c, topo_p);
        exit(0);
    }
}
