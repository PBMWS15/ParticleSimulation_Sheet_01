#pragma once
#include<glm/glm.hpp>

#include <iostream>

class Particle
{
public:
    Particle(const glm::dvec3& position, double mass);
    virtual ~Particle();
    virtual void update(double timeStep);
    
    //Setters
    void setPosition(const glm::dvec3& position);
    void setVelocity(const glm::dvec3& velocity);
    void setAccelertation(const glm::dvec3& acceleration);
    void setForce(const glm::dvec3& force);

    //Getters
    glm::dvec3 getPosition();
    glm::dvec3 getVelocity();
    glm::dvec3 getAcceleration();
    double getMass();

    

private:

    glm::dvec3 _pos;
    glm::dvec3 _vel = { 0.0,0.0,0.0 };
    glm::dvec3 _acc = { 0.0,0.0,0.0 };
    glm::dvec3 _force = { 0.0,0.0,0.0 };

    glm::dvec3 _accOld={0.0,0.0,0.0};
    double _mass;


};

