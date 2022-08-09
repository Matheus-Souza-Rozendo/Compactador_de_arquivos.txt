#ifndef ARQUIVO_TXT_DE_ENTRADA_DESCOMPACTACAO_H
#define ARQUIVO_TXT_DE_ENTRADA_DESCOMPACTACAO_H
#include <bits/stdc++.h>
#include "Arquivo_TXT_de_Entrada.h"
#include "Arvore.h"
#include "bitwise.h"
#include "Arquivo_TXT_de_Saida_descompactacao.h"

class Arquivo_TXT_de_Entrada_descompactacao : protected Arquivo_TXT_de_Entrada
{
    public:
        Arquivo_TXT_de_Entrada_descompactacao();
        void descompactar();// descompacta o arquivo passado como parametro
        bool Set_arquivo_descompactacao(string c); // set do arquivo de entrada

    private:
        Arvore arvore_de_huffman; // arvore de huffman deve ser lida do arquivo para que seja possivel a descompactacao
        string codificacao; //sequencias de bits que representam a codificacao
        string descodificacao; //sequencia de caracteres do arquivo original
        int tamanho; //tamanho da codificacao
        void ler_arvore_arquivo(Arvore *arv, string linha_arvore); //gerar arvore a partir da lida no arquivo
        void gera_codificacao(FILE *arq); //gera a string codificacao
        void gera_descodificacao(); //percorre a aarvore e gera a string decodificacao
        string get_linha(FILE *arq); // funçõ analaloga a get_line() porem para arquivos FILE
        int posicao=0;
};

Arquivo_TXT_de_Entrada_descompactacao::Arquivo_TXT_de_Entrada_descompactacao(){};

bool Arquivo_TXT_de_Entrada_descompactacao::Set_arquivo_descompactacao(string c){
    return Set_arquivo(c);
}

void Arquivo_TXT_de_Entrada_descompactacao::descompactar(){
    FILE *aux = Get_arquivo();
    string str = get_linha(aux);
    ler_arvore_arquivo(&arvore_de_huffman,str);
    str = get_linha(aux);
    tamanho = stoi(str);
    gera_codificacao(aux);
    gera_descodificacao();
    Arquivo_TXT_de_Saida_descompactacao A;
    A.escrever_arquivo(descodificacao,Get_nome(),"descompactados");

}

string Arquivo_TXT_de_Entrada_descompactacao::get_linha(FILE *arq){
    string aux;
    char c = getc(arq);
    while(c!='\n'){
        aux.push_back(c);
        c = getc(arq);
    }
    return aux;
};

void Arquivo_TXT_de_Entrada_descompactacao::ler_arvore_arquivo(Arvore *arv,string linha_arvore){
    if(posicao < linha_arvore.size()){
        string aux;
        int i=0;
        while(linha_arvore[posicao]!=','){
            aux.push_back(linha_arvore[posicao]);
            i++;
            posicao++;
        }
        posicao++;
        Arvore a;
        a.caractere.simbolo=stoi(aux);
        *arv=a;
        i=0;
        int j = posicao;
        aux.clear();
        while(linha_arvore[j]!=','){
            aux.push_back(linha_arvore[j]);
            i++;
            j++;
        }
        if(aux!="/"){
            arv->esquerda = (Arvore*) malloc(sizeof(Arvore));
            ler_arvore_arquivo(arv->esquerda,linha_arvore);
        }else{
            posicao+=2;
        }
        i=0;
        j = posicao;
        aux.clear();
        while(linha_arvore[j]!=','){
            aux.push_back(linha_arvore[j]);
            i++;
            j++;
        }
        if(aux!="/"){
            arv->direita=(Arvore*) malloc(sizeof(Arvore));
            ler_arvore_arquivo(arv->direita,linha_arvore);
        }else{
            posicao+=2;
        }
    }
};

void Arquivo_TXT_de_Entrada_descompactacao::gera_codificacao(FILE *arq){
    unsigned char c = fgetc(arq);
    int i=1;
    while(!feof(arq)){
        if(int(c)>128){
            c=c-128;
        }
        codificacao+=toBinary(c);
        c = fgetc(arq);
    }
};

void Arquivo_TXT_de_Entrada_descompactacao::gera_descodificacao(){
    Arvore aux = arvore_de_huffman;
    int i=0;
    while(i<tamanho){
        if(codificacao[i]=='0'){
            aux=*aux.esquerda;
        }else{
            aux=*aux.direita;
        }
        if(aux.caractere.simbolo!=-1){
            char c = aux.caractere.simbolo;
            descodificacao.push_back(c);
            aux=arvore_de_huffman;
        }
        i++;
    }
};
#endif // ARQUIVO_TXT_DE_ENTRADA_DESCOMPACTACAO_H
