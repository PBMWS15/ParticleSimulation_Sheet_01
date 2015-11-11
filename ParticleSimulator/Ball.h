#pragma once
#include "Particle.h"

/* Ball inherits from Particle*/
class Ball : public Particle
{
public:
    Ball(const glm::dvec3& position, double mass, double radius);
    ~Ball();

    double getArea() const;
    double getRadius() const;

private:

    double _radius;
    double _area;
};
