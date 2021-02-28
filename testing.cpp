#include "Engine3D.hpp"



int main(int argc, char** argv){
    Engine3D::Math::Point p(1.3,2.0,3.0);
    Engine3D::Math::Point d(2.6,7.9,32.5);
    Engine3D::Math::RotationMatrix r({1.0,0.0,0.0}, {1.0,0.0,0.0}, {0.0,0.0,1.0});
    Engine3D::Math::RotationMatrix r2({1.0,0.0,0.0}, {0.0,1.0,0.0}, {1.0,1.0,1.0});
    std::cout << r << std::endl;
    std::cout << r.rotate(1.57079633 ,Engine3D::Math::Vector(0,0,1)) << std::endl;
    std::cout << (p*d)/(p+d) << std::endl;
    return 0;
}