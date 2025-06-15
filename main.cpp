#include <Block.h>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cout << "Error. Filename not specified." << std::endl;
        return 1;
    }

    std::ifstream fs{argv[1], std::ios::in};

    //std::cout << "enter size: ";
    long long m, n;
    fs >> m >> n;
    Block bl{m, n};
    //std::cout << "enter matrix:" << std::endl;
    fs >> bl;

    std::cout << "CSR representation:" << std::endl;
    std::cout << bl;
    return 0;
}