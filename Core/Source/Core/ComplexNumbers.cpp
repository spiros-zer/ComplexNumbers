// Spyridon Zervos ©


#include <cmath>
#include <sstream>
#include <iostream>

#include "ComplexNumbers.h"

#include "CartesianCoordinates/CartesianCoordinates2D.h"
#include "PolarCoordinates/PolarCoordinates.h"

ComplexNumbers::ComplexNumbers(const double& lhs, const double& rhs, bool bIsPolar)
{
    if (bIsPolar)
    {
        PolarForm = new PolarCoordinates(lhs, rhs);
        ToCartesian();
    }
    else
    {
        Complex = new CartesianCoordinates2D(lhs, rhs);
        ToPolar();
    }
}

ComplexNumbers::ComplexNumbers() : ComplexNumbers(0, 0) {}

ComplexNumbers::ComplexNumbers(const CartesianCoordinates2D& InCoords) : ComplexNumbers(InCoords.GetX(), InCoords.GetY()){}

ComplexNumbers::ComplexNumbers(const PolarCoordinates& InCoords) : ComplexNumbers(InCoords.GetRadius(), InCoords.GetTheta(), true){}

ComplexNumbers ComplexNumbers::operator*(const ComplexNumbers& X) const
{
    return {Complex->GetX() * X.Complex->GetX() - Complex->GetY() * X.Complex->GetY(), 
            Complex->GetX() * X.Complex->GetY() + Complex->GetY() * X.Complex->GetX()};
}

ComplexNumbers ComplexNumbers::operator/(const double& InNum) const
{
    return {Complex->GetX() / InNum, Complex->GetY() / InNum};
}

ComplexNumbers ComplexNumbers::operator*(const double& InNum) const
{
    return {Complex->GetX() * InNum, Complex->GetY() * InNum};
}

ComplexNumbers ComplexNumbers::operator/(const ComplexNumbers& X) const
{
    return {(Complex->GetX() * X.Complex->GetX()) / (std::pow(X.Complex->GetX(), 2) + std::pow(X.Complex->GetY(), 2)),
            (Complex->GetX() * X.Complex->GetX() - Complex->GetX() * X.Complex->GetY()) / (std::pow(X.Complex->GetX(), 2) + std::pow(X.Complex->GetY(), 2))};
}

bool ComplexNumbers::operator==(const ComplexNumbers& X) const
{
    if (Complex->GetX() == X.Complex->GetX() && Complex->GetY() == X.Complex->GetY())
    {
        return true;
    }
    return false;
}

ComplexNumbers ComplexNumbers::operator+(const double& InNum) const
{
    return {Complex->GetX() + InNum, Complex->GetY()};
}

ComplexNumbers ComplexNumbers::operator+(const ComplexNumbers& X) const
{
    ComplexNumbers* Result = new ComplexNumbers(*Complex + *X.Complex);
    return {*Result};
}

ComplexNumbers ComplexNumbers::operator-(const double& InNum) const
{
    return {Complex->GetX() - InNum, Complex->GetY()};
}

ComplexNumbers ComplexNumbers::operator-(const ComplexNumbers& X) const
{
    ComplexNumbers* Result = new ComplexNumbers(*Complex - *X.Complex);
    return {*Result};
}

void ComplexNumbers::ToCartesian()
{
    Complex = new CartesianCoordinates2D(PolarForm->GetRadius() * std::cos(PolarForm->GetTheta()), PolarForm->GetRadius() * std::sin(PolarForm->GetTheta()));
}


void ComplexNumbers::ToPolar()
{
    PolarForm = new PolarCoordinates(Complex->GetModulus(), std::atan(Complex->GetY() / Complex->GetX()) * 180 / 3.1415);
}

std::string ComplexNumbers::ToString() const
{
    std::ostringstream OutputStringStream;
    OutputStringStream << Complex->GetX() << "" << (Complex->GetY() >= 0 ?  "+" : "") << Complex->GetY() << "i";
    return OutputStringStream.str();
}

char* ComplexNumbers::ToString(int& InSize, int Precision)
{
    //(x,y)\0 - x+iy\0
    Size = Complex->GetCstringSize() - /*comma*/ 1;
    Cstring = new char[Size];

    int i{0};
    for (; i < Size; i++)
    {
        
    }
    return Cstring;
}

void ComplexNumbers::Print() const
{
    for (int i = 0; i < Size; ++i)
    {
        std::cout << Cstring[i];
    }
}
