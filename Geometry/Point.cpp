Point Point::operator +(const Point& other) const{
    return Point(x+other.x,y+other.y,z+other.z);
}
Point Point::operator -(const Point& other) const{
    return Point(x-other.x,y-other.y,z-other.z);
}

/**
 * Cross product of two points
 */
Point Point::operator *(const Point& other) const{
    return Point(x*other.x,y*other.y,z*other.z);
}
Point Point::operator *(double scalar) const {
    return Point(x*scalar,y*scalar,z*scalar);
}
Point Point::operator /(const Point& other) const{
    return Point(x/other.x,y/other.y,z/other.z);
}
Point Point::operator /(double scalar) const{
    return Point(x/scalar,y/scalar,z/scalar);
}
const Point& Point::operator +=(const Point& other){
    x+=other.x;
    y+=other.y;
    z+=other.z;
    return *this;
}
const Point& Point::operator -=(const Point& other){
    x-=other.x;
    y-=other.y;
    z-=other.z;
    return *this;
}
/**
 * Cross product of two points
 */
const Point& Point::operator *=(const Point& other){
    x*=other.x;
    y*=other.y;
    z*=other.z;
    return *this;
}
const Point& Point::operator *=(double scalar){
    x*=scalar;
    y*=scalar;
    z*=scalar;
    return *this;
}
const Point& Point::operator /=(const Point& other){
    x/=other.x;
    y/=other.y;
    z/=other.z;
    return *this;
}
const Point& Point::operator /=(double scalar){
    x/=scalar;
    y/=scalar;
    z/=scalar;
    return *this;
}

double Point::operator [](size_t index){
    return ((double*)this)[index];
}

double Point::dot(const Point& other){
    return (x*other.x)+(y*other.y)+(z*other.z);
}

