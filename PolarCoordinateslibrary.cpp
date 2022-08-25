// Spyridon Zervos ©


#include "PolarCoordinatesLibrary.h"
#include "ComplexNumbersLibrary.h"
#include <cmath>
#include <sstream>

PolarCoordinate::PolarCoordinate()
{
    _radius = 0;
    _angle = 0;
}

PolarCoordinate::PolarCoordinate(double InRadius, double InAngle)
{
    _radius = InRadius;
    _angle = InAngle;
}

PolarCoordinate PolarCoordinate::operator+(const PolarCoordinate& X)
{
    return {(this->ToCartesianCoordinates() + X.ToCartesianCoordinates()).ToPolarForm()};
}

PolarCoordinate PolarCoordinate::operator-(const PolarCoordinate& X)
{
    return {*this + PolarCoordinate{-X.GetRadius(), X.GetAngle()}};
}

PolarCoordinate PolarCoordinate::operator*(const PolarCoordinate& X)
{
    return {_radius * X.GetRadius(), _angle + X.GetAngle()};
}

PolarCoordinate PolarCoordinate::operator/(const PolarCoordinate& X)
{
    return {_radius / X.GetRadius(), _angle - X.GetAngle()};
}

double PolarCoordinate::Abs() const
{
    return _radius;
}

double PolarCoordinate::GetRadius() const
{
    return _radius;
}

double PolarCoordinate::GetAngle() const
{
    return _angle;
}

ComplexNumber PolarCoordinate::ToCartesianCoordinates() const
{
    return {_radius * std::cos(_angle), _radius * std::sin(_angle)};
}

std::string PolarCoordinate::ToString() const
{
    std::ostringstream OutputStringStream;
    OutputStringStream << _radius << "/_" << _angle;
    return OutputStringStream.str();
}
