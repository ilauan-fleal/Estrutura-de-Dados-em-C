#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//LISTA ENCADEADA PARA INSERIR NOME DE PESSOAS!


struct No{
    char nomes;
    struct No* Proximo;
    
};


typedef struct No no;
int tam = 1;


void InicializaLista(no * LISTA){
    LISTA->Proximo = NULL;

}

//CRIANDO FUNÇÃO PARA VERIFICAR ITENS DA LISTA PREENCHIDOS!

int VerificaListaVazia(no * LISTA){
    if(LISTA->Proximo == NULL){
        return 1;
    }else{
        return 0;
    }
}

//CRIANDO FUNÇÃO PARA INSERIR NÓ NO INÍCIO DA LISTA

void InserirElementoNoInicio(no * LISTA){
    no * NovoNo = (no*)malloc(sizeof(no));
    if(NovoNo == NULL){
        printf("Full memory!\n");
        exit(EXIT_FAILURE);
    }
    printf("ELEMENTO:\n");
    fflush(stdin);
    scanf("%c", &NovoNo->nomes);
    no * HEAD = LISTA->Proximo;
    LISTA->Proximo = NovoNo;
    NovoNo->Proximo = HEAD;
    tam++;
   

}

//CRIANDO FUNÇÃO PARA INSERIR NÓ NO FINAL DA LISTA

void InserirElementoNoFinal(no * LISTA){
    no * NovoNO = (no*)malloc(sizeof(no));
    if(NovoNO == NULL){
        printf("Full memory!\n");
        exit(EXIT_FAILURE);
    }

    
    printf("ELEMENTO:\n");
    fflush(stdin);
    scanf("%c", &NovoNO->nomes);
    NovoNO->Proximo = NULL;
    if(VerificaListaVazia(LISTA))
        LISTA->Proximo = NovoNO;
    
    else{

        no * temp = LISTA->Proximo;

        while(temp->Proximo != NULL)


            temp = temp->Proximo;
    

    temp->Proximo = NovoNO;
    tam++;
    

}
    
}

//CRIANDO FUNÇÃO PARA EXIBIR OS ELEMENTOS

void ExibirOsElementos(no * LISTA){
    if(VerificaListaVazia(LISTA)){

        printf("LISTA VAZIA!\n");

    }
    no * temp = LISTA->Proximo;
    while(temp != NULL){
        printf("%c\n", temp->nomes);
        temp = temp->Proximo;
    }
    printf("\n\n");
    

}

//CRIANDO FUNÇÃO PARA LIBERAR OS NÓS!!

void LiberarLista(no * LISTA){
    if(!VerificaListaVazia(LISTA)){
        no * NoProx, *atual;
            while(atual != NULL){
                NoProx = atual->Proximo;
                free(atual);
                atual = NoProx;
            }

    }
    printf("Lista vazia!\n");
}

//CRIANDO FUNÇÃO PARA REMOVER PRIMEIRO NÓ(DO INÍCIO)

no * RetiraInicio(no * LISTA){
    if(VerificaListaVazia(LISTA)){
        printf("LISTA VAZIA!\n");
    }
    else{
        no * temp = LISTA->Proximo;
        LISTA->Proximo = temp->Proximo;
        tam--;
        return temp;
        
    }
    
}

//CRIANDO FUNÇÃO PARA REMOVER ÚLTIMO NÓ(DO FINAL)

no * RetiraDoFinal(no * LISTA){
    if(VerificaListaVazia(LISTA)){
        printf("Lista Vazia!\n");
    }
    else{
        no * ultimo = LISTA->Proximo;
        no * penultimo = LISTA;
        while(ultimo->Proximo != NULL){
            penultimo = ultimo;
            ultimo = ultimo->Proximo;
        }
        penultimo->Proximo = NULL;
        tam--;
        return ultimo;
        
    }
   
}



//ADICIONANDO FUNÇÃO PARA INSERIR UM ELEMENTO NUMA POSIÇÃO QUALQUER DA LISTA

