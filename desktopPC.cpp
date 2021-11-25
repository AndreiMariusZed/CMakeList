#include<iostream>
#include "pc.cpp"

class desktopPC:public pc{
    private:
    int nrOfCustomizableVents;
    bool dustFilter;

    public: 
    desktopPC(const int &nrOfCustomVents,const bool &dustFil,const std::string &processoR,const int &weighT,const int &heighT,const int &widtH,const std::string &coloR )
    :pc(processoR,weighT,heighT,widtH,coloR),
    nrOfCustomizableVents(nrOfCustomVents),
    dustFilter(dustFil){

    }
    desktopPC& operator =(const desktopPC &p){
        if(this==&p){
            std::cout<<"Assign to self desktop "<<std::endl;
            return *this;
        }
        std::cout<<"Copy assignment operator desktop"<<std::endl;
        pc::operator=(p);
        nrOfCustomizableVents = p.nrOfCustomizableVents;
        dustFilter=p.dustFilter;

        return *this;
    }
    desktopPC& operator +=(const desktopPC &p){
        std::cout<<"Add operator desktop"<<std::endl;
        pc::operator+=(p);
        nrOfCustomizableVents += p.nrOfCustomizableVents;
        dustFilter=p.dustFilter;

        return *this;
    }
    void setColor(const std::string &coloR){
        pc::setColor(color);
        std::cout<<"The desktop's color has been changed"<<std::endl;
    }
    void addVents(const int &numberV){
        this->nrOfCustomizableVents += numberV;
    
    }
    void getV(){
        std::cout<<"Number of customizable vents is :"<<this->nrOfCustomizableVents<<std::endl;
    }
    void removeDustFilter(){
        this->dustFilter = false;
    }
    void getDustFilter(){
        std::cout<<"Does desktop has filter : "<<this->dustFilter<<std::endl;
    }
    ~desktopPC(){
        std::cout<<"desktopPC destructor"<<std::endl;
    }
    

};