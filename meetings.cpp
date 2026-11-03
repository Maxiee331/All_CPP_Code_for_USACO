#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, L;
    cin >> N >> L;
    vector<pair<int, int>> posandspeed (N);
    vector<int> num;
    for(int i = 0; i < N; i++){
        int name;
        cin >> name;
        num.push_back(name);
        int pos, speed;
        cin >> pos >> speed;
        posandspeed[i] = {pos, speed};
    }
    sort(posandspeed.start(), posandspeed.end());
    
    return 0;
}