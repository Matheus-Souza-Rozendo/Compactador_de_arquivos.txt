#ifndef ARQUIVO_TXT_DE_ENTRADA_COMPACTACAO_H
#define ARQUIVO_TXT_DE_ENTRADA_COMPACTACAO_H
#include <bits/stdc++.h>
#include "Arquivo_TXT_de_Entrada.h"
#include "Arvore.h"
#include "Caractere.h"
#include "Arquivo_TXT_de_Saida_compactacao.h"


class Arquivo_TXT_de_Entrada_compactacao : protected Arquivo_TXT_de_Entrada
{
    public:
        Arquivo_TXT_de_Entrada_compactacao();
        bool Set_arquivo_compactacao(string c);// set do arquivo de entrada, retorna true se o arquivo for aberto
        void compactar(); // compacta o arquivo usando o algoritmo de huffman e retorna a string codificacao
        Arvore *Get_Arvore_huffman(); // retorna a arvore de huffman


    private:
        vector <Caractere> tabela_de_frequencia; // tabela de frequencia utilizada no algoritmo de huffman
        Arvore arvore_de_huffman; // Arvore binaria usada no algoritmo de huffman
        vector <Arvore> lista_de_prioridade; // vetor que contem a lista de prioridades usada no algoritmo de huffman
        map <int,string> dicionario; // map que associa o caractere a sua representação binaria
        string codificacao; // sequencia de bits que representa o arquivo de texto. Essa sequencia é gerada a partir do código de huffman
        int pesquisa_linear_elementos_tabela_frequencia(int c); // metodo que realiza a busca na tabela de frequencia por um determinado caractere e retorna sua posição
        void ordenar(); // ordena a tabela de frequencia em ordem crescente usando o algoritmo de ordenação por seleção
        void gerar_tabela_frequencia(); // metodo que gera a tabela de frequencia
        void cria_lista_de_prioridades(); // cria a lista de prioridade do algoritmo de huffman
        void gerar_arvore_de_huffman(); // gera uma arvore de huffman
        int acha_posicao(int n); // acha aposição em que um nó intermediario deve ser inserido na lista de prioridade
        void gerar_dicionario(Arvore *arv,string str); // gera um dicionario, asociando um simbolo a sua representação binaria
        void codifica(); // gera a string codificacao
};

Arquivo_TXT_de_Entrada_compactacao::Arquivo_TXT_de_Entrada_compactacao(){};


bool Arquivo_TXT_de_Entrada_compactacao::Set_arquivo_compactacao(string c){
    return Set_arquivo(c);
}

int Arquivo_TXT_de_Entrada_compactacao::pesquisa_linear_elementos_tabela_frequencia(int c){
    for(int i=0;i<tabela_de_frequencia.size();i++){
        if(tabela_de_frequencia[i].simbolo==c){
            return i;
        }
    }
    return -1;
};

void Arquivo_TXT_de_Entrada_compactacao::ordenar(){
    int indice,i;
    Caractere x;
    indice = 0;
    while(indice < tabela_de_frequencia.size()-1){
			x = tabela_de_frequencia[indice + 1];
        	i = indice;
            while(1){
            	if(x.ocorrencias < tabela_de_frequencia[i].ocorrencias){//verificando se o elemento ja ordenado é menor que o x
            		tabela_de_frequencia[i+1] = tabela_de_frequencia[i];
            		tabela_de_frequencia[i] = x;
				}
				if(x.ocorrencias > tabela_de_frequencia[i].ocorrencias || i==0){ //verificando se é maior
					break;
				}
				i=i-1;
			}
			indice++;
		}
};

void Arquivo_TXT_de_Entrada_compactacao::gerar_tabela_frequencia(){
    char c;
    int p;
    FILE *aux = Get_arquivo();
    while(!feof(aux)){
        c = getc(aux);
        p = pesquisa_linear_elementos_tabela_frequencia(int(c));
        if(p!=-1){
            tabela_de_frequencia[p].ocorrencias++;
        }else{
            if(int(c)!=-1){
                Caractere E;
                E.ocorrencias=1;
                E.simbolo=int(c);
                tabela_de_frequencia.push_back(E);
            }
        }
    }
    ordenar();
}

void Arquivo_TXT_de_Entrada_compactacao::compactar(){
    gerar_tabela_frequencia();
    cria_lista_de_prioridades();
    gerar_arvore_de_huffman();
    gerar_dicionario(&arvore_de_huffman,"");
    codifica();
    Arquivo_TXT_de_Saida_compactacao A;
    A.escrever_arquivo(codificacao,Get_nome(),&arvore_de_huffman,"compactados");
}

void Arquivo_TXT_de_Entrada_compactacao::cria_lista_de_prioridades(){
    for(int i=0;i<tabela_de_frequencia.size();i++){
        Arvore aux;
        aux.caractere=tabela_de_frequencia[i];
        lista_de_prioridade.push_back(aux);
    }
};

void Arquivo_TXT_de_Entrada_compactacao::gerar_arvore_de_huffman(){
    while(lista_de_prioridade.size()!=1){
        Arvore intermediario;
        intermediario.caractere.simbolo=-1;
        intermediario.direita= (Arvore*) malloc(sizeof(Arvore));
        intermediario.esquerda=( Arvore*) malloc(sizeof(Arvore));
        *intermediario.esquerda=lista_de_prioridade[0];
        *intermediario.direita=lista_de_prioridade[1];
        intermediario.caractere.ocorrencias=lista_de_prioridade[0].caractere.ocorrencias+lista_de_prioridade[1].caractere.ocorrencias;
        lista_de_prioridade.erase(lista_de_prioridade.begin());
        lista_de_prioridade.erase(lista_de_prioridade.begin());
        if(lista_de_prioridade.size()!=0){
            int p = acha_posicao(intermediario.caractere.ocorrencias);
            lista_de_prioridade.emplace(lista_de_prioridade.begin()+p,intermediario);
        }else{
            lista_de_prioridade.push_back(intermediario);
        }
    }
    arvore_de_huffman=lista_de_prioridade[0];
}

void Arquivo_TXT_de_Entrada_compactacao::gerar_dicionario(Arvore *arv,string str){
    if(arv!=NULL){
        string esquerda,direita;
        esquerda=str;
        direita=str;
        if(arv->caractere.simbolo!=-1){
            pair <int,string> aux;
            aux.first=arv->caractere.simbolo;
            aux.second=str;
            dicionario.insert(aux);
        }else{
            esquerda.push_back('0');
            direita.push_back('1');
            gerar_dicionario(arv->esquerda,esquerda);
            gerar_dicionario(arv->direita,direita);
        }
    }
};

int Arquivo_TXT_de_Entrada_compactacao::acha_posicao(int n){
    for(int i=0;i<lista_de_prioridade.size();i++){
        if(lista_de_prioridade[i].caractere.ocorrencias>=n){
            return i;
        }
    }
    return lista_de_prioridade.size();
}

void Arquivo_TXT_de_Entrada_compactacao::codifica(){
    FILE *aux = Get_arquivo();
    char c;
    c = getc(aux);
    while(!feof(aux)){
        auto it = dicionario.find(int(c));
        codificacao+= it->second;
        c = getc(aux);
    }
    fclose(aux);
}

#endif // ARQUIVO_TXT_DE_ENTRADA_COMPACTACAO_H
