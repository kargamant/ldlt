#include <vector>
#include <istream>

class Block
{
    private:
        static double sparse_percentage;
        std::vector<double> val;
        std::vector<long long> col;
        std::vector<long long> ptr;

        long long n;
        long long m;
    public:
        Block(long long n, long long m);

        void add_item(double item, long long i);

        friend std::istream& operator>>(std::istream& st, Block& bl);
        friend std::ostream& operator<<(std::ostream& st, Block& bl);
};

std::istream& operator>>(std::istream& st, Block& bl);
std::ostream& operator<<(std::ostream& st, Block& bl);