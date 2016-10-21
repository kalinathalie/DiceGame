//
//	main.cpp
//	Game
//
//	Created by Lucas Nathaniel on 15/10/16;
//	Copyright (c) 2016 Lucas Nathaniel. All rights reserved.
//

#include <iostream>
#include "Game.h"
#include "Players.h"
#include "stdlib.h"

using namespace std;

int main(){
	system("clear");
	cout << "        Welcome to the DiceGame -0.02" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "How many players will to play?" << endl;
	int players;
	cin >> players;
	if(players <= 0){
		cout << "Nobody wants play" << endl;
		return 0;
	}
	if(players == 1){
		cout << "Dont be a Forever Alone" << endl;
		return 0;
	}
	Game* game = new Game();
	for(int i=1; i<=players; i++){
		game->Insert(0);
	}
	cout << "Which the max number?" << endl;
	int Limit;
	cin >> Limit;
	if(Limit <= 0){
		cout << "Nobody wants play" << endl;
		return 0;
	}
	game->setLimit(Limit);
	cout << "==============================================" << endl;
	cout << "              Game started!" << endl;
	game->Playing();
	return 0;
}