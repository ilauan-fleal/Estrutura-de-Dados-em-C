#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//CRIANDO NOVA ESTRUTURA DO TIPO PILHA!


struct No{
    char caractere;
    struct No * Prox;
};

typedef struct No no;

//CRIANDO FUNÇÃO INICIALIZADORA DA PILHA

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

//CRIANDO FUNÇÃO PARA INSERIR ELEMENTO NA PILHA(PUSH)

void Push(no * PILHA){
    no * NovoNO = (no*)malloc(sizeof(no));
    if(NovoNO == NULL){
        printf("Full memory!\n");
        exit(EXIT_FAILURE);
    }
    printf("ELEMENTO:\n");
    fflush(stdin);
    scanf("%c", &NovoNO->caractere);
    NovoNO->Prox = NULL;
    if(VerificaPilha(PILHA)){
        PILHA->Prox = NovoNO;
    }else{
        no * temp = PILHA->Prox;
        while(temp->Prox != NULL){
            temp = temp->Prox;
        }
        temp->Prox = NovoNO;
    }
}


//CRIANDO FUNÇÃO PARA REMOVER NÓ

no * RemoverFinal(no * PILHA){
    if(VerificaPilha(PILHA)){
        printf("Pilha vazia!\n");

    }else{
        no * anterior = PILHA;
        no * sucessor = PILHA->Prox;
        while(sucessor->Prox != NULL){
            anterior = sucessor;
            sucessor = sucessor->Prox;
        }
        anterior->Prox = NULL;
        return sucessor;

    }

}

//CRIANDO FUNÇÃO PARA EXIBIR OS ELEMENTOS

void ExibirElementos(no * PILHA){
    if(VerificaPilha(PILHA)){
        printf("Pilha vazia!\n");
    }else{
        no * temp = PILHA->Prox;
        while(temp != NULL){
            printf("%c\n", temp->caractere);
            temp = temp->Prox;
        }
        printf("\n");
    }
}

//CRIANDO FUNÇÃO PARA ZERAR ELEMENTOS

void ZerarElementos(no * PILHA){
    if(!VerificaPilha(PILHA)){
        no * temp, *NoProx;
        while(temp != NULL){
            NoProx = temp->Prox;
            free(temp);
            temp = NoProx;
        }
    }
    printf("PILHA VAZIA!\n");
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
            printf("Nó removido %c\n", temp->caractere);
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

