//
//	main.cpp
//	Jogo
//
//	Created by Lucas Nathaniel on 15/10/16;
//	Copyright (c) 2016 Lucas Nathaniel. All rights reserved.
//

#include <iostream>
#include "Jogo.h"
#include "Jogadores.h"
#include "stdlib.h"

using namespace std;

int main(){
	system("clear");
	cout << "\tBem vindo ao DiceGame -0.01" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Quantos jogadores desejam participar?" << endl;
	int players;
	cin >> players;
	if(players <= 0){
		cout << "Nenhum jogador quis participar" << endl;
		return 0;
	}
	if(players == 1){
		cout << "Não seja forever alone" << endl;
		return 0;
	}
	Jogo* jogo = new Jogo();
	for(int i=1; i<=players; i++){
		jogo->inserir(0);
	}
	cout << "Qual o número limite determinado pelos jogadores?" << endl;
	int limite;
	cin >> limite;
	jogo->setLimite(limite);
	cout << "==============================================" << endl;
	cout << "\t      O jogo começou!" << endl;
	jogo->Jogando();
	return 0;
}