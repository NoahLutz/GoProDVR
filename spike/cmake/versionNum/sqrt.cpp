#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<SquareRootConfig.h>

int main(int argc, char *argv[])
{
    
    if(argc < 2)
    {
        std::cout << "Usage: " << argv[0] << "<number>" << std::endl << SquareRoot_VERSION_MAJOR << SquareRoot_VERSION_MINOR << std::endl;
        return 1;
    }

    double inputVal = atof(argv[1]);
    double outVal = sqrt(inputVal);
    std::cout << "The square root of " << inputVal << " is " << outVal << std::endl;
    return 0;
}

