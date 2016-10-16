//
//	Jogadores.cpp
//	Jogo
//
//	Created by Lucas Nathaniel on 15/10/16;
//	Copyright (c) 2016 Lucas Nathaniel. All rights reserved.
//
#include "Jogadores.h"


Jogadores::Jogadores(){
    this->setNext(0);
}

Jogadores::Jogadores(int valor){
    this->setValor(valor);
    this->setNext(0);
}

int Jogadores::getValor(){
    return this->valor;
}

void Jogadores::setValor(int val){
    this->valor += val;
}

Jogadores* Jogadores::getNext(){
    return this->next;
}

void Jogadores::setNext(Jogadores* jogadores){
    this->next = jogadores;
}

void Jogadores::setSaiu(){
	this->saiu = true;	
}

bool Jogadores::getSaiu(){
	return this->saiu;
}

void Jogadores::setPerdeu(){
	this->perdeu = true;
}

bool Jogadores::getPerdeu(){
	return this->perdeu;
}

void Jogadores::setNumero(int i ){
	this->numero = i;
}

int Jogadores::getNumero(){
	return this->numero;
}