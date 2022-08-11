#ifndef ARQUIVO_TXT_DE_SAIDA_COMPACTACAO_H
#define ARQUIVO_TXT_DE_SAIDA_COMPACTACAO_H

#include "Arquivo_TXT_de_Saida.h"
#include <bits/stdc++.h>
#include "Arvore.h"
#include "bitwise.h"
#include "leitura_dados.h"

class Arquivo_TXT_de_Saida_compactacao : protected Arquivo_TXT_de_Saida{
    public:
        Arquivo_TXT_de_Saida_compactacao();
        void escrever_arquivo(string c, string n, Arvore *arv, string p); // gera o arquivo de saida
    private:
        Arvore arvore_de_huffman;// arvore de huffman que deve ser escrita no arquivo para que seja possivel a descompactacao
        void escrever_arvore_arquivo(ofstream *arq, Arvore *arv); //escreve a arvore de huffman no inicio do arquivo;
};


Arquivo_TXT_de_Saida_compactacao::Arquivo_TXT_de_Saida_compactacao(){};

void Arquivo_TXT_de_Saida_compactacao::escrever_arvore_arquivo(ofstream *arq,Arvore *arv){
     *arq << to_string(arv->caractere.simbolo);
     *arq << ",";
     if(arv->esquerda!=NULL){
        escrever_arvore_arquivo(arq,arv->esquerda);
     }else{
        *arq << "/,";
     }
    if(arv->direita!=NULL){
        escrever_arvore_arquivo(arq,arv->direita);
     }else{
        *arq << "/,";
     }
}

void Arquivo_TXT_de_Saida_compactacao::escrever_arquivo(string c,string n,Arvore *arv,string p){
    if(cria_arquivo(n,p,".compact")){
        arvore_de_huffman=*arv;
        ofstream *aux = Get_arquivo();
        escrever_arvore_arquivo(aux,&arvore_de_huffman);
        cout << "arvore no arquivo\n";
        *aux<<'\n';
        *aux << to_string(c.size());
        *aux << '\n';
        int j=0;
        string escrita;
        while(j<c.size()){
            unsigned char byte=0;
            int i=0;
            while(j<c.size() && i<7){
                if(c[j]=='1'){
                    byte = ativa_bit_char(6-i,byte);
                }
                j++;
                i++;
            }
            if(int(byte)<=32){
                byte = byte + 128;
            }
            escrita.push_back(byte);
        }
        *aux << escrita;
    }else{
        cout << "falha ao criar arquivo de saida";
    }
}

#endif // ARQUIVO_TXT_DE_SAIDA_COMPACTACAO_H
