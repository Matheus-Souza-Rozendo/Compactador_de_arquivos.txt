#ifndef LEITURA_DADOS_H_INCLUDED
#define LEITURA_DADOS_H_INCLUDED
#include <bits/stdc++.h>

using namespace std;
//função que retorna true se a string passada for um numero e false caso contrario
bool valida_apenas_numeros(string entrada){
    bool ponto,menos;
    ponto=false;
    menos=false;
    for(int i=0;i<entrada.size();i++){
        if((!isdigit(entrada[i]))&&(entrada[i]!='.')&&(entrada[i]!='-')){
            return false;
        }
        if(entrada[i]=='.' && ponto){
            return false;
        }
        if(entrada[i]=='-' && menos){
            return false;
        }
        if(entrada[i]=='.'){
            ponto=true;
        }
        if(entrada[i]=='-'){
            menos=true;
        }
    }
    return true;
}

//converter para float
float to_float(const std::string& str)
{
   std::istringstream is(str) ;
   float result;
   result = ::strtod(str.c_str(), 0);
   is >> result;
   return result ;
}



float ler_numeros_reais(){
    string entrada;
    leitura:
    try{
        cin >> entrada;
        if(!valida_apenas_numeros(entrada)){
            throw(entrada);
        }
    }catch(string msg){
        cout << msg << " Não é um valor valido " <<endl;
        system("pause");
        goto leitura;
        cout << endl << endl;
    }
    return to_float(entrada);
}

float **cria_matriz(int linhas,int colunas){
    float **matriz;
    matriz = (float**) malloc(sizeof(float*)*linhas);
    for(int i=0;i<linhas;i++){
        matriz[i] = (float*) malloc(sizeof(float)*colunas);
    }
    return matriz;
}

float **ler_matriz_numeros_reais(int linhas, int colunas){
        float **matriz = cria_matriz(linhas,colunas);
        for(int i = 0; i<linhas; i++){
            for(int j=0; j<colunas; j++){
                cout << "matriz["<<i+1<<"]["<<j+1<<"]: ";
                matriz[i][j]= ler_numeros_reais();
        }
    }
    return matriz;
}

//recebe uma string e um char como parametro
//retorna a primeira ocorencia do caractere na string, caso não ache retorna -1
int busca_caractere_string(string str, char c){
    for(int i=0;i<str.size();i++){
        if(str[i]==c){
            return i;
        }
    }
    return -1;
}

bool existe( std::string path){
  return std::filesystem::exists( path );
}


#endif // LEITURA_DADOS_H_INCLUDED
