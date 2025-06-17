#pragma once
#include <vector>

class Block
{
    protected:
        long long n;
        long long m;
    public:
        Block(long long n, long long m);

        virtual double get_item(long long i, long long j)=0;
        virtual std::vector<std::vector<double>> to_vector()=0;

        long long get_m() {return m;}
        long long get_n() {return n;}
};