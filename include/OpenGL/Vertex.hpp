struct Vertex{

    Math::Vector position;
    Math::Vector normal;
    Math::Vector texcoord;

    Vertex(Math::Vector position, Math::Vector normal, Math::Vector texcoord) : 
                        position(position), normal(normal), texcoord(texcoord) {};

};