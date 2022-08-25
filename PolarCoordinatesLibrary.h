// Spyridon Zervos ©


#pragma once

#include <string>

class ComplexNumber;

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
     * @brief Returns the Radius.
     * 
     * @return double The Radius of the Polar Number.
     */
    double Abs() const;

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
     * @return ComplexNumber 
     */
    ComplexNumber ToCartesianCoordinates() const;

    std::string ToString() const;
};
