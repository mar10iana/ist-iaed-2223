#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "structs.h"
#include "memoria.h"
#include "funcoes.h"
#include "comandos.h"

/*-----------------------------------------------------------------------------
| Nome da funcao: conta_palavras
| Tipo: int
| Argumentos: char input[INPUT]
| Funcao: Funcao responsavel por retornar o numero de palavras presentes no 
| input
+----------------------------------------------------------------------------*/

int conta_palavras(char input[INPUT]){

    int contador = 0;
    int dentro_palavra = 0, dentro_aspas = 0;
    int i = 0;

    /* Percorre o input */
    for(i = 0; input[i] != '\0'; i++){

        /* Se o caractere for aspas, modifica o valor do identificador dentro 
        de aspas */
        if(input[i] == '"')
            dentro_aspas = !dentro_aspas;

        /* Se e um espaco ou tabulacao e nao esta dentro de aspas, altera
        o valor do identificador dentro de palavra para 0 */
        else if((input[i] == ' ' || input[i] == '\t') && !dentro_aspas)
            dentro_palavra = 0;

        /* Se o caractere atual nao e um espaco, tabulacao ou aspa e dentro de 
        palavra e falso, incrementa o contador de palavras e altera o valor do 
        identificador dentro de palavra */
        else if(!dentro_palavra){
            contador ++;
            dentro_palavra = 1;
        }
    }
    /* Retorna o numero de palavras */
    return contador;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: tamanho_palavra
| Tipo: int
| Argumentos: char input[INPUT], int posicao
| Funcao: Funcao responsavel por retornar o tamanho da palavra na posicao 
| pedida
+----------------------------------------------------------------------------*/

int tamanho_palavra(char input[INPUT], int posicao){

    int contador = 0;
    int dentro_palavra = 0, dentro_aspas = 0;
    int tamanho = 0;
    int i = 0;

    /* Percorre o input */
    for(i = 0; input[i] != '\0'; i++){

        /* Se o caractere for aspas, modifica o valor do identificador dentro 
        de aspas */
        if(input[i] == '"')
            dentro_aspas = !dentro_aspas;

        /* Se e um espaco ou tabulacao e nao esta dentro de aspas, altera
        o valor do identificador dentro de palavra para 0 */
        else if((input[i] == ' ' || input[i] == '\t') && !dentro_aspas)
            dentro_palavra = 0;

        /* Se o caractere atual nao e um espaco, tabulacao ou aspa e dentro de 
        palavra e falso, incrementa a posicao e altera o valor do 
        identificador dentro de palavra */
        else if(!dentro_palavra){
            contador ++;
            dentro_palavra = 1;

            /* Se a posicao atual for igual a posicao desejada, incrementa o 
            tamanho da palavra */
            if(contador == posicao)
                tamanho ++;
        }
        /* Se a posicao atual for igual a posicao desejada e nao estiver dentro 
        de aspas, incrementa o tamanho da palavra */
        else if(contador == posicao && !dentro_aspas)
            tamanho ++;
        
        /* Se a posicao atual for igual a posição desejada e estiver dentro de 
        aspas, incrementa o tamanho da palavra */
        else if (contador == posicao && dentro_aspas) {
            tamanho ++;
            i++;
            while(input[i] != '\0' && input[i] != '"') {
                tamanho ++;
                i++;
            }
            /* Se encontrar as aspas fechadas, retrocede para o caractere 
            anterior */
            if(input[i] == '"')
                i--;
        }
    }
    /* Retorna o numero de palavras */
    return tamanho;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: verifica_abrv_inverso
| Tipo: int
| Argumentos: char *palavra
| Funcao: Funcao responsavel por verificar se a palavra fornecida corresponde 
| a palavra "inverso" ou um prefixo de tamanho pelo menos 3 da mesma.
| Retorna 1 se sim e 0 caso contrario.
+----------------------------------------------------------------------------*/

int verifica_abrv_inverso(char *palavra){

    char inverso[] = "inverso";
    int tamanho = strlen(palavra);
    int i = 0, count = 0;

    /* Verifica se o tamanha da palavra e inferior a 3. Se sim, retorna 0 */
    if(tamanho < 3)
        return 0;

    /* Percorre a palavra fornecida */
    for(i = 0; i < tamanho; i++){    
        /* Compara cada caractere da palavra com o caracter correspondente da 
        palavra "inverso" */  
        if(palavra[i] == inverso[i])
            /* Incrementa o contador */
            count ++;
    }
    /* Se o numero de caracteres correspondentes for igual ao numero de 
    caracteres da palavra recebida, retorna 1 */
    if(count == tamanho)
        return 1;
    /* Caso contrario, retorna 0 */
    else
        return 0;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: verifica_aspas_no_meio
| Tipo: int
| Argumentos: char input[INPUT]
| Funcao: Funcao responsavel por verificar que as aspas no meio do input estão 
| sempre precedidas ou seguidas por um espaco. Retorna 1 se sim e 0 caso
| contrario.
+----------------------------------------------------------------------------*/

int verifica_aspas_no_meio(char input[INPUT]){
    
    int i = 1;
    int tamanho = strlen(input);

    /* Percorre a string, exceto o primeiro e ultimo caractere */
    for(i = 1; i < tamanho - 1; i++){

        /* Verifica se a aspa e precedida ou seguida por um espaco, retorna 0 
        caso contario */
        if(input[i] == '"'){ 
            if(input[i-1] != ' ' && input[i+1] != ' ')
                return 0;
        }
    }
    /* Retorna 1 para indicar que as aspas estao bem formatadas */
    return 1;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: aspas
| Tipo: int
| Argumentos: char input[INPUT]
| Funcao: Funcao responsavel por retornar o numero de aspas presentes no input
+----------------------------------------------------------------------------*/

int aspas(char input[INPUT]){

    int contador = 0;
    int i = 0;

    /* Percorre o input e incrementa o contador sempre que encontrar aspas */
    for (i = 0; input[i] != '\0'; i++){
        if (input[i] == '"')
            contador++;   
    }
    /* Retorna o numero de aspas */
    return contador;
}

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_c
| Tipo: void
| Argumentos: char input[INPUT], lista_carreiras *topo
| Funcao: Funcao responsavel por lidar com os comandos das carreiras. 
+----------------------------------------------------------------------------*/

void comandos_c(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p){
    
    char command = '\0';
    char *nome = NULL;
    int tamanho_nome = 0;
    char *inverso = NULL;
    int tamanho_inverso = 0;
    int i = 0;

    /* Se o input tem apenas um caractere, imprime todas as carreiras */ 
    if(strlen(input) == 1){
        imprime_carreiras(topo_c);
        return;
    }
    
    /* Verifica se o input tem duas palavras */
    if(conta_palavras(input) == 2){

        /* Encontra o tamanho da string */
        tamanho_nome = tamanho_palavra(input, 2) + 1;

        /* Aloca a memoria necessaria para a string */
        nome = (char*) malloc(tamanho_nome * sizeof(char)); 
        erro_alocacao_s(nome, topo_c, topo_p);
        memset(nome, 0, tamanho_nome * sizeof(char));

        /* Le o comando e o nome da carreira */
        i = sscanf(input, "%c %s", &command, nome);

        /* Verifica se a leitura foi bem sucedida */
        if(i != 2){
            free(nome);
            return;
        }

        /* Se a carreira estiver na lista, imprime as paragens associadas 
        a carreira */
        if(procura_carreira(nome, topo_c) == 1)
            imprime_paragens_da_carreira(nome, topo_c);

        /* Se a carreira nao estiver na lista, adiciona-a*/
        else{
            adiciona_carreira(nome, topo_c, topo_p);
            return;
        }
    }

    /* Verifica se o input tem tres palavras */
    else if(conta_palavras(input) == 3){

        /* Encontra o tamanho das strings */
        tamanho_nome = tamanho_palavra(input, 2) + 1;
        tamanho_inverso = tamanho_palavra(input, 3) + 1;

        /* Aloca a memoria necessaria para as strings */
        nome = (char*) malloc(tamanho_nome * sizeof(char)); 
        erro_alocacao_s(nome, topo_c, topo_p);
        memset(nome, 0, tamanho_nome * sizeof(char));

        inverso = (char*) malloc(tamanho_inverso * sizeof(char));
        erro_alocacao_s(inverso, topo_c, topo_p);
        memset(inverso, 0, tamanho_inverso * sizeof(char));

        /* Le o comando, o nome da carreira e a opcao de inversao */
        i = sscanf(input, "%c %s %s", &command, nome, inverso);

        /* Verifica se a leitura foi bem sucedida */
        if(i != 3){
            free(nome);
            free(inverso);
            return;
        }

        /* Se a opcao de inversao for valida e a carreira estiver na lista, 
        imprime as paragens associadas a carreira pela ordem inversa */
        if(verifica_abrv_inverso(inverso) == 1){
            if(procura_carreira(nome, topo_c) == 1)
                imprime_inverso(nome, topo_c);
        }
        /* Se a opcao de inversao nao for valida, imprime uma mensagem de 
        erro */
        else
            printf("incorrect sort option.\n");
        
    }
    /* Liberta a memoria alocada para as strings */
    if(nome != NULL)
        free(nome);
    if(inverso != NULL)
        free(inverso);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_p
| Tipo: void
| Argumentos: char input[INPUT], lista_paragens *topo
| Funcao: Funcao responsavel por lidar com os comandos das paragens.
+----------------------------------------------------------------------------*/

void comandos_p(char input[INPUT], lista_paragens *topo_p, 
    lista_carreiras *topo_c){
    
    char command = '\0';
    char *nome = NULL;
    int tamanho_nome = 0;
    double latitude = 0;
    double longitude = 0;
    int i = 0;

    /* Se o input tem apenas um caractere, imprime todas as paragens */
    if(strlen(input) == 1){
        imprime_paragens(topo_p);
        return;
    }
    /* Verifica que nao ha palavras com aspas no meio */
    if(verifica_aspas_no_meio(input) != 1)
        return;
    
    if(conta_palavras(input) == 2 || conta_palavras(input) == 4){
        
        /* Encontra o tamanho da string */
        tamanho_nome = tamanho_palavra(input, 2) + 1;

        /* Aloca a memoria necessaria para a string */
        nome = (char*) malloc(tamanho_nome * sizeof(char)); 
        erro_alocacao_s(nome, topo_c, topo_p); 
        memset(nome, 0, tamanho_nome * sizeof(char));
    }

    /* Verifica se o input tem duas palavras */
    if(conta_palavras(input) == 2){

        /* Se nao ha aspas no comando, le normalmente */
        if(aspas(input)==0)
            i = sscanf(input, "%c %s", &command, nome);
        
        /* Se ha aspas no comando, le com sscanf para uma string delimitada 
        por aspas*/
        else
            i = sscanf(input, "%c \"%[^\"]\"", &command, nome);

        /* Verifica se a leitura foi bem sucedida */
        if(i != 2){
            free(nome);
            return;
        }

        /* Se a paragem estiver na lista, imprime as suas coordenadas */
        if(procura_paragem(nome, topo_p) == 1)
            imprime_coord(nome, topo_p);

        /* Se a paragem nao estiver na lista, emite uma mensagem de erro */
        else
            printf("%s: no such stop.\n", nome);
        
    }

    /* Verifica se o input tem quatro palavras */
    if(conta_palavras(input) == 4){

        /* Se nao ha aspas no comando, le normalmente */
        if(aspas(input)==0)
            i = sscanf(input, "%c %s %lf %lf", 
                &command, nome, &latitude, &longitude);
        
        /* Se ha aspas no comando, le com sscanf para uma string delimitada 
        por aspas */
        else
            i = sscanf(input, "%c \"%[^\"]\" %lf %lf", 
                &command, nome, &latitude, &longitude);
        
        /* Verifica se a leitura foi bem sucedida */
        if(i != 4){
            free(nome);
            return;
        }

        /* Se a paragem estiver na lista, emite uma mensagem de erro */
        if(procura_paragem(nome, topo_p) == 1)
            printf("%s: stop already exists.\n", nome);

        /* Se a paragem nao estiver na lista, adiciona-a */
        else{
            adiciona_paragem(nome, latitude, longitude, topo_p, topo_c);
            return;
        }
    }
    /* Liberta a memoria alocada para a string */
    free(nome);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_l
| Tipo: void
| Argumentos: char input[INPUT], lista_carreiras *topo_c, 
| lista_paragens *topo_p
| Funcao: Funcao responsavel por lidar com os comandos das ligacoes
+----------------------------------------------------------------------------*/

void comandos_l(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p){
    
    char command = '\0';
    char *carreira = NULL;
    char *origem = NULL;
    char *destino = NULL;
    int tamanho_carreira = 0, tamanho_origem = 0, tamanho_destino = 0;
    double custo = 0;
    double duracao = 0;
    int i = 0;

    /* Verifica se o input tem 6 palavras */
    if(conta_palavras(input) != 6)
        return;

    /* Verifica que nao ha palavras com aspas no meio */
    if(verifica_aspas_no_meio(input)!=1)
        return;

    /* Encontra o tamanho das strings */
    tamanho_carreira = tamanho_palavra(input, 2) + 1;
    tamanho_origem = tamanho_palavra(input, 3) + 1;
    tamanho_destino = tamanho_palavra(input, 4) + 1;

    /* Aloca a memoria necessaria para as strings */
    carreira = (char*) malloc((tamanho_carreira) * sizeof(char));       
    erro_alocacao_s(carreira, topo_c, topo_p);
    memset(carreira, 0, tamanho_carreira * sizeof(char));

    origem = (char*) malloc((tamanho_origem) * sizeof(char));        
    erro_alocacao_s(origem, topo_c, topo_p);
    memset(origem, 0, tamanho_origem * sizeof(char));
        
    destino = (char*) malloc((tamanho_destino) * sizeof(char));
    erro_alocacao_s(destino, topo_c, topo_p);
    memset(destino, 0, tamanho_destino * sizeof(char));

    /* Se nao ha aspas no comando, le normalmente */
    if(aspas(input) == 0)
        i = sscanf(input, "%c %s %s %s %lf %lf", &command, carreira, origem,
            destino, &custo, &duracao);

    /* Se ha duas aspas no comando, le com sscanf para uma string delimitada 
    por aspas na posicao de origem */
    else if(aspas(input) == 2){
        i = sscanf(input, "%c %s \"%[^\"]\" %s %lf %lf", &command, carreira, 
            origem, destino, &custo, &duracao);

        /* Caso a leitura nao tenha sido bem-sucedida, le com sscanf para uma 
        string delimitada por aspas na posicao de destino */
        if(i!=6)
            i = sscanf(input, "%c %s %s \"%[^\"]\" %lf %lf", &command, carreira, 
            origem, destino, &custo, &duracao);
    }

    /* Se o input contem quatro aspas, faz a leitura do input com aspas */
    else if(aspas(input) == 4)
        i = sscanf(input, "%c %s \"%[^\"]\" \"%[^\"]\" %lf %lf", &command, 
            carreira, origem, destino, &custo, &duracao);
    
    /* Verifica se a leitura foi bem sucedida */
    if(i != 6){
        free(carreira);
        free(destino);
        free(origem);
        return;
    }

    /* Verifica se a carreira existe */
    if(procura_carreira(carreira, topo_c) != 1){
        printf("%s: no such line.\n", carreira);
        free(carreira);
        free(destino);
        free(origem);
        return;
    }
        
        
    /* Verifica se a paragem de origem existe */
    if(procura_paragem(origem, topo_p) != 1){
        printf("%s: no such stop.\n", origem);
        free(carreira);
        free(destino);
        free(origem);
        return;
    }
    
    /* Verifica se a paragem de destino existe */
    if(procura_paragem(destino, topo_p) != 1){
        printf("%s: no such stop.\n", destino);
        free(carreira);
        free(destino);
        free(origem);
        return;
    }

    /* Verifica se o custo e a duração são positivos */
    if(custo < 0 || duracao < 0){
        printf("negative cost or duration.\n");
        free(carreira);
        free(destino);
        free(origem);
        return;
    }
            
    /* Adiciona a ligacao */
    else
        adicionar_ligacao(carreira, origem, destino, custo, duracao, 
            topo_c, topo_p);

    /* Liberta a memoria alocada para a string */
    free(carreira);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_i
| Tipo: void
| Argumentos: lista_paragens *topo_p
| Funcao: Funcao responsavel por imprimir as informacoes das paragens que estao 
| presentes em mais de uma carreira
+----------------------------------------------------------------------------*/

void comandos_i(lista_paragens *topo_p){
    
    lista_paragens *aux_p = topo_p->prox_p;

    /* Percorre a lista de paragens */
    while(aux_p != NULL){

        /* Verifica se a paragem esta presente em mais do que uma carreira */
        if(aux_p->paragem.num_carreiras > 1){

            /* Imprime o nome e o numero de carreiras da paragem */
            printf("%s %d: ",aux_p->paragem.nome, aux_p->paragem.num_carreiras);
            /* Imprime o nome das carreiras que contem a paragem */
            imprime_carreiras_intersecao(aux_p->paragem);
        }           
        aux_p = aux_p -> prox_p;
    }
}

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_r
| Tipo: void
| Argumentos: char input[INPUT], lista_carreiras *topo_c
| Funcao: Funcao responsavel por apagar uma carreira.
+----------------------------------------------------------------------------*/

void comandos_r(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p){
    
    char command = '\0';
    char *nome = NULL;
    int tamanho_nome = 0;
    int i = 0;

    /* Verifica se o input tem duas palavras */
    if(conta_palavras(input) != 2)
        return;

    /* Encontra o tamanho da string */
    tamanho_nome = tamanho_palavra(input, 2) + 1;

    /* Aloca a memoria necessaria para a string */
    nome = (char*) malloc(tamanho_nome * sizeof(char));         
    erro_alocacao_s(nome, topo_c, topo_p);
    memset(nome, 0, tamanho_nome * sizeof(char));

    /* Le o comando e o nome da carreira */
    i = sscanf(input, "%c %s", &command, nome);

    /* Verifica se a leitura foi bem sucedida */
    if(i != 2){   
        free(nome);        
        return;
    }
    /* Se a carreira estiver na lista, apaga-a */
    if(procura_carreira(nome, topo_c) == 1){
        apaga_carreira(nome, topo_c);
        apaga_carreira_das_paragens(nome, topo_p);
    }
    /* Se a carreira nao estiver na lista, emite uma mensagem de erro */
    else
        printf("%s: no such line.\n", nome);
    
    /* Liberta a memoria alocada para a string */
    free(nome);
}


/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_e
| Tipo: void
| Argumentos: char input[INPUT], lista_carreiras *topo_c
| Funcao: Funcao responsavel por apagar uma paragem.
+----------------------------------------------------------------------------*/

void comandos_e(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p){
    
    char command = '\0';
    char *nome = NULL;
    int tamanho_nome = 0;
    int i = 0;

    /* Verifica se o input tem duas palavras */
    if(conta_palavras(input) != 2)
        return;

    /* Verifica se o nome da paragem nao tem aspas no meio */
    if(verifica_aspas_no_meio(input)!=1)
        return;

    /* Encontra o tamanho da string */
    tamanho_nome = tamanho_palavra(input, 2) + 1;

    /* Aloca a memoria necessaria para a string */
    nome = (char*) malloc(tamanho_nome * sizeof(char));         
    erro_alocacao_s(nome, topo_c, topo_p);
    memset(nome, 0, tamanho_nome * sizeof(char));

    /* Se nao ha aspas no comando, le normalmente */
    if(aspas(input) == 0)
        i = sscanf(input, "%c %s", &command, nome);
        
    /* Se ha aspas no comando, le com sscanf para uma string delimitada 
    por aspas*/
    else
        i = sscanf(input, "%c \"%[^\"]\"", &command, nome);
    
    /* Verifica se a leitura foi bem sucedida */
    if(i != 2){     
        free(nome);      
        return;
    }

    /* Se a paragem estiver na lista, apaga-a */
    if(procura_paragem(nome, topo_p) == 1){
        apaga_paragem(nome, topo_p);
        apaga_ligacao(nome, topo_c, topo_p);
    }
    /* Se a paragem nao estiver na lista, emite uma mensagem de erro */
    else
        printf("%s: no such stop.\n", nome);
    
    /* Liberta a memoria alocada para a string */
    free(nome);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_q
| Tipo: void
| Argumentos: lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por libertar toda a memoria e sair do programa
+----------------------------------------------------------------------------*/

void comandos_q(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p){

    /* Verifica se o input tem 1 palavras */
    if(conta_palavras(input) != 1)
        return;

    /* Liberta a memoria alocada para as listas*/
    free_memoria(topo_c, topo_p);
    exit(0);
}

/*-----------------------------------------------------------------------------
| Nome da funcao: comandos_a
| Tipo: int
| Argumentos: lista_carreiras *topo_c, lista_paragens *topo_p
| Funcao: Funcao responsavel por libertar toda a memoria. Retorna 1 caso a 
| memoria tenha sido libertado e 0 caso contrario.
+----------------------------------------------------------------------------*/

int comandos_a(char input[INPUT], lista_carreiras *topo_c, 
    lista_paragens *topo_p){

    /* Verifica se o input tem 1 palavras */
    if(conta_palavras(input) != 1)
        return 0;

    /* Liberta a memoria alocada para as listas*/
    free_memoria(topo_c, topo_p);
    return 1;
}

