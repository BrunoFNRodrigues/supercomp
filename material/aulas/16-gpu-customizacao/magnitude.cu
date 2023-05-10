#include <iostream>
 #include <iomanip>
 #include <cstdlib>
 #include <chrono>
 #include <cstdlib>
 #include <algorithm>
 #include <thrust/host_vector.h>
 #include <thrust/device_vector.h>
 #include <thrust/generate.h>
 #include <thrust/functional.h>
 #include <thrust/copy.h>
 #include <thrust/transform.h>
 #include <cmath>
 #include <random>

 using namespace std::chrono;

 void reportTime(const char* msg, steady_clock::duration span) {
     auto ms = duration_cast<milliseconds>(span);
     std::cout << msg << " - levou - " <<
      ms.count() << " milisegundos" << std::endl;
 }

 // CRIE UMA FUNCTOR PARA CALCULAR A SQUARE

struct square
{    
    square() {};
    __host__ __device__
    double operator()(const double& x) {
           return x * x;
    }
};

 // IMPLEMENTE O CALCULO DA MAGNITUDE COM THRUST
 float magnitude(thrust::device_vector<double> v) {
     float result;

    result = std::sqrt(thrust::transform_reduce( v.begin(), v.end(), square(), 0, thrust::plus<double>()));

     return result;
 }

 int main(int argc, char** argv) {
     if (argc != 2) {
         std::cerr << argv[0] << ": numero invalido de argumentos\n"; 
         std::cerr << "uso: " << argv[0] << "  tamanho do vetor\n"; 
         return 1;
     }
     int n = std::atoi(argv[1]); //numero de elementos
     steady_clock::time_point ts, te;


     // Faça um  vector em thrust 
    thrust::device_vector<double> v_d(n);

     // inicilize o  vector
     ts = steady_clock::now();

     std::generate(v_d.begin(), v_d.end(), std::rand);


     te = steady_clock::now();
     reportTime("Inicializacao", te - ts);

     // Calcule a magnitude do vetor
     ts = steady_clock::now();
     float len = magnitude(v_d);
     te = steady_clock::now();
     reportTime("Tempo para calculo", te - ts);


     std::cout << std::fixed << std::setprecision(4);
     std::cout << "Magnitude : " << len << std::endl;
 }