#include <iostream>
//pentru item 11
//problema adusa de pointeri - timpul pierdut la copierea aceluiasi obiect, se copieaza aceleasi campuri
//                           - am ajunge sa stergem pointerul din obiect inainte de ai face o copie -> pointer care nu pointeaza catre nimic.
//                           - pentru a evita acest lucru apare "if" si verificam daca referinta obiectului curent este acelasi cu referinta pb pe care apelam functia
//                           - daca referintele sunt aceleasi putem sa returnam oricare dintre obiecte cu return *this
//                           - daca obiectele nu pointeaza catre acelasi lucru atunci putem sa stergem pointerul nostru (this) si sa il folosim pe cel din functie, astfel
//la stergere suntem siguri ca nu stergem ambele instante


//al doilea mod este atunci cand - ne cream un obiect temporar care sa contina o valoare a pointerului nostre ex pb local din this
//                               - dupa putem sa ne recream pb facand o copie iar apoi sa putem sterge in siguranta pointerul original,
//                               - astfel ocolim cazul in care stregem la inceput referintele
class Vehicul  
{
    private:
    int putere = 400;
    std::string marca = "AUDI";

    public:
    Vehicul(){
        std::cout<<"CONSTRUCTORIL NO ARG" <<std::endl;
    }
    //constructorul cu parametrii imi initializeaza valoarea puterii
    Vehicul(int putere){
        this->putere = putere;
        std::cout<<"CONSTRUCTORIL cu parametrii" <<std::endl;
    }
    
    Vehicul(const Vehicul &d){
        std::cout << "COPY CONSTRUCTOR!" <<std::endl;
        this->putere = putere;
        this->marca = marca;
    }
    //operatorul de incrementarea care adauga valoarea puterii pe care se apeleaza functia si returnez in stanga 
    //adica am trimis catre cealalta apelare a functiei variabila respectiva
    Vehicul& operator=(const Vehicul& d){
        if(this == &d){//partea in care se verifica partea de self, daca am elimina acest if va face pur si simplu
        //copierea din obievtul care se afla in dreapta in campurile lui this
            std::cout << "selfff" <<std::endl;
            return *this;
        }
        std::cout << "COPY assingment operator cu return" <<std::endl;
        putere = d.putere;//adica putere este campul care apartine obiectului care defapt initiaza aceasta opetatie de asignare 
        //pointerul this se refera la obiectul asupra caruia se executa o functie anume, obiectul clasei despre care vorbim
        marca = d.marca;
    return *this;
    }
        
 

    int printPutere(){
        std::cout << "Puterea este" << putere << std::endl;
        return this->putere;
    }

    std::string printMarca(){
        std::cout << "Marca este" <<std::endl;
        return this->marca;
    }

    void setMarca(std::string marca){
        this->marca = marca;
    }

    ~Vehicul(){
        std::cout << "DESTRUCTOOR!" <<std::endl;
    }

};

int main(){


    Vehicul a;//new Vehicul();
    

    std::cout<<" puterea lui a" <<a.printPutere()<<std::endl;
    a = a;//exact asta se intampla se verifica referintele si se gasesc egale acestea si se returneaza unul din pointeri
    std::cout<< "Merge" <<std::endl;
}