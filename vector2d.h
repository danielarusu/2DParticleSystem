#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <QtMath>

//const double G = 6.67384;//e-11;
const float  PI_F = 3.14159265358979f;

class Vector2D
{
public:
    Vector2D();
    Vector2D(double x, double y);
    ~Vector2D();

    //vector2D operator +(const Particle& p);
    void add(Vector2D& v);
    void subtract(Vector2D& v);
    void divideComponentsByScalar(double c);
    void multiplyComponentsByScalar(double c);
    double distance(Vector2D& v);
    void setX(double x);
    double getX();
    void setY(double y);
    double getY();
    double magnitude();
    void clear();
    float theta(Vector2D& v);
    Vector2D getPositionVector(Vector2D& v);
    void normalise();
    Vector2D operator=(const Vector2D& v);
    Vector2D operator+(const Vector2D& v);
    Vector2D& operator+=(const Vector2D& v);
    Vector2D operator-(const Vector2D& v);
    Vector2D operator*(const double c);
    Vector2D& operator*=(const double c);
    Vector2D operator/(const double c);

    //friend class Particle;
private:
    double xCoord;
    double yCoord;
};

#endif // VECTOR2D_H
