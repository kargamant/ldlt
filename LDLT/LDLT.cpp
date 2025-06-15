#include <LDLT.h>
#include <iostream>

std::vector<std::vector<double>> ldlt_decompose(Block& bl)
{
    std::vector<std::vector<double>> L{bl.m, std::vector<double>(bl.n)};

    for(long long i=0; i<bl.m; i++)
    {
        L[i][i] = bl.get_item(i, i);
        std::cout << "A[i][i]: " << L[i][i] << std::endl;
        for(long long j=0; j<i; j++)
            L[i][i] -= L[i][j] * L[i][j] * L[j][j];
        
        std::cout << "D[i][i]: " << L[i][i] << std::endl;
        
        if(i == bl.m-1)
            break;

        for(long long j=0; j<=i; j++)
        {
            L[i+1][j] = bl.get_item(i+1, j) / L[j][j];
            for(long long k=0; k<j; k++)
                L[i+1][j] -= L[i+1][k] * L[j][k] * L[k][k] / L[j][j];
        }
    }
    return L;
}