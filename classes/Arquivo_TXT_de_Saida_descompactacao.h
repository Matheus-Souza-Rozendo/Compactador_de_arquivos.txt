#ifndef ARQUIVO_TXT_DE_SAIDA_DESCOMPACTACAO_H
#define ARQUIVO_TXT_DE_SAIDA_DESCOMPACTACAO_H

#include "Arquivo_TXT_de_Saida.h"


class Arquivo_TXT_de_Saida_descompactacao : protected Arquivo_TXT_de_Saida
{
    public:
        Arquivo_TXT_de_Saida_descompactacao();
        void escrever_arquivo(string c, string n, string p);
};

Arquivo_TXT_de_Saida_descompactacao::Arquivo_TXT_de_Saida_descompactacao(){};

void Arquivo_TXT_de_Saida_descompactacao::escrever_arquivo(string c, string n, string p){
    if(cria_arquivo(n,p,".txt")){
        ofstream *aux = Get_arquivo();
        *aux << c;
    }else{
        cout << "\n Falha ao criar arquivo de saida\n";
    }
}
#endif // ARQUIVO_TXT_DE_SAIDA_DESCOMPACTACAO_H
