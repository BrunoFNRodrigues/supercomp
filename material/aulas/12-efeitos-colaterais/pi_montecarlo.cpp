#include <time.h>
#include <math.h>
#include <iostream>
#include <omp.h>
#include <random>
#include <chrono>

#define ITERATIONS 1000000000

using namespace std;

int main(){
    double tdata = omp_get_wtime();

    int pi=0;
    srand((unsigned)time(NULL)); 
    #pragma omp parallel
    {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        std::default_random_engine generator(seed);
        std::uniform_real_distribution<double> distribution(0.0,1.0);

        #pragma omp for reduction(+:pi)    
        for (int i=0;i<ITERATIONS; i++){
            double x,y;

            
            x = distribution(generator);
            y = distribution(generator);
            if (x*x+y*y<=1)
                pi++;
        }
    
    }
    
    cout << "valor de PI: " << pi*4.0/ITERATIONS << endl;

    tdata = omp_get_wtime() - tdata;
    cout << "tempo em segundos: " << tdata << endl;

    return 0;

}
