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