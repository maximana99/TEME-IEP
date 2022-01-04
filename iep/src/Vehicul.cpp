#include <iostream>

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
        std::cout << "COPY assingment operator cu return" <<std::endl;
        putere = d.putere;
        marca = d.marca;
    return *this;
    }
        
    Vehicul& operator+=(const Vehicul& d){
        std::cout << "Operator += " <<std::endl;
        putere += d.putere;
        marca += d.marca;
    return *this;//daca il comentam atunci la al doilea apel, la linia 75, el nu o sa stie pe cine sa il asigneze pe primul -> eroarea de bad_alloc
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
    Vehicul v1(200);
    Vehicul v2(300);

    Vehicul b = a;
    v1=b=v2;//se apeleaza primul operator
    //se ia de la stanga la dreapta -invers
    std::cout<< v1.printPutere() <<std::endl;//devine 300 v1=v2
    std::cout<< v2.printPutere() <<std::endl;//ramane 300
    std::cout<< a.printPutere() <<std::endl;//ramane 400

    //aici se va apela al doilea operator
    a +=v1+= v2; //aici se vede cum e cu return-ul
    //se face partea aceasta de inlantuire si la final vrem sa vedem puterea obiectului a

    std::cout<<" puterea lui a" <<a.printPutere(); //a in final va fi 10000
    std::cout<< "Merge" <<std::endl;
}