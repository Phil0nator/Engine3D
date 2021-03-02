class Object3D : public Movable, public Pointable {
    public:
    bool visible;
    virtual void render() = 0;
};