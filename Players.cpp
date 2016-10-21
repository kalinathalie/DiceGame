//
//	Players.cpp
//	Game
//
//	Created by Lucas Nathaniel on 15/10/16;
//	Copyright (c) 2016 Lucas Nathaniel. All rights reserved.
//
#include "Players.h"


Players::Players(){
    this->setNext(0);
}

Players::Players(int Value){
    this->setValue(Value);
    this->setNext(0);
}

int Players::getValue(){
    return this->Value;
}

void Players::setValue(int val){
    this->Value += val;
}

Players* Players::getNext(){
    return this->next;
}

void Players::setNext(Players* Players){
    this->next = Players;
}

void Players::setQuit(){
	this->Quit = true;	
}

bool Players::getQuit(){
	return this->Quit;
}

void Players::setLost(){
	this->Lost = true;
}

bool Players::getLost(){
	return this->Lost;
}

void Players::setNumber(int i ){
	this->Number = i;
}

int Players::getNumber(){
	return this->Number;
}