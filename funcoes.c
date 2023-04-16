/* Funcoes utilizadas para realizar cada pedido */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structs.h"
#include "memoria.h"
#include "funcoes.h"

/*-----------------------------------------------------------------------------
| Nome da funcao: adiciona_carreira
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo_c, 
|    lista_paragens *topo_p
| Funcao: Funcao responsavel por adicionar uma nova carreira a lista.
+----------------------------------------------------------------------------*/

void adiciona_carreira(char *nome, lista_carreiras *topo_c, 
    lista_paragens *topo_p){

    lista_carreiras *novo = NULL;
    lista_carreiras *aux = NULL;

    /* Cria uma nova estrutura com a carreira a ser adicionada */
    novo = cria_carreira(nome, topo_c, topo_p);

    /* Inicializa o auxiliar como o topo da lista */          
    aux = topo_c;

    /* Percorre a lista ate chegar ao ultimo elemento e incrementa o contador */
    while(aux -> prox_c != NULL)
        aux = aux -> prox_c;

    /* Adiciona a nova estrutura no fim da lista */
    aux -> prox_c = novo;

}

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_carreira
| Tipo: lista_carreiras *
| Argumentos: char *nome, lista_carreiras *topo_c, 
|    lista_paragens *topo_p
| Funcao: Funcao responsavel por criar um novo elemento da lista de carreiras
+----------------------------------------------------------------------------*/

