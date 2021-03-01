/**
 * Understanding resource:
 * http://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/code/index.htm
 */

Quaternion::Quaternion( double angle, const Vector& axis ){
    set(angle, axis);
}
Quaternion::Quaternion( const RotationMatrix& matrix ){
    set(matrix);
}
Quaternion::Quaternion( const std::array<double, 4> arr ){
    set(arr);
}


void Quaternion::set( double x, double y, double z, double w ){
    this->x=x;
    this->y=y;
    this->z=z;
    this->w=w;
}
void Quaternion::set( const Vector& xyz, double w ){
    x=xyz.x;
    y=xyz.y;
    z=xyz.z;
    this->w = w;
}
void Quaternion::set( double angle, const Vector& axis ){

}
void Quaternion::set( const RotationMatrix& matrix ){
    /**
     * qw= √(1 + m00 + m11 + m22) /2
     * qx = (m21 - m12)/( 4 *qw)
     * qy = (m02 - m20)/( 4 *qw)
     * qz = (m10 - m01)/( 4 *qw)
     * http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/
    */
    double m00 = matrix[0][0];
    double m11 = matrix[1][1];
    double m22 = matrix[2][2];
    // Calculate the 'trace' of the matrix, in order to prevent division by zero
    double trace = m00+m11+m22;
    
    /**
     * Based on the value of the matrix's trace, or subsequently its major diagonals,
     * a diagonal is chosen to create the Quaternion in order to prevent division by zero.
     */


    // if the trace of the matrix is greater than zero, the answer is simple.
    if (trace > 0) {
        // S = 4w
        double S = sqrt(trace+1)*2;
        w = S/4;
        // can divide by S because S = 4w
        x = (matrix[2][1] - matrix[1][2]) / S;
        y = (matrix[0][2] - matrix[2][0]) / S;
        z = (matrix[1][0] - matrix[0][1]) / S;

    // otherwise, we need the greatest major diagonal
    } else if ((m00 > m11) and (m00 > m22)){
        // S = 4x
        double S = sqrt((m00-m11-m22)+1)*2;
        x = S/4;
        // Can divide by S because S = 4x
        y = (matrix[0][1]+matrix[1][0]) / S;
        z = (matrix[0][2]+matrix[2][0]) / S;
        w = (matrix[2][1]-matrix[1][2]) / S;
    } else if (m11 > m22) {
        // S = 4y
        double S = sqrt((m11-m00-m22)+1)*2;
        y = S/4;
        // Can divide by S because S = 4y
        x = (matrix[0][1]+matrix[1][0]) / S;
        z = (matrix[1][2]+matrix[2][1]) / S;
        w = (matrix[0][2]-matrix[2][0]) / S;

    } else {
        // S = 4z
        double S = sqrt((m22-m00-m11)+1)*2;
        z = S/4;
        // Can divide by S because S = 4z
        x = (matrix[0][2] + matrix[2][0]) / S;
        y = (matrix[1][2] + matrix[2][1]) / S;
        w = (matrix[1][0] - matrix[0][1]) / S;
    
    }


}
void Quaternion::set( const std::array<double, 4> arr ){
    x = arr[0];
    y = arr[1];
    z = arr[2];
    w = arr[3];
}


double Quaternion::magnitude(){
    return sqrt(x*x+y*y+z*z+w*w);
}
void Quaternion::normalize(){
    double mag = magnitude();
    x*=mag;
    y*=mag;
    z*=mag;
    w*=mag;
}
void Quaternion::invert(){
    x*=-1;
    y*=-1;
    z*=-1;
    w*=1;
}
void Quaternion::reset(){
    x=y=z=0;
    w=1;
}

