// General Use
#include <stdio.h>
#include <algorithm>
#include <memory>
#include <vector>
#include <iostream>
#include <math.h>
#include <fstream>
#include <iostream>
#include <sstream> //std::stringstream
// OpenGL
#include "glad/glad.h"
#include <GL/gl.h>
#include <GL/glut.h>

namespace Engine3D{

    namespace Core{
        class Material;
        class Object3D;
        class Movable;
        class Rotatable;
        class Pointable;
        class Scene;
    };

    namespace Math{

        class Point;
        class Quaternion;
        class RotationMatrix;

    };


    #include "Math/Math.hpp"
    #include "Core/Properties.hpp"
    #include "OpenGL/GLTypes.hpp"
    #include "Core/Core.hpp"
    #include "Geometry/Geometry.hpp"



};

