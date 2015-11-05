#include "Ball.h"

Ball::Ball(const glm::vec3& position, double mass, double radius):Particle{position,mass},_radius{radius}
{
}

Ball::~Ball()
{
}

void Ball::update()
{
    //do ball specific update
    std::cout << "Ball updater\n";
}

double Ball::getRadius()
{
    return _radius;
}