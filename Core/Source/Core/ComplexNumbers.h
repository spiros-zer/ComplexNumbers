// Spyridon Zervos ©


#pragma once

#include <string>

struct PolarCoordinates;
struct CartesianCoordinates;

/**
 * @brief Implements and provides the basic functionality for Complex numbers. It also 
 * implements the Polar form for the Complex.
 */
struct ComplexNumbers
{
    /** @brief Complex in the form of x+jb. The x holds the real, while the y holds the imaginary part. */
    CartesianCoordinates* Complex;

    /** @brief The Polar form of the Complex. */
    PolarCoordinates* PolarForm;
 
    /**** CONSTRUCTORS/DESTRUCTORS */
    ComplexNumbers(const double& RealPart, const double& ImaginaryPart);
    ComplexNumbers();
 
    /**** OPERATOR OVERLOADING */
    bool operator==(const ComplexNumbers& X);
    /** @brief Multiplication with num. */
    ComplexNumbers operator*(const double& Num);
    ComplexNumbers operator*(const ComplexNumbers& X);
    /** @brief Division with num. */
    ComplexNumbers operator/(const double& Num);
    ComplexNumbers operator/(const ComplexNumbers& X);

    /** @brief Transforms the Complex Number from Cartesian to Polar coordinates. */
    PolarCoordinates ToPolarForm();

    /** @brief Converts the Complex number to a std::string.*/
    std::string ToString() const;
};
