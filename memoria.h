/* Funcoes utilizadas para verificar a alocao de memoria e liberta-la */

#ifndef MEMORIA_H_INCLUDED
#define MEMORIA_H_INCLUDED

#include <stdio.h>
#include "structs.h"

/*-----------------------------------------------------------------------------
| Nome da funcao: free_paragem_struct
| Tipo: void
| Argumentos: paragem_struct *p
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da
| estrutura paragem.
+----------------------------------------------------------------------------*/

void free_paragem_struct(paragem_struct *p);

/*-----------------------------------------------------------------------------
| Nome da funcao: free_carreira_struct
| Tipo: void
| Argumentos: carreira_struct *c
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da
| estrutura carreira.
+----------------------------------------------------------------------------*/

void free_carreira_struct(carreira_struct *c);

/*-----------------------------------------------------------------------------
| Nome da funcao: free_ligacao_struct
| Tipo: void
| Argumentos: ligacao_struct *l
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da
| estrutura ligacao.
+----------------------------------------------------------------------------*/

void free_ligacao_struct(ligacao_struct *l);

/*-----------------------------------------------------------------------------
| Nome da funcao: free_lista_nomes
| Tipo: void
| Argumentos: lista_nomes *topo_n
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da lista
| de nomes.
+----------------------------------------------------------------------------*/

void free_lista_nomes(lista_nomes_carreiras *topo_n);

/*-----------------------------------------------------------------------------
| Nome da funcao: free_lista_ligacoes
| Tipo: void
| Argumentos: lista_ligacoes *topo_l
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da lista
| de ligacoes.
+----------------------------------------------------------------------------*/

void free_lista_ligacoes(lista_ligacoes *topo_l);

/*-----------------------------------------------------------------------------
| Nome da funcao: free_lista_paragens
| Tipo: void
| Argumentos: lista_paragens *topo_p
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da lista
| de paragens.
+----------------------------------------------------------------------------*/

void free_lista_paragens(lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: free_lista_carreiras
| Tipo: void
| Argumentos: lista_carreiras *topo_c
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da lista
| de paragens.
+----------------------------------------------------------------------------*/

void free_lista_carreiras(lista_carreiras *topo_c);

/*-----------------------------------------------------------------------------
| Nome da funcao: free_memoria
| Tipo: void
| Argumentos: lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por desalocar a memoria de cada elemento da lista
| de paragens.
+----------------------------------------------------------------------------*/

void free_memoria(lista_carreiras *topo_c, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: erro_alocacao_c
| Tipo: void
| Argumentos: lista_carreiras *lista, lista_carreiras *topo_c, 
|    lista_paragens *topo_p
| Funcao: Funcao responsavel por testar a alocacao de memoria.
+----------------------------------------------------------------------------*/

void erro_alocacao_c(lista_carreiras *lista, lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: erro_alocacao_p
| Tipo: void
| Argumentos: lista_paragens *lista, lista_carreiras *topo_c, 
|    lista_paragens *topo_p
| Funcao: Funcao responsavel por testar a alocacao de memoria.
+----------------------------------------------------------------------------*/

void erro_alocacao_p(lista_paragens *lista, lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: erro_alocacao_s
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por testar a alocacao de memoria.
+----------------------------------------------------------------------------*/

void erro_alocacao_s(char *nome, lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: erro_alocacao_n
| Tipo: void
| Argumentos: lista_nomes_carreiras *lista, lista_carreiras *topo_c, 
|    lista_paragens *topo_p
| Funcao: Funcao responsavel por testar a alocacao de memoria.
+----------------------------------------------------------------------------*/

void erro_alocacao_n(lista_nomes_carreiras *lista, lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: erro_alocacao_l
| Tipo: void
| Argumentos: lista_ligacoes *lista, lista_carreiras *topo_c, 
    lista_paragens *topo_p
| Funcao: Funcao responsavel por testar a alocacao de memoria.
+----------------------------------------------------------------------------*/

void erro_alocacao_l(lista_ligacoes *lista, lista_carreiras *topo_c, 
    lista_paragens *topo_p);

#endif
