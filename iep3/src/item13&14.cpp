//item 13 use objects to manage resources -> managementul resurselor in C++ -> atunci cand alocam memorie pt un pointer 
//veti folosi pointerul respectiv si la un moment dat vrem sa facem dezalocare, sau sa adune memorie la care nu vom mai avea acces, pt ca nu avem garbage collector 
//aici ne referim la smart pointers 
//tipuri de smart poinnters 
//   -auto_ptr, unique_ptr, shared_ptr, weak_ptr
//exemplu pg 62 crearea unui pointer care la un moment dat va fi sters, adica se va apela destructorul //si se elibereaza memoria acestui pointer 
//dar ce se intampla daca pe parcurs facem un return, exemplu throw eroare si astfel nu se mai ajunge la partea asta de delete 
//-> memorie care nu este eliberata (in general pe hardware memorie e mereu limitata si poate sa ajunga la un caz in care ocupa foarte multa- de evitat)

//auto_ptr nu se mai foloseste deoarece problema era atunci cand cand faci copierea unui astfel de pointer auto_ptr i se va schimba owner shippul 
//exemplu atunci cand cream in plnv2 o copie a lui pnlv1 se schimba, 1 devine null, iar 2 pointeaza catre zona de memorie catre care pointa inainte 1 
//s-ar putea ajunge si la cazul in care am trece printr-o functie iar la final acestia sa fie nuli - de evitat 
//daca vrem sa facem schimbare de ownership o sa avem operatia move 


// item 14 : orientat pe cazul  in care nu avem un obiect stocat in heap - nu e alocat dinamic 
//in heap variabilele ce sunt alocate dinamic cu new/malloc...partea de date initializate si textul partea de cod 
//stiva stack functi lifo - aici var locale, parametrii functiei, diverse adrese de return 
//fiecare functie are o adresa in memorie ,resp adresa =adresa de la care se executa -> se face jump la adresa fct respective de unde se exec insttuct
//camd se face acest jump trebuie sa stim unde sa ne si intoarcem si cu ce valori te intorci in main spre ex
//astfel in stack se va salva - adresa de la care plecam si valorile variabilelor locale

//idea de MUTEX- 1 mutex era folosita la thread-uri care sunt mai multe care ruleaza in paralel 
//si ai o resursa la care respectivele threaduri vor sa aiba acces atunci trebuie sa facem un tip de managemnt 
//care sa nu fie un thread care scrie resursa resp si un altul care sa o citeasca in acelasi timp -> ex la socket

#include<iostream>
#include<memory>

//item 13
//am alocat memorie pt un obiect pe care l-am pus intr-o variabila, iar la final vrem sa ne asiguram ca obiectul este distrus, memorie este eliberata
class Masina{
    private:
    int putere = 400;
    std::string marca = "AUDI";

    public:
    Masina(){
        std::cout<<"CONSTRUCTOR FARA PARAMETRII " << std::endl;
    }

    Masina(int putere){
        this->putere = putere;
        std::cout<<"CONSTRUCTOR 1 PARAMETRu " << std::endl;
    }

    Masina(const Masina &d){
        std::cout<<" COPY CONSTRUCTOR " << std::endl;
        this->putere = d.putere;
        this->marca = d.marca;
    }

    Masina& operator=(const Masina& d){
        std::cout<<"Copy assignment operator cu return " << std::endl;
        putere = d.putere;
        marca = d.marca;
    return *this;
    }

    Masina& operator+=(const Masina& d){
        std::cout<<"OPERATOR +=" << std::endl;
        putere += d.putere;
        marca += d.marca;
    return *this;
    }

    int printPutere(){
        std::cout<<"puterea " << putere << std::endl;
        return this->putere;
    }

    std::string printMarca(){
        std::cout<<"marca " << marca << std::endl;
        return this->marca;
    }

    void setMarca(std::string marca){
        this->marca = marca;
    }

    ~Masina(){
        std::cout <<"Destructor "<< std::endl;
    }

};

//aici - design pattern factory care are o functie care creeaza obiectul 

using namespace std;
Masina* createMasinaInstance(){
    return (new Masina);
}


//item 14
class Laptop{
    private:
    int baterie = 80;
    bool isLocked = false;

    public:
    Laptop(){
        std::cout<<"CONSTR FARA PARAM" <<std::endl;
    }

    Laptop(int baterie){
        this->baterie = baterie;
        std::cout<<"CONSTR 1 PARAM" <<std::endl;
    }

    Laptop(const Laptop &d){
        std::cout<<" COPY CONSTR" <<std::endl;
        this->baterie = d.baterie;
        this->isLocked = d.isLocked;
    }

    int printBaterie(){
        std::cout<<"baterie = " << baterie << std::endl;
        return this->baterie;
    }

    bool printisLocked(){
        std::cout<<"isLocked = " << isLocked << std::endl;
        return this->isLocked;
    }

    void setisLocked(bool isLocked){
        this->isLocked = isLocked;
    }

