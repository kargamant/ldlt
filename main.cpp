#include <CsrBlock.h>
#include <iostream>
#include <fstream>
#include <LDLT.h>
#include <chrono>

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        std::cout << "Error. Input and Output filenames should be specified." << std::endl;
        return 1;
    }

    std::cout << "Reading matrix..." << std::endl;
    std::ifstream ifs{argv[1], std::ios::in};

    long long m, n;
    ifs >> m >> n;
    CsrBlock bl{m, n};
    ifs >> bl;


    std::cout << "Decomposing matrix..." << std::endl;
    auto start = std::chrono::system_clock::now();
    auto ld = ldlt_decompose(bl);
    auto end = std::chrono::system_clock::now();
    std::cout << "decomposition took: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << " milliseconds" << std::endl;

    std::ofstream ofs{argv[2], std::ios::out};
    ofs << m << " " << n << std::endl;
    auto res = ld.to_vector();
    for(auto& vec: res)
    {
        for(auto& item: vec)
            ofs << item << " ";
        ofs << std::endl;
    }
    std::cout << "decomposition written to " << argv[2] << std::endl;

    return 0;
}