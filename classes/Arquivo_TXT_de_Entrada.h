#ifndef ARQUIVO_TXT_DE_ENTRADA_H
#define ARQUIVO_TXT_DE_ENTRADA_H
#include <bits/stdc++.h>
#include "Arquivo.h"


class Arquivo_TXT_de_Entrada : protected Arquivo{
    public:
        Arquivo_TXT_de_Entrada();
        bool Set_arquivo(string c);
        FILE *Get_arquivo();
    private:
        FILE *arquivo;
};

Arquivo_TXT_de_Entrada::Arquivo_TXT_de_Entrada(){};

bool Arquivo_TXT_de_Entrada::Set_arquivo(string c){
    Set_Caminho(c);
    char *aux = &c[0];
    arquivo = fopen(aux,"r");
    if(arquivo!=NULL){
        return true;
    }else{
        return false;
    }
}

FILE *Arquivo_TXT_de_Entrada::Get_arquivo(){
    string str = Get_caminho();
    char *aux = &str[0];
    arquivo = fopen(aux,"r");
    return arquivo;
}
#endif // ARQUIVO_TXT_DE_ENTRADA_H
