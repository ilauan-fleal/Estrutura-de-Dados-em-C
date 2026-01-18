#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct No{
    
    float number;
    struct No * Proximo;
};

typedef struct No no;
int tam = 1;

//CONSTRUINDO FUNÇÃO PARA INICIALIZAR A LISTA

int InicializaLista(no * LISTA){
    LISTA->Proximo = NULL;

}

//CONSTRUINDO FUNÇÃO PARA VERIFICAR SE A LISTA ESTÁ VAZIA

int ListaVazia(no * LISTA){
    if(LISTA->Proximo == NULL){
        return 1;
    }else{
        return 0;
    }
}


//CRIANDO FUNÇÃO PARA INSERIR ELEMENTO NO INÍCIO

void InserirInicio(no * LISTA){
    no * NovoNO = (no*)malloc(sizeof(no));
    if(NovoNO == NULL){
        printf("Full memory!\n");
        exit(EXIT_FAILURE);
    }
    printf("ELEMENTO:\n");
    scanf("%f", &NovoNO->number);
    no * Nohead = LISTA->Proximo;
    LISTA->Proximo = NovoNO;
    NovoNO->Proximo = Nohead;
    tam++;
}

//CRIANDO FUNÇÃO PARA INSERIR ELEMENTO NO FINAL DA LISTA ENCADEADA!

void InserirFim(no * LISTA){
    no * NovoNO = (no*)malloc(sizeof(no));
    if(NovoNO == NULL){
        printf("Full memory!\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Elemento:\n");
    scanf("%f", &NovoNO->number);
    NovoNO->Proximo = NULL;
    if(ListaVazia(LISTA)){
        LISTA->Proximo = NovoNO;
    }
    no * temp = LISTA->Proximo;
    while(temp->Proximo != NULL){
        temp = temp->Proximo;

    }
    temp->Proximo = NovoNO;
    tam++;
}

//CRIANDO UMA FUNÇÃO PARA INSERIR ELEMENTO EM QUALQUER POSIÇÃO

void Inserir(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    no * NovoNO = (no*)malloc(sizeof(no));
    int pos, contagem;
    if(NovoNO == NULL){
        printf("Full memory!\n");
        exit(EXIT_FAILURE);
    }
    printf("Selecione a posição para inserir o elemento:\n");
    scanf("%d", &pos);
    if(pos > 0 && pos <= tam){
        if(pos == 1){
            InserirInicio(LISTA);
        }
        printf("Elemento:\n");
        scanf("%f", &NovoNO->number);
        no * temp = LISTA->Proximo;
        no * anterior = LISTA;
        for(contagem = 1; contagem < pos; contagem++){
            anterior = temp;
            temp = temp->Proximo;

        }
        anterior->Proximo = NovoNO;
        NovoNO->Proximo = temp;
        tam++;
    }
    else{
        printf("Posição não encontrada!\n");
    }
    
    
}

//CRIANDO FUNÇÃO PARA REMOVER NÓ DO INÍCIO DA LISTA

no * RemoverInicio(no * LISTA){
    if(ListaVazia(LISTA)){
        printf("Lista vazia!\n");
    }
    no * temp = LISTA->Proximo;
    LISTA->Proximo = temp->Proximo;
    tam--;
    return temp;

}

//CRIANDO FUNÇÃO PARA REMOVER NÓ DO FINAL DA LISTA

no * RemoverFinal(no * LISTA){
    if(ListaVazia(LISTA)){
        printf("Lista vazia!\n");
    }
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

//CRIANDO FUNÇÃO PARA REMOVER ELEMENTO DE UMA DETERMINADA POSIÇÃO!

no * Remover(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    if(ListaVazia(LISTA)){
        printf("Lista vazia!\n");

    }
    int contagem , pos;
    printf("Escolha uma posição para remover o elemento:\n");
    scanf("%d", &pos);
    if(pos > 0 && pos <= tam){
        if(pos == 1){
            return RemoverInicio(LISTA);
        }
        no * atual = LISTA->Proximo;
        no * anterior = LISTA;
        for(contagem = 1; contagem < pos; contagem++){
            anterior = atual;
            atual = atual->Proximo;

        }
        anterior->Proximo = atual->Proximo;
        tam--;
        return atual;
    }else{
        printf("Posição não encontrada!\n");
    }
}

//CRIANDO FUNÇÃO PARA EXIBIR LISTA

void ExibirElementos(no * LISTA){
    if(ListaVazia(LISTA)){
        printf("Lista vazia!\n");
    }
    no * temp = LISTA->Proximo;
    while(temp != NULL){
        printf("%.2f\n\n", temp->number);
        temp = temp->Proximo;
    }
    printf("\n\n");
}

//CRIANDO A FUNÇÃO PARA ZERAR A LISTA!

void ZerarLista(no * LISTA){
    if(!ListaVazia(LISTA)){
        no * temp = LISTA->Proximo , * NoProx;
        while(temp != NULL){
            NoProx = temp->Proximo;
            free(temp);
            temp = NoProx;
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
            InserirInicio(LISTA);
            break;
            case 2:
            InserirFim(LISTA);
            break;
            case 3:
            Inserir(LISTA);
            break;
            case 4:
            temp = RemoverInicio(LISTA);
            printf("Elemento removido: %.2f\n", temp->number);
            break;
            case 5:
            temp = RemoverFinal(LISTA);
            printf("Elemento removido: %.2f\n", temp->number);
            break;
            case 6:
            temp = Remover(LISTA);
            printf("Elemento removido: %.2f\n", temp->number);
            break;
            case 7:
            ExibirElementos(LISTA);
            break;
            case 8:
            ZerarLista(LISTA);
            InicializaLista(LISTA);
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

