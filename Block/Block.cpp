#include <Block.h>

double Block::sparse_percentage = 0.05;

Block::Block(long long m, long long n) : m(m), n(n)
{
    val.reserve(sparse_percentage*n*m);
    ptr.reserve(sparse_percentage*m);
    col.reserve(sparse_percentage*n);
}

void Block::add_item(double item, long long i)
{
    val.push_back(item);
    col.push_back(i);
}

std::istream& operator>>(std::istream& st, Block& bl)
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

std::ostream& operator<<(std::ostream& st, Block& bl)
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
