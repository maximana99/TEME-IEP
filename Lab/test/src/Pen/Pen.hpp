#ifndef PEN_HPP
//verifies if the library is not already declared 
#define PEN_HPP

class Pen{
    
        private: 
        std::string color="white";
        std::string rubber="red";

        public:
        Pen();

        Pen(const Pen &p);

        Pen& operator=(const Pen &p);

        std::string getRubber();

};


#endif
