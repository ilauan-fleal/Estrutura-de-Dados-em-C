#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



//CRIANDO ESTRUTURA DO TIPO FILA EM C

struct No{
    int number;
    struct No * Proximo;
};

typedef struct No no;

//CRIANDO CÓDIGO PARA INICIALIZAR A FILA

void InicializaFila(no * FILA){
    FILA->Proximo = NULL;
}

//CRIANDO CÓDIGO PARA VERIFICAR FILA VAZIA!

int VerificaFila(no * FILA){
    if(FILA->Proximo == NULL){
        return 1;
    }else{
        return 0;
    }
}

//CRIANDO CÓDIGO PARA INSERIR ELEMENTO NA ÚLTIMA POSIÇÃO DA FILA!

void Inserir(no * FILA){
    no * NovoNo = (no*)malloc(sizeof(no));
    NovoNo->Proximo = NULL;
    printf("ELEMENTO:\n");
    scanf("%d", &NovoNo->number);
    no * temp = FILA->Proximo;
    if(VerificaFila(FILA)){
        FILA->Proximo = NovoNo;
    }else{
        no * temp = FILA->Proximo;
        while(temp->Proximo != NULL){
            temp = temp->Proximo;

        }
        temp->Proximo = NovoNo;

    }
    
}

//CRIANDO FUNÇÃO PARA REMOVER NÓ DO INÍCIO

no * RemoverInicio(no * FILA){
    if(VerificaFila(FILA)){
        printf("Fila vazia!\n");
    }else{
        no * temp = FILA->Proximo;
        FILA->Proximo = temp->Proximo;
        return temp;
        
    }

}

//FUNÇÃO PARA EXIBIR OS ELEMENTOS

void Exibir(no * FILA){
    if(VerificaFila(FILA)){
        printf("Fila vazia!\n");

    }else{
        no * temp = FILA->Proximo;
        while(temp != NULL){
            printf("%d\n", temp->number);
            temp = temp->Proximo;
        }
    }
}

//CRIANDO FUNÇÃO PARA ZERAR OS ELEMENTOS

void Zerar(no * FILA){
    if(!VerificaFila(FILA)){
        no * temp = FILA->Proximo;
        no * NoProx;
        while(temp != NULL){
            NoProx = temp->Proximo;
            free(temp);
            temp = NoProx;
        }
    }
    printf("Fila vazia!\n");
}

//BLOCO MAIN!!



int main(){
    setlocale(LC_ALL, "Portuguese");
    no * FILA, *temp;
    FILA = (no*)malloc(sizeof(no));
    printf("Bem-vindo ao código da fila em C!\n");
    printf("Escolha uma opção abaixo!\n");
    int escolha;
    do{
        printf("1. Inserir elemento(última posição)!\n");
        printf("2. Remover elemento da primeira posição!\n");
        printf("3. Exibir fila!\n");
        printf("4. Zerar fila!\n");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
            Inserir(FILA);
            break;
            case 2:
            temp = RemoverInicio(FILA);
            printf("Nó removido %d\n", temp->number);
            break;
            case 3:
            Exibir(FILA);
            break;
            case 4:
            Zerar(FILA);
            InicializaFila(FILA);
            break;
            default:
            printf("Valor inválido!\n");
            exit(EXIT_FAILURE);
        }

    }while(escolha !=  0);


}