double Quaternion::dot( const Quaternion& other ) const {
    return (x*other.x)+(y*other.y)+(z*other.z)+(w*other.w);
};
double Quaternion::angleTo( const Quaternion& other ) const {
    /**
     * https://www.researchgate.net/post/How_do_I_calculate_the_smallest_angle_between_two_quaternions
     * https://www.mathworks.com/matlabcentral/answers/476474-how-to-find-the-angle-between-two-quaternions
     * qa = this
     * qb = other
     * qc = -qa*qb
     * 
     * qc.w = cos(angle/2)
     * or
     * qc.xyz = sin(angle/2)e
     * 
     * so...
     * angle = 2asin(qc.normalize()[xyz])
     * and...
     * angle = 2acos(scalar part of qc)
     * 
     * therefore
     * 
     * angle = 2 * acos(| qc |)     [-1:1]
     * 
     */
    Quaternion qa = copy();
    Quaternion qb = other.copy();
    qa.normalize();
    qb.normalize();
    return 2 * asin( abs( qa.dot(qb) ) );

};

Quaternion Quaternion::slerp( const Quaternion& other, double t ) const {
    /**
     * Calculate a smooth rotation over the shortest path to a quaternion end-point.
     * (uniform angular velocity)
     * https://en.wikipedia.org/wiki/Slerp#Quaternion_Slerp
     *  Slerp(q0,q1,t) = q0(q0^-1q1)^t
     * http://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/slerp/
     * 
     * qm = ( qa(sin(1-t)theta)+qb(sin(t*theta)) )/ sin theta 
     * 
     */

    // When t == 0, there will be no change, and when t == 1 the resultant will be other
    if (t == 0)
        return copy();
    if (t == 1)
        return other.copy();

    Quaternion out;

    // Actual calculation:


    // Angle between this and other
    double cosHalfTheta = dot(other);
    // if qa=qb or qa=-qb then theta = 0 and we can return qa
    if(abs(cosHalfTheta) >= 1){
        return copy();
    }

    double halfTheta = acos(cosHalfTheta);
    double sinHalfTheta = sqrt(1-cosHalfTheta*cosHalfTheta);

    // When theta is 180 degress, the result is undefined because the rotation
    // could be in theory around any axis. (div/0)
    if (fabs(sinHalfTheta) < 0.001){
        out.set(
            (w/2+other.w/2),
            (x/2+other.x/2),
            (y/2+other.y/2),
            (z/2+other.y/2)
        );
    }else{
        // Find the actual interpolated quaternion:
        double rotationA = sin((1-t)*halfTheta) / sinHalfTheta;
        double rotationB = sin(t*halfTheta) / sinHalfTheta;
        out.set(
            (w*rotationA + other.w*rotationB),
            (x*rotationA + other.x*rotationB),
            (y*rotationA + other.y*rotationB),
            (z*rotationA + other.z*rotationB)
        );

    }

    return out;
};

Quaternion Quaternion::copy() const {
    return Quaternion(x,y,z,w);
};

Quaternion Quaternion::operator*( const Quaternion& other ) const{
    /**
     * http://www.euclideanspace.com/maths/algebra/realNormedAlgebra/quaternions/geometric/orthogonal/index.htm
     */
    return Quaternion(
        (x*other.w + y*other.z - z*other.y + w * other.x),
        (-x*other.z + y*other.w + z*other.x + w*other.y),
        (x*other.y - y * other.x + z * other.w + w * other.z),
        (-x*other.x - y*other.y - z*other.z + w*other.w )
    );
};
Quaternion Quaternion::operator*( double scalar) const{
    return Quaternion(x*scalar, y*scalar, z*scalar, w*scalar);
}
Quaternion Quaternion::operator+( const Quaternion& other ) const{
    return Quaternion( x+other.x, y+other.y, z+other.z, w+other.w );
}
bool Quaternion::operator == ( const Quaternion& other ) const {
    return (x==other.x)&&(y==other.y)&&(z==other.z)&&(w==other.w);
};
Quaternion::operator std::array<double, 4>(){
    return {x,y,z,w};
}