void Inserir(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    int contagem, posicao;
    printf("Informe a posição, na qual deseja inserir o elemento?\n");
    scanf("%d", &posicao);
    if(posicao > 0 && posicao <= tam){
        if(posicao == 1){
            InserirElementoNoInicio(LISTA);

        }
        else{
            no * atual = LISTA->Proximo;
            no *anterior = LISTA;
            //ALOCAÇÃO DINÂMICA DE PONTEIRO!
            no * NovoNO = (no*)malloc(sizeof(no));
            printf("Digite o elemento que deverá ser inserido:\n");
            scanf("%s", &NovoNO->nomes);
            for(contagem = 1; contagem < posicao; contagem++){
                anterior = atual;
                atual = atual->Proximo;
            }
            anterior->Proximo = NovoNO;
            NovoNO->Proximo = atual;
            tam++;

        }
    }
    else{
        printf("POSIÇÃO INEXISTENTE NA LISTA!\n");
        
    }

}

//ADICIONANDO FUNÇÃO PARA RETIRAR UM ELEMENTO DE UMA POSIÇÃO QUALQUER

no * Retira(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    if(VerificaListaVazia(LISTA)){
        printf("Lista vazia!\n");

    }
    
    int contagem, posicao;
    printf("Escolha uma posição , na qual deseja remover o nó:\n");
    scanf("%d", &posicao);
    
    
    if(posicao > 0 && posicao <= tam){
        if(posicao == 1){

            return RetiraInicio(LISTA);
        }
        else{
            no * atual = LISTA->Proximo;
            no * anterior = LISTA;
            for(contagem = 1; contagem < posicao; contagem++){
                anterior = atual;
                atual = atual->Proximo;
            }
            anterior->Proximo = atual->Proximo;
            tam--;
            return atual;

        }

    }else{
        printf("POSIÇÃO INEXISTENTE NA LISTA.\n");
        return NULL;
    }


}

//BLOCO MAIN

int main(){
    
    setlocale(LC_ALL, "Portuguese");
    no * LISTA;
    no * temp;
    LISTA = (no*)malloc(sizeof(no));
    if(LISTA == NULL){
        printf("Ponteiro não alocado!\n");
        exit(EXIT_FAILURE);
    }
    printf("Bem-vindo ao programa de lista encadeada em C!\n");
    printf("Escolha uma das opções abaixo:\n");
    int escolha, posicao;
   
    do{
        printf("1. Inserir Elemento no início!\n");
        printf("2. Inserir Elemento no final da lista!\n");
        printf("3. Exibir  Elementos da lista!\n");
        printf("4. Zerar a lista!\n");
        printf("5. Remover nó do início!\n");
        printf("6. Remover nó do fim!\n");
        printf("7. Inserir Elemento em uma posição qualquer:\n");
        printf("8. Remover Elemento de uma posição qualquer:\n");
        printf("0. Para sair!\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
            InserirElementoNoInicio(LISTA);
            break;
            case 2:
            InserirElementoNoFinal(LISTA);
            break;
            case 3:
            ExibirOsElementos(LISTA);
            break;
            case 4:
            LiberarLista(LISTA);
            InicializaLista(LISTA);
            break;
            case 5:            
            temp = RetiraInicio(LISTA);
            printf("Nó removido do início: %c\n", temp->nomes);
            break;
            case 6:
            temp = RetiraDoFinal(LISTA);
            printf("Nó removido do final: %c\n", temp->nomes);
            break;
            case 7:
            Inserir(LISTA);
            break;
            case 8:
            temp = Retira(LISTA);
            printf("O elemento %c foi retirado da posição em questão\n", temp->nomes);
            break;
            case 0:
            printf("Saindo...\n");
            exit(EXIT_SUCCESS);
            default:
            printf("Opção não válida!\n");
            exit(EXIT_FAILURE);
        }
    }while(escolha != 0);

}