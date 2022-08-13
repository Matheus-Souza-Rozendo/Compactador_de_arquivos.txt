#ifndef ARQUIVO_TXT_DE_SAIDA_DESCOMPACTACAO_H
#define ARQUIVO_TXT_DE_SAIDA_DESCOMPACTACAO_H

#include "Arquivo_TXT_de_Saida.h"

class Arquivo_TXT_de_Saida_descompactacao : public Arquivo_TXT_de_Saida
{
    public:
        Arquivo_TXT_de_Saida_descompactacao();
        void escrever_arquivo(string conteudo, string nome, string pasta);
};

Arquivo_TXT_de_Saida_descompactacao::Arquivo_TXT_de_Saida_descompactacao(){};

void Arquivo_TXT_de_Saida_descompactacao::escrever_arquivo(string conteudo, string nome, string pasta){
    if(cria_arquivo(nome,pasta,".txt")){
        ofstream *aux = Get_arquivo();
        *aux << conteudo;
    }else{
        cout << "\n Falha ao criar arquivo de saida\n";
    }
}
#endif // ARQUIVO_TXT_DE_SAIDA_DESCOMPACTACAO_H
