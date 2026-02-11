Estrutura de dados em C é um dos assuntos mais importantes a estudar, após aprender lógica de programação e manipular structs e ponteiros em C:

*As estruturas trabalhadas, nesse repositório são Lista Encadeada, Fila e Pilha:

Lista Encadeada -> Estrutura de dados constituída por elementos ligados, de modo que um nó, aponta para o próximo elemento, ou então para NULL, 
                   se for o último elemento da lista;

Fila -> Estrutura de dados na qual insere-se os elementos no final e remove-os do início(FIFO-> First in First Out);

Pilha -> Estrutura de dados, na qual só é possível remover e inserir os elementos da última posição(correspondente ao topo da pilha) -> (LIFO -> Last In First Out);

*Regras resumidas, para inserção, remoção dos nós, liberação e exibição de informações:

Inserir na primeira posição -> O novo primeiro nó inserido, deverá apontar para o antigo primeiro nó, 
                                sendo que esse antigo primeiro nó deverá ser "empurrado" para a segunda posição;

Inserir na última posição -> O último nó, da lista atual, deverá apontar para o novo nó inserido, que deverá apontar para NULL, já que passará a ser o último elemento
                             da lista;
                             
Remover do início -> O ponteiro, que aponta para o primeiro elemento da lista, deverá apontar para o próximo elemento(no caso o segundo), 
                    que passará a ser o primeiro da lista(LISTA->prox = tmp->prox);

Remover do fim -> Nesse caso, deve-se fazer com que o penúltimo elemento da lista, aponte para NULL, indicando que é o último elemento dessa lista;

Inserir em uma posição qualquer -> Deve-se armazenar a posição anterior, e a atual do nó, que será inserido, 
                                  de modo que o nó da posição anterior deverá apontar para o nó que irá ser inserido, enquanto que o nó 
                                  a ser inserido deverá apontar para o atual(deslocando-o para frente);

Remover de uma posição qualquer -> Basta fazer com que o nó da posição anterior ao que se pretende remover, aponte para o próximo elemento
                                   de modo que mais nenhum nó, aponte para o que deseja-se remover , o que o fará ser eliminado da lista
                                   ou seja: anterior->prox = atual->prox;
                                   
Exibir elementos da lista-> Basta, percorrer todos os seus elementos, por meio de um laço à medida que esses forem sendo exibidos(obs: temp = temp->proximo);

Liberar os nós(zerar lista) -> Ao liberar um nó, deve-se salvar o ponteiro que aponta para o próximo nó, portanto cria-se
                               um ponteiro para o nó, de modo a guardar essa informação, em outras palavras, guarda-se o 
                               endereço do próximo, desaloca e vai para o próximo;

Para observar isso, plenamente, veja os códigos do repositórios, no main;
