/* Funcoes relacionadas com a interpretacao dos comandos */

#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED

#include <stdio.h>
#include "structs.h"
#include "memoria.h"
#include "funcoes.h"

/*-----------------------------------------------------------------------------
| Nome da funcao: conta_palavras
| Tipo: int
| Argumentos: char input[INPUT]
| Funcao: Funcao responsavel por retornar o numero de palavras presentes no 
| input
+----------------------------------------------------------------------------*/

int conta_palavras(char input[INPUT]);

/*-----------------------------------------------------------------------------
| Nome da funcao: tamanho_palavra
| Tipo: int
| Argumentos: char input[INPUT], int posicao
| Funcao: Funcao responsavel por retornar o tamanho da palavra na posicao 
| pedida
+----------------------------------------------------------------------------*/

int tamanho_palavra(char input[INPUT], int posicao);

/*-----------------------------------------------------------------------------
| Nome da funcao: verifica_abrv_inverso
| Tipo: int
| Argumentos: char *palavra
| Funcao: Funcao responsavel por verificar se a palavra fornecida corresponde 
| a palavra "inverso" ou um prefixo de tamanho pelo menos 3 da mesma.
| Retorna 1 se sim e 0 caso contrario.
+----------------------------------------------------------------------------*/

int verifica_abrv_inverso(char *palavra);

/*-----------------------------------------------------------------------------
| Nome da funcao: verifica_aspas_no_meio
| Tipo: int
| Argumentos: char input[INPUT]
| Funcao: Funcao responsavel por verificar que as aspas no meio do input estão 
| sempre precedidas ou seguidas por um espaco. Retorna 1 se sim e 0 caso
| contrario.
+----------------------------------------------------------------------------*/

int verifica_aspas_no_meio(char input[INPUT]);

/*-----------------------------------------------------------------------------
| Nome da funcao: aspas
| Tipo: int
| Argumentos: char input[INPUT]
| Funcao: Funcao responsavel por retornar o numero de aspas presentes no input
+----------------------------------------------------------------------------*/

int aspas(char input[INPUT]);

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_c
| Tipo: void
| Argumentos: char input[INPUT], lista_carreiras *topo
| Funcao: Funcao responsavel por lidar com os comandos das carreiras. 
+----------------------------------------------------------------------------*/

void comandos_c(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_p
| Tipo: void
| Argumentos: char input[INPUT], lista_paragens *topo
| Funcao: Funcao responsavel por lidar com os comandos das paragens.
+----------------------------------------------------------------------------*/

void comandos_p(char input[INPUT], lista_paragens *topo_p, 
    lista_carreiras *topo_c);

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_l
| Tipo: void
| Argumentos: char input[INPUT], lista_carreiras *topo_c, 
| lista_paragens *topo_p
| Funcao: Funcao responsavel por lidar com os comandos das ligacoes
+----------------------------------------------------------------------------*/

void comandos_l(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_i
| Tipo: void
| Argumentos: lista_paragens *topo_p
| Funcao: Funcao responsavel por imprimir as informacoes das paragens que estao 
| presentes em mais de uma carreira
+----------------------------------------------------------------------------*/

void comandos_i(lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_r
| Tipo: void
| Argumentos: char input[INPUT], lista_carreiras *topo_c
| Funcao: Funcao responsavel por apagar uma carreira.
+----------------------------------------------------------------------------*/

void comandos_r(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_e
| Tipo: void
| Argumentos: char input[INPUT], lista_carreiras *topo_c
| Funcao: Funcao responsavel por apagar uma paragem.
+----------------------------------------------------------------------------*/

void comandos_e(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_q
| Tipo: void
| Argumentos: lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por libertar toda a memoria e sair do programa
+----------------------------------------------------------------------------*/

void comandos_q(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p);

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_a
| Tipo: int
| Argumentos: lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por libertar toda a memoria. Retorna 1 caso a 
| memoria tenha sido libertado e 0 caso contrario.
+----------------------------------------------------------------------------*/

int comandos_a(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p);

#endif
