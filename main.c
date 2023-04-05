#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include "tree.h"
#include "queue.h"

#define TAMANHO 1000
#define MAX 50

/* 
--------------------------------------------------
Autores: Mateus Emer fauri
--------------------------------------------------
                    Similaridade Textual

    Calcular a similaridade de Jaccard entre dois textos usando uma árvore binaria de pesquisa. A similaridade de
    Jaccard pode ser calculada da seguinte maneira:
            Sim = |TextoA uniao TextoB| / ( |TextoA| + |TextoB| - |TextoA uniao TextoB|)
    
    Foi usado a estrutura de arvores AVL para os textos. 
 */


Tree* textPreProcessing(char pathText[], char pathNewText[], Tree *root, Tree *rootStop);
void copyText(char textoPath[], char textoPathCopia[]);
Tree* turningIntoTree();

int main(int argc, char *argv[]) 
{
    setlocale(LC_ALL,"pt-br"); 

    clock_t start, end; 

    Tree *root1 = NULL;
    Tree *root2 = NULL;
    Tree *rootStop = NULL;

    char separador[]= {" ,.&*%\?!;/-'@\"$#=><()][}{:\n\t"};

    int textA, textB, unionAB;
    float jaccard;

    char text1[MAX], text2[MAX];
    char *word, linha[TAMANHO]; 
    float miliseconds;

    if (argc!=3) 
    {
        printf ("Numero incorreto de pararetros.\n Para chamar o programa digite: exemplo <arq_texto1> <arq_texto2>\n");
        return 1;
    }
    else
    {
        rootStop = turningIntoTree();
        strcpy(text1, argv[1]);
        strcpy(text2, argv[2]);

        start = clock(); 

        printf("Comecando processamento do texto 1... \n");        
        root1 = textPreProcessing(text1, "novoTexto1.txt", root1, rootStop);
        printf("Fim do processamento do texto 1. \n");     

        printf("Comecando processamento do texto 2... \n");        
        root2 = textPreProcessing(text2, "novoTexto2.txt", root2, rootStop);
        printf("Fim do processamento do texto 2... \n");        

        compareTree(root1, root2);

        textA = wordsTree(root1) ;
        textB = wordsTree(root2);
        unionAB = equalWords(root1);
        jaccard = (float) unionAB / (textA + textB - unionAB);

        printf("textoA: %d palavras distintas \ntextoB: %d palavras distintas  \ntextoIntersecao: %d \n", textA, textB, unionAB );
        
        printf("Similaridade de jaccard: %.2f \n", jaccard);

        end = clock(); 
        miliseconds = (float)(end - start) / CLOCKS_PER_SEC * TAMANHO; 
        printf("Tempo: %.2f s\n", miliseconds / 1000);

        return 0;
    }
}


Tree* textPreProcessing(char pathText[], char pathNewText[], Tree *root, Tree *rootStop)
{
    FILE *text, *newText;
    char pahtTextprocess[] = "processText.txt";
    char linha[TAMANHO];
    char separador[]= {" ,.&*%\?!;/-'@\"$#=><()][}{:\n\t"};
    char *word;
    int done, find;

    done = find = 0;

    text = fopen(pathText, "r");
    newText = fopen(pathNewText, "w");

    if(text == NULL || newText == NULL)
        printf("Error stopwordsFile or creating a new pre process text! \n");
    else
        while (fgets(linha,TAMANHO,text))
        {        
            word = strtok (linha, separador); 
            while (word != NULL)
            {
                done = find = 0;

                find = findWordTree(rootStop, word);
                if(!find)
                {
                    root = insertAVL(root, strlwr(word), &done);
                    fprintf(newText, "%s " , strlwr(word));
                }

                word = strtok(NULL, separador);
            }

    }
    fclose(newText);
    fclose(text);

    return root;
}

Tree* turningIntoTree()
{
    Tree *rootStop = NULL;
    FILE *stopwordsFile;
    char stopword[MAX];
    int done=0;

    stopwordsFile = fopen("stopwords.txt","r");

    if(stopwordsFile == NULL)
    {
        printf("Error stopwordsFile or creating a new pre process text! \n");
        return NULL;
    }

    while((fscanf(stopwordsFile, "%s", stopword) != EOF))
        insertAVL(rootStop, strlwr(stopword), &done);

    fclose(stopwordsFile);

    return rootStop;
}