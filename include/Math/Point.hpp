
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
    /**
     * Initialize a point from an std::array of doubles
     */
    Point(std::array<double, 3> a) : x(a[0]), y(a[1]), z(a[2]) {};

    /**
     * Add two points, and return the result.
     * (Vector addition)
     */
    Point operator +(const Point& other) const;
    /**
     * Subtract two points, and return the result.
     * (Vector subtraction)
     */
    Point operator -(const Point& other) const;

    /**
     * cross product two points, and return the result.
     * (Vector cross product)
     */
    Point operator *(const Point& other) const;
    /**
     * mulitply by a scalar, and return the result.
     * (scalar multiply)
     */
    Point operator *(double scalar) const;
    /**
     * divide two points, and return the result.
     * (Vector division)
     */
    Point operator /(const Point& other) const;
    /**
     * divide by a scalar, and return the result.
     * (scalar divide)
     */
    Point operator /(double scalar) const;
    /**
     * Add a point, and return const reference to 'this'.
     * (Vector addition)
     */
    const Point& operator +=(const Point& other);
    /**
     * subtract a point, and return const reference to 'this'.
     * (Vector subtraction)
     */
    const Point& operator -=(const Point& other);
    /**
     * cross product a point, and return const reference to 'this'.
     * (Vector cross product)
     */
    const Point& operator *=(const Point& other);
    /**
     * scalar multiply a point, and return const reference to 'this'.
     * (scalar multiply)
     */
    const Point& operator *=(double scalar);
    /**
     * divide a point, and return const reference to 'this'.
     * (Vector division)
     */
    const Point& operator /=(const Point& other);
    /**
     * scalar divide a point, and return const reference to 'this'.
     * (scalar divide)
     */
    const Point& operator /=(double scalar);
    /**
     * Test equality of two points
     * @param other testing point
     * @returns if x,y,z = other[x,y,z]
     */
    bool operator ==( const Point& other );
    /**
     * Access x, y, or z through an index
     * @param index 0-2 index of x,y,z
     * @returns { 0:x, 1:y, 2:z }
     */
    double operator [](size_t index);
    /**
     * Dot product
     * @param other other point
     * @returns dot product of this, and other
     */
    double dot(const Point& other);
    /**
     * Normalize this point
     */
    void normalize();
    /**
     * Create a copy of this point
     */
    Point copy() const;
    
    /**
     * Standard conversion to an std::array
     */
    operator std::array<double,3>(){
        return {x,y,z};
    }
};



// Debugging
std::ostream &operator<<(std::ostream &os, Point const &m){
    return os << "[ " << m.x << ", " << m.y << ", " << m.z << " ]";
}
#include "Point.cpp"