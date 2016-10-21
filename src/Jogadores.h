//
//	Jogadores.h
//	Jogo
//
//	Created by Lucas Nathaniel on 15/10/16;
//	Copyright (c) 2016 Lucas Nathaniel. All rights reserved.
//
#ifndef __Jogo__Jogadores__
#define __Jogo__Jogadores__

using namespace std;

class Jogadores{

private:
    int valor;
    Jogadores* next;
    bool saiu = false;
    bool perdeu = false;
    int numero;
public:
    Jogadores();

    Jogadores(int val);

    Jogadores* getNext();

    int getValor();

    void setValor(int i);
    
    void setNext(Jogadores* jogadores);

    void setSaiu();

    bool getSaiu();

    void setPerdeu();

    bool getPerdeu();

    void setNumero(int i);

    int getNumero();
};

#endif /* defined(__Jogo__Jogadores__) */
