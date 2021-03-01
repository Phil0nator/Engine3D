/**
 * The Quaternion class is used to represent rotations in 3D space
 * [x,y,z,w]
 */
class Quaternion{
    public:
    /**
     * The values of x,y,z, and w are initialized to the identiy quaternion:
     * [0,0,0,1]
     */
    double x,y,z;
    double w = 1.0;
    /**
     * Default Constructor
     */
    Quaternion() = default;
    /**
     * Basic setup constructor.
     * @param x x component
     * @param y y component
     * @param z z component
     * @param w w component
     */
    Quaternion( double x, double y, double z, double w ) : x(x), y(y), z(z), w(w) {};
    /**
     * Construct from a point, and a w value
     * @param xyz x, y, and z components from a vector
     * @param w w component
     */
    Quaternion( const Vector& xyz, double w ) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {};
    /**
     * Construct from an angle and axis
     * @param angle radians of angle
     * @param axis axis of angle
     */
    Quaternion( double angle, const Vector& axis );
    /**
     * Construct from a rotation matrix
     * @param matrix
     * @see {Engine3D::Math::RotationMatrix}
     */
    Quaternion( const RotationMatrix& matrix );
    /**
     * Construct from an array in the form [x,y,z,w]
     * @param arr array
     */
    Quaternion( const std::array<double, 4> arr );

    /**
     * Set components.
     * @param x x component
     * @param y y component
     * @param z z component
     * @param w w component
     */
    void set( double x, double y, double z, double w );
    /**
     * Set from a point, and a w value
     * @param xyz x, y, and z components from a vector
     * @param w w component
     */
    void set( const Vector& xyz, double w );
    /**
     * Set from an angle and axis
     * @param angle radians of angle
     * @param axis axis of angle
     */
    void set( double angle, const Vector& axis );
    /**
     * Set from a rotation matrix
     * @param matrix
     * @see {Engine3D::Math::RotationMatrix}
     */
    void set( const RotationMatrix& matrix );
    /**
     * Set from an array in the form [x,y,z,w]
     * @param arr array
     */
    void set( const std::array<double, 4> arr );

    /**
     * Get the magnitude
     */
    double magnitude();
    /**
     * Normalize this
     */
    void normalize();
    /**
     * Invert this
     */
    void invert();
    /**
     * Reset this to identity quaternion ([0,0,0,1])
     */
    void reset();

    /**
     * Get the dot product with other
     * @param other other quaternion
     * @returns dot product of this and other
     */
    double dot( const Quaternion& other ) const;
    /**
     * Get the angle between this and other in radians
     * @param other other quaternion
     * @returns angle to other
     */
    double angleTo( const Quaternion& other ) const;

    /**
     * Calculate spherical linear interpolation between quaternions.
     * (aka) get a quaternion rotated towards another quaternion along the
     * shortest axis.
     * @param other quaternion to rotate towards
     * @param t amount of rotation between this and other [0.0 : 1.0]
     * @returns a quaternion of this rotated towards other by t
     */
    Quaternion slerp( const Quaternion& other, double t ) const;
    /**
     * Get an exact copy of this quaternion
     * @returns a new quaternion with the same values as this
     */
    Quaternion copy() const;
    /**
     * Multiply quaternions
     */
    Quaternion operator*( const Quaternion& other ) const;
    /**
     * Scale a quaternion
     */
    Quaternion operator*( double scalar) const;
    /**
     * Add quaternions
     */
    Quaternion operator+( const Quaternion& other ) const;
    /**
     * Test that x,y,z, and w are equal between this and other
     */
    bool operator == ( const Quaternion& other ) const;
    /**
     * Decay this quaternion into an array of 4 doubles
     */
    operator std::array<double, 4>();


};
// Debugging
std::ostream &operator<<(std::ostream &os, Quaternion const &m){
    return os << "[ " << m.x << ", " << m.y << ", " << m.z << ", " << m.w << " ]";
}
