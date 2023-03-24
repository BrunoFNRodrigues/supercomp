#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include "valarray"

using namespace std;

int main(){
    struct filme{
        int id;
        int inicio;
        int fim;
        int categoria;
    };

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
        lista.push_back({i+1, inicio, fim, categoria});
    }

    sort(lista.begin(), lista.end(), [](auto& i, auto& j){return i.fim < j.fim;});

    vector<int> dia(24, 0);
    int tempo = 24;
    
    for(auto& el: lista){
        if(categorias[el.categoria-1] != 0){
            if(tempo - abs(el.fim - el.inicio) >= 0){
                if(el.fim > el.inicio){
                    if(count(dia.begin()+el.inicio, dia.end()-(24-el.fim), 0) == (el.fim - el.inicio)){
                        for (int i = el.inicio; i < el.fim; i++)
                        {
                            dia[i] = el.id;
                        }

                        maratona.push_back(el);
                        tempo -= (el.fim - el.inicio); 
                        categorias[el.categoria-1]--;
                    }                    
                } else {
                    if(count(dia.begin()+el.inicio, dia.end(), 0) == (24 - el.inicio)){
                        for (int i = el.inicio; i < 24; i++)
                        {
                            dia[i] = el.id;
                        }

                        maratona.push_back(el);
                        tempo -= (el.fim - el.inicio); 
                        categorias[el.categoria-1]--;
                    }
                }
            }
        }

    }    
    cout << "[ ";
        for(auto& el:dia){
    cout << el  <<" ";
    }
    cout << "]" << endl;

    for(auto& el:maratona){
        cout << el.id << " ";
    }
    cout << endl;

    ofstream file;
    file.open ("gananciosa.csv", ios_base::app);
    file << "n_filmes,n_categorias,t_restante,t_execucao,n_filmes,\n";
    file << to_string(n)+","+to_string(c)+","+to_string(tempo)+","+"100"+","+to_string(maratona.size());
    file.close();

}