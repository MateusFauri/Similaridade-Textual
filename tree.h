#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <string.h>
#define MAX 100

// Binary Tree 
typedef struct 
{
    char word[MAX];
    int factor;
    int comparison;
    struct Tree *left;
    struct Tree *right;
}Tree;

// Name: insertAVL
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
//      char key[MAX]   ->  uma palavra que sera adicionada na arvore
//      int *done       ->  um ponteiro para verificar rotações na arvore
// Output: None.
// Return: Retorna um ponteiro para o inicio da nova arvore AVL
// Description:  Adiciona um nodo em uma arvore AVL, cuidando de todas as rotações necessarias. Devolve o novo
//              inicio da arvore (caso este tenha mudado pelas rotações)
Tree* insertAVL(Tree *root, char key[MAX], int *done);

// Name: Delete
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
//      char key[MAX]   ->  uma palavra que sera deletada da arvore
// Output: None.
// Return: Retorna um ponteiro para o inicio da nova arvore AVL
// Description: Deleta um nodo em uma arvore AVL, cuidando de todas as rotações necessarias.Devolve o novo
//              inicio da arvore (caso este tenha mudado pelas rotações)
Tree* delete(Tree* root, char key[MAX] );

// Name: BalanceFactor
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
// Output: None.
// Return: 
// Description: 
int balanceFactor(Tree *root);

// Name: height
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL 
// Output: None.
// Return: 
// Description: 
int height(Tree *root);

// Name: findWordTree
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
//      char word[]     ->  uma palavra para encontrar na arvore
// Output: None. 
// Return: retorna 1 se achou a palavra na arvore, 0 se não achou.
// Description: Procura a palavra na arvore, se achar, muda o atributo comparison do nodo na arvore para 1 
//              e retorna 1. Caso contrario não muda nada na arvore e retorna 0.
int findWordTree(Tree *root, char word[]);

// Name: compareTree
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
// Output: None.
// Return: None.
// Description: Compara duas arvores, cada palavra da primeira com um loop da segunda.
//              Caso achar uma palavra igual na arvore 2, muda o atributo comparison do nodo da arvore para 1
void compareTree(Tree *root1, Tree *root2);

// Name: distinctWords
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
// Output:  None. 
// Return: o numero de palavras distintas de uma arvore.
// Description: Ve quantas palavras distintas ha na arvore (palavras que contem o atributo comparison igual a zero)
int distinctWords(Tree *root);

// Name: equalWords
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
// Output: None.
// Return: o numero de palavras iguais de uma arvore.
// Description: Ve quantas palavras iguais ha na arvore (palavras que contem o atributo comparison igual a um)
int equalWords(Tree *root);

// Name: grater
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
// Output: None.
// Return: Retorna um ponteiro para o inicio da nova arvore AVL
// Description: Acha o maior nodo de uma arvore e o devolve.
Tree* greater( Tree* root );

// Name: case1
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
//      int *done       ->  um ponteiro para verificar rotações na arvore
// Output: None.
// Return: Retorna um ponteiro para o inicio da nova arvore AVL
// Description: Faz rotação simples a direita se o factor é igual a 1, se não faz uma rotação dupla a direita
Tree* case1(Tree *root, int *done);

// Name: case2
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
//      int *done       ->  um ponteiro para verificar rotações na arvore
// Output: None.
// Return: Retorna um ponteiro para o inicio da nova arvore AVL
// Description: Faz rotação simples a esquerda se o factor é igual a -1, se não faz uma rotação dupla a esquerda
Tree* case2(Tree *root, int *done);


// Name: preFixedLeft
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
//      int nivel       ->  um numero inteiro correspondente ao nivel do nodo na arvore 
// Output: Imprime os nodos da arvore com a notação "=", com uma quantidade x de = por nodo, onde x é o valor do nivel do nodo
// Return: None.
// Description: Faz o caminhamento pre fixado esquerdo da arvore, imprimindo os nodos do modo colocado acima.
void preFixedLeft(Tree *root, int nivel);

// ------------------- four types of rotate tree --------------

// Name: rotateRight
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
// Output: None.
// Return: Retorna um ponteiro para o inicio da nova arvore AVL
// Description: Faz uma simples rotação a direita no nodo passado como input para a função
Tree* rotateRight(Tree *root);

// Name: rotateLeft
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
// Output: None.
// Return: Retorna um ponteiro para o inicio da nova arvore AVL
// Description: Faz uma simples rotação a esquerda no nodo passado como input para a função
Tree* rotateLeft(Tree *root);

// Name: doubleRotateRight
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
// Output: None.
// Return: Retorna um ponteiro para o inicio da nova arvore AVL
// Description: Faz uma dupla rotação a direita no nodo passado como input para a função
Tree* doubleRotateRight(Tree *root);

// Name: DoubleRotateLeft
// Type: Function
// Inputs:
//      Tree *root      ->  um ponteiro para o inicio de uma arvore AVL
// Output: None.
// Return: Retorna um ponteiro para o inicio da nova arvore AVL
// Description: Faz uma dupla rotação a esquerda no nodo passado como input para a função
Tree* doubleRotateLeft(Tree *root);

#endif