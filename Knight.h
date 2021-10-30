//
// Created by hamsuke on 16/10/18.
//

#ifndef TEORIA_DE_LA_COMPUTACION_KNIGHT_H
#define TEORIA_DE_LA_COMPUTACION_KNIGHT_H

#include <string>
#include <iostream>

using std::string;

class knight{
private:
    bool alive;
    string name;
    int hp;
    int armor;
    int str;
    int dex;

public:
    knight();

    void setName(const string &);
    void setHp(const int &);
    void setArmor(const int &);
    void setStr(const int &);
    void setDex(const int &);

    string getName();
    int getHp();
    int getArmor();
    int getStr();
    int getDex();
    bool isAlive();

    void menuAttack();
};

knight::knight() {
    hp=30;
    armor=0;
    str=0;
    dex=0;
    alive=true;
}

void knight::setName(const string & n) {
    name=n;
}

void knight::setHp(const int &h) {
    hp=h;
}

void knight::setArmor(const int &a) {
    armor=a;
}

void knight::setStr(const int &s) {
    str=s;
}

void knight::setDex(const int &d) {
    dex=d;
}

string knight::getName() {
    return name;
}

int knight::getHp() {
    return hp;
}

int knight::getArmor() {
    return armor;
}

int knight::getStr() {
    return str;
}

int knight::getDex() {
    return dex;
}

bool knight::isAlive() {
    if(hp<=0){
        alive= false;
        return alive;
    }
    return alive;
}

#endif //TEORIA_DE_LA_COMPUTACION_KNIGHT_H
