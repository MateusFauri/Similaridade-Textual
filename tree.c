#include "tree.h"

Tree* insertAVL(Tree *root, char key[MAX], int *done)
{
    int value;

    if (root == NULL)
    {
        root = malloc(sizeof(Tree));
        strcpy(root->word, key);
        root->left = NULL;
        root->right = NULL;
        root->factor = 0;
        root->comparison = 0;
        *done = 1;
    }
    else
    {
        value = strcmp(root->word, key);
        if(value > 0)
        {
            root->left = insertAVL(root->left, key, done);
            if(*done)
            {
                switch(root->factor)
                {
                    case -1:
                        root->factor = 0;
                        *done = 0;
                        break;

                    case 0:
                        root->factor = 1;
                        break;

                    case 1:
                        root = case1(root, done);
                        break;
                }
            }
        }
        else if (value < 0)
        {
            root->right = insertAVL(root->right, key, done);
            
            if(*done)
            {
                switch(root->factor)
                {
                    case 1:
                        root->factor = 0;
                        *done = 0;
                        break;
                    case 0:
                        root->factor = -1;
                        break;
                    case -1:
                        root = case2(root, done);
                        break;
                }
            }
        }
        else
            return root;
    }

    return root;
}

Tree* delete(Tree* root, char key[MAX] )
{
    Tree* aux;

    if( root == NULL )
        printf( "Elemento nao encontrado.\n" );
    else if(strcmpi(key, root->word) < 0)
        root->left = delete(root->left, key);
    else if (strcmpi(key, root->word) > 0)
        root->right = delete(root->right, key);
    else 
        if( root->left && root->right ) 
        {
            aux = greater( root->left );
            strcpy(root->word, aux->word);
            root->left = delete( root->left, root->word );
        }
        else
        {
            aux = root;
            if( root->left == NULL ) 
                root = root->right;
            else if( root->right == NULL )
                root = root->left; 
            free( aux );
        }

    return root;
}

Tree* rotateRight(Tree *root)
{
    Tree *aux;

    aux = root->left;
    root->left = aux->right;
    aux->right = root;
    root->factor = 0;
    root = aux;
    return root;
}

Tree* rotateLeft(Tree *root)
{
    Tree *aux;

    aux = root->right;
    root->right = aux->left;
    aux->left = root;
    root->factor = 0;
    root = aux;
    return aux;
}

Tree* doubleRotateRight(Tree *root)
{
    Tree *son, *grandson;

    son = root->left;
    grandson = son->right;
    son->right = grandson->left;
    grandson->left = son;
    root->left = grandson->right;
    grandson->right = root;

    if(grandson->factor == 1)
        root->factor = -1;
    else   
        root->factor = 0;

    if(grandson->factor == -1)
        son->factor = 1;
    else
        son->factor = 0;
    
    root = grandson;

    return root;
}

Tree* doubleRotateLeft(Tree *root)
{
    Tree *son, *grandson;

    son = root->right;
    grandson = son->left;
    son->left = grandson->right;
    grandson->right = son;
    root->right = grandson->left;
    grandson->left = root;

    if(grandson->factor == -1)
        root->factor = 1;
    else
        root->factor = 0;

    if(grandson->factor == 1)
        son->factor = -1;
    else
        son->factor = 0;

    root = grandson;

    return root;
}


void preFixedLeft(Tree *root, int nivel)
{
    int i;

    if(root != NULL)
    {
        for(i = 0; i < nivel; i++)
        {
            printf("=");
            fflush(stdout);
        }
        printf("%s %d \n", root->word, root->comparison);
        preFixedLeft(root->left, nivel + 1);
        preFixedLeft(root->right,nivel + 1);
    }
}


Tree* case1(Tree *root, int *done)
{
    Tree *son;

    son = root->left;
    if(son->factor == 1)
        root = rotateRight(root);
    else
        root = doubleRotateRight(root);

    root->factor = 0;
    *done = 0;
    return root;
}

Tree* case2(Tree *root, int *done)
{
    Tree *son;

    son = root->right;
    if(son->factor == -1)
        root = rotateLeft(root);
    else
        root = doubleRotateLeft(root);

    root->factor = 0;
    *done = 0;
    return root;
}


Tree* greater( Tree* root)
{
    if( root != NULL )
        while( root->right != NULL )
            root =root->right;

        return root;
}


int balanceFactor(Tree *root)
{
    int factor, leftFactor, rightFactor;

    if(root == NULL)
        return 0;
    else
    {
        leftFactor = balanceFactor(root->left);
        rightFactor = balanceFactor(root->right);

        factor = height(root->left) - height(root->right);
        if(factor < 0)
            factor = factor * -1;

        if(factor > rightFactor && factor > leftFactor)
            return factor;
        else if(rightFactor > leftFactor)
            return rightFactor;
        else
            return leftFactor;
    }
}

int height(Tree *root)
{
    int heightRight, heightLeft;

    if(root == NULL)
        return 0;
    else
    {
        heightLeft = height(root->left);
        heightRight = height(root->right);
        if (heightLeft > heightRight)
            return (1 + heightLeft);
        else
            return (1 + heightRight);
    }
}

int findWordTree(Tree *root, char word[])
{
    int value;

    if(root == NULL)
        return 0;

    value = strcmp(root->word, word);

    if(value == 0)
    {
        root->comparison = 1;
        return 1;
    }
    else if(value < 0)
        value = findWordTree(root->right, word);
    else
        value = findWordTree(root->left, word);
}

void compareTree(Tree *root1, Tree *root2)
{
    if(root2 != NULL && root1 != NULL)
    {
        if(findWordTree(root1, root2->word))
            root2->comparison = 1;

        compareTree(root1, root2->left);
        compareTree(root1, root2->right);
    }
}

int distinctWords(Tree *root)
{
    int distinct = 0;

    if(root == NULL)
        return 0;
    else
    {
        distinct += distinctWords(root->right);
        distinct += distinctWords(root->left);
        if (root->comparison == 0)
            distinct = (1 + distinct);
    }

    return distinct;
}

int equalWords(Tree *root)
{
    int equal = 0;

    if(root == NULL)
        return 0;
    else
    {
        equal += equalWords(root->right);
        equal += equalWords(root->left);
        if(root->comparison != 0)
            equal = (1 + equal);
    }
    
    return equal;
}

int wordsTree(Tree *root)
{
    int word = 0;

    if(root == NULL)
        return 0;
    else
    {
        word += wordsTree(root->right);
        word += wordsTree(root->left);
        word = (1 + word);
    }

    return word;
}