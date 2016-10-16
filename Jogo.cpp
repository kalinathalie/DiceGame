//
//	Jogo.cpp
//	Jogo
//
//	Created by Lucas Nathaniel on 15/10/16;
//	Copyright (c) 2016 Lucas Nathaniel. All rights reserved.
//

#include "Jogadores.h"
#include "Jogo.h"
#include <cstdlib>
#include <ctime>

Jogadores* primeiro;
Jogadores* ultimo;
Jogo::Jogo(){
    primeiro = 0;
	this->quantidade = 0;
}

Jogo::~Jogo(){

}

void Jogo::inserir(int valor){
	Jogadores* novo = new Jogadores(valor);
	novo->setNext(primeiro);
	primeiro = novo;
	if(this->quantidade == 0){
		ultimo = novo;
	}
	this->quantidade++;
	ultimo->setNext(primeiro);
}


int Jogo::getQuantidade(){
	return this->quantidade;
}

void Jogo::Jogando(){
	Jogadores* percorre = primeiro;
	int vez = getQuantidade();
	int vezes = 1;
	int entrada;
	int dados;
	bool TemJogando = true;
	srand(time(0));
	while(TemJogando == true){
		TemJogando = false;
		while(vez > 0){
			percorre->setNumero(vezes);
			if(percorre->getPerdeu() == false && percorre->getSaiu() == false){
			cout << "Vez do jogador: " << vezes << endl;
			cout << "(1)Jogar Dados (2)Parar" << endl;
			cin >> entrada;
				if(entrada == 1){
					TemJogando = true;
					dados = rand()%(10)+2;
					percorre->setValor(dados);
					cout << "Você tirou " << dados << " nos dados!" << endl;
					cout << "Valor total: " << percorre->getValor() << endl;
					if(percorre->getValor() > this->limite){
						percorre->setPerdeu();
						cout << "O jogador perdeu, pois ultrapassou o limite de " << this->limite << endl;
					}
				}else if(entrada == 2){
					percorre->setSaiu();
					cout << "O jogador parou com " << percorre->getValor() << " pontos!" << endl;
				}else{
					cout << "você é burro ou não sabe apertar 1 ou 2? Perdeu o jogo!" << endl;
					percorre->setPerdeu();
				}
			}else{
				cout << "O jogador " << vezes << " saiu ou perdeu!" << endl;
			}
			percorre = percorre->getNext();
			
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
			vezes++;
			vez--;
		}
		if(TemJogando == true){
			vez = getQuantidade();
			vezes = 1;
		}
	}
	Jogadores* vencedor = primeiro;
	while(vencedor->getPerdeu() == true && vencedor != ultimo){
		vencedor = vencedor->getNext();
	}
	percorre = vencedor->getNext();
	while(percorre != ultimo){
		if(percorre->getValor() > vencedor->getValor() && percorre->getPerdeu() == false){
			vencedor = percorre;
		}
		percorre = percorre->getNext();
	}
	if(ultimo->getPerdeu() == false && ultimo->getValor() > vencedor->getValor() ){
		vencedor = ultimo;
	}
	if(vencedor->getPerdeu() == true){
		cout << "Todos os jogadores perderam!" << endl;
	}else{
		cout << "O vencedor é o jogador " << vencedor->getNumero() << " com " << vencedor->getValor() << " pontos!" << endl;
	}
}

void Jogo::setLimite(int l){
	this->limite = l;
}