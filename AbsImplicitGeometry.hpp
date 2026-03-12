#pragma once 
#include <memory>

namespace implicit
{
    class AbsImplicitGeometry
    {
    public:
        virtual ~AbsImplicitGeometry() { }

        virtual bool inside(double x, double y) const = 0;
    };

    using ImplicitGeometryPtr = std::shared_ptr<AbsImplicitGeometry>;
} // namespace implicit

