#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdio.h>

#define INPUT 65535

typedef struct lista_nomes_carreiras{
    char *nome;
    struct lista_nomes_carreiras *prox_n;
}lista_nomes_carreiras;

typedef struct{
    char *origem;
    char *destino;
    double custo;
    double duracao;
}ligacao_struct;

typedef struct lista_ligacoes{
    ligacao_struct ligacao;
    struct lista_ligacoes *prox_l;
    struct lista_ligacoes *ant_l;
}lista_ligacoes;

typedef struct {
    double latitude;
    double longitude;
    char *nome;
    int num_carreiras;
    lista_nomes_carreiras *carreiras;
}paragem_struct;

typedef struct lista_paragens{
    paragem_struct paragem;
    struct lista_paragens *prox_p;
}lista_paragens;

typedef struct {
    char *origem;
    char *destino;
    lista_ligacoes *paragens;
    double custo_total;
    double duracao_total;
    int numero_paragens;
    char *nome;
}carreira_struct;

typedef struct lista_carreiras{
    carreira_struct carreira;
    struct lista_carreiras *prox_c;
}lista_carreiras;

#endif
