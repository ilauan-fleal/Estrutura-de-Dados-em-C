#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct No{
    int number;
    struct No * Proximo;
};

typedef struct No no;

//CRIANDO FUNÇÃO PARA INICIALIZAR A PILHA

int Inicializa(no * PILHA){
    PILHA->Proximo = NULL;

}

//CRIANDO FUNÇÃO PARA VERIFICAR SE A PILHA ESTÁ VAZIA!


int VerificaPilhaVazia(no * PILHA){
    if(PILHA->Proximo == NULL){
        return 1;
    }else{
        return 0;
    }
}

//CRIANDO FUNÇÃO PARA INSERIR ELEMENTO NA PILHA

void Push(no * PILHA){
    no * NovoNO = (no*)malloc(sizeof(no));
    if(NovoNO == NULL){
        printf("Full memory!\n");

    }
    printf("ELEMENTO:\n");
    scanf("%d", &NovoNO->number);
    NovoNO->Proximo = NULL;
    if(VerificaPilhaVazia(PILHA)){
        PILHA->Proximo = NovoNO;
    }
    else{
        no * temp = PILHA->Proximo;
        while(temp->Proximo != NULL){
            temp = temp->Proximo;
        }
        temp->Proximo = NovoNO;
       
    }

}

//CRIANDO FUNÇÃO PARA REMOVER NÓ

no * RemoverFinal(no * PILHA){
    if(VerificaPilhaVazia(PILHA)){
        printf("Lista vazia!\n");
    }
    no * ultimo = PILHA->Proximo;
    no * penultimo = PILHA;
    while(ultimo->Proximo != NULL){
        penultimo = ultimo;
        ultimo = ultimo->Proximo;
        
    }
    penultimo->Proximo = NULL;
   
    return ultimo;
}

//CRIANDO FUNÇÃO PARA EXIBIR A LISTA

void ExibirElementos(no * PILHA){
    if(VerificaPilhaVazia(PILHA)){
        printf("PILHA VAZIA!\n");
    }else{
        no * temp = PILHA->Proximo;
        while(temp != NULL){
            printf("%d\n", temp->number);
            temp = temp->Proximo;
        }
    }
}


//CRIANDO FUNÇÃO PARA ZERAR ELEMENTOS

void ZerarElementos(no * PILHA){
    if(!VerificaPilhaVazia(PILHA)){
        no * atual = PILHA->Proximo;
        no * NoProx;
        while(atual != NULL){
            NoProx = atual->Proximo;
            free(atual);
            atual = NoProx;
            
        }

    }
    printf("Pilha Vazia!\n");
}


int main(){
    setlocale(LC_ALL, "Portuguese");
    no * PILHA, *temp;
    PILHA = (no*)malloc(sizeof(no));
    if(PILHA == NULL){
        printf("Full memory!\n");

    }
    int escolha;
    printf("Bem-vindo ao programa de pilha em C!\n");
    printf("Escolha uma das opções abaixo!\n");
    do{
        printf("1. Inserir elementos(push)!\n");
        printf("2. Remover elemento(pop)\n");
        printf("3. Exibir Pilha!\n");
        printf("4. Zerar Pilha!\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
            Push(PILHA);
            break;
            case 2:
            temp = RemoverFinal(PILHA);
            printf("Nó removido %d\n", temp->number);
            break;
            case 3:
            ExibirElementos(PILHA);
            break;
            case 4:
            ZerarElementos(PILHA);
            Inicializa(PILHA);
            break;
        }
       
            

        }while(escolha != 0);

}

