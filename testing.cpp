#include "Engine3D.hpp"



int main(int argc, char** argv){
    Engine3D::Geometry::Point p(1.3,2.0,3.0);
    Engine3D::Geometry::Point d(2.6,7.9,32.5);
    std::cout << (p*d)/(p+d) << std::endl;
    return 0;
}