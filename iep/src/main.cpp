#include <iostream>
#include "Masina.cpp"

int Masina::count = 0;
int main()
{
    Vehicul a;// = new Vehicul();
    std::cout<<"a.putere = "<<a.putere<<std::endl;
    a = a;
   

    Masina m1;
    Masina m2;

    m2.marca = "BMW";
    //marca este din clasa de baza de acolo il setam pe obiectul Masina, dar la afisare va fi AUDI - ce era in parinte
    //atunci cand printam e cel din clasa Vehicul, deoarece in operator de la Masina nu facem copierea elemntelor ce se afla in clasa de baza,
    //ci facem copierea strict pe cea derivata, si daca nu ii spunem nu va face nimic 
    m1 = m2;
    std::cout<<"marca este"<<m1.marca<<std::endl;

    std::cout<< "Merge" <<std::endl;
}