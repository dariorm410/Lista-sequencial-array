/******************************************************************
* Aluno: Dário Ribieiro Maracajá;                                 *
* Matrícula: 20180115826;                                         *
* Exercício 1 - Listas sequencial					              *
/*****************************************************************/

#include <stdio.h>


struct lista {
int control;        //controle de ocupação da lista - informa se a lista está vazia (-1)
                    //ou ocupada (contendo a posição do último elemento da lista no vetor)
int info[10];     //vetor que armazena os dados da lista.
};

int lista_vazia (struct lista);              //esvazia a lista
int lista_cheia (struct lista);               //verifica se a lista está cheia
int insere_lista (struct lista *, int);       //insere um valor no final da lista
void cria_lista (struct lista *);              //cria uma lista. definindo o valor da variavel de controle como -1 lista vazia
int remove_ultimo_valor (struct lista *);       //remove o último dado válido da lista
void imprime_lista (struct lista);               //exibe o tamanho da lista na tela
void limpa_lista (struct lista *);             //limpa a lista. definindo o valor da variavel de controle como -1 lista vazia (faz a mesma coisa que a função cria_lista)

int main() {
    struct lista L1; //declara a lista para reservar espaço na memória;
    cria_lista(&L1);   //cria a lista

    //verifica se a lista está vazia e exibe na tela o resultado
    //se estiver vazia, é pq a lista foi criada com sucesso na função anterior, do contrário a lista não foi criada com sucesso.
    if(lista_vazia(L1))
        printf("LISTA VAZIA\n\n");
    else{
        printf("LISTA NÃO VAZIA\n\n");
    }

    int valor;  //variável para armazenar o valor que será capturado pelo usuário.
    for (int i=0; i<10; i++) 
    {  //laço para preencher toda a lista
        printf("Digite o %d º valor inteiro para ser adicionado a lista: ", i+1);
        scanf("%d", &valor);  //captura, do usuário, um valor a ser adicionado à lista e o armazena na variável "valor";
        if (insere_lista(&L1, valor)) // adiciona à lista o valor capturado - está dentro de um if para saber se foi ou não adicionado com sucesso, e informa na tela o resultado.
            printf("Valor %d adicionado com sucesso ao final da lista!\n\n", valor);
        else {//caso a lista esteja cheia encerra o programa.
            printf("Lista cheia, o valor %d nao pode ser adicionado a lista!", valor);
            return 0;
        }

    }

    //verifica se a lista está cheia e exibe na tela o resultado - se estiver cheia, o laço for anterior funcionou com sucesso.
     if(lista_cheia(L1))
        printf("LISTA CHEIA\n\n");
    else{
        printf("LISTA NÃO CHEIA\n\n");
    }

    imprime_lista(L1); //exibe a lista na tela

    remove_ultimo_valor(&L1); //remove o último ítem da lista

    printf("\nLista apos ser retirado o ultimo item:\n");
    imprime_lista(L1);

        
    printf("Programa finalizado com sucesso!\n");

return 0;
}

///----FUNÇÕES----///

//VERIFICA SE A LISTA ESTÁ VAZIA E RETORNA 1 (SE SIM), OU 0 (SE NÃO).

int lista_vazia (struct lista lst) {
    if (lst.control == -1)
        return 1;
    else
        return 0;
}

//VERIFICA SE A LISTA ESTÁ CHEIA E RETORNA 1 (SE SIM), OU 0 (SE NÃO).
int lista_cheia (struct lista lst) {
    if (lst.control == 10-1) // lista tem 10 elementos
        return 1;
    else
        return 0;
}

//INSERE UM VALOR NA PRÓXIMA POSIÇÃO VAZIA DA LISTA E RETORNA "1" (SE FOI INSERIDO COM SUCESSO), OU "0" CASO A LISTA JA ESTEJA CHEIA E NÃO POSSA INSERIR MAIS NENHUM DADO.
int insere_lista (struct lista *lst, int y) {
    if (lista_cheia(*lst))
        return 0;
    else {
        lst -> info[(lst->control) + 1] = y; //insere o valor "y" na próxima posição vazia da lista.
        lst -> control++; //adiciona o valor à lista incrementando a variável de controle em +1.
        return 1;
    }
}

//CRIA UMA LISTA, DEFININDO A VARIÁVEL DE CONTROLE DA LISTA (lst.control) COM -1 (VALOR QUE DEFINE A LISTA COMO VAZIA);
void cria_lista (struct lista *lst) {
    lst->control = -1;
}

//REMOVE O ÚLTIMO VALOR VÁLIDO DA LISTA - CASO A LISTA JÁ ESTEJA VAZIA RETORNA FALSO (0) E NÃO FAZ NADA,
//DO CONTRÁRIO, DECREMETA A VARIÁVEL DE CONTROLE DA LISTA EM 1 E RETORNA TRUE (1)
int remove_ultimo_valor (struct lista *lst) {
    if (lista_vazia(*lst))
        return 0;
    else {
        lst->control--;
        return 1;
    }
}

//EXIBE A LISTA NA TELA
void imprime_lista (struct lista lst){
    if (lista_vazia(lst))
        printf("\nLISTA VAZIA!!!\n");
    else {
          for (int i=0; i<=lst.control; i++) {
              printf("Item %d: %d\n", i+1, lst.info[i]);
          };
    }
}



//LIMPA A LISTA, OU SEJA, REINICIALIZA DO VALOR DA VARIÁVEL DE CONTROLE COMO -1 (VAZIA)
//tal como a esvazia lista
void limpa_lista (struct lista *lst) {
    lst->control = -1;
}
