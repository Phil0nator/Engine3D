class Color{
    public:
    float r,g,b,a;
    
    Color() = default;
    Color(float r, float g, float b) : r(r), g(g), b(b), a(1) {}
    Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a) {}
    //Color(int r, int g, int b) : r(r/255.0), g(g/255.0), b(b/255.0), a(1) {}
    //Color(int r, int g, int b, int a) : r(r/255.0), g(g/255.0), b(b/255.0), a(a/255.0) {} 

};