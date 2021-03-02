

void Scene::render(Camera camera){

    glClearColor( background.r, background.g, background.b, background.a );
    glClear( GL_COLOR_BUFFER_BIT );

    //gluLookAt(camera.position.x, camera.position.y, camera.position.z, 0, 0, 0, 0, 0, 1);

    for (size_t i = 0; i < objects.size(); i++)
    {
        objects.at(i)->render();
    }
    

}