#include <iostream>
#include <ctime>

#include "System.h"

sys start;

int main() {

    player.setName("Stronoff");
    player.setArmor(14);
    player.setDex(1);
    player.setStr(3);
    player.setHp(95);
    knobj.bombuses=3;
    knobj.potuses=3;

    /*
    kobold[0].setName("Kobold1");
    kobold[0].setArmor(12);
    kobold[0].setDex(3);
    kobold[0].setStr(1);
    kobold[0].setHp((rand()%7)+10);
    kobold[0].setMorale(70);
    kobj[0].potuses=1;

    kobold[1].setName("kobold2");
    kobold[1].setArmor(12);
    kobold[1].setDex(3);
    kobold[1].setStr(1);
    kobold[1].setHp((rand()%7)+10);
    kobold[1].setMorale(70);
    kobj[1].potuses=1;
     */

    kobold.setName("Draco warrior");
    kobold.setArmor(14);
    kobold.setDex(2);
    kobold.setStr(4);
    srand(time(NULL));
    kobold.setHp((rand()%11)+30);
    kobold.setMaxhp();
    kobj.potuses=2;

    do{
        start.show();
        if(player.isAlive()) {
            start.knightTurn();
            if(kobold.getHp()<=0){
                kobold.setStatus("Death");
            }
        }
        if(kobold.getStatus()=="Alive"){
            start.koboldTurn();
        }
    }while (player.isAlive() and kobold.getStatus()=="Alive");

        if(kobold.getStatus()=="Death"){
            cout<<kobold.getName()<<" falls on his knees covered in blood "<<endl;
            cout<<"You win"<<endl;
        }
        if(kobold.getStatus()=="Escaped"){
            cout<<kobold.getName()<<" Runs from the battle in a cowardly way, what a disgrace to its race "<<endl;
            cout<<"You win"<<endl;
        }
        if(!player.isAlive()) {
            cout << "You drop your sword and fall while you feel the life leaving your body"<<endl;
            cout << "Game Over" << endl;
        }
}