#include "Engine3D.hpp"

using Engine3D::Math::Point;
using Engine3D::Math::Quaternion;
using std::cout;
using std::endl;
using namespace Engine3D;
using namespace Core;

Scene myScene = Scene(Color(0.5,1,0.5));
Camera myCamera = Camera();
Shader myShader;

void display(){
    myScene.render(myCamera);
    glutSwapBuffers();


}



int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);    // Use single color buffer and no depth buffer.
    glutInitWindowSize(500,500);                    // Size of display area, in pixels.
    glutInitWindowPosition(100,100);                // Location of window in screen coordinates.
    glutCreateWindow("3D Engine");                  // Parameter is window title.
    glutDisplayFunc(display);                       // Called when the window needs to be redrawn.
    gladLoadGL();                                   // Set up shader compiler
    
    myShader = Shader("include/OpenGL/BasicShaders/BasicVertexShader.glsl", 
                    "include/OpenGL/BasicShaders/BasicFragmentShader.glsl");
    ShaderMaterial mat;
    mat.shader = myShader;

    Mesh cube = BoxGeometry(Point(), Point());
    cube.mat = &mat;

    myScene.addObject(&cube);


    
    glutMainLoop(); // Run the event loop!  This function does not return.
                    // Program ends when user closes the window.
    
    return 0;
}