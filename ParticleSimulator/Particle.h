#pragma once
#include<glm/glm.hpp>
#include <iostream>

class Particle
{
public:
    Particle(const glm::vec3& position, double mass);
    virtual ~Particle();
    void virtual update() { std::cout << "doing nothing\n"; };
    
    //Setters
    void setPosition(const glm::vec3& position);
    void setVelocity(const glm::vec3& velocity);
    void setAccelertation(const glm::vec3& acceleration);
    void setForce(const glm::vec3& force);

    //Getters
    glm::vec3 getPosition();
    glm::vec3 getVelocity();
    glm::vec3 getAcceleration();
    double getMass();

    

private:

    glm::vec3 _pos;
    glm::vec3 _vel;
    glm::vec3 _acc;
    glm::vec3 _force;
    double _mass;


};

