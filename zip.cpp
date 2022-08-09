#include <bits/stdc++.h>
#include "classes/Arquivo_TXT_de_Entrada_descompactacao.h"
#include "classes/Arquivo_TXT_de_Entrada_compactacao.h"
#include "classes/leitura_dados.h"


using namespace std;



void compactar(){
    Arquivo_TXT_de_Entrada_compactacao E;
    cout << "\n\n Digite o caminho do arquivo .txt que será compactado\n";
    cout << "caminho: ";
    string caminho;
    cin >> caminho;
    size_t found = caminho.find(".txt");
    if(found != string::npos){
        if(E.Set_arquivo_compactacao(caminho)){
        E.compactar();
        cout << "\narquivo compactado gerado com sucesso\n";
    }else{
        cout << "\nArquivo Não Encontrado\n";
    }
    }else{
        cout<<"\nFormato Inválido\nAceita apenas arquivos com a extensão .txt";
    }
}

void descompactar(){
    Arquivo_TXT_de_Entrada_descompactacao A;
    cout << "\n\n Digite o caminho do arquivo .compact que será descompactado\n";
    cout << "caminho: ";
    string caminho;
    cin >> caminho;
    size_t found = caminho.find(".compact");
    if(found != string::npos){
        if(A.Set_arquivo_descompactacao(caminho)){
        A.descompactar();
        cout << "\narquivo descompactado gerado com sucesso\n";
    }else{
        cout << "\nArquivo Não Encontrado\n";
    }
    }else{
        cout<<"\nFormato Inválido\nAceita apenas arquivos com a extensão .compact";
    }
}

int main(){
    string op;
    setlocale(LC_ALL, "ptb");

    inicio:
    system("cls");
    cout << "Digite 1 para compactar arquivo .txt\nDigite 2 para descompactar arquivo .compact\n";
    cout << "op: ";
    cin >> op;
    if(op=="1"){
        compactar();
    }
    if(op=="2"){
        descompactar();
    }
    if(op!="1"&&op!="2"){
        cout <<"\nopção invalida\n";
    }
    cout << "digite 1 para sair\n qualquer outra tecla para continuar";
    cout <<"\nop: ";
    op.clear();
    cin >> op;
    if(op!="1"){
        goto inicio;
    }
}
