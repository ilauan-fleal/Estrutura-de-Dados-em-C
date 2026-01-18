#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//CRIANDO LISTA ENCADEADA PARA INSERIR CARACTERES

struct No{
    char letra;
    struct No * Proximo;

};

typedef struct No no;
int tam = 1;

//CRIANDO FUNÇÃO PARA INICIALIZAR LISTA ENCADEADA

void IniciaLista(no * LISTA){
    LISTA->Proximo = NULL;

}

//CRIANDO FUNÇÃO PARA VERIFICAR LISTA VAZIA!

int VerificaListaVazia(no * LISTA){
    if(LISTA->Proximo == NULL){
        return 1;
    }else{
        return 0;
    }
}

//CRIANDO FUNÇÃO PARA INSERIR ELEMENTO NO INÍCIO!

void InserirNoInicio(no * LISTA){
    no * NovoNO = (no*)malloc(sizeof(no));
    if(NovoNO == NULL){
        printf("Full memory!\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Elemento:\n");
    fflush(stdin);
    scanf("%c", &NovoNO->letra);
    no * NoHead = LISTA->Proximo;
    LISTA->Proximo = NovoNO;
    NovoNO->Proximo = NoHead;
    tam++;


}

//FUNÇÃO PARA INSERIR ELEMENTO EM UMA POSIÇÃO QUALQUER!

void Inserir(no * LISTA){
    int contagem, posicao;
    setlocale(LC_ALL, "Portuguese");
    printf("Selecione uma posição para inserir o elemento:\n");
    scanf("%d", &posicao);
    if(posicao > 0 && posicao <= tam){
        if(posicao == 1){
            InserirNoInicio(LISTA);
        }
        else{
            no * anterior = LISTA;
            no * atual = LISTA->Proximo;
            //AlOCAÇÃO DINÂMICA DE PONTEIRO
            no * NovoNo = (no*)malloc(sizeof(no));
            if(NovoNo == NULL){
                printf("Ponteiro não alocado!\n");
                exit(EXIT_FAILURE);
            }
            printf("ELEMENTO:\n");
            fflush(stdin);
            scanf("%c", &NovoNo->letra);
            for(contagem = 1; contagem < posicao; contagem++){
                anterior = atual;
                atual = atual->Proximo;
            }
            anterior->Proximo = NovoNo;
            NovoNo->Proximo = atual;
            tam++;
        }
    }else{
        printf("Posição inexistente na lista!\n");
    }

}

//CRIANDO FUNÇÃO PARA INSERIR ELEMENTO NO FINAL!

void InserirFinal(no * LISTA){
    no * NovoNo = (no*)malloc(sizeof(no));
    
    if(NovoNo == NULL){
        printf("Full memory!\n");

    }
    
    printf("Elemento:\n");
    fflush(stdin);
    scanf("%c", &NovoNo->letra);
    NovoNo->Proximo = NULL;

    if(VerificaListaVazia(LISTA))
        //O ELEMENTO JÁ É INSERIDO DIRETO NO FINAL!
        LISTA->Proximo = NovoNo;
    

    else{

        no * temp = LISTA->Proximo;

        while(temp->Proximo != NULL)

            temp = temp->Proximo;
    


    temp->Proximo = NovoNo;

    tam++;

}
  

}

//CRIANDO FUNÇÃO PARA RETIRAR NÓ DO INÍCIO


no * RemoverElementoDoInicio(no * LISTA){
    //VERIFICA SE A LISTA ESTÁ VAZIA!
    if(VerificaListaVazia(LISTA)){
        printf("Lista vazia!\n");
        return NULL;
    }
    no * temp = LISTA->Proximo;
    LISTA->Proximo = temp->Proximo;
    tam--;
    return temp;


}

//CRIANDO FUNÇÃO PARA REMOVER NÓ DO FINAL

no * RemoverElementoDoFinal(no * LISTA){
    if(VerificaListaVazia(LISTA)){
        printf("Lista Vazia!\n");
        return NULL;
    }
    no * penultimo = LISTA;
    no * ultimo = LISTA->Proximo;
    while(ultimo->Proximo != NULL){
        penultimo = ultimo;
        ultimo = ultimo->Proximo;


    }
    penultimo->Proximo = NULL;
    tam--;
    return ultimo;
}

//CRIANDO FUNÇÃO PARA REMOVER ELEMENTO DE UMA DETERMINADA POSIÇÃO

no * RemoverElemento(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    if(VerificaListaVazia(LISTA)){
        printf("LISTA VAZIA!\n");
    }
    int posicao, contagem;
    printf("Escolha uma posição para remover o elemento:\n");
    scanf("%d", &posicao);
    if(posicao > 0 && posicao <= tam){
        if(posicao == 1){
            return RemoverElementoDoInicio(LISTA);
        }
        else{
            no * anterior = LISTA;
            no * atual = LISTA->Proximo;
            for(contagem = 1; contagem < posicao; contagem++){
                anterior = atual;
                atual = atual->Proximo;

            }
            anterior->Proximo = atual->Proximo;
            tam--;
            return atual;
        }
    }else{
        printf("Posição inexistente na lista!\n");
    }
}

//CRIANDO FUNÇÃO PARA EXIBIR LISTA!!

void ExibirLista(no * LISTA){
    if(VerificaListaVazia(LISTA)){
        printf("Lista vazia!\n");
    }
    no * atual = LISTA->Proximo;
    while(atual != NULL){
        printf("%c\n", atual->letra);
        atual = atual->Proximo;
    }
    printf("\n\n");
}

//CRIANDO FUNÇÃO PARA ZERAR A LISTA!!

void ZerarLista(no * LISTA){
    if(!VerificaListaVazia(LISTA)){
        no * atual = LISTA->Proximo;
        no * NoProx;
        while(atual != NULL){
            NoProx = atual->Proximo;
            free(atual);
            atual = NoProx;

        }

    }
    printf("Lista Vazia!\n");
}


//BLOCO MAIN


int main(){
    setlocale(LC_ALL, "Portuguese");
    no * LISTA, *temp;
    LISTA = (no*)malloc(sizeof(no));
    if(LISTA == NULL){
        printf("Full memory!\n");

    }
    int escolha;
    printf("Bem-vindo ao programa de lista encadeada em C!\n");
    printf("Escolha uma das opções abaixo!\n");
    do{
        printf("1. Inserir elemento no início!\n");
        printf("2. Inserir elemento no final!\n");
        printf("3. Inserir elemento em uma posição qualquer!\n");
        printf("4. Remover elemento do início!\n");
        printf("5. Remover elemento do final!\n");
        printf("6. Remover elemento de uma posição qualquer!\n");
        printf("7. Exibir elementos da lista!\n");
        printf("8. Zerar a lista\n");
        printf("9. Tecla 0 para sair!\n");
        printf("ESCOLHA:\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
            InserirNoInicio(LISTA);
            break;
            case 2:
            InserirFinal(LISTA);
            break;
            case 3:
            Inserir(LISTA);
            break;
            case 4:
            temp = RemoverElementoDoInicio(LISTA);
            printf("Elemento removido: %c\n", temp->letra);
            break;
            case 5:
            temp = RemoverElementoDoFinal(LISTA);
            printf("Elemento removido: %c\n", temp->letra);
            break;
            case 6:
            temp = RemoverElemento(LISTA);
            printf("Elemento removido: %c\n", temp->letra);
            break;
            case 7:
            ExibirLista(LISTA);
            break;
            case 8:
            ZerarLista(LISTA);
            IniciaLista(LISTA);
            break;
            case 0:
            printf("Saindo...\n");
            exit(EXIT_SUCCESS);
            default:
            printf("Comando inválido!\n");
            exit(EXIT_FAILURE);
            

        }

    }while(escolha != 0);



}
