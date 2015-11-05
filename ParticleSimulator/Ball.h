#pragma once
#include "Particle.h"

class Ball : public Particle
{
public:
    Ball(const glm::vec3& position, double mass, double radius);
    ~Ball();

    void update() override;

    double getRadius();

private:
    double _radius;
};

