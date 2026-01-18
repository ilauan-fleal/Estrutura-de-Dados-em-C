#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


struct No{
    char * Nomenclatura;
    struct No * Proximo;
};

typedef struct No no;
int tam = 1;

//DEFININDO FUNÇÃO PARA INICIALIZAR LISTA

int InicializaLista(no * LISTA){
    LISTA->Proximo = NULL;

}

//CRIANDO FUNÇÃO PARA VERIFICAR LISTA VAZIA!

int VerificaLista(no * LISTA){
    if(LISTA->Proximo == NULL){
        return 1;
    }else{
        return 0;
    }

}

//CRIANDO FUNÇÃO PARA INSERIR ELEMENTO NO INÍCIO

void InserirInicio(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    no * NovoNo = (no*)malloc(sizeof(no));
    if(NovoNo == NULL){
        printf("Ponteiro não alocado!\n");
        exit(EXIT_FAILURE);
    }
    printf("ELEMENTO:\n");
    scanf("%s", &NovoNo->Nomenclatura);
    no * Nohead = LISTA->Proximo;
    LISTA->Proximo = NovoNo;
    NovoNo->Proximo = Nohead;
    tam++;
}



//CRIANDO FUNÇÃO PARA INSERIR ELEMENTO EM QUALQUER POSIÇÃO!


void Inserir(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    no * NovoNO = (no*)malloc(sizeof(no));
    if(NovoNO == NULL){
        printf("Ponteiro não alocado!\n");

    }
    int pos, contagem;
    printf("Escolha a posição, na qual deseja inserir o elemento:\n");
    scanf("%d", &pos);
    
    if(pos > 0  && pos <= tam){
        if(pos == 1){
            InserirInicio(LISTA);

        }
        else{
            no * atual = LISTA->Proximo;
            no * anterior = LISTA;
            printf("ELEMENTO PARA INSERIR:\n");
            scanf("%s", &NovoNO->Nomenclatura);
            for(contagem = 1; contagem < pos ; contagem++){
                anterior = atual;
                atual = atual->Proximo;
            }
            anterior->Proximo = NovoNO;
            NovoNO->Proximo = atual;
            tam++;
        }

    }else{
        printf("POSIÇÃO INVÁLIDA!\n");
    }
}

//CRIANDO FUNÇÃO PARA INSERIR NO FINAL


void InserirFim(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    no * NovoNo = (no*)malloc(sizeof(no));
    if(NovoNo == NULL){
        printf("Full memory!\n");
    }
    printf("ELEMENTO:\n");
    scanf("%s",  &NovoNo->Nomenclatura);
    NovoNo->Proximo = NULL;
    if(VerificaLista(LISTA)){
        LISTA->Proximo = NovoNo;
    }
    
    else{

        no * atual = LISTA->Proximo;

        while(atual->Proximo != NULL){

            atual = atual->Proximo;

    }

    
    atual->Proximo = NovoNo;
    tam++;

}
  

}

//CRIANDO FUNÇÃO PARA REMOVER ELEMENTO DO INÍCIO

no * RemoverInicio(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    if(VerificaLista(LISTA)){
        printf("Lista vazia!\n");
    }
    no * anterior = LISTA;
    no * atual = LISTA->Proximo;
    anterior->Proximo = atual->Proximo;
    tam--;
    return atual;
    
}

//CRIANDO FUNÇÃO PARA REMOVER ELEMENTO DE UMA DADA POSIÇÃO

no * Remover(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    if(VerificaLista(LISTA)){
        printf("LISTA VAZIA!\n");
    }
    
    int pos, contagem;
    printf("Selecione uma posição, para remover o nó!\n");
    scanf("%d", &pos);
    if(pos > 0 && pos <= tam){
        if(pos == 1){
            return RemoverInicio(LISTA);
        }
        else{
            no * atual = LISTA->Proximo;
            no * anterior = LISTA;
            for(contagem = 1; contagem < pos; contagem++){
                anterior = atual;
                atual = atual->Proximo;
            }
            anterior->Proximo = atual->Proximo;

            tam--;
            return atual;
        
        }

    }else{
        printf("POSIÇÃO INEXISTENTE!\n");

    }

}

//CRIANDO FUNÇÃO PARA REMOVER ELEMENTO DO FINAL

no * RemoverFim(no * LISTA){
    if(VerificaLista(LISTA)){
        printf("LISTA VAZIA!\n");
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


//CRIANDO FUNÇÃO PARA EXIBIR OS ELEMENTOS DA LISTA

void ExibirElementos(no * LISTA){
    if(VerificaLista(LISTA)){
        printf("Lista vazia!\n");
    }
    no * atual = LISTA->Proximo;
    while(atual != NULL){
        printf("%s\n", &atual->Nomenclatura);
        atual = atual->Proximo;
    }
    printf("\n\n");

}

//CRIANDO FUNÇÃO PARA ZERAR ELEMENTOS

void ZerarElementos(no * LISTA){
    if(!VerificaLista(LISTA)){
        no * atual = LISTA->Proximo;
        no * NoProx;
        while(atual != NULL){
            NoProx = atual->Proximo;
            free(atual);
            atual = NoProx;
        }
    }
    printf("LISTA VAZIA!\n");
}


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
            printf("Elemento removido: %s\n", &temp->Nomenclatura);
            break;
            case 5:
            temp = RemoverFim(LISTA);
            printf("Elemento removido: %s\n", &temp->Nomenclatura);
            break;
            case 6:
            temp = Remover(LISTA);
            printf("Elemento removido: %s\n", &temp->Nomenclatura);
            break;
            case 7:
            ExibirElementos(LISTA);
            break;
            case 8:
            ZerarElementos(LISTA);
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
