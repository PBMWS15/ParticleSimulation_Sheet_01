#include "Particle.h"

Particle::Particle(const glm::vec3& position, double mass) : _pos{position}, _mass{mass}
{
}

Particle::~Particle()
{
}

void Particle::setAccelertation(const glm::vec3& acceleration)
{
    _acc = acceleration;
}

void Particle::setForce(const glm::vec3& force)
{
    _force = force;
}

glm::vec3 Particle::getPosition()
{
    return _pos;
}

glm::vec3 Particle::getVelocity()
{
    return _vel;
}

glm::vec3 Particle::getAcceleration()
{
    return _acc;
}

double Particle::getMass()
{
    return _mass;
}

void Particle::setPosition(const glm::vec3& position)
{
    _pos = position;
}

void Particle::setVelocity(const glm::vec3& velocity)
{
    _vel = velocity;
}