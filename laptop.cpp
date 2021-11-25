#include<iostream>

#include "pc.cpp"

class laptop:public pc{
    private:
    int displayFrequency;
    float batteryLevel;

    public: 
    laptop(const int &dispFreq,const float &battLevel,const std::string &processoR,const int &weighT,const int &heighT,const int &widtH,const std::string &coloR )
    :pc(processoR,weighT,heighT,widtH,coloR),
    displayFrequency(dispFreq),
    batteryLevel(battLevel){
    }
    laptop& operator =(const laptop &p){
        if(this==&p){
            std::cout<<"Assign to self laptop "<<std::endl;
            return *this;
        }
        std::cout<<"Copy assignment operator laptop"<<std::endl;
        pc::operator=(p);
        displayFrequency=p.displayFrequency;
        batteryLevel=p.batteryLevel;

        return *this;
    }
    laptop& operator +=(const laptop &p){
        std::cout<<"Add operator laptop"<<std::endl;
        pc::operator+=(p);
        displayFrequency+=p.displayFrequency;
        batteryLevel+=p.batteryLevel;

        return *this;
    }
    void getDisplayFrequency(){
        std::cout<<"Display frequency is: "<<this->displayFrequency<<std::endl;
    }
    void setColor(const std::string &coloR){
        pc::setColor(color);
        std::cout<<"The laptop's color has been changed"<<std::endl;
    }
    void getBatteryLevel(){
        std::cout<<"Battery level is : "<<this->batteryLevel<<std::endl;
    }
    void setFrequency(const int &freq){
        this->displayFrequency = freq;
    }
    ~laptop(){
        std::cout<<"laptop destructor"<<std::endl;
    }

};