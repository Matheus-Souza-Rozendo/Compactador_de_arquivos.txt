

# Compactador para arquivos .txt
![GitHub repo size](https://img.shields.io/github/repo-size/Matheus-Souza-Rozendo/Compactador_de_arquivos.txt)
![GitHub](https://img.shields.io/github/license/Matheus-Souza-Rozendo/Compactador_de_arquivos.txt)
![GitHub language count](https://img.shields.io/github/languages/count/Matheus-Souza-Rozendo/Compactador_de_arquivos.txt)
![GitHub top language](https://img.shields.io/github/languages/top/Matheus-Souza-Rozendo/Compactador_de_arquivos.txt)
> Compactador e descompactador de Arquivos no formato .txt, usando o algoritmo de huffman.


O número de dados gerados pela internet em um ano chega na casa de impressionantes 350 zetabyttes de informação. O armazenamento dessa quantidade de dados não é barata. Por isso, programas de compactação de arquivos são extremamente necessários e utilizados no dia-a-dia.

#### ALGORITMO DE HUFFMAN

Existem dois tipos de compactação possíveis para arquivos. A primeira alternativa seria a compactação com perda. Apesar de ser amplamente usada para arquivos de vídeo, áudio e imagem, não é recomendada para a compactação de documentos de textos.
Para esse tipo de arquivo, onde a perda de um único bit de informação já faria diferença, foram criados algoritmos que mudam a representação de cada caractere de acordo com a sua frequência. O mais famoso desses algoritmos é o de Huffman.
A codificação de Huffman é um método de compressão que usa as probabilidades de ocorrência dos símbolos no conjunto de dados a ser comprimido para determinar códigos de tamanho variável para cada símbolo.


Uma árvore binária completa, chamada de árvore de Huffman é construída recursivamente a partir da junção dos dois símbolos de menor probabilidade, que são então somados em símbolos auxiliares e estes símbolos auxiliares colocados no conjunto de símbolos. O processo termina quando todos os símbolos forem unidos em símbolos auxiliares, formando uma árvore binária. A árvore é então percorrida, atribuindo-se valores binários de 1 ou 0 para cada aresta, e os códigos são gerados a partir desse percurso.


A codificação gerada tem também a garantia de não ser ambígua, pois nenhum código pode ser o prefixo de outro código.

O resultado do algoritmo de Huffman pode ser visto como uma tabela de códigos de tamanho variável para codificar um símbolo da fonte. Assim como em outros métodos de codificação, os símbolos mais comuns são geralmente representados usando-se menos dígitos que os símbolos que aparecem com menos frequência.


## Instalação
Basta baixar o repositório e compilar o arquivo zip.cpp na versão mais recente do C++

## Como usar
* execute o programa
* escolha uma opção
    * Digite 1 para compactar um arquivo `.txt`
    * Digite 2 para descompactar um arquivo `.compact`
![](https://raw.githubusercontent.com/Matheus-Souza-Rozendo/Compactador_de_arquivos.txt/main/documenta%C3%A7%C3%A3o/prints/print_1.png)
#### Compactando Arquivos .txt
* Apenas digite o caminho para o arquivo que será compactado que o programa criará um arquivo de saida do tipo `.compact` na `pasta compactados`. Esta pasta é criada na pasta onde o usuario salvou o programa.
![](https://raw.githubusercontent.com/Matheus-Souza-Rozendo/Compactador_de_arquivos.txt/main/documenta%C3%A7%C3%A3o/prints/print_2.png)
#### Descompactando Arquivos .compact
* Apenas digite o caminho para o arquivo que será compactado que o programa criará um arquivo de saida do tipo `.txt` na `pasta descompactados`. Esta pasta é criada na pasta onde o usuario salvou o programa.
![](https://raw.githubusercontent.com/Matheus-Souza-Rozendo/Compactador_de_arquivos.txt/main/documenta%C3%A7%C3%A3o/prints/print_3.png)


## Contato
Matheus Souza Rozendo –– matheusrozendo234674@gmail.com

Distribuído sob a licença MIT. Veja `LICENSE` para mais informações.




