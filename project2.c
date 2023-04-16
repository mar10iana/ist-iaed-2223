/* iaed-23 - ist199528 - project2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "comandos.h"

int main()
{
    char input[INPUT];

    lista_carreiras *topo_c = NULL;
    lista_paragens *topo_p = NULL;
    int free_topo = 1;

    while(1){

        /* Le os dados inseridos pelo utilizador e armazena na variavel input */
        fgets(input, sizeof(input), stdin);

        /* Substitui o caractere "\n" por '\0' */
        input[strcspn(input, "\n")] = '\0';

        if(free_topo == 1){
            
            /* Aloca memoria para o topo da lista de carreiras */
            topo_c = (lista_carreiras*) malloc(sizeof(lista_carreiras));
            erro_alocacao_c(topo_c, topo_c, topo_p);
            topo_c->prox_c = NULL;

            /* Aloca memoria para o topo da lista de paragens */
            topo_p = (lista_paragens*) malloc(sizeof(lista_paragens));
            erro_alocacao_p(topo_p, topo_c, topo_p);
            topo_p->prox_p = NULL;

            free_topo = 0;
        }

        /* Avalia a primeira letra do input e chama a funcao correspondente a 
        esse comando. */
        if(input[0] == 'q')
            comandos_q(input, topo_c, topo_p);

        else if(input[0] == 'c')
            comandos_c(input, topo_c, topo_p);
            
        else if(input[0] == 'p')
            comandos_p(input, topo_p, topo_c);

        else if(input[0] == 'l')
            comandos_l(input, topo_c, topo_p);

        else if(input[0] == 'i')
            comandos_i(topo_p);
        
        else if(input[0] == 'r')
            comandos_r(input, topo_c, topo_p);

        else if(input[0] == 'e')
            comandos_e(input, topo_c, topo_p);

        else if(input[0] == 'a')
            free_topo = comandos_a(input, topo_c, topo_p);
    }
    return 0;
}


