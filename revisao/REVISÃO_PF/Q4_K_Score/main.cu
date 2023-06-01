#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/transform_reduce.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <thrust/copy.h>
#include <thrust/fill.h>
#include <thrust/sequence.h>
#include <thrust/execution_policy.h>
#include <thrust/device_ptr.h>
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono>
#include <cstdio>

using namespace std;

int main() {
    const char* str1 = "ATCG";
    const char* str2 = "ATCD";

    size_t length = std::strlen(str1);

    // Alocar memória no device
    char* dev_str1;
    char* dev_str2;
    cudaMalloc((void**)&dev_str1, length * sizeof(char));
    cudaMalloc((void**)&dev_str2, length * sizeof(char));

    // Copiar dados para o device
    cudaMemcpy(dev_str1, str1, length * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_str2, str2, length * sizeof(char), cudaMemcpyHostToDevice);

    // Criar thrust::device_ptr a partir dos ponteiros no device
    thrust::device_ptr dev_ptr_str1(dev_str1);
    thrust::device_ptr dev_ptr_str2(dev_str2);

    bool equal = thrust::equal(dev_ptr_str1, dev_ptr_str1 + length, dev_ptr_str2);

    if (equal) {
        std::cout << "As strings são iguais." << std::endl;
    } else {
        std::cout << "As strings são diferentes." << std::endl;
    }

    // Liberar memória no device
    cudaFree(dev_str1);
    cudaFree(dev_str2);

    return 0;
}