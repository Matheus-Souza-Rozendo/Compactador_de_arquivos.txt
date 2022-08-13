#ifndef ARQUIVO_TXT_DE_SAIDA_H
#define ARQUIVO_TXT_DE_SAIDA_H

#include <bits/stdc++.h>
#include "Arvore.h"
#include "Arquivo.h"
#include "leitura_dados.h"


class Arquivo_TXT_de_Saida : public Arquivo
{
    public:
        Arquivo_TXT_de_Saida();
        bool cria_arquivo(string nome, string pasta,string extensao); // set do arquivo de saida o parametro não precisa conter .txt
        ofstream *Get_arquivo(); // retorna um ponteiro para o arquivo de saida


    private:
        string pasta;//contem a pasta onde o arquivo de saida será criado
        ofstream arquivo; // contem o arquivo de saida
        void cria_pasta(); // se a pasta definida como destino não existir, cria uma pasta com o nome passado
};

Arquivo_TXT_de_Saida::Arquivo_TXT_de_Saida(){};


void Arquivo_TXT_de_Saida::cria_pasta(){
    if(!existe(pasta)){
        string comando = "md ";
        comando+=pasta;
        char *c = &comando[0];
        system(c);
    }
}

bool Arquivo_TXT_de_Saida::cria_arquivo(string nome, string pasta, string extensao){
    string aux;
    aux = nome;
    aux+=extensao;
    Set_Caminho(nome);
    this->pasta=pasta;
    cria_pasta();
    aux = pasta;
    aux+="/";
    aux+=nome;
    aux+=extensao;
    arquivo.open(aux);
    return (arquivo.is_open())?true : false;
}

ofstream *Arquivo_TXT_de_Saida::Get_arquivo(){
    return &arquivo;
}

#endif // ARQUIVO_TXT_DE_SAIDA_H
