/**
 * Store and manipulate a Rotation Matrix
 */
class RotationMatrix{
    protected:
        /**
         * 'v' is the name of the matrix storing the values.
         * It is initialized by default to the identity matrix.
         */
        std::array< std::array<double,4>, 4> v = 
        {{
                {1.0,0.0,0.0,0.0},
                {0.0,1.0,0.0,0.0},
                {0.0,0.0,1.0,0.0},
                {0.0,0.0,0.0,1.0}
        }};
        
    
    public:
        /**
         * Default constructor
         */
        RotationMatrix() = default;
        /**
         * Construct a rotation matrix in 4 dimensions
         * @param x-w rows
         */
        RotationMatrix(std::array<double, 4> x, std::array<double, 4> y, std::array<double, 4> z, std::array<double, 4> w);
        /**
         * Construct a rotation matrix in 3 dimensions.
         * (The 4th dimension is initialized to identity)
         * @param x-z rows
         */
        RotationMatrix(std::array<double, 3> x, std::array<double, 3> y, std::array<double, 3> z);

        /**
         * Get read-only access to a row of the matrix
         * @param index row index
         * @returns read-only row
         */
        std::array<double, 4> operator[](size_t index) const;
        /**
         * Get a read/write access to a row of the matrix
         * @param index row index
         * @returns read/write reference to a row
         */
        std::array<double, 4>& operator[](size_t index);

        /**
         * Translate by a vector
         * @param translation vector to translate by
         * @returns the translated matrix
         */
        RotationMatrix translate( const Vector& translation ) const;
        /**
         * Scale by a vector
         * @param scale vector to scale with
         * @returns the scaled matrix
         */
        RotationMatrix scale( const Vector& scale ) const;
        /**
         * Multiply by a matrix
         * @param other matrix to multiply
         * @returns the product matrix
         */
        RotationMatrix operator *( const RotationMatrix& other ) const;
        /**
         * Multiply by a scalar
         * @param scalar scalar to multiply
         * @returns the product matrix
         */
        RotationMatrix operator *( double scalar ) const;
        /**
         * Rotate using an angle (radians) and axis
         * @param angle the rotation angle in radians
         * @param axis  the axis of rotation
         * @returns the rotated matrix
         */
        RotationMatrix rotate( double angle, const Vector& axis ) const;

};
// Debugging
std::ostream &operator<<(std::ostream &os, RotationMatrix const &m){
    return os << "|¯ " << m[0][0] << ", " << m[0][1] << ", " << m[0][2] << " ¯|\n"
              << "|  " << m[1][0] << ", " << m[1][1] << ", " << m[1][2] << "  |\n"
              << "|_ " << m[2][0] << ", " << m[2][1] << ", " << m[2][2] << " _|";
}
#include "RotationMatrix.cpp"