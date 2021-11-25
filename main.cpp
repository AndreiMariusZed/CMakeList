#include<iostream>
//#include"pc.cpp"
#include "laptop.cpp"
#include "desktopPC.cpp"

int main(){
    pc p1("AMD",1,12,15,"gray");
    
    laptop l1(200,50,"INTEL",2,23,10,"black");
    laptop l6(600,50,"INTEL",2,23,10,"yellow");

    //laptop l2(l1);
    laptop *l4 = new laptop(120,40,"AMD",23,20,20,"blue");
    //l1 = *l4; 

    l4->getBatteryLevel();
    l4->getColor();
    l4->setColor("red");
    l4->getProcessor();
    

    desktopPC d1(5,true,"Apple M1",10,23,24,"white");
    d1.getV();
    d1.addVents(3);
    d1.getV();

    
    p1.getColor();
    p1.getProcessor();
    p1.setColor("cyan");
    p1.getColor();
    {
        desktopPC *d2 = new desktopPC(7,true,"AMD",23,23,23,"yellow");
        d2->getDustFilter();
        d2->removeDustFilter();
        d2->getDustFilter();



        delete d2;

    }
    laptop l5(300,60,"INTEL",2,23,10,"black");;
    l5.getDisplayFrequency();
    l4->getDisplayFrequency();
    l5 = l1=*l4;
    l5.getDisplayFrequency();
    l1=l1;
    l1.getDisplayFrequency();

    l5+=l1+=*l4;
    l5.getDisplayFrequency();
    l1.getDisplayFrequency();
    
    l5.getColor();
    l5.color="white";
    l1 = l5;
    l1.getColor();

    return 0;
}