#include <math.h>
#include <iostream>
#include <omp.h>

using namespace std;

int main(){
    double tdata = omp_get_wtime();
    int nthreads = omp_get_max_threads();
    static int N = 1000000000;
    double sum = 0.0;

    cout << "Número de threads: " << nthreads << endl;
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++)
    {
        sum += pow(-1, i)/(2*i + 1);
    }

    cout << "valor de PI: " << sum*4 << endl;
    tdata = omp_get_wtime() - tdata;
    cout << "tempo em segundos: " << tdata << endl;

    return 0;
}