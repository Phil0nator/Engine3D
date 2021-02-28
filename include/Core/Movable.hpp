using Math::Point;
using Math::RotationMatrix;
using Math::Vector;
using Math::Euler;
class Movable{
    public:
        Point location;

        virtual void translate(const Vector& translator);
            virtual void translate(double x, double y, double z);
            virtual void translate(int x, int y, int z);

};
