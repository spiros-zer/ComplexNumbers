// Spyridon Zervos ©


#include "ComplexNumbersLibrary.h"
#include "PolarCoordinatesLibrary.h"
#include <cmath>
#include <sstream>

#define DEBUG
#ifdef DEBUG
#include <iostream>
#endif

ComplexNumber::ComplexNumber()
{
    _real = 0;
    _imag = 0;

    _absoluteValue = 0;
    _polarForm = {0, 0};

#ifdef DEBUG
    std::cout << "\n\033[4m>Default Constructor of ComplexNumber used.\033[0m" << std::endl;
#endif
}

ComplexNumber::ComplexNumber(const double& RealPart, const double& ImaginaryPart)
{
    _real = RealPart;
    _imag = ImaginaryPart;

    _absoluteValue = std::sqrt((std::pow(RealPart, 2) + std::pow(ImaginaryPart, 2)));
    _polarForm = {this->ToPolarForm()};

#ifdef DEBUG
    std::cout << "\n\033[4m>User defined Constructor of ComplexNumber used.\033[0m" << std::endl;
#endif
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& X)
{
    return {_real + X.GetReal(), _imag += X.GetImag()};
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& X)
{
    return {_real - X.GetReal(), _imag - X.GetImag()};
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& X)
{
    return {_real * X.GetReal() - _imag * X.GetImag(), 
            _real * X.GetImag() + _imag * X.GetReal()};
}

ComplexNumber ComplexNumber::operator*(const double& Num)
{
    return {Num * _real, Num * _imag};
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber& X)
{
    return {(_real * X.GetReal() + _imag * X.GetImag()) / (std::pow(X.GetReal(), 2) + std::pow(X.GetImag(), 2)),
            (_imag * X.GetReal() - _real * X.GetImag()) / (std::pow(X.GetReal(), 2) + std::pow(X.GetImag(), 2))};
}

ComplexNumber ComplexNumber::Conjugate()
{
    return {_real, -_imag};
}

double ComplexNumber::GetReal() const
{
    return _real;
}

void ComplexNumber::SetReal(const double& X)
{
    _real = X;
}

double ComplexNumber::GetImag() const
{
    return _imag;
}

void ComplexNumber::SetImag(const double& X)
{
    _imag = X;
}

double ComplexNumber::GetAbs() const
{
    return _absoluteValue;
}

PolarCoordinate ComplexNumber::ToPolarForm()
{
    return {this->GetAbs(), std::atan(_imag / _real) * 180 / 3.1415};
}

std::string ComplexNumber::ToString() const
{
    std::ostringstream OutputStringStream;
    OutputStringStream << _real << "" << (_imag >= 0 ?  "+" : "") << _imag << "i";
    return OutputStringStream.str();
}
