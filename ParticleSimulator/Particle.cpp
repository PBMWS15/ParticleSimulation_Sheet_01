#include "Particle.h"

Particle::Particle(const glm::dvec3& position, double mass) : _pos{position}, _mass{mass}
{
}

Particle::~Particle()
{
}

void Particle::update(double timeStep)
{
    /*Explicit Euler is bad only use it if you want this out of your way and revisit it later*/
    /*
    _acc = _force / _mass;
    _vel += _acc*timeStep;
    _pos += _vel*timeStep;
    */


    /*Velocity Verlet Method is a much better method and is barely any more complex than Euler*/
    _acc = _force / _mass;
    _pos+= timeStep * (_vel + timeStep/2 * _acc);
    _vel += timeStep * _acc;

    /*Runge-Kutte 4th Order method, the go to solver, a good degree more complex than the methods above but usually achieves good accuracy*/
    //Look it up, many implementations can be found online
    


}

void Particle::setAccelertation(const glm::dvec3& acceleration)
{
    _acc = acceleration;
}

void Particle::setForce(const glm::dvec3& force)
{
    _force = force;
}

glm::dvec3 Particle::getPosition()
{
    return _pos;
}

glm::dvec3 Particle::getVelocity()
{
    return _vel;
}

glm::dvec3 Particle::getAcceleration()
{
    return _acc;
}

double Particle::getMass()
{
    return _mass;
}

void Particle::setPosition(const glm::dvec3& position)
{
    _pos = position;
}

void Particle::setVelocity(const glm::dvec3& velocity)
{   
    _vel = velocity;
}