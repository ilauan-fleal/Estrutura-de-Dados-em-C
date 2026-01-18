#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct No{
    int number;
    struct No * Proximo;
};

typedef struct No no;
int tam = 1;

//CRIANDO FUNÇÃO PARA INICIAR A LISTA

int InicializaLista(no * LISTA){
    LISTA->Proximo = NULL;

}

//CRIANDO FUNÇÃO PARA VERIFICAR SE A LISTA ESTÁ VAZIA!


int VerificaListaVazia(no * LISTA){
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
        printf("FULL MEMORY!\n");
    }
    printf("ELEMENTO:\n");
    scanf("%d", &NovoNO->number);
    no * NOhead = LISTA->Proximo;
    LISTA->Proximo = NovoNO;
    NovoNO->Proximo = NOhead;
    tam++;
}

//CRIANDO FUNÇÃO PARA INSERIR ELEMENTO NO FINAL

void InserirNoFim(no * LISTA){
    no * NovoNO = (no*)malloc(sizeof(no));
    if(NovoNO == NULL){
        printf("Full memory!\n");

    }
    printf("ELEMENTO:\n");
    scanf("%d", &NovoNO->number);
    NovoNO->Proximo = NULL;
    if(VerificaListaVazia(LISTA)){
        LISTA->Proximo = NovoNO;
    }
    else{
        no * temp = LISTA->Proximo;
        while(temp->Proximo != NULL){
            temp = temp->Proximo;
        }
        temp->Proximo = NovoNO;
        tam++;
    }

}

//CRIANDO FUNÇÃO PARA INSERIR ELEMENTO NUMA POSIÇÃO QUALQUER

void Inserir(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    no * NovoNO = (no*)malloc(sizeof(no));
    if(NovoNO == NULL){
        printf("Full memory!\n");
        exit(EXIT_FAILURE);
    }
    int contagem, posicao;
    printf("Selecione uma posição para inserir o elemento:\n");
    scanf("%d", &posicao);
    if(posicao > 0 && posicao <= tam){
        if(posicao == 1){
            InserirInicio(LISTA);
        }else{
            no * antecedente = LISTA;
            no * consequente = LISTA->Proximo;
            printf("ELEMENTO:\n");
            scanf("%d", &NovoNO->number);

            for(contagem = 1; contagem < posicao; contagem++){
                antecedente = consequente;
                consequente = consequente->Proximo;
            }
            antecedente->Proximo = NovoNO;
            NovoNO->Proximo = consequente;
            tam++;
           

        }

    }else{
        printf("Posição inexistente na lista!\n");
    }
}

//CRIANDO FUNÇÃO PARA REMOVER ELEMENTO DO INÍCIO DA LISTA!

no * RemoverInicio(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    if(VerificaListaVazia(LISTA)){
        printf("LISTA VAZIA!\n");
    }
    no * temp = LISTA->Proximo;
    LISTA->Proximo = temp->Proximo;
    tam--;
    return temp;
}


//CRIANDO FUNÇÃO PARA REMOVER ELEMENTO DO FIM DA LISTA

no * RemoverFim(no * LISTA){
    setlocale(LC_ALL , "Portuguese");
    if(VerificaListaVazia(LISTA)){
        printf("LISTA VAZIA!\n");

    }
    else{
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
}

//CRIANDO FUNÇÃO PARA REMOVER UM ELEMENTO DE UMA DETERMINADA POSIÇÃO!

no * Remover(no * LISTA){
    setlocale(LC_ALL, "Portuguese");
    if(VerificaListaVazia(LISTA)){
        printf("LISTA VAZIA!\n");

}
    else{

        int pos, contagem;
        printf("Selecione uma posição para remover o elemento:\n");
        scanf("%d", &pos);
        if(pos > 0 && pos <= tam){
            if(pos == 1){

                return RemoverInicio(LISTA);
        }
            else{

                no * antes = LISTA;
                no * posterior = LISTA->Proximo;

                for(contagem = 1; contagem < pos; contagem++){
                    antes = posterior;
                    posterior = posterior->Proximo;
        }


        antes->Proximo = posterior->Proximo;
        tam--;
        return posterior;

    }
        
}     
 
else{



    printf("POSIÇÃO NÃO ENCONTRADA!\n");
    
}
        
        
      
}


}

//CRIANDO FUNÇÃO PARA EXIBIR A LISTA

void ExibirElementos(no * LISTA){
    if(VerificaListaVazia(LISTA)){
        printf("LISTA VAZIA!\n");
    }else{
        no * temp = LISTA->Proximo;
        while(temp != NULL){
            printf("%d\n", temp->number);
            temp = temp->Proximo;
        }
    }
}


//CRIANDO FUNÇÃO PARA ZERAR ELEMENTOS

void ZerarElementos(no * LISTA){
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
            InserirNoFim(LISTA);
            break;
            case 3:
            Inserir(LISTA);
            break;
            case 4:
            temp = RemoverInicio(LISTA);
            printf("Elemento removido: %d\n", temp->number);
            break;
            case 5:
            temp = RemoverFim(LISTA);
            printf("Elemento removido: %d\n", temp->number);
            break;
            case 6:
            temp = Remover(LISTA);
            printf("Elemento removido: %d\n", temp->number);
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


