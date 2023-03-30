#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]){
    //declaracao a struct para os filmes
    struct filme{
        int id;
        int inicio;
        int fim;
        int categoria;
    };

    // vetor de categorias
    vector<int> categorias;
    // vetor com todos os filmes
    vector<filme> lista;
    // vetor com os filmes selecionados
    vector<filme> maratona;

    // quantidade de filmes e categorias 
    int n = 0;
    int c = 0;
    // varicavel para a leitura dos limetes por categorias
    int catn;

    // le a primeira linha do arquivo e atribui os valores de quantidade de filmes e categorias
    cin >> n >> c;

    // loop que le o limite de cada categoria e salva do vetor categorias
    for (int i = 0; i < c; i++){
        cin >> catn;
        categorias.push_back(catn); 
    }

    // horario de inicio, fim e a categoria do filme
    int inicio, fim, categoria;

    // le uma linha correspondente a um filme até chegar no valor que foi passado na primeira linha do arquivo
    for (int i = 0; i < n; i++){
        cin >> inicio >> fim >> categoria;
        // realiza o ajuste horario caso um filme acaba em horario menor que o de inicio para ele acabar as 24
        if (fim < inicio){
            lista.push_back({i+1, inicio, 24, categoria});
        } else {
            lista.push_back({i+1, inicio, fim, categoria});
        }
    }

    // ordena a lista com base no horario de fim dos filmes sendo do menor para o maior
    sort(lista.begin(), lista.end(), [](auto& i, auto& j){return i.fim < j.fim;});

    // vetor que serve para alocar os filmes em um espaço de 24 horas
    vector<int> dia(24, 0);
    int tempo = 24;
    // inicia a contagem do tempo de execução
    clock_t t = clock();
    // adiciona um filme a maratona...
    for(auto& el: lista){
        // se ainda puderem ser adicionados mais filmes da categoria
        if(categorias[el.categoria-1] != 0){
            // a não estourar o limite de tempo
            if(tempo - abs(el.fim - el.inicio) >= 0){
                // se o horario que acaba for maior que o do que comeca
                if(el.fim > el.inicio){
                    // se não tem nenhum filme ja esta ocupando periodo de tempo
                    if(count(dia.begin()+el.inicio, dia.end()-(24-el.fim), 0) == (el.fim - el.inicio)){
                        for (int i = el.inicio; i < el.fim; i++)
                        {
                            dia[i] = el.id;
                        }

                        maratona.push_back(el);
                        // diminui o tempo disponivel
                        tempo -= (el.fim - el.inicio); 
                        // diminui a quantidade de filmes que ainda podem ser colocadas naquela categoria
                        categorias[el.categoria-1]--;
                    }                    
                } 
            }
        }
    } 
    // termina de contar o tempo de execucao
    t = clock() - t;   
 
    // realiza o output grafico de como ficaram alocados os filmes
    cout << "[ ";
        for(auto& el:dia){
    cout << el  <<" ";
    }
    cout << "]" << endl;
    
    // realiza o output dos filmes que foram selecionados
    for(auto& el:maratona){
        cout << el.id << " ";
    }
    cout << endl;
    // salvo os valoresde quantidade de filmes, quantidade de categorias, tempo nao alocado, tempo de execucao e quantidade de filmes alocados 
    // em um arquivo csv
    string arquivo = argv[1];
    ofstream file;
    file.open ("./../resultados/"+arquivo+".csv", ios_base::app);
    file << to_string(n)+","+to_string(c)+","+to_string(tempo)+","+to_string(((float)t)/CLOCKS_PER_SEC)+","+to_string(maratona.size()) << endl;
    file.close();

}