/**
 * The Mesh class is designed to store the geometry of a 3D shape 
 */
class Mesh{

    private:
        std::vector<Vertex> vertices;
        std::vector<GLuint> indices;
        std::vector<Texture> textures;

        GLuint VAO, VBO, EBO;

        void compile();

    public:

        Mesh() = default;
        Mesh(std::vector<Vertex> v, std::vector<GLuint> i, std::vector<Texture> t) : vertices(v), indices(i), textures(t) {compile();}


};