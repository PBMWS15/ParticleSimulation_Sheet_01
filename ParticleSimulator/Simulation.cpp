#include "Simulation.h"


Simulation::Simulation(const Ball& ball, double tStart, double tEnd, double deltaTime, const glm::dvec3& wind) : _ball{ ball }, _tStart{ tStart }, _tEnd{ tEnd }, _deltaT{ deltaTime }, _vWind{ wind }
{
}

Simulation::~Simulation()
{
}

void Simulation::update(double deltaTime)
{
    /*Calculate the forces acting on the ball*/

    //F=m*vec(g)
    glm::vec3 gravForce = _ball.getMass()*_gravAcc;

    //F=0.5*rho*v_rel^2*c_D*A*vec(v_Nrel)
    auto vRel = _ball.getVelocity() - _vWind;
    glm::vec3 dragForce= -0.5*_rho*_dragCoeff*_ball.getArea()*glm::dot(vRel, vRel) *glm::normalize(vRel);


    //apply forces to the ball
    _ball.setForce(gravForce+dragForce);

    //let the ball move according to newtons second law of motion (a=F/m)
    _ball.update(deltaTime);
}

void Simulation::run()
{
    auto t = _tStart;
    while (t < _tEnd && _ball.getPosition().y >= 0)
    {
        update(_deltaT);
        t += _deltaT;

    }
}

Ball Simulation::getBall()
{
    return _ball;
}