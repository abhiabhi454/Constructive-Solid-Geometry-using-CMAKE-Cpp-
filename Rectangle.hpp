#pragma once
#include "AbsImplicitGeometry.hpp"
namespace implicit
{
    class Rectangle : public AbsImplicitGeometry
    {
    public:
        Rectangle(double x1, double x2, double y1, double y2);

        bool inside(double x, double y) const override;
    private:
        double x1_, x2_, y1_, y2_;
    };
} // namespace implicit
