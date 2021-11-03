#include<iostream>

#ifndef pc_cpp
#define pc_cpp

class pc{

    protected:
    std::string processor;
    int weight;
    int height;
    int width;
    std::string color;
    
    public:
    pc(const std::string &processoR,const int &weighT,const int &heighT,const int &widtH,const std::string &coloR)
    :processor(processoR),
    weight(weighT),
    height(heighT),
    width(weighT),
    color(coloR)
    {

    }
    pc(const pc &p)=delete;
    pc& operator =(const pc &p);

    virtual void getProcessor(){
        std::cout<<"The processor is : "<<this->processor<<std::endl;
    }
    virtual void setColor(const std::string &coloR){
        this->color = coloR;
    }
    void getColor(){
        std::cout<<"Color is :"<<this->color<<std::endl;
    }
    ~pc(){
        std::cout<<"Pc destructor"<<std::endl;
    }


};

#endif
