#include "Ball.h"
#include<glm/gtc/constants.hpp>

Ball::Ball(const glm::dvec3& position, double mass, double radius):Particle{position,mass},_radius{radius},_area{_radius * _radius * glm::pi<double>()}
{
}

Ball::~Ball()
{
}


double Ball::getArea() const
{
    return _area;
}

double Ball::getRadius() const
{
    return _radius;
}
