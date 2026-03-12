#include "AbsImplicitGeometry.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Intersection.hpp"
#include "Union.hpp"
#include "Difference.hpp"
#include <iostream>


void visualize(implicit::ImplicitGeometryPtr c )
{
    // Number of characters in terminal
    int nx = 100;
    int ny = 60;

    // Window in x-y plane
    double x1 = -1.0;
    double y1 = -1.6;

    double x2 = 1.0;
    double y2 = 1.6;

    for (int i = ny - 1; i >= 0; --i)
    {
        for (int j = 0; j < nx; ++j)
        {
            double x = j / (nx - 1.0) * (x2 - x1) + x1;
            double y = i / (ny - 1.0) * (y2 - y1) + y1;

            if (c->inside(x, y))
            {
                std::cout << "X";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}
    //using ImplicitGeometryPtr = std::shared_ptr<implicit::AbsImplicitGeometry>;

int main( )
{

    // these two do the same thing (but the second one is slightly faster):
   // implicit::ImplicitGeometryPtr circle1( new implicit::Circle( 0.0, 0.0, 1.06 ) );
   // auto circle1 = std::make_shared<implicit::Circle>( 0.0, 0.0, 1.06 );

    auto circle1 = std::make_shared<implicit::Circle>(0.0, 0.0, 1.06);
    auto rectangle1 = std::make_shared<implicit::Rectangle>(-1.0, -1.0, 1.0, 1.0);
    auto intersection = std::make_shared<implicit::Intersection>(circle1, rectangle1);
    auto rectangle2 = std::make_shared<implicit::Rectangle>(-0.1, -1.5, 0.1, 1.5);
    auto union1 = std::make_shared<implicit::Union>(intersection, rectangle2);
    auto circle2 = std::make_shared<implicit::Circle>(0.0, 0.0, 0.65);
    auto root = std::make_shared<implicit::Difference>(union1, circle2);

    std::cout << "Point (0, 0): " << root->inside(0.0, 0.0) << std::endl;
    std::cout << "Point (1, 0): " << root->inside(0.0, 1.0) << std::endl;
    std::cout << "Point (1, 0): " << root->inside(1.1, 0.0) << std::endl;
    
    // ... 
    // (to be used in the quad tree example)
 
    visualize(root);
    return 0;
}
