class Camera : public Core::Movable, public Core::Pointable{
    private:
    public:
        double roll = 0;
    
        Camera() = default;
        Camera(Math::Point position) : Movable(position) {};
        Camera(Math::Point position, Math::Quaternion rotation) : Movable(position), Pointable(rotation) {};
        Camera(Math::Point position, Math::Quaternion rotation, double roll) : Movable(position), Pointable(rotation), roll(roll) {};




};