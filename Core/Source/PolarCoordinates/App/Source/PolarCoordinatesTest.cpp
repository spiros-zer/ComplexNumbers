// (c) Spyridon Zervos


#include<iostream>

#include "PolarCoordinates/Core/Source/Core/PolarCoordinates.h"

int main(int argc, char* argv[])
{
    /**** INITIALIZATION TESTTING */
    std::cout << "/**** INITIALIZATION TESTING */" << '\n';
    
    const PolarCoordinates X(1, 90);
    std::cout << "X ";
    X.Print();
    std::cout << '\n';

    const PolarCoordinates Y(4, 180);
    std::cout << "Y ";
    Y.Print();
    std::cout << '\n';

    PolarCoordinates Z(1, 0);
    std::cout<< "Z ";
    Z.Print();
    std::cout << '\n';

    /**** OPERATOR TESTING */
    std::cout << "/**** OPERATOR TESTING */" << '\n';

    Z = X * Y;
    std::cout << "Z = Χ * Υ = ";
    Z.Print();
    std::cout << '\n';

    const PolarCoordinates K = Z / Z;
    std::cout << "K = Z / Z = ";
    K.Print();
    std::cout << "\n";
    
    return 0;
}
