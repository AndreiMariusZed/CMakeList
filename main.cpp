#include<iostream>
//#include"pc.cpp"
#include "laptop.cpp"
#include "desktopPC.cpp"
#include<memory>

using namespace std;
pc* CreatePcInstance(){
    return (new pc("i7",2,23,24,"alb"));
}
void lock(pc &pc){
    std::cout<<"Locking "<<std::endl;
    pc.setIsLocked(true);
}
void unlock(pc &pc){
    std::cout<<"Unlocking "<<std::endl;
    pc.setIsLocked(false);
}

class Lock{
    private:
    pc &lockPtr;

    public:
    Lock(pc &ptr):
    lockPtr(ptr){
        lock(lockPtr);
    }
    ~Lock(){
        unlock(lockPtr);
    }
};
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
    l1.getDisplayFrequency();
    l1=l1;

    l5+=l1+=*l4;
    l5.getDisplayFrequency();
    l1.getDisplayFrequency();

    l5.getColor();
    l5.color="white";
    l1 = l5;
    l1.getColor();
    std::cout<<"auto"<<std::endl;
    {
        auto_ptr<pc> autopc(CreatePcInstance());
        autopc->getColor();
        auto_ptr<pc> autopc2(autopc);
        autopc2->getColor();
        // autopc->getColor();       
    }

    std::cout<<"unique"<<std::endl;
    {
        unique_ptr<pc> uniquepc(CreatePcInstance());
        uniquepc->getProcessor();
        unique_ptr<pc> uniquepc2 = move(uniquepc);
        // uniquepc->getProcessor();
        // uniquepc2->getProcessor();

    }
    std::cout<<"shared"<<std::endl;
    {
        shared_ptr<pc> sharedPc(CreatePcInstance());
        sharedPc->getProcessor();
        std::cout<<"sharedPc count = " <<sharedPc.use_count()<<std::endl;
        shared_ptr<pc> sharedPc2(sharedPc);
        std::cout<<"sharedPc count = " <<sharedPc.use_count()<<std::endl;
        sharedPc2->getColor();
        sharedPc2->setColor("red");
        sharedPc->getColor();

        shared_ptr<pc> sharedPc3=move(sharedPc);
        std::cout<<"sharedPc count = " <<sharedPc.use_count()<<std::endl;
        std::cout<<"sharedPc3 count = " <<sharedPc3.use_count()<<std::endl;
        sharedPc3->setColor("rosu");
        sharedPc3->getColor();

        sharedPc2->getColor();

        std::cout<<"weak"<<std::endl;
        weak_ptr<pc> weakCar(sharedPc3);
        std::cout<<"sharedPC3 count = " <<sharedPc3.use_count()<<std::endl;


        
    }

    pc pcLock("i9",23,24,23,"blue");
    Lock *locked = new Lock(pcLock);
    pcLock.askResource();
    delete locked;
    pcLock.askResource();

    return 0;
}