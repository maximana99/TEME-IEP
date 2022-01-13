#include <iostream>
#include "Pen.hpp"



    Pen::Pen(): rubber("blue"){
        std::cout<<"Pen with rubber color: "<<this->rubber<<std::endl;
    }

    Pen::Pen(const Pen &p){ //copy constructor
        this->rubber=p.rubber;
        std::cout<<"Pen with rubber color: "<<p.rubber<< " from copy operator"<<std::endl;
    }

    Pen& Pen::operator=(const Pen &p)//copy assigment operator
    {
        if( this == &p )
        {
            return *this;
        }
        
        this->rubber=p.rubber;
        std::cout<<"Pen with rubber color: "<<p.rubber<< " from assigment operator"<<std::endl;

        return *this;
    }
    std::string Pen::getRubber()
     {
                return this->rubber;
     }

   
    


