/**
 * Add two points, and return the result.
 * (Vector addition)
 */
Point Point::operator +(const Point& other) const{
    return Point(x+other.x,y+other.y,z+other.z);
}
/**
 * Subtract two points, and return the result.
 * (Vector subtraction)
 */
Point Point::operator -(const Point& other) const{
    return Point(x-other.x,y-other.y,z-other.z);
}
/**
 * cross product two points, and return the result.
 * (Vector cross product)
 */
Point Point::operator *(const Point& other) const{
    return Point(x*other.x,y*other.y,z*other.z);
}
/**
 * mulitply by a scalar, and return the result.
 * (scalar multiply)
 */
Point Point::operator *(double scalar) const {
    return Point(x*scalar,y*scalar,z*scalar);
}
/**
 * divide two points, and return the result.
 * (Vector division)
 */
Point Point::operator /(const Point& other) const{
    return Point(x/other.x,y/other.y,z/other.z);
}
/**
 * divide by a scalar, and return the result.
 * (scalar divide)
 */
Point Point::operator /(double scalar) const{
    return Point(x/scalar,y/scalar,z/scalar);
}
/**
 * Add a point, and return const reference to 'this'.
 * (Vector addition)
 */
const Point& Point::operator +=(const Point& other){
    x+=other.x;
    y+=other.y;
    z+=other.z;
    return *this;
}
/**
 * subtract a point, and return const reference to 'this'.
 * (Vector subtraction)
 */
const Point& Point::operator -=(const Point& other){
    x-=other.x;
    y-=other.y;
    z-=other.z;
    return *this;
}
/**
 * cross product a point, and return const reference to 'this'.
 * (Vector cross product)
 */
const Point& Point::operator *=(const Point& other){
    x*=other.x;
    y*=other.y;
    z*=other.z;
    return *this;
}
/**
 * scalar multiply a point, and return const reference to 'this'.
 * (scalar multiply)
 */
const Point& Point::operator *=(double scalar){
    x*=scalar;
    y*=scalar;
    z*=scalar;
    return *this;
}
/**
 * divide a point, and return const reference to 'this'.
 * (Vector division)
 */
const Point& Point::operator /=(const Point& other){
    x/=other.x;
    y/=other.y;
    z/=other.z;
    return *this;
}
/**
 * scalar divide a point, and return const reference to 'this'.
 * (scalar divide)
 */
const Point& Point::operator /=(double scalar){
    x/=scalar;
    y/=scalar;
    z/=scalar;
    return *this;
}
/**
 * Access x, y, or z through an index
 * @param index 0-2 index of x,y,z
 * @returns { 0:x, 1:y, 2:z }
 */
double Point::operator [](size_t index){
    return ((double*)this)[index];
}
/**
 * Dot product
 * @param other other point
 * @returns dot product of this, and other
 */
double Point::dot(const Point& other){
    return (x*other.x)+(y*other.y)+(z*other.z);
}

void Point::normalize(){
    double max = (x>y) ? ((x>z) ? x : z) : ((y>z) ? y : z);
    x/=max;
    y/=max;
    z/=max;
}

void Point::apply( const Quaternion& q ){

    // quaternion * this
    double ix = q.w * x + q.y * z - q.z * y;
    double iy = q.w * y + q.z * x - q.x * z;
    double iz = q.w * z + q.x * y - q.y * x;
    double iw = -q.x * x - q.y * y - q.z* z;

    // resultant * q.inverse()
    x = ix * q.w + iw * - q.x + iy * - q.z - iz * - q.y;
    y = iy * q.w + iw * - q.y + iz * - q.x - ix * - q.z;
    z = iz * q.w + iw * - q.z + ix * - q.y - iy * - q.x;
}


Point Point::copy() const {
    return Point(x,y,z);
}

double Point::magnitude(){
    return sqrt((x*x)+(y*y)+(z*z));
}