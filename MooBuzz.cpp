#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    int a = N % 8;
    int b = N / 8;
    if(b > 0){
        if(a == 1){
            cout << b * 1 << endl;
        }
        if(a == 2){
            cout << b * 2 << endl;
        }
        if(a == 3){
            cout << b * 4 << endl;
        }
        if(a == 4){
            cout << b * 7 << endl;
        }
        if(a == 5){
            cout << b * 8 << endl;
        }
        if(a == 6){
            cout << b * 16 << endl;
        }
        if(a == 7){
            cout << b * 13 << endl;
        }
        if(a == 0){
            cout << b * 14 << endl;
        }
    }
    else{
        if(a == 1){
            cout << 1 << endl;
        }
        if(a == 2){
            cout << 2 << endl;
        }
        if(a == 3){
            cout << 4 << endl;
        }
        if(a == 4){
            cout << 7 << endl;
        }
        if(a == 5){
            cout << 8 << endl;
        }
        if(a == 6){
            cout << 16 << endl;
        }
        if(a == 7){
            cout << 13 << endl;
        }
        if(a == 0){
            cout << 14 << endl;
        }
    }
    return 0;
}