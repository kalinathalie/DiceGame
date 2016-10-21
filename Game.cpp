//
//	Game.cpp
//	Game
//
//	Created by Lucas Nathaniel on 15/10/16;
//	Copyright (c) 2016 Lucas Nathaniel. All rights reserved.
//

#include "Players.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>

Players* First;
Players* Last;
Game::Game(){
    First = 0;
	this->Quantity = 0;
}

Game::~Game(){

}

void Game::Insert(int Value){
	Players* New = new Players(Value);
	New->setNext(First);
	First = New;
	if(this->Quantity == 0){
		Last = New;
	}
	this->Quantity++;
	Last->setNext(First);
}


int Game::getQuantity(){
	return this->Quantity;
}

void Game::Playing(){
	Players* Walk = First;
	int vez = getQuantity();
	int Times = 1;
	int Input;
	int dices;
	bool HavePlaying = true;
	srand(time(0));
	while(HavePlaying){
		HavePlaying = false;
		while(vez > 0){
			Walk->setNumber(Times);
			if(!Walk->getLost() && !Walk->getQuit()){
			cout << "Turn of the player: " << Times << endl;
			cout << "(1)Run Dices (2)Stop" << endl;
			cin >> Input;
				if(Input == 1){
					HavePlaying = true;
					dices = rand()%(10)+2;
					Walk->setValue(dices);
					cout << "You got " << dices << " on dices!" << endl;
					cout << "Total value: " << Walk->getValue() << endl;
					if(Walk->getValue() > this->Limit){
						Walk->setLost();
						cout << "The player Lost, because over the limit: " << this->Limit << endl;
					}
				}else if(Input == 2){
					Walk->setQuit();
					cout << "The player stopped with " << Walk->getValue() << " points!" << endl;
				}else{
					cout << "You dont know press the button 1 or 2, man? You lost the game!" << endl;
					Walk->setLost();
				}
			}else{
				cout << "The player " << Times << " quit or lost!" << endl;
			}
			Walk = Walk->getNext();
			
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
			Times++;
			vez--;
		}
		if(HavePlaying){
			vez = getQuantity();
			Times = 1;
		}
	}
	Players* Winner = First;
	while(Winner->getLost() && Winner != Last){
		Winner = Winner->getNext();
	}
	Walk = Winner->getNext();
	while(Walk != Last){
		if(Walk->getValue() > Winner->getValue() && !Walk->getLost()){
			Winner = Walk;
		}
		Walk = Walk->getNext();
	}
	if(!Last->getLost() && Last->getValue() > Winner->getValue() ){
		Winner = Last;
	}
	if(Winner->getLost()){
		cout << "All players lost!" << endl;
	}else{
		cout << "The winner is the player " << Winner->getNumber() << " with " << Winner->getValue() << " points!" << endl;
	}
}

void Game::setLimit(int l){
	this->Limit = l;
}