#include <iostream>
#include <Pen.hpp>
#include <Paper.hpp>
int main()
{
  
  Pen p;
  //std::cout<<p.getRubber()<<std::endl;

  Pen p2(p);
  Pen p3;
  p3=p;

  Paper pa;

  //Paper pa2(pa); //private constructor





  return 0;
}