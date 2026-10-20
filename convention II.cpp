#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<pair<int,int>> cowandtime;
    for(int i = 0; i < N; i++){
        int cow;
        cin >> cow;
        int time;
        cin >> time;
        cowandtime[i] = {cow, time};
    }
    sort(cowandtime.begin(), first_cow_time.end());
    int waittime = 0, max = 0;
    int totaltimecount = 0;
    for(int i = 0; i < N; i++){
        totaltimecount += (cowandtime[i].first()+cowandtime.second());
        
    }
}