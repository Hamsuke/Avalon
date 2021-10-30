//
// Created by hamsuke on 7/11/18.
//

#ifndef TEORIA_DE_LA_COMPUTACION_OBJECTS_H
#define TEORIA_DE_LA_COMPUTACION_OBJECTS_H

#include <iostream>
#include <ctime>

class objects{
private:
    int potion;
    int sword;
    int dagger;
    int bomb;

public:
    int getPotion();
    int getSword();
    //int getDagger();
    int getBomb();

    int bombuses;
    int potuses;
};

int objects::getSword() {
    srand(time(NULL));
    sword=(rand()%10)+1;
    return sword;
}

int objects::getPotion() {
    srand(time(NULL));
    potion=2+((rand()%8)+1);
    return potion;
}

int objects::getBomb() {
    srand(time(NULL));
    bomb=(rand()%12)+1;
}

#endif //TEORIA_DE_LA_COMPUTACION_OBJECTS_H
