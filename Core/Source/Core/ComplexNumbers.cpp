// Spyridon Zervos ©


#include <cmath>
#include <sstream>

#include "ComplexNumber.h"
#include "PolarCoordinates/Core/Source/Core/PolarCoordinates.h"
#include "CartesianCoordinates/Core/Source/Core/CartesianCoordinates.h"

ComplexNumbers::ComplexNumbers(const double& RealPart, const double& ImaginaryPart)
{
    Complex = new<CartesianCoordinates>();
}

ComplexNumbers::ComplexNumbers() : ComplexNumbers(0, 0) {}

ComplexNumbers ComplexNumbers::operator*(const ComplexNumbers& X)
{
    return {_real * X.GetReal() - _imag * X.GetImag(), 
            _real * X.GetImag() + _imag * X.GetReal()};
}

ComplexNumbers ComplexNumbers::operator*(const double& Num)
{
    return {Num * _real, Num * _imag};
}

ComplexNumbers ComplexNumbers::operator/(const ComplexNumbers& X)
{
    return {(_real * X.GetReal() + _imag * X.GetImag()) / (std::pow(X.GetReal(), 2) + std::pow(X.GetImag(), 2)),
            (_imag * X.GetReal() - _real * X.GetImag()) / (std::pow(X.GetReal(), 2) + std::pow(X.GetImag(), 2))};
}

bool ComplexNumbers::operator==(const ComplexNumbers& X)
{
    if (this->_real == X.GetReal() && this->_imag == X.GetImag())
    {
        return true;
    }
    return false;
}

PolarCoordinate ComplexNumbers::ToPolarForm()
{
    return {this->GetAbs(), std::atan(_imag / _real) * 180 / 3.1415};
}

std::string ComplexNumbers::ToString() const
{
    std::ostringstream OutputStringStream;
    OutputStringStream << _real << "" << (_imag >= 0 ?  "+" : "") << _imag << "i";
    return OutputStringStream.str();
}
