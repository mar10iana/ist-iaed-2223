/* Funcoes utilizadas para realizar cada pedido */

#ifndef FUNCAO_H_INCLUDED
#define FUNCAO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structs.h"

/*-----------------------------------------------------------------------------
| Nome da funcao: adiciona_carreira
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo_c, 
|    lista_paragens *topo_p
| Funcao: Funcao responsavel por adicionar uma nova carreira a lista.
+----------------------------------------------------------------------------*/

void adiciona_carreira(char *nome, lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_carreira
| Tipo: lista_carreiras *
| Argumentos: char *nome, lista_carreiras *topo_c, 
|    lista_paragens *topo_p
| Funcao: Funcao responsavel por criar um novo elemento da lista de carreiras
+----------------------------------------------------------------------------*/

lista_carreiras* cria_carreira(char *nome, lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_lista_carreiras
| Tipo: lista_carreiras *
| Argumentos: carreira_struct carreira, 
|    lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por associar a estrutura carreira a uma estrutura 
| lista de carreiras.
+----------------------------------------------------------------------------*/

lista_carreiras* cria_lista_carreiras(carreira_struct carreira, 
    lista_carreiras *topo_c, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_carreiras
| Tipo: void
| Argumentos: lista_carreiras *topo
| Funcao: Funcao responsavel por imprimir as informaçoes de todas as carreiras 
| existentes na lista.
+----------------------------------------------------------------------------*/

void imprime_carreiras(lista_carreiras *topo);

/*-----------------------------------------------------------------------------
| Nome da funcao: procura_carreira
| Tipo: int
| Argumentos: char *nome, lista_carreiras *topo
| Funcao: Funcao responsavel por verificar se uma carreira com o nome fornecido 
| existe na lista de carreiras. Retorna 1 caso exista e 0 caso contrario.
+----------------------------------------------------------------------------*/

int procura_carreira(char *nome, lista_carreiras *topo);

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_paragens_da_carreira
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo
| Funcao: Funcao responsavel por imprimir as paragens de uma carreira
+----------------------------------------------------------------------------*/

void imprime_paragens_da_carreira(char *nome,  lista_carreiras *topo);

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_inverso
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo
| Funcao: Funcao responsavel por imprimir as paragens de uma carreira pela
| ordem inversa.
+----------------------------------------------------------------------------*/

void imprime_inverso(char *nome, lista_carreiras * topo);

/*-----------------------------------------------------------------------------
| Nome da funcao: procura_paragem
| Tipo: int
| Argumentos: char *nome, lista_paragens *topo
| Funcao: Funcao responsavel por verificar se uma paragem com o nome fornecido 
| existe na lista de paragens. Retorna 1 caso exista e 0 caso contrario.
+----------------------------------------------------------------------------*/

int procura_paragem(char *nome, lista_paragens *topo);

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_coord
| Tipo: void
| Argumentos: char nome, lista_paragens *topo
| Funcao: Funcao responsavel por imprimir as coordenadas da paragem com o nome 
| fornecido.
+----------------------------------------------------------------------------*/

void imprime_coord(char *nome, lista_paragens *topo);

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_paragens
| Tipo: void
| Argumentos: lista_paragens *topo
| Funcao: Funcao responsavel por imprimir as informacoes de todas as paragens
| da lista.
+----------------------------------------------------------------------------*/

void imprime_paragens(lista_paragens *topo);

/*-----------------------------------------------------------------------------
| Nome da funcao: adiciona_paragem
| Tipo: lista_paragens *
| Argumentos: char *nome, double latitude, 
|    double longitude, lista_paragens *topo_p, lista_carreiras *topo_c
| Funcao: Funcao responsavel por adicionar uma nova paragem a lista.
+----------------------------------------------------------------------------*/

void adiciona_paragem(char *nome, double latitude, 
    double longitude, lista_paragens *topo_p, lista_carreiras *topo_c);

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_paragem
| Tipo: lista_paragens *
| Argumentos: char *nome, double latitude,
|    double longitude, lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por criar um novo elemento da lista de paragens.
+----------------------------------------------------------------------------*/

lista_paragens* cria_paragem(char *nome, double latitude,
    double longitude, lista_carreiras *topo_c, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_lista_paragens
| Tipo: lista_paragens*
| Argumentos: paragem_struct paragem
| Funcao: Funcao responsavel por associar a estrutura paragem a uma estrutura 
| lista de paragens.
+----------------------------------------------------------------------------*/

lista_paragens* cria_lista_paragens(paragem_struct paragem,
    lista_carreiras *topo_c, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: adicionar_ligacao
| Tipo: void
| Argumentos: char *carreira, char *origem, char *destino, 
|    double custo, double duracao, lista_carreiras *topo_c, 
|    lista_paragens *topo_p
| Funcao: Funcao responsavel por atualizar as carreiras e paragens tendo em 
| conta a informacao da ligacao.
+----------------------------------------------------------------------------*/

void adicionar_ligacao(char *carreira, char *origem, char *destino, 
    double custo, double duracao, lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: verifica_ligacao
| Tipo: int
| Argumentos: char *nome, lista_carreiras *topo_c, char *origem, 
|    char *destino 
| Funcao: Funcao responsavel por verificar se a ligacao nova pode ser associada
| a carreira. Retorna 1 se sim e 0 caso contrario.
+----------------------------------------------------------------------------*/

int verifica_ligacao(char *nome, lista_carreiras *topo_c, char *origem, 
    char *destino);

/*-----------------------------------------------------------------------------
| Nome da funcao: verfica_carreira_nova
| Tipo: int
| Argumentos: char *carreira, char *paragem, 
|    lista_carreiras* topo
| Funcao: Funcao responsavel por verificar se uma paragem ja esta associada a 
| uma determinada carreira.
| Retorna 1 caso a paragem ja esteja associada a carreira e 0 caso
| contrario.
+----------------------------------------------------------------------------*/

int verifica_carreira_nova(char *carreira, char *paragem, 
    lista_carreiras* topo);

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_lista_nomes_carreiras
| Tipo: lista_nomes_carreiras *
| Argumentos: char *nome, 
|    lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por criar uma estrutura lista de nomes.
+----------------------------------------------------------------------------*/

lista_nomes_carreiras* cria_lista_nomes_carreiras(char *nome, 
    lista_carreiras *topo_c, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: strcasecmp
| Tipo: int
| Argumentos: const char *s1, const char *s2
| Funcao: Funcao responsavel por comparar duas strings sem diferenciacao entre 
| letras maiusculas e minusculas.
| Retorna a diferenca entre os caracteres ou 0 se as strings forem iguais.
+----------------------------------------------------------------------------*/

int strcasecmp(const char *s1, const char *s2);

/*-----------------------------------------------------------------------------
| Nome da funcao: adiciona_por_ordem
| Tipo: lista_nomes_carreiras *
| Argumentos: lista_nomes_carreiras *topo, 
|    lista_nomes_carreiras *novo
| Funcao: Funcao responsavel por adicionar, por ordem alfabetica, um novo 
| elemento a lista dos nomes das carreiras de uma paragem.
+----------------------------------------------------------------------------*/

void adiciona_por_ordem(lista_nomes_carreiras *topo, 
    lista_nomes_carreiras *novo);

/*-----------------------------------------------------------------------------
| Nome da funcao: update_paragem
| Tipo: void
| Argumentos: char *nome, lista_paragens *topo
| Funcao: Funcao responsavel por incrementar o numero de carreiras de uma 
| paragem.
+----------------------------------------------------------------------------*/

void update_paragem(char *carreira, char *nome, lista_paragens *topo_p, 
    lista_carreiras *topo_c);

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_ligacao
| Tipo: lista_ligacoes *
| Argumentos: char *nome
| Funcao: Funcao responsavel por criar um novo elemento da lista de ligacoes.
+----------------------------------------------------------------------------*/

lista_ligacoes* cria_ligacao(char *origem, char *destino, double custo, 
    double duracao, lista_carreiras *topo_c, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_lista_ligacoes
| Tipo: lista_ligacoes *
| Argumentos: char *nome
| Funcao: Funcao responsavel por associar a estrutura ligacao a uma estrutura 
| lista de ligacoes.
+----------------------------------------------------------------------------*/

lista_ligacoes* cria_lista_ligacoes(ligacao_struct ligacao,
    lista_carreiras *topo_c, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: update_carreira
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo_c, 
|    lista_paragens* topo_p,  double custo, double duracao, 
|    char *origem, char *destino
| Funcao: Funcao responsavel por atualizar as informacoes da carreira em funcao
| da nova ligacao.
+----------------------------------------------------------------------------*/

void update_carreira(char *nome, lista_carreiras *topo_c, 
    lista_paragens* topo_p,  double custo, double duracao, 
    char *origem, char *destino);

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_carreiras_intersecao
| Tipo: void
| Argumentos: paragem_struct paragem
| Funcao: Funcao responsavel por imprimir o nome das carreiras que contem a 
| paragem.
+----------------------------------------------------------------------------*/

void imprime_carreiras_intersecao(paragem_struct paragem);

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_carreira
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo_c
| Funcao: Funcao responsavel por remover uma carreira da lista de carreiras.
+----------------------------------------------------------------------------*/

void apaga_carreira(char *nome, lista_carreiras *topo_c);

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_carreira_das_paragens
| Tipo: void
| Argumentos: char *nome, lista_paragens *topo_p
| Funcao: Funcao responsavel por remover a carreira de todas as paragens.
+----------------------------------------------------------------------------*/

void apaga_carreira_das_paragens(char *nome, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_paragem
| Tipo: void
| Argumentos: char *nome, lista_paragens *topo_p
| Funcao: Funcao responsavel por remover uma paragem da lista de paragens.
+----------------------------------------------------------------------------*/

void apaga_paragem(char *nome, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_ligacao
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por remover a carreira removida de todas as
| carreiras.
+----------------------------------------------------------------------------*/

void apaga_ligacao(char *nome, lista_carreiras *topo_c, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_ligacao_origem
| Tipo: void
| Argumentos: lista_carreiras *aux_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por atualizar a carreira caso a paragem removida 
| seja a sua origem.
+----------------------------------------------------------------------------*/

void apaga_ligacao_origem(lista_carreiras *aux_c, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_ligacao_destino
| Tipo: void
| Argumentos: lista_carreiras *aux_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por atualizar a carreira caso a paragem removida 
| seja o seu destino.
+----------------------------------------------------------------------------*/

void apaga_ligacao_destino(lista_carreiras *aux_c, lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_ultima_ligacao
| Tipo: void
| Argumentos: lista_carreiras *aux_c, lista_paragens *topo_p, 
|    char *outra_paragem
| Funcao: Funcao responsavel por apagar a ultima ligacao da carreira
+----------------------------------------------------------------------------*/

void apaga_ultima_ligacao(lista_carreiras *aux_c, lista_paragens *topo_p, 
    char *outra_paragem);

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_carreira_de_uma_paragem
| Tipo: void
| Argumentos: char *paragem, char *carreira, 
|    lista_paragens* topo_p
| Funcao: Funcao responsavel por apagar um carreira de apenas uma paragem.
+----------------------------------------------------------------------------*/

void apaga_carreira_de_uma_paragem(char *paragem, char *carreira, 
    lista_paragens* topo_p);

#endif
