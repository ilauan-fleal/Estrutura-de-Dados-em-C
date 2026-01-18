#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



//CRIANDO ESTRUTURA DO TIPO PILHA EM C

struct No{
    int number;
    struct No * Prox;
};
typedef struct No no;

//CRIANDO FUNÇÃO PARA INICIALIZAR A PILHA!

void Inicializa(no * PILHA){
    PILHA->Prox = NULL;
}

//CRIANDO FUNÇÃO PARA VERIFICAR PILHA VAZIA!

int VerificaPilha(no * PILHA){
    if(PILHA->Prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

//CRIANDO FUNÇÃO PARA INSERIR ELEMENTO NA PILHA!

void Push(no * PILHA){
    no * NovoNO = (no*)malloc(sizeof(no));
    printf("ELEMENTO:\n");
    scanf("%d", &NovoNO->number);
    no * temp = PILHA->Prox;
    PILHA->Prox = NovoNO;
    NovoNO->Prox = temp;
}

//CRIANDO FUNÇÃO PARA REMOVER ELEMENTO DA PILHA!    

no * Pop(no * PILHA){
    if(VerificaPilha(PILHA)){
        printf("Pilha vazia!\n");
    }else{
        no * temp = PILHA->Prox;
        PILHA->Prox = temp->Prox;
        return temp;
    }
}

//CRIANDO FUNÇÃO PARA EXIBIR OS ELEMENTOS DA PILHA!

void Exibir(no * PILHA){
    if(VerificaPilha(PILHA)){
        printf("Pilha vazia!\n");
    }else{
        no * temp = PILHA->Prox;
        while(temp != NULL){
            printf("%d\n", temp->number);
            temp = temp->Prox;
        }
    }
}

//CRIANDO FUNÇÃO PARA ZERAR A LISTA

void Zerar(no * PILHA){
    if(!VerificaPilha(PILHA)){
        no * atual = PILHA->Prox;
        no * NoProx;
        while(atual != NULL){
            NoProx = atual->Prox;
            free(atual);
            atual = NoProx;
        }
    }
}



//BLOCO MAIN

int main(){
    setlocale(LC_ALL, "Portuguese");
    no * PILHA, *temp;
    PILHA = (no*)malloc(sizeof(no));
    
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
            temp = Pop(PILHA);
            printf("Nó removido %d\n", temp->number);
            break;
            case 3:
            Exibir(PILHA);
            break;
            case 4:
            Zerar(PILHA);
            Inicializa(PILHA);
            break;
        }
       
            

        }while(escolha != 0);

}



