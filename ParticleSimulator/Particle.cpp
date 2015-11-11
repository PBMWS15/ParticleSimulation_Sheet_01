#include "Particle.h"
#include "ODE.h"

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
    //_acc = _force / _mass;
    //_pos+= timeStep * (_vel + timeStep/2 * _acc);
    //_vel += timeStep * _acc;

    /*Runge Kutta 4th Order*/
    _acc = _force / _mass;

    //estimate derivatives v(t+z)=v(t)+z*a(t), a(t+z)=a(t)
    auto deriv = [&](double t, std::vector<double> u)
        {
            return std::vector<double>{_vel.x + t * _acc.x, _vel.y + t * _acc.y, _vel.z + t * _acc.z, _acc.x, _acc.y, _acc.z};
        };

    auto result = ODE::rk4vec(0, {_pos.x,_pos.y,_pos.z,_vel.x,_vel.y,_vel.z}, timeStep, deriv);

    _pos = {result[0],result[1], result[2]};
    _vel = {result[3],result[4], result[5]};
}

void Particle::setAccelertation(const glm::dvec3& acceleration)
{
    _acc = acceleration;
}

void Particle::setForce(const glm::dvec3& force)
{
    _force = force;
}

glm::dvec3 Particle::getPosition() const
{
    return _pos;
}

glm::dvec3 Particle::getVelocity() const
{
    return _vel;
}

glm::dvec3 Particle::getAcceleration() const
{
    return _acc;
}

double Particle::getMass() const
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
