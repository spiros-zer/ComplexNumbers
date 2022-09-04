// Spyridon Zervos ©


#pragma once

#include <string>

class PolarCoordinate;

/**
 * @brief Implements and provides the basic functionality for Complex numbers. It also 
 * implements the Polar form for the Complex alongside functionalities for it.
 */
class ComplexNumber
{
private:

    /**
     * @brief The Real part of the Complex Number.
     * 
     */
    double _real;

    /**
     * @brief The Imaginary part of the Complex Number.
     * 
     */
    double _imag;

    /**
     * @brief The Absolute value (or length) of the Complex.
     * 
     */
    double _absoluteValue;

    /**
     * @brief The Polar form of the Complex.
     * 
     */
    PolarCoordinate* _polarForm;

public:

    ComplexNumber();

    ComplexNumber(const double& RealPart, const double& ImaginaryPart);

    /**
     * @brief Addition Operator Overloading.
     * 
     * @param X The Complex Number to be added.
     * @return ComplexNumber The Addition result.
     */
    ComplexNumber operator+(const ComplexNumber& X);

    /**
     * @brief Deduction Operator Overloading.
     * 
     * @param X The Complex Number to be deduced.
     * @return ComplexNumber The Deduction result.
     */
    ComplexNumber operator-(const ComplexNumber& X);

    /**
     * @brief Multiplication Operator Overloading.
     * 
     * @param X The Complex Number to be multiplied.
     * @return ComplexNumber The Multiplication result.
     */
    ComplexNumber operator*(const ComplexNumber& X);

    /**
     * @brief Multiplication Operator Overloading for double.
     * 
     * @param X The Complex Number to be multiplied.
     * @return ComplexNumber The Multiplication result.
     */
    ComplexNumber operator*(const double& Num);

    /**
     * @brief Division Operator Overloading.
     * 
     * @param X The Divisor.
     * @return ComplexNumber The Division result.
     */
    ComplexNumber operator/(const ComplexNumber& X);

    /**
     * @brief Calculates the conjugate.
     * 
     * @return The conjugate.
     */
    ComplexNumber Conjugate();

    /**
     * @brief Get the Real object.
     * 
     * @return double Real part of Complex.
     */
    double GetReal() const;

    /**
     * @brief Set the Real object.
     * 
     * @param X The value to be assigned to the Real part of the Complex.
     */
    void SetReal(const double& X);

    /**
     * @brief Get the Imag object.
     * 
     * @return double Imaginary part of Complex.
     */
    double GetImag() const;

    /**
     * @brief Set the Imag object.
     * 
     * @param X The value to be assigned to the Imaginary part of the Complex.
     */
    void SetImag(const double& X);

    /**
     * @brief Getter of _absolutevalue.
     * 
     * @return double  The _absoluteValue field.
     */
    double GetAbs() const;

    /**
     * @brief Transforms the Complex Number from Cartesian to Polar coordinates.
     * 
     * @return PolarCoordinate 
     */
    PolarCoordinate ToPolarForm();

    /**
     * @brief Converts the Complex number to a std::string.
     * 
     * @return std::string The complex number in literal format.
     */
    std::string ToString() const;
};
