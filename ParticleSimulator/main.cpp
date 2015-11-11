#include "Ball.h"
#include "Simulation.h"
#include <iostream>


void printVector(const glm::dvec3& vec)
{
    std::cout << vec.x << "," << vec.y << "," << vec.z;
}
int main(int argc, char** argv)
{

    /*Simulation Parameter*/
    double timeStep = 0.001;


    /*create a golfball*/

    //golfbal={position,mass, radius}
    Ball golfball{ {0,0,0},0.04593,0.0427/2 };
    double angle = 42;
    double speed = 45;


    //creating the starting velocitz vector
    auto angleInRadians = glm::radians(angle);
    glm::dvec3 launchVelocity{ cos(angleInRadians),sin(angleInRadians),0.0 };    
    launchVelocity *= speed;

    //set the launch vector for the ball
    golfball.setVelocity(launchVelocity);

    //create the simulation={ball, startTime,endTime,stepsize,(optional)wind vector}
    Simulation sim{ golfball,0.0,100,timeStep,{0,0,0.0}};

    //run simulation
    sim.run();

    auto ball = sim.getBall();
  
    std::cout << glm::length(ball.getPosition()) << std::endl;
    printVector(ball.getPosition());

    return 0;


}