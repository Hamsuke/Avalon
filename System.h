//
// Created by hamsuke on 20/11/18.
//

#ifndef TEORIA_DE_LA_COMPUTACION_SYSTEM_H
#define TEORIA_DE_LA_COMPUTACION_SYSTEM_H

#include "Knight.h"
#include "Monster.h"
#include "Objects.h"
#include "Actions.h"

actions actions1;

using namespace std;

class sys{
private:
    int opc=0;
public:
    void show();
    void knightTurn();
    void koboldTurn();
};

void sys::show() {
    std::cout<<"Name:  "<<player.getName()<<"                "<<"Name:   "<<kobold.getName()<<std::endl;
    std::cout<<"Hp:    "<<player.getHp()<<"                      "<<"Hp:     "<<kobold.getHp()<<std::endl;
    std::cout<<"Armor: "<<player.getArmor()<<"                      "<<"Armor:  "<<kobold.getArmor()<<std::endl;
    std::cout<<"Str:   "<<player.getStr()<<"                       "<<"Menace: "<<kobold.getMenace()<<"%"<<std::endl;
    std::cout<<"Dex:   "<<player.getDex()<<"                       "<<"Status: "<<kobold.getStatus()<<std::endl;
    std::cout<<std::endl;
}

void sys::knightTurn() {
        do {
            cout << "Choose a option" << endl;
            cout << "1.Attack" << endl;
            cout << "2.Use a skill" << endl;
            cout << "3.Use a object" << endl;
            cin >> opc;
            switch (opc) {
                case 1:
                    actions1.knightAttack(opc);
                    break;
                case 2:
                    actions1.knightSkill(opc);
                    break;
                case 3:
                    actions1.knightObject(opc);
                    break;
            }
        }while(opc!=1 and opc!=2 and opc!=3);
}

void sys::koboldTurn() {
    srand(time(NULL));
    int tmp=0;
    float percentilHP=kobold.getHp();
    float percentilM;
    percentilM=(kobold.getMorale()/100)*100;
    percentilHP=(percentilHP/kobold.getMaxHP()*100);
    kobold.setMenace(((percentilHP+percentilM)/2));

    if(kobold.getMenace()>50) {
        tmp = (rand() % 2) + 1;
        if (tmp == 1) {
            actions1.koboldAttack();
        }
        if (tmp == 2) {
            actions1.koboldSkill();
        }
    }

    if(kobold.getMenace()>30 and kobold.getMenace()<51){
        tmp=0;
        tmp = (rand() % 101) + 1;
        if(tmp>30){
            if(kobj.potuses>0) {
                actions1.koboldObject();
            }else{
                tmp=0;
                tmp = (rand() % 101) + 1;
                if(tmp>0 and tmp<41){
                    actions1.koboldAttack();
                }
                if(tmp>40 and tmp<71){
                    actions1.koboldSkill();
                }
                if(tmp>70 and tmp<101){
                    actions1.koboldEscape();
                }
            }
        }
    }

    if(kobold.getMenace()>1 and kobold.getMenace()<31){
        actions1.koboldEscape();
    }

    if(kobold.getHp()<kobold.getMaxHP()){
        tmp=0;
        tmp=kobold.getHp()+5;
        kobold.setHp(tmp);
        cout<<kobold.getName()<<" recovered HP due to pasive skill"<<endl;
        if(kobold.getHp()>kobold.getMaxHP()){
            kobold.setHp(kobold.getMaxHP());
        }
        tmp=0;
        tmp=kobold.getMorale()-5;
        kobold.setHp(tmp);
        cout<<kobold.getName()<<" lost morale due to pasive skill"<<endl;
    }
}

#endif //TEORIA_DE_LA_COMPUTACION_SYSTEM_H