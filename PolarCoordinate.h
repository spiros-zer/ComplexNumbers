// (c) Spyridon Zervos


#pragma once

#include <string>
#include <utility>

class PolarCoordinate
{
private:

    /**
     * @brief The Radius of the Polar coordinates.
     * 
     */
    double _radius;

    /**
     * @brief The Angle of the Polar coordinates.
     * 
     */
    double _angle;

public:

    PolarCoordinate();

    PolarCoordinate(double InRadius, double InAngle);

    /**
     * @brief Addition Operator Overloading.
     * 
     * @param X The Complex Number to be added.
     * @return ComplexNumber The Addition result.
     */
    PolarCoordinate operator+(const PolarCoordinate& X);

    /**
     * @brief Deduction Operator Overloading.
     * 
     * @param X The Complex Number to be deduced.
     * @return ComplexNumber The Deduction result.
     */
    PolarCoordinate operator-(const PolarCoordinate& X);

    /**
     * @brief Multiplication Operator Overloading.
     * 
     * @param X The Complex Number to be multiplied.
     * @return ComplexNumber The Multiplication result.
     */
    PolarCoordinate operator*(const PolarCoordinate& X);

    /**
     * @brief Division Operator Overloading.
     * 
     * @param X The Divisor.
     * @return ComplexNumber The Division result.
     */
    PolarCoordinate operator/(const PolarCoordinate& X);

    /**
     * @brief Get the Radius object.
     * 
     * @return double _radius.
     */
    double GetRadius() const;

    /**
     * @brief Get the Angle object.
     * 
     * @return double _angle.
     */
    double GetAngle() const;

    /**
     * @brief Conversion of Polar to Cartesian coordinates.
     * 
     * @return A pair of doubles symbolizing Cartesian coordinates.
     */
    std::pair<double, double> ToCartesianCoordinates() const;

    /**
     * @brief Converts the Polar coordinates to a std::string.
     *
     * @return std::string The Polar in literal format.
     */
    std::string ToString() const;
};
