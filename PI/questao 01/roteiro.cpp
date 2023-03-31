#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

double distance(double lat1, double lon1, double lat2, double lon2);

int main(){
    struct atividade{
        int id;
        double lat;
        double log;
    };

    // geração da seed para as buscas aleatórias
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    std::uniform_int_distribution<int> distribution(0.0,1.0);

    vector<atividade> atividades;
    vector<atividade> roteiro;

    int n;
    double lat, lon;
    cin >> n;

    roteiro.reserve(n);
    atividades.reserve(n);

    for (int i = 0; i < n; i++){
        cin >> lat >> lon;
        atividades.push_back({i+1,lat,lon});
    }

    uniform_int_distribution<int> distributionInt(0 , n-1);
    int p = distributionInt(generator);

    atividade atv_atual = atividades[p];
    roteiro.push_back(atv_atual);
    atividades.erase(atividades.begin()+p);

    int d_total = 0;
    double d_atual;

    while (n-1 > 0){
        double d_anterior = 1e8;
        int j = 0;
        for (int i = 0; i < n-1; i++){
            d_atual = distance(atv_atual.lat, atv_atual.log, atividades[i].lat, atividades[i].log);
            if (d_atual < d_anterior){
                j = i;
                d_anterior = d_atual;
            }
        }
        d_total += d_anterior;
        atv_atual = atividades[j];
        roteiro.push_back(atv_atual);
        atividades.erase(atividades.begin()+j);
        n--;
    }


    cout << "Distância total percorrida: " << d_total << " metros" << endl;
    cout << "Ordem das atividades:" << endl;
    cout << roteiro[0].id;
    roteiro.erase(roteiro.begin());
    for(auto& el:roteiro){
        cout << " -> "  << el.id;
    }
    cout << endl;


    return 0;
}




double distance(double lat1, double lon1, double lat2, double lon2) {
    const double R = 6371000;
    double phi1 = lat1 * M_PI / 180;
    double phi2 = lat2 * M_PI / 180;
    double dphi = (lat2 - lat1) * M_PI / 180;
    double dlambda = (lon2 - lon1) * M_PI / 180;
    double a = pow(sin(dphi / 2), 2) + cos(phi1) * cos(phi2) * pow(sin(dlambda / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    double distance = R * c;

    return distance;
 }