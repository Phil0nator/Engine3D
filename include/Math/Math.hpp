#include <numbers>
namespace Math{

    class Quaternion;
    class Point;
    class RotationMatrix;

    #include "Point.hpp"
    typedef Point Vector;
    typedef Point Euler;
    #include "RotationMatrix.hpp"
    #include "Quaternion.hpp"


    #include "Point.cpp"
    #include "RotationMatrix.cpp"
    #include "Quaternion.cpp"


    const Vector X_AXIS = Vector(1,0,0);
    const Vector Y_AXIS = Vector(0,1,0);
    const Vector Z_AXIS = Vector(0,0,1);

};