
/**
 * Store a 3D coordinate.
 * [x, y, z]
 */
class Point{
    public:
    double x = 0;
    double y = 0;
    double z = 0;
    /**
     * Default constructor
     */
    Point() = default;
    /**
     * Initialize a point from integers
     */
    Point(int x, int y, int z) : x(x), y(y), z(z) {};
    /**
     * Initialize a point from doubles
     */
    Point(double x, double y, double z) : x(x), y(y), z(z) {};


    Point operator +(const Point& other) const;
    Point operator -(const Point& other) const;

    /**
     * Cross product of two points
     */
    Point operator *(const Point& other) const;
    Point operator *(double scalar) const;
    Point operator /(const Point& other) const;
    Point operator /(double scalar) const;
    const Point& operator +=(const Point& other);
    const Point& operator -=(const Point& other);
    /**
     * Cross product of two points
     */
    const Point& operator *=(const Point& other);
    const Point& operator *=(double scalar);
    const Point& operator /=(const Point& other);
    const Point& operator /=(double scalar);
    double operator [](size_t index);
    /**
     * Dot product
     */
    double dot(const Point& other);

};
// Debugging
std::ostream &operator<<(std::ostream &os, Point const &m){
    return os << "[ " << m.x << ", " << m.y << ", " << m.z << " ]";
}
#include "Point.cpp"