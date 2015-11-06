#include "Ball.h"
#include<glm/gtc/constants.hpp>
Ball::Ball(const glm::dvec3& position, double mass, double radius):Particle{position,mass},_radius{radius}
{
}

Ball::~Ball()
{
}


double Ball::getArea()
{
    return _radius*_radius*glm::pi<double>();
}

double Ball::getRadius()
{
    return _radius;
}