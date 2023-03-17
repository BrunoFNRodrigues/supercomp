#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

int main(){
    struct item{
        int id;
        int peso;
        int valor;
    };
    //unsigned seed = std::chrono::system_clock
    int seed = 10;
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(0.0,1.0);

    int n = 0;
    int w = 0;

    vector<item> itens;
    vector<item> mochila;

    cin >> n >> w;
    itens.reserve(n); // reserva o espaço na memoria


    int peso, valor;
    for (int i = 0; i < n; i++)
    {
        cin >> peso;
        cin >> valor;
        itens.push_back({i, peso, valor});
    }
    // ordena 
    sort(itens.begin(), itens.end(), [](auto& i, auto& j){return i.valor > j.valor;}); //func de uma linha
    peso = 0;
    valor = 0;
    int i = 0;
    for(auto& el: itens){
        if(el.peso + peso <= w){
            mochila.push_back(el);
            peso += el.peso;
            valor += el.valor;
        }

        if (distribution(generator) > 0.75 && i < n){
            uniform_int_distribution<int> distributionInt(i , n-1);
            int p = distributionInt(generator);

            if (itens[p].peso + peso <= w)
            {
                mochila.push_back(itens[p]);
                peso = peso + itens[p].peso;
                valor = valor + itens[p].valor;
                itens.erase(itens.begin()+p-1);
            }
            i++;
        }
    }   

    sort(mochila.begin(), mochila.end(), [](auto& i, auto& j){return i.id < j.id;});
    for(auto& el:mochila){
        cout << el.id << " ";
    }
    cout << endl << "Valor:" << valor << endl;
    return 0;
    
}
/*
Fazer tudo que for possivel por referencias
Alocar toda memoria que voce sabe que vai usar para evitar realocamento
*/