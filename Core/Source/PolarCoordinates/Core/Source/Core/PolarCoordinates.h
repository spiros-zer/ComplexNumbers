// (c) Spyridon Zervos


#pragma once

#include <string>

struct PolarCoordinates
{
    /** @brief The radius and angle in degrees of the Polar coordinates. */
    double R{}, Theta{};

    /** @brief Array containing the polar coordinates pair. */
    char* Cstring;

    /** @brief Size of the array. */
    int Size;

    /**** CONSTRUCTORS/DESTRUCTORS */
    PolarCoordinates(double InRadius, double InTheta);
    PolarCoordinates();

    /**** SETTERS/GETTERS */
    [[nodiscard]] double GetRadius() const {return R;}
    void SetRadius(double InRadius) {R = InRadius;}

    [[nodiscard]] double GetTheta() const {return Theta;}
    void SetTheta(double InTheta) {Theta = InTheta;}

    [[nodiscard]] int GetSize() const {return Size;}
    void SetSize(int InSize) {Size = InSize;}

    [[nodiscard]] char* GetCstring() const {return Cstring;}
    void SetCstring(char* InCstring) {Cstring = InCstring;}

    /**** OPERATOR OVERLOADING */
    PolarCoordinates operator*(const PolarCoordinates& X) const;
    PolarCoordinates operator/(const PolarCoordinates& X) const;

    /**** STRING OPERATIONS */
    /** @brief Converts the Polar coordinates to a std::string. */
    std::string ToString() const;

    /** @brief Converts cartesian coordinate to char*. */
    char* ToString(int& InSize, int Precision = 2) const;

    /** @brief Prints the Cstring in the iostream with the NULL char. */
    void Print() const;
};
