#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>

using namespace std;

int main(){
    //declaracao a struct para os filmes
    struct filme{
        int id;
        int inicio;
        int fim;
        int categoria;
    };

    // quantidade de filmes e categorias 
    int N = 0;
    int M = 0;

    // varicavel para a leitura dos limetes por categorias
    int catn;

    // le a primeira linha do arquivo e atribui os valores de quantidade de filmes e categorias
    cin >> N >> M;

    // vetor de categorias
    vector<int> max_filmes;

    // loop que le o limite de cada categoria e salva do vetor categorias
    for (int i = 0; i < M; i++){
        cin >> catn;
        max_filmes.push_back(catn); 
    }
    // vetor com todos os filmes
    vector<filme> lista;
    // vetor com os filmes selecionados
    vector<filme> maratona;

    // horario de inicio, fim e a categoria do filme
    int inicio, fim, categoria;

    // le uma linha correspondente a um filme até chegar no valor que foi passado na primeira linha do arquivo
    for (int i = 0; i < N+1; i++){
        cin >> inicio >> fim >> categoria;
        lista.push_back({i+1, inicio, fim, categoria});
    }

    // ordena a lista com base no horario de fim dos filmes sendo do menor para o maior
    sort(lista.begin(), lista.end(), [](auto& i, auto& j){return i.fim < j.fim;});
    // cria matriz com zeros

    vector< vector<int> > dp(N+1, vector<int>(M+1, 0));

    for (int j = 0; j < M; j++)
    {
        dp[0][j] = max_filmes[j];
    }


    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if(lista[i].categoria != j){
                dp[i+1][j] = dp[i][j];
            } 
            else{
                int last = i;
                while(last >= 0 && lista[last].fim > lista[i+1].inicio){
                    last = last - 1;
                }
                int max_count = 0;
                for (int k = 0; k < min(dp[last][j], (lista[i+1].fim)-(lista[i+1].inicio)); k++){
                    max_count = max(max_count, dp[last][j-1-k] + k + 1);
                }
                dp[i+1][j] = max(dp[i][j], max_count);
            }
        }
    }
    for (int i = 0; i < N+1; i++){
        for (int j = 0; j < M+1; j++){
            cout << dp[i][j] << " " ;
        }
        cout << endl;
    }
}