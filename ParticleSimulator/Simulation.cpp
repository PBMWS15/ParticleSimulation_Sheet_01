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

    /*  Note: velocity breaking condition will fail under certain conditions, 
        the simulation would stop if you throw a ball straight up into the air at the top point
        A different approach is to calculate the total energy of the ball (kinetic + potential)
        and break if the total energy is <eps
    */
    while (t < _tEnd && glm::length(_ball.getVelocity())>0.01)
    {
        update(_deltaT);

        //collision with ground handling
        if(_ball.getPosition().y<=0)
        {
            std::cout<<"BOUNCE!\n";
            //reflect velocity vector to the normal and rescale it
            _ball.setVelocity(_collisionEps*glm::reflect(_ball.getVelocity(), _collisionNormal));
        }
        t += _deltaT;

    }
}

Ball Simulation::getBall()
{
    return _ball;
}