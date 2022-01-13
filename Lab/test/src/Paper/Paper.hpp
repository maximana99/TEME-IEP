#ifndef PAPER_HPP
//verifies if the library is not already declared 
#define PAPER_HPP

class Paper{
    
        private: 
        std::string script="black";
        std::string color="purple";
        Paper(const Paper &p);
        Paper& operator=(const Paper &p);

        public:
        Paper();
        
        std::string getScript();

        
};


#endif
