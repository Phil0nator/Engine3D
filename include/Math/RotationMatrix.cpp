RotationMatrix::RotationMatrix(std::array<double, 3> x, std::array<double, 3> y, std::array<double, 3> z){
    v[0]={x[0],x[1],x[2],0.0};
    v[1]={y[0],y[1],y[2],0.0};
    v[2]={z[0],z[1],z[2],1.0};
}
RotationMatrix::RotationMatrix(std::array<double, 4> x, std::array<double, 4> y, std::array<double, 4> z,  std::array<double, 4> w){
    v[0]=x;
    v[1]=y;
    v[2]=z;
    v[3]=w;
}


std::array<double, 4> RotationMatrix::operator[](size_t index) const{
    return v[index];
}
std::array<double, 4>& RotationMatrix::operator[](size_t index) {
    return v[index];
}


RotationMatrix RotationMatrix::operator *( const RotationMatrix& other ) const{
    /*return RotationMatrix(
        {a[0][0]*b[0][0] + a[0][1]*b[1][0] + a[0][2]*b[2][0],
                                                            a[0][0]*b[0][1] + a[0][1]*b[1][1] + a[0][2]*b[2][1],
                                                            a[0][0]*b[0][2] + a[0][1]*b[1][2] + a[0][2]*b[2][2]},
        {a[1][0]*b[0][0] + a[1][1]*b[1][0] + a[1][2]*b[2][0],
                                                            a[1][0]*b[0][1] + a[1][1]*b[1][1] + a[1][2]*b[2][1],
                                                            a[1][0]*b[0][2] + a[1][1]*b[1][2] + a[1][2]*b[2][2]},
        {a[2][0]*b[0][0] + a[2][1]*b[1][0] + a[2][2]*b[2][0],
                                                            a[2][0]*b[0][1] + a[2][1]*b[1][1] + a[2][2]*b[2][1],
                                                            a[2][0]*b[0][2] + a[2][1]*b[1][2] + a[2][2]*b[2][2]}
    );*/

    RotationMatrix out;
    for(int i = 0 ; i < 4; i ++){
        for(int j = 0; j < 4; j ++){
            out[i][j] = 
                        v[0][j] * other[i][0] +
                        v[1][j] * other[i][1] +
                        v[2][j] * other[i][2] +
                        v[3][j] * other[i][3];
        }
    }
    return out;


}

RotationMatrix RotationMatrix::translate( const Vector& translation ) const{


    RotationMatrix multiplier(
        {1.0,0.0,0.0,0.0},
        {0.0,1.0,0.0,0.0},
        {0.0,0.0,1.0,0.0},
        {translation.x, translation.y, translation.z, 1.0}
    );

    return (*this)*multiplier;
}

RotationMatrix RotationMatrix::scale( const Vector& scale ) const{

    RotationMatrix multiplier(
        {scale.x, 0.0, 0.0,0.0},
        {0.0, scale.y, 0.0,0.0},
        {0.0, 0.0, scale.z,0.0},
        {0.0, 0.0, 0.0,1.0}
    );

    return (*this)*multiplier;

}
RotationMatrix RotationMatrix::operator *( double scalar ) const{

    RotationMatrix multiplier(
        {scalar, 0.0, 0.0, 0.0},
        {0.0, scalar, 0.0, 0.0},
        {0.0, 0.0, scalar, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    );

    return (*this)*multiplier;

}
RotationMatrix RotationMatrix::rotate( double angle, const Vector& axis ) const {
    

    double c = cos((long double)angle);
    double s = sin((long double)angle);

    RotationMatrix multiplier(
        {axis.x*axis.x*(1.0f-c)+c,   axis.x*axis.y*(1.0f-c)-axis.z*s, axis.x*axis.z*(1.0f-c)+axis.y*s},
        {axis.y*axis.x*(1.0f-c)+axis.z*s, axis.y*axis.y*(1.0f-c)+c,   axis.y*axis.z*(1.0f-c)-axis.x*s},
        {axis.z*axis.x*(1.0f-c)-axis.y*s, axis.z*axis.y*(1.0f-c)+axis.x*s, axis.z*axis.z*(1.0f-c)+c}
    );

    return (*this)*multiplier;


}
