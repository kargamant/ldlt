#include <CsrBlock.h>

double CsrBlock::sparse_percentage = 0.05;

CsrBlock::CsrBlock(long long m, long long n) : Block(n, m)
{
    val.reserve(sparse_percentage*n*m);
    ptr.reserve(sparse_percentage*m);
    col.reserve(sparse_percentage*n);
}

void CsrBlock::add_item(double item, long long i)
{
    val.push_back(item);
    col.push_back(i);
}

std::istream& operator>>(std::istream& st, CsrBlock& bl)
{
    bl.ptr.push_back(0);

    for(long long i=0; i<bl.m; i++)
    {
        for(long long j=0; j<bl.n; j++)
        {
            double item = 0.0;
            st >> item;
            if(item != 0.0)
                bl.add_item(item, j);
        }
        bl.ptr.push_back(bl.val.size());
    }

    return st;
}

std::ostream& operator<<(std::ostream& st, CsrBlock& bl)
{
    st << "val: ";
    for(auto& v: bl.val)
        st << v << " ";
    st << std::endl << "col: ";
    
    for(auto& c: bl.col)
        st << c << " ";
    st << std::endl << "ptr: ";
    
    for(auto& p: bl.ptr)
        st << p << " ";
    st <<std::endl;
    
    return st;
}

double CsrBlock::get_item(long long i, long long j)
{
    if (cache.contains(i) && cache[i].contains(j))
        return cache[i][j];

    long long row_start = ptr[i];
    long long row_end = ptr[i+1];

    auto it = std::lower_bound(
        col.begin() + row_start,
        col.begin() + row_end,
        j
    );
    
    if (it != col.begin() + row_end && *it == j)
    {
        cache[i][j] = val[row_start + (it - (col.begin() + row_start))];
        return val[row_start + (it - (col.begin() + row_start))];
    }
    cache[i][j] = 0.0;
    return 0.0;
}

std::vector<std::vector<double>> CsrBlock::to_vector()
{
    std::vector<std::vector<double>> res{static_cast<size_t>(m), std::vector<double>(n)};
    for(long long i=0; i < ptr.size()-1; i++)
    {
        long long row_start = ptr[i];
        long long row_end = ptr[i+1];

        for(long long j=row_start; j<row_end; j++)
        {
            res[i][col[j]] = val[j];
        }
    }
    return res;
}