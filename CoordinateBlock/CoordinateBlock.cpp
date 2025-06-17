#include <CoordinateBlock.h>

CoordinateBlock::CoordinateBlock(long long n, long long m) : Block(n, m)
{

}

double CoordinateBlock::get_item(long long i, long long j)
{
    if(map.contains(i) && map[i].contains(j))
        return map[i][j];
    return 0.0;
}

std::vector<std::vector<double>> CoordinateBlock::to_vector()
{
    std::vector<std::vector<double>> vec{static_cast<size_t>(m), std::vector<double>(n)};
    for(auto& itr1: map)
    {
        for(auto& itr2: itr1.second)
            vec[itr1.first][itr2.first] = itr2.second;
    }
    return vec;
}

void CoordinateBlock::set_item(long long i, long long j, double v)
{
    if(v != 0.0)
        map[i][j] = v;
    else if(map.contains(i))
        map[i].erase(j);
}