#include <random>
#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;
int main () {
    long N = 100000000L;
    long sum = 0;
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);
    for (long i = 0; i < N; i++) {
        double x, y;

        x = distribution(generator);
        y = distribution(generator);
        if (x*x + y*y <= 1) {
            sum++;
        }
    }
    double pi = 4.0 * sum / N;
    cout << pi << endl;
    cout << sum << endl;

} 