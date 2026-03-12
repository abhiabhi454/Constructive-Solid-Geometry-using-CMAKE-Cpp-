#pragma once 

#include "AbsImplicitGeometry.hpp"
namespace implicit
{
    class AbsOperation : public AbsImplicitGeometry
    {
    public:
        AbsOperation(ImplicitGeometryPtr operand1, ImplicitGeometryPtr operand2);
        virtual ~AbsOperation() { }
        virtual bool inside(double x, double y) const = 0;
    protected:
        ImplicitGeometryPtr operand1_;
        ImplicitGeometryPtr operand2_;
    };

} // namespace implicit

