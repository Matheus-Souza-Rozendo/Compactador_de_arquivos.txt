#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <bits/stdc++.h>
#include "leitura_dados.h"

using namespace std;


class Arquivo{
    public:
        Arquivo();
        void Set_Caminho(string caminho);
        string Get_nome();
        string Get_caminho();
    private:
        string caminho;
        string nome;
        void Set_nome();

};

Arquivo::Arquivo(){};

void Arquivo::Set_Caminho(string caminho){
    this->caminho=caminho;
    Set_nome();
};

string Arquivo::Get_nome(){
    return nome;
};

void Arquivo::Set_nome(){
    string aux = caminho;
    if(aux.find("/")==string::npos){
         nome = aux.substr(0,aux.find("."));
    }else{
        while(aux.find("/")!=string::npos){
            aux.erase(0,caminho.find('/')+1);
        }
        nome = aux.substr(0,aux.find("."));
    }
};

string Arquivo::Get_caminho(){
    return caminho;
}
#endif // ARQUIVO_H
