//
//	Game.h
//	Game
//
//	Created by Lucas Nathaniel on 15/10/16;
//	Copyright (c) 2016 Lucas Nathaniel. All rights reserved.
//
#ifndef __Game__Game__
#define	__Game__Game__

#include <iostream>

class Game{
private:
	int Quantity;
	int Limit;
public:
	Game();
	~Game();
	void Insert(int Value);
	int getQuantity();
	void Playing();
	void setLimit(int l);

};


#endif /* defined(__Game__Game__) */