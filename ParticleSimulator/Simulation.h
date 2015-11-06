#pragma once
#include"Ball.h"
class Simulation
{
public:
    Simulation(const Ball& ball, double tStart, double tEnd, double deltaTime, const glm::dvec3& wind={0.0,0.0,0.0});
    ~Simulation();
    void update(double deltaTime);
    void run();
    Ball getBall();
private:
    Ball _ball; 


    //Simulation parameter
    double _tStart;
    double _tEnd;
    double _deltaT;


    glm::dvec3 _gravAcc{ 0.0,-9.81,0.0 };
    glm::dvec3 _vWind;
    double _rho = 1.2;
    double _dragCoeff = 0.3;

    //relevant data for collision for more complex terrain should be computed, for a flat surface can be hardcoded
    glm::dvec3 _collisionNormal{ 0.0,1.0,0.0 };
    glm::dvec3 _collisionTangent{ 1.0,0.0,0.0 };
    double _collisionEps = 0.9;
   
};

