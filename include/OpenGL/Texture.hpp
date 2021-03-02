
enum TextureType {

    DIFFUSE,
    SPECULAR

};


struct Texture{

    GLuint id;
    TextureType type;



};

Texture loadImage(const char* path);
Texture loadImageFromMemory(const char* memory, const char* format);
