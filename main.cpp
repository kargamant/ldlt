#include <Block.h>
#include <iostream>
#include <fstream>
#include <LDLT.h>

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        std::cout << "Error. Input and Output filenames should be specified." << std::endl;
        return 1;
    }

    std::ifstream ifs{argv[1], std::ios::in};

    //std::cout << "enter size: ";
    long long m, n;
    ifs >> m >> n;
    Block bl{m, n};
    //std::cout << "enter matrix:" << std::endl;
    ifs >> bl;

    std::cout << "CSR representation:" << std::endl;
    std::cout << bl;

    auto res = ldlt_decompose(bl);

    std::ofstream ofs{argv[2], std::ios::out};
    ofs << m << " " << n << std::endl;
    for(auto& vec: res)
    {
        for(auto& item: vec)
            ofs << item << " ";
        ofs << std::endl;
    }
    std::cout << std::endl;

    return 0;
}