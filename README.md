# Similaridade-Textual
Trabalho final de Estrutura de Dados - UFRGS - 2022 / 2


## Estruturas Usadas

O trabalho usa três árvores binárias de pesquisa AVLS, uma cada texto e outra para os stopsWords.


## Motivos das Estruturas

<p>&emsp; A escolha da AVL foi porque esse tipo de árvore tem um tempo de pesquisa mais eficiente que as outras, principalmente quando usada para conjunto de dados maiores, por ter um fator de balanceamento mais rígido. Assim, inserções e consultas serão mais eficientes que rubro-negras ou splays (não foi usado remoção). Além disso, ela garante um desempenho previsível independentemente da ordem dos elementos inseridos, o que não é verdade para as outras duas árvores. 
Ela possui algumas desvantagens também, como ser mais complexa que as outras árvores e pode ter um custo mais alto para inserção e remoção de elementos, pois é preciso sempre garantir o equilíbrio da árvore (com rotações), que é mais forte do que as outras. Ela também consome mais memória, pois cada nó precisa ter informações sobre sua altura e sobre o fator de balanceamento. </p>
<p>&emsp; Optamos pela árvore AVL pelo fato de que ordem das inserções dos elementos não importa para o balanceamento da árvore e por ela ter uma melhor eficiência em textos que podem ser conter várias palavras distintas pois, como citado no texto do trabalho, “Os textos de entrada poderão ter um tamanho arbitrário (desde algumas centenas de caracteres até milhões)”.</p>


## Funcionamento do projeto

<p>&emsp; O programa só começa se forem passados dois arquivos como parâmetros para o executável. Se isso for atendido, começamos a contagem do tempo. </p>
	
<p>&emsp; Primeiro transformamos o arquivo de stopword em uma AVL, usando a função turningIntoTree, com cada palavra em um nodo. Isso acelera muito o processo para “limpar” o texto dessas palavras posteriormente.</p>

<p>&emsp; Depois disso, vamos para a função textPreProcessing, que cuida da transformação das palavras do texto para uma árvore AVL - não colocando palavras idênticas nela. A cada palavra do texto, a função verifica se a palavra está contida na árvore criada para as stopword usando a função findWordTree, se a função retornar 1 ,ou seja, ela achar, a palavra não é passada para a árvore do texto. A própria inserção das árvores AVLS cuida das palavras iguais do texto, não colocando-as de novo na árvore.</p>

<p>&emsp; Transformando os dois textos em árvores AVLS, usamos a função compareTree, do arquivo tree.h, que passa por dois processos.
      <ol>
         <li>Fixa uma palavra da árvore 1 e passa essa palavra junto com a árvore 2 para a função findWordTree. </li>
         <li>Essa função, por sua vez, irá tentar achar a palavra da árvore 1 na árvore 2. Se ela achar, coloca 1 no atributo comparison do nodo em que foi achado a palavra igual na árvore 2 e retorna 1. Se ela não achar, apenas retorna 0.</li>
      </ol>
</p>

<p>&emsp; Voltando para a primeira função, se à findWordTree retornar 1, colocamos 1 no atributo comparison do nodo em que a palavra foi passada na árvore 1. Essa função faz isso para todas as palavras da árvore 1, comparando com todas as palavras da árvore 2.</p>

<p>&emsp; Usamos o atributo comparison para depois contabilizar quantas palavras iguais e diferentes há em cada árvore. Os nodos em que há comparison é igual a 0 diz que aquela palavra não foi achada no outro texto, e, quando comparison é igual a 1, a palavra do nodo foi achada no outro texto.</p>
	
<p>&emsp; Com a comparação das árvores feitas, contabilizamos quantas palavras no total há em cada texto, usando a função wordsTree. E, depois, calculamos  quantas palavras tem comparison igual a 1 em uma das duas árvores (não faz diferença qual, pois terão o mesmo resultado) com a função equalWords.</p>

<p>&emsp; A partir dos dados acima, conseguimos calcular o coeficiente de jaccard da seguinte maneira:</p>
	   
```math
  jacc = \frac {Texto_{A} \bigcap Texto_{B}}{|Texto_{A}| + |Texto_{B}| - |Texto_{A} \bigcap Texto_{B}|}
```
<p>&emsp; Com o coeficiente de jaccard calculado, calculamos o tempo (pegando o momento em que acabou o cálculo do coeficiente) transformando em segundos.</p>


### Author

By [Mateus Fauri](https://github.com/MateusFauri) 👋🏽 
