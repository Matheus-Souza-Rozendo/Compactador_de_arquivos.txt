#ifndef ARVORE_H
#define ARVORE_H
#include <bits/stdc++.h>
#include "Caractere.h"

using namespace std;

class Arvore{
    public:
        Arvore();
        Caractere caractere;
        Arvore *esquerda=NULL;
        Arvore *direita=NULL;
};

Arvore::Arvore(){};


#endif // ARVORE_H
