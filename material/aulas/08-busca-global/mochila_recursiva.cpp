#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

struct item{
        int id;
        int peso;
        int valor;
    };

int knapSack(int w, vector<item> itens, vector<item>& usado, vector<item>& melhor){
    int peso = 0;
    int valor = 0;
    int sem_i = 0, com_i = 0;
    vector<item> itens2 = itens;
    if(itens.empty() || w == 0){
        return 0;
    }

    if(itens[0].peso <= w){
        usado.push_back(itens[0]);
        valor = itens[0].valor;
        peso = itens[0].peso;
        itens.erase(itens.begin());
        com_i = knapSack(w-peso, itens, usado, melhor);
    }

    itens2.erase(itens2.begin());
    sem_i = knapSack(w, itens2, usado, melhor);

    int valor_atual = 0, valor_melhor = 0;
    for(auto& el: usado){
        valor_atual += el.valor;
    }

    for(auto& el:melhor){
        valor_melhor += el.valor;
    }

    if (valor_atual > valor_melhor){
        melhor = usado;
    }

    usado.clear();
    return max(sem_i, com_i + valor);
}

int main(){
        int n = 0;
        int w = 0;


        vector<item> itens, usado, melhor;
        vector<item> mochila;

        cin >> n >> w;
        itens.reserve(n); // reserva o espaço na memoria
        usado.reserve(n);

        int peso, valor;
        for (int i = 0; i < n; i++)
        {
            cin >> peso;
            cin >> valor;
            itens.push_back({i, peso, valor});
        }
        cout << "Resultado = " << knapSack(w, itens, usado, melhor) << endl;
        for(auto& el: melhor){
            cout << el.id << " ";
        }
        return 0;

}