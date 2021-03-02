

Mesh BoxGeometry(Math::Point topleft, Math::Vector diagonal){

    Vertex va = Vertex(
        Math::Point(-1.0, -1.0, 0.0),
        Math::Point(0,0,0),
        Math::Point(0,0,0)
    );
    Vertex vb = Vertex(
        Math::Point(1.0, -1.0, 0.0),
        Math::Point(0,0,0),
        Math::Point(0,0,0)
    );
    Vertex vc = Vertex(
        Math::Point(0.0, 1.0, 0.0),
        Math::Point(0,0,0),
        Math::Point(0,0,0)
    );
    
    auto vertices = std::vector<Vertex>({va,vb,vc});
    

    return Mesh(vertices);

}