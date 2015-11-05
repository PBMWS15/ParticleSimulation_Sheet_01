#include "Ball.h"

int main(int argc, char** argv)
{
    Ball test{ {1,2,3},12,3 };

    Particle& k = test;
    k.update();
    std::cout << test.getMass() << std::endl;
    int a;
  

    return 0;


}