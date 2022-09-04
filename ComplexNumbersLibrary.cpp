// Spyridon Zervos ©


#include "ComplexNumbersLibrary.h"

#include "PolarCoordinatesLibrary.h"
#include <cmath>
#include <sstream>

ComplexNumber::ComplexNumber()
{
    _real = 0;
    _imag = 0;

    _absoluteValue = 0;
    _polarForm = new PolarCoordinate{};
}

ComplexNumber::ComplexNumber(const double& RealPart, const double& ImaginaryPart)
{
    _real = RealPart;
    _imag = ImaginaryPart;

    _absoluteValue = std::sqrt((std::pow(RealPart, 2) + std::pow(ImaginaryPart, 2)));
    _polarForm = new PolarCoordinate{this->ToPolarForm()};
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
