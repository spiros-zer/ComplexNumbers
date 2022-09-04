// (c) Spyridon Zervos


#include "PolarCoordinatesLibrary.h"

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
    std::pair<double, double> CartesianCoordinates = this->ToCartesianCoordinates();
    std::pair<double, double> InCartesianCoordinates = X.ToCartesianCoordinates();
    std::pair<double, double> Sum = {CartesianCoordinates.first + InCartesianCoordinates.first,
                                      CartesianCoordinates.second + InCartesianCoordinates.second};
    return {std::sqrt((std::pow(Sum.first, 2) + std::pow(Sum.second, 2))),
            std::atan(Sum.second / Sum.first) * 180 / 3.1415};
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

std::pair<double, double> PolarCoordinate::ToCartesianCoordinates() const
{
    return {_radius * std::cos(_angle), _radius * std::sin(_angle)};
}

std::string PolarCoordinate::ToString() const
{
    std::ostringstream OutputStringStream;
    OutputStringStream << _radius << "/_" << _angle;
    return OutputStringStream.str();
}
