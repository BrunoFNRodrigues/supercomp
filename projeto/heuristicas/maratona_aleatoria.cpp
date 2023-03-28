#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include "valarray"

using namespace std;

int main(){
    struct filme{
        int id;
        int inicio;
        int fim;
        int categoria;
    };

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    //int seed = 10;
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(0.0,1.0);

    vector<int> categorias;
    vector<filme> lista;
    vector<filme> maratona;
    
    int n = 0;
    int c = 0;

    cin >> n >> c;
    int catn;
    for (int i = 0; i < c; i++){
        cin >> catn;
        categorias.push_back(catn); 
    }

    int inicio, fim, categoria;
    for (int i = 0; i < n; i++){
        cin >> inicio >> fim >> categoria;
        if(fim == 0){
            lista.push_back({i+1, inicio, 24, categoria});
        }
        else{
            lista.push_back({i+1, inicio, fim, categoria});
        }
    }

    sort(lista.begin(), lista.end(), [](auto& i, auto& j){return i.fim < j.fim;});

    vector<int> dia(24, 0);
    int tempo = 24;
    int j = 0;
    for(auto& el: lista){
        if(categorias[el.categoria-1] != 0){
            if(tempo - abs(el.fim - el.inicio) >= 0){
                if(el.fim > el.inicio){
                    if(count(dia.begin()+el.inicio, dia.end()-(24-el.fim), 0) == (el.fim - el.inicio)){
                        for (int i = el.inicio; i < el.fim; i++){
                            dia[i] = el.id;
                        }

                        maratona.push_back(el);
                        tempo -= (el.fim - el.inicio); 
                        categorias[el.categoria-1]--;
                    }                    
                }
            }
        }

        if (distribution(generator) > 0.75 && j < n){
            uniform_int_distribution<int> distributionInt(j , n-1);
            int p = distributionInt(generator);

            if(categorias[lista[p].categoria-1] != 0){
                        if(tempo - abs(lista[p].fim - lista[p].inicio) >= 0){
                            if(lista[p].fim > lista[p].inicio){
                                if(count(dia.begin()+lista[p].inicio, dia.end()-(24-lista[p].fim), 0) == (lista[p].fim - lista[p].inicio)){
                                    for (int i = lista[p].inicio; i < lista[p].fim; i++){
                                        dia[i] = lista[p].id;
                                    }

                                    maratona.push_back(lista[p]);
                                    tempo -= (lista[p].fim - lista[p].inicio); 
                                    categorias[lista[p].categoria-1]--;
                                    lista.erase(lista.begin()+p-1);
                                }                    
                            }
                        }
                    }

            j++;
        }

    }

    j = 0;
    for(auto& el:dia){
        cout << j << "h00 -> " << el  << endl;
        j++;
    }


    sort(maratona.begin(), maratona.end(), [](auto& i, auto& j){return i.id < j.id;});
    for(auto& el:maratona){
        cout << el.id << " ";
    }
    cout << endl;

    }    