lista_carreiras* cria_carreira(char *nome, lista_carreiras *topo_c, 
    lista_paragens *topo_p){

    carreira_struct carreira;
    lista_carreiras *novo = NULL;
    lista_ligacoes *topo_paragens = NULL;

    /* Aloca memoria para o topo da lista de ligacoes da carreira */
    topo_paragens = (lista_ligacoes*) malloc(sizeof(lista_ligacoes));
    erro_alocacao_l(topo_paragens, topo_c, topo_p);
    topo_paragens->prox_l = NULL;

    /* Preenche a estrutura da carreira */
    carreira.nome = nome;
    carreira.paragens = topo_paragens;
    carreira.origem = NULL;
    carreira.destino = NULL;
    carreira.custo_total = 0;
    carreira.duracao_total = 0;
    carreira.numero_paragens = 0;

    /* Associa a estrutura carreira a lista de carreiras */
    novo = cria_lista_carreiras(carreira, topo_c, topo_p);

    /* Retorna o ponteiro para o elemento da lista de carreiras criado */
    return novo;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_lista_carreiras
| Tipo: lista_carreiras *
| Argumentos: carreira_struct carreira, 
|    lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por associar a estrutura carreira a uma estrutura 
| lista de carreiras.
+----------------------------------------------------------------------------*/

lista_carreiras* cria_lista_carreiras(carreira_struct carreira, 
    lista_carreiras *topo_c, lista_paragens *topo_p){

    lista_carreiras *novo = NULL;
    
    /* Aloca memoria para o novo elemento da lista de carreiras */
    novo = (lista_carreiras*) malloc(sizeof(lista_carreiras));
    erro_alocacao_c(novo, topo_c, topo_p);

    /* Associa a estrutura carreira a uma estrutura lista de carreiras */
    novo->carreira = carreira;
    novo->prox_c = NULL;

    /* Retorna o ponteiro para o elemento da lista de carreiras criado */
    return novo;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_carreiras
| Tipo: void
| Argumentos: lista_carreiras *topo
| Funcao: Funcao responsavel por imprimir as informaçoes de todas as carreiras 
| existentes na lista.
+----------------------------------------------------------------------------*/

void imprime_carreiras(lista_carreiras *topo){

    lista_carreiras *aux = topo->prox_c;

    /* Percorre a lista de carreiras */
    while(aux!=NULL){

        /* Imprime informacoes de uma carreira sem paragens */
        if(aux->carreira.destino == NULL)
            printf("%s %d %.2f %.2f\n", 
                aux->carreira.nome, aux->carreira.numero_paragens, 
                aux->carreira.custo_total, aux->carreira.duracao_total);
        
        /* Imprime informações de uma carreira com paragens */
        else
            printf("%s %s %s %d %.2f %.2f\n",
                aux->carreira.nome, aux->carreira.origem,
                aux->carreira.destino, aux->carreira.numero_paragens, 
                aux->carreira.custo_total, aux->carreira.duracao_total);

        aux = aux -> prox_c;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: procura_carreira
| Tipo: int
| Argumentos: char *nome, lista_carreiras *topo
| Funcao: Funcao responsavel por verificar se uma carreira com o nome fornecido 
| existe na lista de carreiras. Retorna 1 caso exista e 0 caso contrario.
+----------------------------------------------------------------------------*/

int procura_carreira(char *nome, lista_carreiras *topo){

    lista_carreiras *aux = topo->prox_c;

    /* Percorre a lista de carreiras */
    while(aux != NULL){
        
        /* Se encontrar a carreira com o nome desejado, retorna 1 */
        if(strcmp(aux->carreira.nome, nome) == 0)
            return 1;
        
        aux = aux -> prox_c;
    }
    return 0;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_paragens_da_carreira
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo
| Funcao: Funcao responsavel por imprimir as paragens de uma carreira
+----------------------------------------------------------------------------*/


void imprime_paragens_da_carreira(char *nome, lista_carreiras *topo){

    lista_carreiras *aux_c = topo->prox_c;
    lista_ligacoes *aux_l = NULL;

    /* Percorre a lista de carreiras */
    while(aux_c != NULL){

        /* Verifica se a carreira existe e tem paragens associadas */
        if(strcmp(aux_c->carreira.nome, nome) == 0 && 
            aux_c->carreira.destino != NULL){

            /* Percorre a lista de paragens da carreira */
            aux_l = aux_c->carreira.paragens->prox_l;

            while(aux_l->prox_l != NULL){

                /* Imprime o nome das paragens */
                printf("%s, ", aux_l->ligacao.origem);

                aux_l = aux_l->prox_l;
            }
            /* Imprime o nome da ultima paragem */
            printf("%s, %s\n", aux_l->ligacao.origem, aux_l->ligacao.destino);
        }  
        aux_c = aux_c -> prox_c;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_inverso
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo
| Funcao: Funcao responsavel por imprimir as paragens de uma carreira pela
| ordem inversa.
+----------------------------------------------------------------------------*/

void imprime_inverso(char *nome, lista_carreiras * topo){

    lista_carreiras *aux_c = topo->prox_c;
    lista_ligacoes *aux_l = NULL;

    /* Percorre a lista de carreiras */
    while(aux_c!=NULL){

        /* Verifica se a carreira existe e tem paragens associadas */
        if(strcmp(aux_c->carreira.nome, nome) == 0 && 
            aux_c->carreira.destino != NULL){

            /* Ponteiro para a lista de paragens da carreira */
            aux_l = aux_c->carreira.paragens->prox_l;
            
            /* Percorre a lista de paragens da carreira ate ao fim */
            while (aux_l->prox_l != NULL)
                 aux_l = aux_l->prox_l;
            
            break;
        }  
        aux_c = aux_c -> prox_c;
    }
    /* Imprime o nome das paragens pela ordem inversa */
    while(aux_l != NULL && aux_l->ant_l != NULL){

        if(aux_l->ant_l->ant_l == NULL) {
            printf("%s, %s\n", aux_l->ligacao.destino, aux_l->ligacao.origem);
            break;
        }

        printf("%s, ", aux_l->ligacao.destino);
        aux_l = aux_l->ant_l;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: procura_paragem
| Tipo: int
| Argumentos: char *nome, lista_paragens *topo
| Funcao: Funcao responsavel por verificar se uma paragem com o nome fornecido 
| existe na lista de paragens. Retorna 1 caso exista e 0 caso contrario.
+----------------------------------------------------------------------------*/

int procura_paragem(char *nome, lista_paragens *topo){

    lista_paragens *aux = topo->prox_p;

    /* Percorre a lista de paragens */
    while(aux != NULL){

        /* Se encontrar a paragem com o nome desejado, retorna 1 */
        if(strcmp(aux->paragem.nome, nome) == 0)
            return 1;
        
        aux = aux -> prox_p;
    }
    return 0;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_coord
| Tipo: void
| Argumentos: char nome, lista_paragens *topo
| Funcao: Funcao responsavel por imprimir as coordenadas da paragem com o nome 
| fornecido.
+----------------------------------------------------------------------------*/

void imprime_coord(char *nome, lista_paragens *topo){

    lista_paragens *aux = topo->prox_p;

    /* Percorre a lista de paragens */
    while(aux != NULL){

        /* Se encontrar a paragem com o nome desejado, imprime as suas 
        coordenadas */
        if(strcmp(aux->paragem.nome, nome) == 0){
            printf("%16.12f %16.12f\n", 
                aux->paragem.latitude, aux->paragem.longitude);
            break;
        }
        aux = aux -> prox_p;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_paragens
| Tipo: void
| Argumentos: lista_paragens *topo
| Funcao: Funcao responsavel por imprimir as informacoes de todas as paragens
| da lista.
+----------------------------------------------------------------------------*/

void imprime_paragens(lista_paragens *topo){

    lista_paragens *aux = topo->prox_p;

    /* Percorre a lista de paragens */
    while(aux != NULL){

        /* Imprime informacoes da paragem*/
        printf("%s: %16.12f %16.12f %d\n", aux->paragem.nome, 
            aux->paragem.latitude, aux->paragem.longitude, 
            aux->paragem.num_carreiras);

        aux = aux -> prox_p;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: adiciona_paragem
| Tipo: lista_paragens *
| Argumentos: char *nome, double latitude, 
|    double longitude, lista_paragens *topo_p, lista_carreiras *topo_c
| Funcao: Funcao responsavel por adicionar uma nova paragem a lista.
+----------------------------------------------------------------------------*/

void adiciona_paragem(char *nome, double latitude, 
    double longitude, lista_paragens *topo_p, lista_carreiras *topo_c){

    lista_paragens *novo = NULL;
    lista_paragens *aux = NULL;

    /* Cria uma nova estrutura com a paragem a ser adicionada */
    novo = cria_paragem(nome, latitude, longitude, topo_c, topo_p);

    /* Inicializa o auxiliar como o topo da lista */      
    aux = topo_p;

    /* Percorre a lista ate chegar ao ultimo elemento e incrementa o contador */
    while(aux -> prox_p != NULL)
        aux = aux -> prox_p;

    /* Adiciona a nova estrutura no fim da lista */
    aux -> prox_p = novo;

}

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_paragem
| Tipo: lista_paragens *
| Argumentos: char *nome, double latitude,
|    double longitude, lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por criar um novo elemento da lista de paragens.
+----------------------------------------------------------------------------*/

lista_paragens* cria_paragem(char *nome, double latitude,
    double longitude, lista_carreiras *topo_c, lista_paragens *topo_p){

    paragem_struct paragem;
    lista_paragens *novo = NULL;
    lista_nomes_carreiras *topo_carreiras = NULL;

    /* Aloca memoria para o topo da lista de carreiras da paragem */
    topo_carreiras = 
        (lista_nomes_carreiras*) malloc(sizeof(lista_nomes_carreiras));
    erro_alocacao_n(topo_carreiras, topo_c, topo_p);
    topo_carreiras->prox_n = NULL;

    /* Preenche a estrutura da paragem */
    paragem.carreiras = topo_carreiras;
    paragem.nome = nome;
    paragem.latitude = latitude;
    paragem.longitude = longitude;
    paragem.num_carreiras = 0;

    /* Associa a estrutura paragem a uma estrutura lista de paragens */
    novo = cria_lista_paragens(paragem, topo_c, topo_p);

    /* Retorna o ponteiro para o elemento da lista de paragens criado */
    return novo;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_lista_paragens
| Tipo: lista_paragens*
| Argumentos: paragem_struct paragem
| Funcao: Funcao responsavel por associar a estrutura paragem a uma estrutura 
| lista de paragens.
+----------------------------------------------------------------------------*/

lista_paragens* cria_lista_paragens(paragem_struct paragem,
    lista_carreiras *topo_c, lista_paragens *topo_p){

    lista_paragens *novo = NULL;
    
    /* Aloca memoria para o novo elemento da lista de paragens */
    novo = (lista_paragens*) malloc(sizeof(lista_paragens));
    erro_alocacao_p(novo, topo_c, topo_p);

    /* Associa a estrutura paragem a uma estrutura lista de paragens */
    novo->paragem = paragem;
    novo->prox_p = NULL;

    /* Retorna o ponteiro para o elemento da lista de paragens criado */
    return novo;
}

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
    lista_paragens *topo_p){

    /* Verifica se a ligacao pode ser adicionada. Caso contrario, imprime
    uma mensagem de erro */
    if(verifica_ligacao(carreira, topo_c, origem, destino) == 0){
        printf("link cannot be associated with bus line.\n");
        free(origem);
        free(destino);
        return;
    }

    /* Verifica se a paragem de origem ja existe na carreira.
    Se nao existir, atualiza a lista de paragens */
    if(verifica_carreira_nova(carreira, origem, topo_c) == 0)
        update_paragem(carreira, origem, topo_p, topo_c);
    
    /* Verifica se a paragem de destino e diferente da de origem e se ja existe 
    na carreira. Se nao existir, atualiza a lista de paragens */
    if(verifica_carreira_nova(carreira, destino, topo_c) == 0 
        && strcmp(origem, destino) != 0)
        update_paragem(carreira, destino, topo_p, topo_c);

    /* Atualiza a carreira com a nova ligacao */
    update_carreira(carreira, topo_c, topo_p, custo, duracao, origem, destino);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: verifica_ligacao
| Tipo: int
| Argumentos: char *nome, lista_carreiras *topo_c, char *origem, 
|    char *destino 
| Funcao: Funcao responsavel por verificar se a ligacao nova pode ser associada
| a carreira. Retorna 1 se sim e 0 caso contrario.
+----------------------------------------------------------------------------*/

int verifica_ligacao(char *nome, lista_carreiras *topo_c, char *origem, 
    char *destino){

    lista_carreiras *aux = topo_c->prox_c;

    /* Percorre a lista de carreiras */
    while(aux != NULL){

        if(strcmp(aux->carreira.nome, nome) == 0){

            if(aux->carreira.origem == NULL || 
                strcmp(aux->carreira.destino, origem) == 0 ||
                strcmp(aux->carreira.origem, destino) == 0)
                return 1;
        }
        aux = aux -> prox_c;
    }
    return 0;
}

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
    lista_carreiras* topo){

    lista_carreiras * aux = topo->prox_c;        
    lista_ligacoes *aux_l = NULL;

    /* Percorre a lista de carreiras */
    while(aux != NULL){

        if(strcmp(aux->carreira.nome, carreira) == 0){
            
            /* Começa a percorrer a lista de paragens da carreira */
            aux_l = aux->carreira.paragens->prox_l;

            while(aux_l != NULL){
                
                /* Verifica se a paragem ja existe na carreira */
                if(strcmp(aux_l->ligacao.origem, paragem) == 0 || 
                    strcmp(aux_l->ligacao.destino, paragem) == 0)
                    return 1;
                
                aux_l = aux_l->prox_l;
            }
            break;       
        }
        aux = aux->prox_c;
    }
    return 0;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_lista_nomes_carreiras
| Tipo: lista_nomes_carreiras *
| Argumentos: char *nome, 
|    lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por criar uma estrutura lista de nomes.
+----------------------------------------------------------------------------*/

lista_nomes_carreiras* cria_lista_nomes_carreiras(char *nome, 
    lista_carreiras *topo_c, lista_paragens *topo_p){

    lista_nomes_carreiras *novo = NULL;
    
    /* Aloca memoria para o novo elemento da lista de nomes */
    novo = (lista_nomes_carreiras*) malloc(sizeof(lista_nomes_carreiras));
    erro_alocacao_n(novo, topo_c, topo_p);

    novo->nome = nome;
    novo->prox_n = NULL;

    /* Retorna o ponteiro para o elemento da lista de nomes criado */
    return novo;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: strcasecmp
| Tipo: int
| Argumentos: const char *s1, const char *s2
| Funcao: Funcao responsavel por comparar duas strings sem diferenciacao entre 
| letras maiusculas e minusculas.
| Retorna a diferenca entre os caracteres ou 0 se as strings forem iguais.
+----------------------------------------------------------------------------*/

int strcasecmp(const char *s1, const char *s2){
    
    int i = 0;
    char c1 = '\0', c2 = '\0';

    /* Percorre as duas strings */
    for(i = 0; s1[i] && s2[i]; i++){
        /* Converte os caracteres para minuscula */
        c1 = tolower(s1[i]);
        c2 = tolower(s2[i]);
        /* Compara os caracteres em minuscula */
        if(c1 != c2){
            /* Retorna a diferenca entre os caracteres caso sejam diferentes */
            return (c1 - c2);
        }
    }
    /* Retorna a diferenca entre os ultimos caracteres comparados 
    ou 0 caso as strings tenham o mesmo tamanho */
    return (s1[i] - s2[i]);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: adiciona_por_ordem
| Tipo: lista_nomes_carreiras *
| Argumentos: lista_nomes_carreiras *topo, 
|    lista_nomes_carreiras *novo
| Funcao: Funcao responsavel por adicionar, por ordem alfabetica, um novo 
| elemento a lista dos nomes das carreiras de uma paragem.
+----------------------------------------------------------------------------*/

void adiciona_por_ordem(lista_nomes_carreiras *topo, 
    lista_nomes_carreiras *novo){

    lista_nomes_carreiras *aux_n = topo->prox_n;
    lista_nomes_carreiras *ant_n = topo;

    /* Se a lista estiver vazia, adiciona o novo elemento apos o topo */
    if(topo->prox_n == NULL){
        topo->prox_n = novo;
        return;
    }

    /* Percorre a lista ate encontrar a posicao correta para inserir o novo 
    elemento por ordem alfabetica */
    while(aux_n->prox_n != NULL && strcasecmp(aux_n->nome, novo->nome) < 0){
        ant_n = aux_n;
        aux_n = aux_n->prox_n;
    }

     /* Se encontrou uma posicao onde o nome do novo elemento e menor
    do que o nome do elemento atual, insere-o antes desse */
    if(strcasecmp(aux_n->nome, novo->nome) > 0){
        ant_n->prox_n = novo;
        novo->prox_n = aux_n;
    }
    /* Se chegou ao fim da lista e o nome do novo elemento e maior (ou igual) 
    do que o nome do ultimo elemento, insere-o no fim da lista */
    else
        aux_n->prox_n = novo;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: update_paragem
| Tipo: void
| Argumentos: char *nome, lista_paragens *topo
| Funcao: Funcao responsavel por incrementar o numero de carreiras de uma 
| paragem.
+----------------------------------------------------------------------------*/

void update_paragem(char *carreira, char *nome, lista_paragens *topo_p, 
    lista_carreiras *topo_c){

    lista_paragens *aux_p = topo_p->prox_p;
    lista_nomes_carreiras *novo = NULL;
    char *nome_carreira = NULL;
    int tamanho_nome = strlen(carreira) + 1;

    /* Aloca espaco para o nome da carreira a ser associada a paragem */
    nome_carreira = (char*) malloc((tamanho_nome) * sizeof(char));
    erro_alocacao_s(nome_carreira, topo_c, topo_p);
    memset(nome_carreira, 0, tamanho_nome * sizeof(char));

    /* Define o nome da carreira */
    strcpy(nome_carreira, carreira);

    /* Percorre a lista de paragens */
    while(aux_p != NULL){
    
        if(strcmp(aux_p -> paragem.nome, nome) == 0){

            /* Adiciona a nova carreira a lista de carreiras da paragem */
            novo = cria_lista_nomes_carreiras(nome_carreira, topo_c, topo_p);
            adiciona_por_ordem(aux_p->paragem.carreiras, novo);

            /* Incrementa o numero de carreiras que passam na paragem */
            aux_p->paragem.num_carreiras ++;
            break;
        }
        aux_p = aux_p -> prox_p;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_ligacao
| Tipo: lista_ligacoes *
| Argumentos: char *nome
| Funcao: Funcao responsavel por criar um novo elemento da lista de ligacoes.
+----------------------------------------------------------------------------*/

lista_ligacoes* cria_ligacao(char *origem, char *destino, double custo, 
    double duracao, lista_carreiras *topo_c, lista_paragens *topo_p){

    ligacao_struct ligacao;
    lista_ligacoes *novo = NULL;

    /* Preenche a estrutura da ligacao */
    ligacao.origem = origem;
    ligacao.destino = destino;
    ligacao.custo = custo;
    ligacao.duracao = duracao;

    /* Associa a estrutura carreira a lista de ligacoes */
    novo = cria_lista_ligacoes(ligacao, topo_c, topo_p);

    /* Retorna o ponteiro para o elemento da lista de ligacoes criado */
    return novo;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: cria_lista_ligacoes
| Tipo: lista_ligacoes *
| Argumentos: char *nome
| Funcao: Funcao responsavel por associar a estrutura ligacao a uma estrutura 
| lista de ligacoes.
+----------------------------------------------------------------------------*/

lista_ligacoes* cria_lista_ligacoes(ligacao_struct ligacao,
    lista_carreiras *topo_c, lista_paragens *topo_p){

    lista_ligacoes *novo = NULL;
    
    /* Aloca memoria para o novo elemento da lista de nomes */
    novo = (lista_ligacoes*) malloc(sizeof(lista_ligacoes));
    erro_alocacao_l(novo, topo_c, topo_p);

    novo->ligacao = ligacao;
    novo->prox_l = NULL;

    /* Retorna o ponteiro para o elemento da lista de nomes criado */
    return novo;
}

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
    char *origem, char *destino){

    lista_carreiras *aux = topo_c->prox_c;
    lista_ligacoes *aux_l = NULL;
    lista_ligacoes *novo = NULL;

    /* Percorre a lista de carreiras */
    while(aux != NULL){

        if(strcmp(aux->carreira.nome, nome) == 0){

            /* Se a origem da carreira ainda não foi definida, atualiza a 
            carreira com a nova origem e destino */
            if(aux->carreira.origem == NULL){

                /* Atualiza o custo e duracao da carreira */
                aux->carreira.custo_total += custo;
                aux->carreira.duracao_total += duracao;

                /* Cria uma nova estrutura ligacao */
                novo = cria_ligacao(origem, destino, custo, duracao, topo_c, 
                    topo_p);

                /* Define a origem e o destino da carreira como a nova origem 
                e destino */
                aux->carreira.origem = origem;
                aux->carreira.destino = destino;

                /* Adiciona a nova ligacao a carreira */
                aux->carreira.paragens->prox_l = novo;
                novo->ant_l = aux->carreira.paragens;

                /* Define o numero total de paragens como 2 */
                aux->carreira.numero_paragens = 2;
            }
            /* Se o destino da carreira e igual a origem da nova ligacao,
            atualiza a carreira com a nova paragem de destino */
            else if(strcmp(aux->carreira.destino, origem)==0){

                /* Atualiza o custo e duracao da carreira */
                aux->carreira.custo_total += custo;
                aux->carreira.duracao_total += duracao;

                /* Cria uma nova estrutura ligacao */
                novo = cria_ligacao(origem, destino, custo, duracao, topo_c, 
                    topo_p);

                /* Percorre a lista de ligacoes da carreira ate chegar a 
                ultima ligacao e adiciona a nova */
                aux_l = aux->carreira.paragens;

                while(aux_l->prox_l != NULL)
                    aux_l = aux_l -> prox_l;
                
                aux_l -> prox_l = novo;
                novo -> ant_l = aux_l;
                
                /* Define o destino da carreira como o novo destino */
                aux->carreira.destino = destino;
                /* Incrementa o numero total de paragens */
                aux->carreira.numero_paragens ++;
            }

            /* Se a origem da carreira e igual ao destino da nova ligacao,
            atualiza a carreira com a nova paragem de origem */
            else if(strcmp(aux->carreira.origem, destino)==0){

                /* Atualiza o custo e duracao da carreira */
                aux->carreira.custo_total += custo;
                aux->carreira.duracao_total += duracao;

                /* Cria uma nova estrutura ligacao */
                novo = cria_ligacao(origem, destino, custo, duracao, topo_c, 
                    topo_p);

                /* Adiciona a nova ligacao no inicio da lista */
                novo -> prox_l = aux->carreira.paragens->prox_l;
                aux->carreira.paragens->prox_l ->ant_l = novo;

                novo -> ant_l = aux->carreira.paragens;
                aux->carreira.paragens->prox_l = novo;

                /* Define a origem da carreira como a nova origem */
                aux->carreira.origem = origem;
                /* Incrementa o numero total de paragens */
                aux->carreira.numero_paragens ++;
            }
        }
        aux = aux -> prox_c;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: imprime_carreiras_intersecao
| Tipo: void
| Argumentos: paragem_struct paragem
| Funcao: Funcao responsavel por imprimir o nome das carreiras que contem a 
| paragem.
+----------------------------------------------------------------------------*/

void imprime_carreiras_intersecao(paragem_struct paragem){
    
    lista_nomes_carreiras *aux = paragem.carreiras->prox_n;

    /* Percorre a lista de carreiras da paragem e imprime o nome de cada uma */
    while(aux->prox_n !=  NULL){
        printf("%s ", aux->nome);
        aux = aux->prox_n;
    }
    if(aux->prox_n == NULL)
        printf("%s\n", aux->nome);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_carreira
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo_c
| Funcao: Funcao responsavel por remover uma carreira da lista de carreiras.
+----------------------------------------------------------------------------*/

void apaga_carreira(char *nome, lista_carreiras *topo_c){
    
    lista_carreiras *aux = topo_c->prox_c;
    lista_carreiras *ant = topo_c;
    lista_carreiras *libertar = NULL;

    /* Percorre a lista de carreiras */
    while(aux != NULL){

        if(strcmp(aux->carreira.nome, nome) == 0){
            /* Define o no a libertar */
            libertar = aux;
            /* Atualiza o ponteiro anterior de forma a pular o no */
            ant->prox_c = aux->prox_c;
            /* Libertar a memoria alocada para o no e os seus elementos */
            free_carreira_struct(&libertar->carreira);
            free(libertar);
            break;
        }
        ant = aux;
        aux = aux -> prox_c;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_carreira_das_paragens
| Tipo: void
| Argumentos: char *nome, lista_paragens *topo_p
| Funcao: Funcao responsavel por remover a carreira de todas as paragens.
+----------------------------------------------------------------------------*/

void apaga_carreira_das_paragens(char *nome, lista_paragens *topo_p){
    
    lista_paragens *aux_p = topo_p->prox_p;
    lista_nomes_carreiras *aux_n = NULL;
    lista_nomes_carreiras *ant_n = NULL;

    /* Percorre a lista de paragens */
    while(aux_p != NULL){

        aux_n = aux_p->paragem.carreiras->prox_n;
        ant_n = aux_p->paragem.carreiras;

        while(aux_n != NULL){

            if(strcmp(aux_n->nome, nome) == 0){
                /* Diminui o numero de carreiras da paragem */
                aux_p->paragem.num_carreiras --;
                /* Atualiza o ponteiro anterior de forma a pular o no */
                ant_n->prox_n = aux_n->prox_n;
                /* Libertar a memoria alocada para o no e os seus elementos */
                free(aux_n->nome);
                free(aux_n);
                break;
            }
            ant_n = aux_n;
            aux_n = aux_n->prox_n;
        }
        aux_p = aux_p -> prox_p;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_paragem
| Tipo: void
| Argumentos: char *nome, lista_paragens *topo_p
| Funcao: Funcao responsavel por remover uma paragem da lista de paragens.
+----------------------------------------------------------------------------*/

void apaga_paragem(char *nome, lista_paragens *topo_p){
    
    lista_paragens *aux = topo_p->prox_p;
    lista_paragens *ant = topo_p;
    lista_paragens *libertar = NULL;

    /* Percorre a lista de paragens */
    while(aux != NULL){

        if(strcmp(aux->paragem.nome, nome) == 0){
            /* Define o no a libertar */
            libertar = aux;
            /* Atualiza o ponteiro anterior de forma a pular o no */
            ant->prox_p = aux->prox_p;
            /* Libertar a memoria alocada para o no e os seus elementos */
            free_paragem_struct(&libertar->paragem);
            free(libertar);
            break;
        }
        ant = aux;
        aux = aux -> prox_p;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_ligacao
| Tipo: void
| Argumentos: char *nome, lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por remover a carreira removida de todas as
| carreiras.
+----------------------------------------------------------------------------*/

void apaga_ligacao(char *nome, lista_carreiras *topo_c, lista_paragens *topo_p){
    
    lista_carreiras *aux_c = topo_c->prox_c;
    lista_ligacoes *aux_l = NULL;
    lista_ligacoes *proxima = NULL;
    lista_ligacoes *libertar = NULL;

    /* Percorre a lista de carreiras */
    while(aux_c != NULL){

        /* Enquanto a origem da carreira atual for nula e nao for o ultimo no 
        na lista, avança para a proxima carreira */
        while(aux_c->carreira.origem == NULL && aux_c->prox_c != NULL)
            aux_c = aux_c -> prox_c;

        /* Se a origem da ultima carreira na lista tambem for nula, sai do 
        loop */
        if(aux_c->carreira.origem == NULL && aux_c->prox_c == NULL)
            break;
        /* Inicia o ponteiro aux_l na primeira ligacao da carreira atual  */
        aux_l = aux_c->carreira.paragens->prox_l;

        /* Percorre a lista de ligacoes da carreira ate ao penultimo elemento */
        while(aux_l->prox_l != NULL){

            /* Compara o destino da ligacao com a paragem apagada */
            if(strcmp(aux_l->ligacao.destino, nome) == 0){

                /* Diminui o numero de paragens da carreira */
                aux_c->carreira.numero_paragens --;
                
                /* Define o proximo elemento como o elemento seguinte ao atual */
                proxima = aux_l->prox_l;

                /* Enquanto o destino da proxima ligacao for a paragem apagada,
                liberta essa ligacao e os seus elementos, avancado para o 
                proximo elemento */
                while(strcmp(proxima->ligacao.destino, nome) == 0 
                    && proxima->prox_l != NULL){
                    libertar = proxima;
                    aux_c->carreira.numero_paragens--;
                    aux_l->ligacao.custo += proxima->ligacao.custo;
                    aux_l->ligacao.duracao += proxima->ligacao.duracao;
                    proxima = proxima->prox_l;
                    free_ligacao_struct(&libertar->ligacao);
                    free(libertar);
                }
                /* Define o no a libertar */
                libertar = proxima;

                /* Atualiza os campos da ligacao e liberta a informacao que nao
                e mais necessario */
                free(aux_l->ligacao.destino);
                aux_l->ligacao.destino = proxima->ligacao.destino;

                aux_l->ligacao.custo += proxima->ligacao.custo;
                aux_l->ligacao.duracao += proxima->ligacao.duracao;

                /* Remove a proxima ligacao e liberta a memoria alocada */
                aux_l->prox_l = proxima->prox_l;
                free(libertar->ligacao.origem);
                free(libertar);

                if (aux_l->prox_l != NULL)
                    aux_l->prox_l->ant_l = aux_l;
                else
                    break;
            }
            aux_l = aux_l->prox_l;
        }
        /* Verifica se a origem da carreira e a paragem apagada. 
        Se sim, atualiza a carreira. */
        if(strcmp(aux_c->carreira.origem, nome) == 0)
            apaga_ligacao_origem(aux_c, topo_p);

        while(aux_c->carreira.origem == NULL && aux_c->prox_c != NULL)
            aux_c = aux_c -> prox_c;

        if(aux_c->carreira.origem == NULL && aux_c->prox_c == NULL)
            break;

        /* Verifica se o destino da carreira e a paragem apagada. 
        Se sim, atualiza a carreira. */
        if(strcmp(aux_c->carreira.destino, nome) == 0)
            apaga_ligacao_destino(aux_c, topo_p);
        
        aux_c = aux_c -> prox_c;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_ligacao_origem
| Tipo: void
| Argumentos: lista_carreiras *aux_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por atualizar a carreira caso a paragem removida 
| seja a sua origem.
+----------------------------------------------------------------------------*/

void apaga_ligacao_origem(lista_carreiras *aux_c, lista_paragens *topo_p){
    
    lista_ligacoes *aux_l = NULL;

    aux_l = aux_c->carreira.paragens->prox_l;

    /* Diminui o numero de paragens da carreira */
    aux_c->carreira.numero_paragens --;

    /* Caso a carreira tenha apenas uma ligacao, atualiza os dados */
    if(aux_c->carreira.numero_paragens == 1){
        apaga_ultima_ligacao(aux_c, topo_p, aux_c->carreira.destino);
        return;
    }

    /* Retira o custo da primeira ligacao ao custo total da carreira */
    aux_c->carreira.custo_total -= aux_l->ligacao.custo;       
    aux_c->carreira.duracao_total -= aux_l->ligacao.duracao;

    /* Remove a primeira ligacao da lista e atualiza os dados da carreira */ 
    aux_c->carreira.paragens->prox_l = aux_l->prox_l;
    
    aux_c->carreira.origem = aux_l->prox_l->ligacao.origem;
                
    if(aux_c->carreira.paragens->prox_l != NULL)            
        aux_c->carreira.paragens->prox_l->ant_l = aux_c->carreira.paragens;

    /* Liberta a memoria alocada */
    free_ligacao_struct(&aux_l->ligacao);            
    free(aux_l);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_ligacao_destino
| Tipo: void
| Argumentos: lista_carreiras *aux_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por atualizar a carreira caso a paragem removida 
| seja o seu destino.
+----------------------------------------------------------------------------*/

void apaga_ligacao_destino(lista_carreiras *aux_c, lista_paragens *topo_p){
    
    lista_ligacoes *aux_l = NULL;

    aux_l = aux_c->carreira.paragens->prox_l;

    /* Diminui o numero de paragens da carreira */
    aux_c->carreira.numero_paragens --;

    /* Caso a carreira tenha apenas uma ligacao, atualiza os dados */
    if(aux_c->carreira.numero_paragens == 1){
        apaga_ultima_ligacao(aux_c, topo_p, aux_c->carreira.origem);
        return;
    }

    /* Remove a ultima ligacao e atualiza os dados da carreira */
    while(aux_l->prox_l != NULL)
        aux_l = aux_l->prox_l;

    aux_c->carreira.custo_total -= aux_l->ligacao.custo;        
    aux_c->carreira.duracao_total -= aux_l->ligacao.duracao;
    aux_c->carreira.destino = aux_l->ant_l->ligacao.destino;
    aux_l->ant_l->prox_l = NULL;

    /* Liberta a memoria alocada */
    free_ligacao_struct(&aux_l->ligacao);
    free(aux_l);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_ultima_ligacao
| Tipo: void
| Argumentos: lista_carreiras *aux_c, lista_paragens *topo_p, 
|    char *outra_paragem
| Funcao: Funcao responsavel por apagar a ultima ligacao da carreira
+----------------------------------------------------------------------------*/

void apaga_ultima_ligacao(lista_carreiras *aux_c, lista_paragens *topo_p, 
    char *outra_paragem){

    lista_ligacoes *aux_l = NULL;

    /* Se uma das paragens da ultima ligacao nao for apagada, retira os dados 
    da carreira dessa paragem */
    if(strcmp(aux_c->carreira.origem, aux_c->carreira.destino) != 0)
        apaga_carreira_de_uma_paragem(outra_paragem, aux_c->carreira.nome, 
            topo_p);

    /* Atualiza os dados da carreira de forma a ter 0 ligacoes */
    aux_l = aux_c->carreira.paragens->prox_l;

    aux_c->carreira.numero_paragens = 0;
    aux_c->carreira.custo_total = 0;
    aux_c->carreira.duracao_total = 0;
    aux_c->carreira.paragens->prox_l = NULL;            
    aux_c->carreira.destino = NULL;
    aux_c->carreira.origem = NULL;

    /* Liberta a memoria alocada */
    free_ligacao_struct(&aux_l->ligacao);            
    free(aux_l);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: apaga_carreira_de_uma_paragem
| Tipo: void
| Argumentos: char *paragem, char *carreira, 
|    lista_paragens* topo_p
| Funcao: Funcao responsavel por apagar um carreira de apenas uma paragem.
+----------------------------------------------------------------------------*/

void apaga_carreira_de_uma_paragem(char *paragem, char *carreira, 
    lista_paragens* topo_p){

    lista_paragens *aux_p = topo_p->prox_p;
    lista_nomes_carreiras *aux_n = NULL;
    lista_nomes_carreiras *ant_n = NULL;

    /* Percorre a lista de paragens */
    while(aux_p != NULL){

        if(strcmp(aux_p->paragem.nome, paragem) == 0){
            
            aux_n = aux_p->paragem.carreiras->prox_n;
            ant_n = aux_p->paragem.carreiras;

            while(aux_n != NULL){

                if(strcmp(aux_n->nome, carreira) == 0){
                    /* Diminui o numero de carreiras da paragem */
                    aux_p->paragem.num_carreiras --;
                    /* Atualiza o ponteiro anterior de forma a pular o no */
                    ant_n->prox_n = aux_n->prox_n;
                    /* Libertar a memoria alocada */
                    free(aux_n->nome);
                    free(aux_n);
                    break;
                }
                ant_n = aux_n;
                aux_n = aux_n->prox_n;
            }
            break;
        }
        aux_p = aux_p -> prox_p;
    }
}
