#pragma once
#include <vector>
#include <istream>
#include <unordered_map>
#include <Block.h>

class CsrBlock : public Block
{
    private:
        static double sparse_percentage;
        std::vector<double> val;
        std::vector<long long> col;
        std::vector<long long> ptr;

        std::unordered_map<long long, std::unordered_map<long long, double>> cache;

        void add_item(double item, long long i);
    public:
        CsrBlock(long long n, long long m);


        double get_item(long long i, long long j) override;
        std::vector<std::vector<double>> to_vector() override;

        friend std::istream& operator>>(std::istream& st, CsrBlock& bl);
        friend std::ostream& operator<<(std::ostream& st, CsrBlock& bl);
};

std::istream& operator>>(std::istream& st, CsrBlock& bl);
std::ostream& operator<<(std::ostream& st, CsrBlock& bl);