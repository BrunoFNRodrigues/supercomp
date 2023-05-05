#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <thrust/functional.h>
#include <thrust/transform.h>
#include <iostream>
#include <chrono>

int main(){
    thrust::host_vector<double>vcpu(2518);
    for(int i=0;i<2518;i++)
    std::cin>>vcpu[i];

    thrust::device_vector<double> vgpu(vcpu);
    double media = thrust::reduce(vgpu.begin(), vgpu.end(), (double) 0, thrust::plus<double>()) / vgpu.size();
    std::cout << "Média: " << media << std::endl;

    //Ponteiro para espaço especifico do vetor no caso aponta para o elemento 365 de trás para frente
    thrust::device_vector<double>::iterator last_365 = vgpu.end() - 365;
    double media365 = thrust::reduce(last_365, vgpu.end(), (double) 0, thrust::plus<double>()) / 365;
    std::cout << "Média dos últimos 365: " << media365 << std::endl;

    //Ponteiro para o valor máximo do vetor             Pega o maior valor
    thrust::device_vector<double>::iterator max_elem = thrust::max_element(vgpu.begin(), vgpu.end());
    //Ponteiro para o valor mínimo do vetor             Pega o menor valor
    thrust::device_vector<double>::iterator min_elem = thrust::min_element(vgpu.begin(), vgpu.end());
    std::cout << "Max. Val.: " << *max_elem << std::endl;
    std::cout << "Min. Val.: " << *min_elem << std::endl;

    max_elem = thrust::max_element(last_365, vgpu.end());
    min_elem = thrust::min_element(last_365, vgpu.end());
    std::cout << "Max. Val. 365: " << *max_elem << std::endl;
    std::cout << "Min. Val. 365: " << *min_elem << std::endl;


}