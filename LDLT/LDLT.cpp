#include <LDLT.h>
#include <iostream>

CoordinateBlock ldlt_decompose(CsrBlock& bl)
{
    //std::vector<std::vector<double>> L{bl.get_m(), std::vector<double>(bl.get_n())};
    CoordinateBlock L{bl.get_n(), bl.get_m()};

    for(long long i=0; i<bl.get_m(); i++)
    {
        double dii = bl.get_item(i, i);
        //std::cout << "A[i][i]: " << dii << std::endl;
        for(long long j=0; j<i; j++)
            dii -= L.get_item(i, j) * L.get_item(i, j) * L.get_item(j, j);
        
        //std::cout << "D[i][i]: " << dii << std::endl;
        L.set_item(i, i, dii);

        if(i == bl.get_m()-1)
            break;

        //#pragma omp parallel for
        for(long long j=0; j<=i; j++)
        {
            double lij = bl.get_item(i+1, j) / L.get_item(j, j);
            //L[i+1][j] = bl.get_item(i+1, j) / L[j][j];
            for(long long k=0; k<j; k++)
                lij -= L.get_item(i+1, k) * L.get_item(j, k) * L.get_item(k, k) / L.get_item(j, j);
            //std::cout << "L[i][j]: " << lij << std::endl;
            L.set_item(i+1, j, lij);
        }
    }

    return L;
}

/*std::vector<std::vector<double>> ldlt_decompose_omp(Block& bl)
{

}*/