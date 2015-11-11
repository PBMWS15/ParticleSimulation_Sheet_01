#pragma once
#include <vector>
#include <functional>

namespace ODE
{
    //RK4 for vector functions
    inline std::vector<double> rk4vec(double t0, const std::vector<double>& u0, double dt,
                                      std::function<std::vector<double>(double t, std::vector<double> u)> derivative)
    {
        auto f0 = derivative(t0, u0);

        auto t1 = t0 + dt / 2.0;
        std::vector<double> u1(u0.size());

        for (auto i = 0; i < u0.size(); i++)
            u1[i] = u0[i] + dt * f0[i] / 2.0;

        auto f1 = derivative(t1, u1);
        auto t2 = t0 + dt / 2.0;
        std::vector<double> u2(u0.size());

        for (auto i = 0; i < u0.size(); i++)
            u2[i] = u0[i] + dt * f1[i] / 2.0;

        auto f2 = derivative(t2, u2);
        auto t3 = t0 + dt;
        std::vector<double> u3(u0.size());

        for (auto i = 0; i < u0.size(); i++)
            u3[i] = u0[i] + dt * f2[i];

        auto f3 = derivative(t3, u3);
        std::vector<double> u(u0.size());

        for (auto i = 0; i < u0.size(); i++)
            u[i] = u0[i] + dt * (f0[i] + 2.0 * f1[i] + 2.0 * f2[i] + f3[i]) / 6.0;


        //lvalue return, compile should optimize it and use move instead of copy
        return u;
    }
}