    ~Laptop(){
        std::cout <<"Destructor "<< std::endl;
    }

    void askLaptop(){
        if(this->isLocked) {
            std::cout <<"RESURSA E BLOCATA "<< std::endl;
        }else {
            std::cout <<"RESURSA POATE FI FOLOSITA "<< std::endl;
        }
    }

};
//immplementare asem cu cea din carte 
void lock(Laptop &r){
    std::cout <<"Locking laptop "<< std::endl;
    r.setisLocked(true);
}

void unlock(Laptop &r){
    std::cout <<"Unlocking laptop "<< std::endl;
    r.setisLocked(false);
}
class LockLaptop{
//in constructor vom bloca laptopul si in destructor il vom elibera 
    private:
        Laptop &lockPtr;
    
    public:
    LockLaptop(Laptop &ptr):
    lockPtr(ptr){
        lock(lockPtr);
    }

    ~LockLaptop(){
        unlock(lockPtr);
    }
};

int main(){

    //item 13
    std::cout<<"....auto"<<std::endl;
    {
        auto_ptr<Masina> smallMasina(createMasinaInstance());
        //punem un obiect de tip Masina in acest pointer 
        //acest modul de folosire e deprecated - exista unique_ptr in loc
        smallMasina->printPutere();//afiseaza 400
        auto_ptr<Masina> smallMasina2(smallMasina);//facem aceasta copiere 

        smallMasina2->printPutere();//afiseaza 400
        //smallMasina->printPutere(); daca vrem sa printam asta putem vedea ca avem segmentation fault -> deoarece smallMasina devine null 
    }

    std::cout<<".....unique"<<std::endl;
    {
        unique_ptr<Masina> uniqueMasina(createMasinaInstance());
        uniqueMasina->printPutere();
        //unique_ptr<Masina> uniqueMasina2(uniqueMasina);//dar nu putem sa il copiem pt ca e un unique_ptr
        unique_ptr<Masina> uniqueMasina2 = move(uniqueMasina); // e un transfer de ownership, nu e o copiere - il mut in alt obiect 
    }

    std::cout<<".......shared"<<std::endl;
    { 
        shared_ptr<Masina> sharedMasina(createMasinaInstance());
        //putem sa il copiem si in momentul in care il copiem este incrementat un counter = nr de copii ale obiectului 
        //astfel obiectul va fi distrus doar in momentul in care numarul de copii ale obiectului ajunge la 0
        sharedMasina->printPutere();//afisez puterea 
        std::cout<<"sharedMasina count = "<<sharedMasina.use_count()<<std::endl;//afiseaza nr de instante la un moment dat - count=1
        shared_ptr<Masina> sharedMasina2(sharedMasina);//fac o copie 
        std::cout<<"sharedMasina count = "<<sharedMasina.use_count()<<std::endl;//aici count = 2
        sharedMasina2->printMarca();
        sharedMasina2->setMarca("bmw");
        sharedMasina2->printMarca();//ambii pointeri pointeaza spre acelasi obiect, daca modifucam intr-o parte se modif ambele valori-> devine bmw

        shared_ptr<Masina> sharedMasina3 = move(sharedMasina); //tot transfer de ownership, nu e o copiere
        //sharedMasina nu o sa mai fie owner0ul resursei si o sa devine acest sharedMasina3
        std::cout<<"sharedMasina count = "<<sharedMasina.use_count()<<std::endl;//aici count = 0 e pur si simplu null, nu pointeaza catre ceva 
        //si am avea segmnetation fault daca apeleazi ceva pe el 
        std::cout<<"sharedMasina3 count = "<<sharedMasina3.use_count()<<std::endl;//count =2 - a preluat de la sharedMasina toate proprietatile 
        sharedMasina3->setMarca("mmmm");
        sharedMasina3->printMarca();

        sharedMasina2->printMarca();//ambele pointeaza catre aceeasi zona de memorie 

        std::cout<<".....weak"<<std::endl;
        //e o copie a lui shared_ptr, fara sa incrementeze counterul de copii


    }
    
    
    //item 14
    Laptop res(55);
    //atunci cand avem un thread care vrea sa faca edit de laptop, altul de ciire 
    LockLaptop *lockedLaptop = new LockLaptop(res);
    //seteaza flag-ul acesta de locked - primul thread de scriere/edit care preia laptopul foloseste LockLaptop iar editarea se face doar de catre el 
    //dupa ce a incheiat opratiunea de scriere va fi distrusa aceasta clasa de lockedLaptop - se folo destructorul clasei 
    // si o sa ni se elibereze resursa, mai departe poate sa vina urmatorul thread care era in asteptare sa preia resursa si sa citeasca inf de acolo 
    res.askLaptop();
    delete lockedLaptop;
    res.askLaptop();
    std::cout<<"Merge"<<std::endl;


    //la afisare - se apeleaza constructorul nostru
    // locking laptop
    // laptopul e blocat
    //Unlocking - pt delete
    //REsursa nu poate fi folosita
    //merge
    //destructor

}

