// (c) Spyridon Zervos


#include "ComplexNumber.h"
#include "PolarCoordinate.h"
#include <iostream>

int main(int argc, char** argv)
{
    std::cout << "\n> Testing the functionality of the ComplexNumber & PolarCoordinate Library:\n\n";

    std::cout << "\nTest 1: Initialization of a Complex." << std::endl;
    ComplexNumber A = { 3, 1 };
    std::cout << "A = " << A.ToString() << std::endl;
    std::cout << "Polar form of A =  " << (A.ToPolarForm()).ToString() << std::endl;

    ComplexNumber B = { 4, -5 };
    std::cout << "B = " << B.ToString() << std::endl;
    std::cout << "Polar form of B =  " << (B.ToPolarForm()).ToString() << std::endl;

    std::cout << "\nTest 2: Operations between Complexes." << std::endl;
    ComplexNumber C = (A + B) * 2;
    std::cout << "C = (A + B) * 2 = " << C.ToString() << std::endl;
    std::cout << "Polar form of C =  " << (C.ToPolarForm()).ToString() << std::endl;

    ComplexNumber D = ComplexNumber{ 1, 2 } / ComplexNumber{ 0.5, -0.1 };
    std::cout << "D = (1+2i)/(0.5-i) = " << D.ToString() << std::endl;
    std::cout << "Polar form of D =  " << (D.ToPolarForm()).ToString() << std::endl;

    ComplexNumber E = C - D;
    std::cout << "E = C - D = " << E.ToString() << std::endl;
    std::cout << "Polar form of E =  " << (E.ToPolarForm()).ToString() << std::endl;

    std::cout << "\nTest 3: Initialization of Polar Coordinates." << std::endl;
    PolarCoordinate W = { 1, 90 };
    std::cout << "W = " << W.ToString() << std::endl;

    std::cout << "\nTest 4: Operations between Polar Coordinates." << std::endl;
    std::cout << (PolarCoordinate{ -1, -90 } * W).ToString() << std::endl;
    return 0;
}
