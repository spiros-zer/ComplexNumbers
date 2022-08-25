#include "ComplexNumbersLibrary.h"
#include "PolarCoordinatesLibrary.h"
#include <iostream>

/**
 * @brief Simple function to test the Complex&Polar Libraries.
 */
void TestComplexLibrary();

int main(int argc, char** argv)
{
    TestComplexLibrary();
    return 0;
}

void TestComplexLibrary()
{
    std::cout << "*Testing the functionality of ComplexNumbersLibrary:\n";

    ComplexNumber A = {3, 1};
    std::cout << "A = " << A.ToString() << std::endl;
    std::cout << "Polar form of A =  " << (A.ToPolarForm()).ToString() << std::endl;

    ComplexNumber B = {4, -5};
    std::cout << "B = " << B.ToString() << std::endl;
    std::cout << "Polar form of B =  " << (B.ToPolarForm()).ToString() << std::endl;

    ComplexNumber C = (A + B) * 2;
    std::cout << "C = " << C.ToString() << std::endl;
    std::cout << "Polar form of C =  " << (C.ToPolarForm()).ToString() << std::endl;

    ComplexNumber D = ComplexNumber{1, 2} / ComplexNumber{0.5, -0.1};
    std::cout << "D = " << D.ToString() << std::endl;
    std::cout << "Polar form of D =  " << (D.ToPolarForm()).ToString() << std::endl;

    ComplexNumber E = C - D;
    std::cout << "E = " << E.ToString() << std::endl;
    std::cout << "Polar form of E =  " << (E.ToPolarForm()).ToString() << std::endl;

    PolarCoordinate W = {1, 90};
    std::cout << "W = " << W.ToString() << std::endl;

    std::cout << (PolarCoordinate{-1, -90} * W).ToString() << std::endl;
}