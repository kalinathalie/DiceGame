//
//	Jogo.h
//	Jogo
//
//	Created by Lucas Nathaniel on 15/10/16;
//	Copyright (c) 2016 Lucas Nathaniel. All rights reserved.
//
#ifndef __Jogo__Jogo__
#define	__Jogo__Jogo__

#include <iostream>

class Jogo{
private:
	int quantidade;
	int limite;
public:
	Jogo();
	~Jogo();
	void inserir(int valor);
	int getQuantidade();
	void Jogando();
	void setLimite(int l);

};


#endif /* defined(__Jogo__Jogo__) */