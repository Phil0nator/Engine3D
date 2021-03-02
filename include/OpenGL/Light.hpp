class Light : public Core::Movable {
    public:
    Material properties;

};

class AmbientLight: public Light {};
class DirectionalLight: public Light {};
class PointLight : public Light {};