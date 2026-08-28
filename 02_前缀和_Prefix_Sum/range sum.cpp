#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, Q, number, l, r;
    cin>>N>>Q;
    vector<int>queue;
    for(int i = 0; i < N; i++){
        cin>>number;
        queue.push_back(number);
    }
    for(int i = 0; i < Q; i++){
        int sum = 0;
        cin>> l >> r;
        for(int j = l; j < r; j++){
            sum += queue[j];
        }
        cout << sum <<endl;
    }
    return 0;
}