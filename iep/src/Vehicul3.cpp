#include <iostream>
//pentru itemul 12 trebuie sa fi atenti sa copiem toate partile unui obiect
//cazul in care avem o clasa de baza si una derivata, atunci cand adaugam un camp nou, iar item-ul ne spune ca
//trebuie sa ne adaugam respectivul camp si in COPY CONSTRUCTOR SI OPERATOR,
//deoarece in clasa derivata vom face o copiere a obiectului din clasa de baza


class Vehicul  
{
    public:
    int putere = 400;
    std::string marca = "AUDI";

    
    Vehicul(){
        std::cout<<"CONSTRUCTORIL NO ARG" <<std::endl;
    }
   
    Vehicul(int putere){
        this->putere = putere;
        std::cout<<"CONSTRUCTORIL cu parametrii" <<std::endl;
    }
    
    Vehicul(const Vehicul &d){
        std::cout << "COPY CONSTRUCTOR!" <<std::endl;
        this->putere = putere;
        this->marca = marca;
    }
//atunci cand creeam acest assignment operator implementarea va fi exact asa cum o vom face noi

    Vehicul& operator=(const Vehicul& d){
        if(this == &d){
            std::cout << "copy de selfff" <<std::endl;
            return *this;
        }
        std::cout << "COPY assingment operator cu return" <<std::endl;
        putere = d.putere;
        marca = d.marca;
    return *this;
    }
        
   
    ~Vehicul(){
        std::cout << "DESTRUCTOOR!" <<std::endl;
    }

};