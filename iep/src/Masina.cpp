#include <iostream>
#include "Vehicul3.cpp"
class Masina : public Vehicul
{
    private:
    std::string nume = "Renault Capture";
    std::string anFabricatie = "2010";
    static int count;


    //aici in cazul constructorului vrem sa se apeleze si cel din clasa de baza - linia 14

    public:
    Masina():Vehicul(){
        count++;
        std::cout<< "Masina constructor"<<std::endl;

    }

    Masina& operator=(const Masina& m){
        if(this == &m){
            std::cout << "copy de selfff" <<std::endl;
            return *this;
        }

        Vehicul::operator=(m);  
        //daca decomentam aceasta linie unde ne apelam operatorul de asignare din clasa de baza
        //ii spunem clasa de baza, ce vrem sa se apeleze adica operatorul de asignare pe exact acelasi obiect, 
        //iar daca facem din nou executia va fi BMW - copiza putere si marca
        std::cout << "COPY assingment operator masina" <<std::endl;
        nume = m.nume;
        anFabricatie = m.anFabricatie;
    return *this;
    }

    void printNume(){
         std::cout << "numele este" << nume << std::endl;
        
    }

    void printAn(){
         std::cout << "anul este" << anFabricatie << std::endl;
        
    }

    void setTHings(int a){
        this->count = a;
    }

    ~Masina(){
        std::cout<<"Masina destructor"<<std::endl;
    }
};