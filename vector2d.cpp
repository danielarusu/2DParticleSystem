#include "vector2d.h"

Vector2D::Vector2D()
{
    xCoord = 0.0;
    yCoord = 0.0;
}

Vector2D::Vector2D(double x, double y)
{
    xCoord = x;
    yCoord = y;
}

Vector2D::~Vector2D()
{

}

void Vector2D::setX(double x)
{
    xCoord = x;
}

double Vector2D::getX()
{
    return xCoord;
}

void Vector2D::setY(double y)
{
    yCoord = y;
}

double Vector2D::getY()
{
    return yCoord;
}

double Vector2D::magnitude()
{
    return sqrt(xCoord*xCoord + yCoord*yCoord);
}

void Vector2D::clear()
{
    xCoord = 0;
    yCoord = 0;
}

float Vector2D::theta(Vector2D &v)
{
    float theta_in_degrees = atan2(v.yCoord - yCoord, v.xCoord - xCoord);
    float theta_in_radians = (theta_in_degrees * PI_F) / 180;
    return theta_in_radians;
}

Vector2D Vector2D::getPositionVector(Vector2D &v)
{
    return Vector2D(v.xCoord - xCoord, v.yCoord - yCoord);
}

void Vector2D::normalise()
{
    double mag = magnitude();
    xCoord /= mag;
    yCoord /= mag;
}

Vector2D Vector2D::operator=(const Vector2D &v)
{
    xCoord = v.xCoord;
    yCoord = v.yCoord;
    return Vector2D(xCoord, yCoord);
}

Vector2D Vector2D::operator+(const Vector2D &v)
{
    xCoord += v.xCoord;
    yCoord += v.yCoord;
    return Vector2D(xCoord, yCoord);
}

Vector2D& Vector2D::operator+=(const Vector2D &v)
{
    this->xCoord += v.xCoord;
    this->yCoord += v.yCoord;
    return *this;
}

Vector2D Vector2D::operator-(const Vector2D &v)
{
    xCoord -= v.xCoord;
    yCoord -= v.yCoord;
    return Vector2D(xCoord, yCoord);
}

Vector2D Vector2D::operator*(const double c)
{
    xCoord = c*xCoord;
    yCoord = c*yCoord;
    return Vector2D(xCoord, yCoord);
}

Vector2D& Vector2D::operator*=(const double c)
{
    this->xCoord *= c;
    this->yCoord *= c;
    return *this;
}

Vector2D Vector2D::operator/(const double c)
{
    xCoord = c / xCoord;
    yCoord = c / yCoord;
    return Vector2D(xCoord, yCoord);
}

void Vector2D::add(Vector2D& v)
{
    xCoord += v.xCoord;
    yCoord += v.yCoord;
}

void Vector2D::subtract(Vector2D &v)
{
    xCoord -= v.xCoord;
    yCoord -= v.yCoord;
}

void Vector2D::divideComponentsByScalar(double c)
{
    xCoord /= c;
    yCoord /= c;
}

void Vector2D::multiplyComponentsByScalar(double c)
{
    xCoord *= c;
    yCoord *= c;
}

double Vector2D::distance(Vector2D& v)
{
    double xd = (xCoord - v.xCoord);
    double yd = (yCoord - v.yCoord);

    return sqrt(xd * xd + yd * yd);
}



