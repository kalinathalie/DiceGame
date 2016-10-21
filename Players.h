//
//	Players.h
//	Game
//
//	Created by Lucas Nathaniel on 15/10/16;
//	Copyright (c) 2016 Lucas Nathaniel. All rights reserved.
//
#ifndef __Game__Players__
#define __Game__Players__

using namespace std;

class Players{

private:
    int Value;
    Players* next;
    bool Quit = false;
    bool Lost = false;
    int Number;
public:
    Players();

    Players(int val);

    Players* getNext();

    int getValue();

    void setValue(int i);
    
    void setNext(Players* Players);

    void setQuit();

    bool getQuit();

    void setLost();

    bool getLost();

    void setNumber(int i);

    int getNumber();
};

#endif /* defined(__Game__Players__) */
