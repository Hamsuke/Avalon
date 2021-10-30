//
// Created by hamsuke on 9/10/18.
//

#ifndef TEORIA_DE_LA_COMPUTACION_MONSTER_H
#define TEORIA_DE_LA_COMPUTACION_MONSTER_H

#include <string>
#include <iostream>

using std::string;

class monster{
private:
    string status;
    string name;
    int hp;
    int armor;
    int str;
    int dex;
    int morale;
    int maxHp;
    float menace;

public:
    monster();

    void setName(const string &);
    void setHp(const int &);
    void setArmor(const int &);
    void setStr(const int &);
    void setDex(const int &);
    void setMorale(const int &);
    void setStatus(const string &);
    void setMenace(const float &);
    void setMaxhp();

    string getName();
    int getHp();
    int getArmor();
    int getStr();
    int getDex();
    int getMorale();
    int getMaxHP();
    string getStatus();
    float getMenace();
};

monster::monster() {
    hp=0;
    armor=0;
    str=0;
    dex=0;
    morale=100;
    menace=100;
    status="Alive";
}

void monster::setStatus(const string &s) {
    status=s;
}

void monster::setName(const string & n) {
    name=n;
}

void monster::setHp(const int &h) {
    hp=h;
}

void monster::setArmor(const int &a) {
    armor=a;
}

void monster::setStr(const int &s) {
    str=s;
}

void monster::setDex(const int &d) {
    dex=d;
}

void monster::setMorale(const int &m) {
    morale=m;
}

void monster::setMenace(const float & m) {
    menace=m;
}

void monster::setMaxhp() {
    maxHp=hp;
}

string monster::getName() {
    return name;
}

int monster::getHp() {
    return hp;
}

int monster::getArmor() {
    return armor;
}

int monster::getStr() {
    return str;
}

int monster::getDex() {
    return dex;
}

int monster::getMorale() {
    return morale;
}

int monster::getMaxHP() {
    return maxHp;
}

float monster::getMenace() {
    return menace;
}

string monster::getStatus() {
    return status;
}



#endif //TEORIA_DE_LA_COMPUTACION_MONSTER_H
