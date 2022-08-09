#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <bits/stdc++.h>
#include "leitura_dados.h"

using namespace std;


class Arquivo{
    public:
        Arquivo();
        void Set_Caminho(string cami);
        string Get_nome();
        string Get_caminho();
    private:
        string caminho;
        string nome;
        void Set_nome();

};

Arquivo::Arquivo(){};

void Arquivo::Set_Caminho(string cami){
    caminho=cami;
    Set_nome();
};

string Arquivo::Get_nome(){
    return nome;
};

void Arquivo::Set_nome(){
    string aux = caminho;
    if(busca_caractere_string(aux,'/')==-1){
         nome = aux.substr(0,busca_caractere_string(aux,'.'));
    }else{
        while(busca_caractere_string(aux,'/')!=-1){
            aux.erase(0,busca_caractere_string(aux,'/')+1);
        }
        nome = aux.substr(0,busca_caractere_string(aux,'.'));
    }
};

string Arquivo::Get_caminho(){
    return caminho;
}
#endif // ARQUIVO_H
