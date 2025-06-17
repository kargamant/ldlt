#include <unordered_map>
#include <vector>
#include <Block.h>

class CoordinateBlock : public Block
{
    private:
        std::unordered_map<long long, std::unordered_map<long long, double>> map;
    public:
        CoordinateBlock(long long n, long long m);

        double get_item(long long i, long long j) override;
        void set_item(long long i, long long j, double v);
        std::vector<std::vector<double>> to_vector() override;
};