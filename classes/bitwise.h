#ifndef BITWISE_H_INCLUDED
#define BITWISE_H_INCLUDED
#include <bits/stdc++.h>

// 6 5 4 3 2 1 0
unsigned char ativa_bit_char(int n, unsigned char variavel){
     unsigned char mascara = 1 << n;
     return variavel | mascara;
}
// 6 5 4 3 2 1 0
bool testa_bit_char(unsigned char variavel, int n){
    unsigned char mascara = 1 << n;
    unsigned char aux = variavel & mascara;
    if(aux!=0){
        return true;
    }else{
        return false;
    }
}

string toBinary(unsigned char variavel){
    string r;
    for(int i=0;i<=6;i++){
        if(testa_bit_char(variavel,6-i)){
            r.push_back('1');
        }else{
            r.push_back('0');
        }
    }
    return r;
}

#endif // BITWISE_H_INCLUDED
