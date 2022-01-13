#include <iostream>
#include "Paper.hpp"




    Paper::Paper(): script("yellow"){
        std::cout<<"Paper with script color: "<<this->script<<std::endl;
    }

    Paper::Paper(const Paper &p){ //copy constructor
        this->script=p.script;
        std::cout<<"Paper with script color: "<<p.script<< " from copy operator"<<std::endl;
    }

    //Papper::Paper(const Paper &p)=delete;
    //Papper::Paper(const Paper &p);

    Paper& Paper::operator=(const Paper &p)//copy assigment operator
    {
        if( this == &p )
        {
            return *this;
        }
        
        this->script=p.script;
        std::cout<<"Paper with script color: "<<p.script<< " from assigment operator"<<std::endl;

        return *this;
    }
    std::string Paper::getScript()
     {
                return this->script;
     }

    