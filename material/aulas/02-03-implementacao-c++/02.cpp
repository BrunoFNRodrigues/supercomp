#include <iostream>

using namespace std;

int main(){
    int x;
    cout << "Num:" << endl;
    if(!(cin >> x)){
        cout << "NaN" << endl;
        return 1;
    }
    return 0;
}