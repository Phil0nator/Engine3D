void Movable::translate(const Vector& translator){
    position+=translator;
}
void Movable::translate(double x, double y, double z){
    position+=Point(x,y,z);
}
void Movable::translate(int x, int y, int z){
    position+=Point(x,y,z);
}
void Rotatable::rotateX( double angle ){
    rotate(Math::X_AXIS, angle);
}
void Rotatable::rotateY( double angle ){
    rotate(Math::Y_AXIS, angle);
}
void Rotatable::rotateZ( double angle ){
    rotate(Math::Z_AXIS, angle);
}
void Rotatable::rotate( const Vector& axis, double angle ){
    rotation.multiply(Quaternion(axis,angle));
}
void Pointable::lookAt(const Point& location){
    
}