// (c) Spyridon Zervos


#include <iostream>

#include "CartesianCoordinates/CartesianCoordinates2D.h"
#include "Core/ComplexNumbers.h"
#include "PolarCoordinates/PolarCoordinates.h"

int main(int argc, char** argv)
{
    std::cout << "/**** FUNCTIONALITY TESTING OF COMPLEX NUMBERS */\n";

    std::cout << "Test 1: Initialization of a Complex." << '\n';
    ComplexNumbers A = { 3, 1 };
    std::cout << "A = ";
    A.Complex->Print();
    std::cout << '\n';
    std::cout << "Polar form of A = ";
    A.PolarForm->Print();
    std::cout << '\n';

    ComplexNumbers B = { 4, -5 };
    std::cout << "B = ";
    B.Complex->Print();
    std::cout << '\n';
    std::cout << "Polar form of B = ";
    B.PolarForm->Print();
    std::cout << '\n';

    std::cout << '\n';
    std::cout << "Test 2: Operations between Complexes." << '\n';
    
    ComplexNumbers C = (A + B) * 2;
    std::cout << "C = (A + B) * 2 = ";
    C.Complex->Print();
    std::cout << '\n';
    std::cout << "Polar form of C = ";
    C.PolarForm->Print();
    std::cout << '\n';

    ComplexNumbers D = ComplexNumbers{ 1, 2 } / ComplexNumbers{ 0.5, -0.1 };
    std::cout << "D = (1+2i)/(0.5-i) = ";
    D.Complex->Print();
    std::cout << '\n';
    std::cout << "Polar form of D = ";
    D.PolarForm->Print();
    std::cout << '\n';

    ComplexNumbers E = C - D;
    std::cout << "E = C - D = ";
    E.Complex->Print();
    std::cout << '\n';
    std::cout << "Polar form of E = ";
    E.PolarForm->Print();
    std::cout << '\n';

    std::cout << "\nTest 3: Initialization of Polar Coordinates." << '\n';
    ComplexNumbers W = {1, 90, true};
    std::cout << "W = ";
    W.Complex->Print();
    std::cout << '\n';
    std::cout << "Polar form of W = ";
    W.PolarForm->Print();
    std::cout << '\n';

    return 0;
}
