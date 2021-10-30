//
// Created by hamsuke on 7/11/18.
//

#ifndef TEORIA_DE_LA_COMPUTACION_ACTIONS_H
#define TEORIA_DE_LA_COMPUTACION_ACTIONS_H

#include <iostream>
#include <ctime>

#include "Knight.h"
#include "Monster.h"
#include "Objects.h"

using std::cout;
using std::endl;
using std::cin;

monster kobold;
knight player;
objects knobj;
objects kobj;

class actions{
public:
    int attack(const int &, const int &, const int &);
    int doubleAttack(const int &, const int &, const int &);
    int tripleAttack(const int &, const int &, const int &);

    void dracoBreath();
    void dracoAttack();

    void knightAttack(int &);
    void knightSkill(int &);
    void knightObject(int &);

    int mightyStrike();

    void koboldAttack();
    void koboldSkill();
    void koboldObject();
    void koboldEscape();
};

int actions::attack(const int & A, const int & S, const int & W){
    srand(time(NULL));

    int aux=(rand()%21)+S;
    if(aux-S<=1){
        return 0;
    }
    if(aux>A and aux-S<20){
        return W+S;
    }
    if(aux-S==20){
        return (W+S)*2;
    }
}

int actions::doubleAttack(const int & A, const int & S, const int & W) {
    srand(time(NULL));

    int aux=(rand()%21)+S;
    if(aux-S<=1){
        std::cout<<"Critical failure"<<std::endl;
    }
    if(aux>A and aux-S<20){
        return (W+S)*2;
    }
    if(aux-S==20){
        std::cout<<"Critical hit"<<std::endl;
        return (W+S)*4;
    }
}

int actions::tripleAttack(const int & A, const int & S, const int & W){
    srand(time(NULL));

    int aux=(rand()%21)+S;
    if(aux-S<=1){
        return 0;
    }
    if(aux>A and aux-S<20){
        return (W+S)*3;
    }
    if(aux-S==20){
        return (W+S)*6;
    }
}

void actions::dracoBreath() {
    srand(time(NULL));
    int tmp=0;
    tmp=(rand()%12)+1;
    player.setHp((player.getHp()-tmp));
    cout<<kobold.getName()<<" used dracobreath throwing a fire storm from his mouth"<<endl;
    cout<<"Inflicted "<<tmp<<" "<<"damage"<<endl;
}

void actions::dracoAttack() {
    int tmp=0;
    tmp=(rand()%15)+1;
    player.setHp((player.getHp()-tmp));
    cout<<kobold.getName()<<" bites you and throws you to in the air while a fire storm escape from his mouth"<<endl;
    cout<<"Inflicted "<<tmp<<" "<<"damage"<<endl;
}

void actions::knightAttack(int &o) {
    int tmp;
    tmp=attack(kobold.getArmor(), player.getStr(), knobj.getSword());
    kobold.setHp((kobold.getHp() - tmp));
    if(tmp>0){
        cout<<"You hit your enemy with a single strike dealing "<<tmp<<" of damage"<<endl;
    }else{
        cout<<"Missed attack"<<endl;
    }
}

int actions::mightyStrike() {
    srand(time(NULL));
    int tmp;
    tmp=(rand()%15)+1;
    return tmp;
}

void actions::knightSkill(int &o) {
    int t2;
    int tmp;
    do {
        cout << "Choose a option" << endl;
        cout << "1.Spinning blade " << endl;
        cout << "2.Mighty strike "<< endl;
        cout << "3.Return" << endl;
        cin >> t2;
        switch (t2) {
            case 1:
                tmp=doubleAttack(kobold.getArmor(), player.getStr(), knobj.getSword());
                kobold.setHp((kobold.getHp() - tmp));
                cout<<"You spin your sword against your opponent dealing "<<tmp<<" damage"<<endl;
                break;

            case 2:
                tmp=mightyStrike();
                kobold.setHp((kobold.getHp()-tmp));
                cout<<"You swing your sword with all your strength dealing "<<tmp<<" damage to your enemy"<<endl;
                break;
            case 3:
                o=0;
                break;
                }
    }while (t2!=1 and t2!=2 and t2!=3);
}

void actions::knightObject(int &o) {
    int t4;
    do {
        cout << "Backpack" << endl;
        cout << "Name          " << "Uses" << endl;
        cout << "1.Potion      " << "< " << knobj.potuses << " >" << endl;
        cout << "2.Bomb        " << "< " << knobj.bombuses << " >" << endl;
        cout << "3.Return" << endl;
        cin >> t4;
        switch (t4){
            case 1:
            if (knobj.potuses > 0) {
                player.setHp((player.getHp() + knobj.getPotion()));
                knobj.potuses--;
            } else {
                cout << "No more potions available" << endl;
                t4=0;
            }
        break;
            case 2:
            if (knobj.bombuses > 0) {
                int tmp=knobj.getBomb();
                kobold.setHp((kobold.getHp()-tmp));
                knobj.bombuses--;
            } else {
                cout << "No more bombs available" << endl;
                t4=0;
            }
            break;
            case 3:
                o=0;
                break;
        }
    }while(t4!=1 and t4!=2);
}

void actions::koboldEscape() {
    kobold.setStatus("Escaped");
}

void actions::koboldAttack() {
    int tmp=0;
    cout<<kobold.getName()<<" "<<"attacked"<<endl;
    tmp=attack(player.getArmor(),kobold.getStr(),kobj.getSword());
    player.setHp((player.getHp()-tmp));
    if(tmp>0){
        cout<<"Inflicted "<<tmp<<" "<<"damage"<<endl;
    }else{
        cout<<"Missed attack"<<endl;
    }
}

void actions::koboldSkill() {
    srand(time(NULL));
    int tmp=0;
    tmp=(rand()%99)+1;
    if(tmp<34 and tmp>0){
        dracoBreath();
    }
    if (tmp<67 and tmp>33){
        dracoAttack();
    }
    if (tmp<100 and tmp>66) {
        tmp=tripleAttack(player.getArmor(), kobold.getStr(), kobj.getSword());
        player.setHp((player.getHp()-tmp));
        cout<<"The "<<kobold.getName()<<" move its blade in a hypnotic way hitting you 3 times dealing "<<tmp<<" of damage"<<endl;
    }
}

void actions::koboldObject() {
        cout<<kobold.getName()<<" used a potion"<<endl;
        int tmp=kobj.getPotion();
        kobold.setHp((kobold.getHp()+tmp));
        kobj.potuses--;
}

#endif //TEORIA_DE_LA_COMPUTACION_ACTIONS_H
