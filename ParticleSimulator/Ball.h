#pragma once
#include "Particle.h"

class Ball : public Particle
{
public:
    Ball(const glm::dvec3& position, double mass, double radius);
    ~Ball();
    
    double getArea();
    double getRadius();

private:
    double _radius;
};

