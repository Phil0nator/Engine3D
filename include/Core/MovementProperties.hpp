using Math::Point;
using Math::RotationMatrix;
using Math::Vector;
using Math::Euler;
using Math::Quaternion;
class Movable{
    public:
        Point position;
        Movable() = default;
        Movable(Point position) : position(position) {};
        void translate(const Vector& translator);
            void translate(double x, double y, double z);
            void translate(int x, int y, int z);

};

class Rotatable{
    public:
        Quaternion rotation;
        Rotatable() = default;
        Rotatable(Quaternion rotation) : rotation(rotation){};
        void rotateX( double angle );
        void rotateY( double angle );
        void rotateZ( double angle );
        void rotate( const Vector& axis, double angle );
};

class Pointable : public Rotatable {
    public:
        Pointable() = default;
        Pointable(Quaternion rotation) : Rotatable(rotation) {};
        void lookAt(const Point& location);
};