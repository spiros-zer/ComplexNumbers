// (c) Spyridon Zervos


#include <iostream>
#include <sstream>

#include "PolarCoordinates.h"
#include "Converters/Core/Source/Core/Double2Cstring.h"

PolarCoordinates::PolarCoordinates(double InRadius, double InTheta)
{
    R = InRadius;
    Theta = InTheta;
    Cstring = ToString(Size);
}

PolarCoordinates::PolarCoordinates() : PolarCoordinates(0, 0) {}

PolarCoordinates PolarCoordinates::operator*(const PolarCoordinates& X) const
{
    return {R * X.GetRadius(), Theta + X.GetTheta()};
}

PolarCoordinates PolarCoordinates::operator/(const PolarCoordinates& X) const
{
    return {R / X.GetRadius(), Theta - X.GetTheta()};
}

std::string PolarCoordinates::ToString() const
{
    std::ostringstream OutputStringStream;
    OutputStringStream << R << "/_" << Theta;
    return OutputStringStream.str();
}

char* PolarCoordinates::ToString(int& InSize, int Precision) const
{
    int SizeX{0}, SizeY{0};

    const char* XToCString = Converters::DoubleToCstring(R, SizeX, Precision);
    const char* YToCString = Converters::DoubleToCstring(Theta, SizeY, Precision);
    
    const int TotalSize = SizeX + SizeY - 1 + /* angle symbol /_*/ 2;
    char* Result = new char[TotalSize];

    /**** STRUCTURING RESULT */
    int j = 0;
    for (; j < SizeX; j++)
    {
        Result[j] = XToCString[j];
    }
    Result[j++] = '/';
    Result[j++] = '_';
    for (int i = 0; i < SizeY - 1; i++)
    {
        Result[j++] = YToCString[i];
    }
    Result[TotalSize - 1] = '\0';
    
    InSize = TotalSize;
    return Result;
}

void PolarCoordinates::Print() const
{
    for (int i = 0; i < Size; i++)
    {
        std::cout << Cstring[i];
    }
}
