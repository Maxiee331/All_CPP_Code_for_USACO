#include<bits/stdc++.h>
#include<cmath>
using namespace std;
using ll = long long;
struct grass{
    ll x;
    ll y;
    ll t;
};
struct cows{
    ll cx;
    ll cy;
    ll ct;
};
bool cmp(grass a, grass b){
    return a.t < b.t;
}
int main(){
    ll G,N;
    cin >> G >> N;
    vector<grass> grazing;
    for(ll i = 0; i < G; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        grazing.push_back({a,b,c});
    }
    vector<cows> pos;
    for(ll i = 0; i < N; i++){
        ll d, e, f;
        cin >> d >> e >> f;
        pos.push_back({d,e,f});
    }
    ll ans = 0;
    sort(grazing.begin(),grazing.end(),cmp);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < G; j++){
            double dis = 0.0;
            double dx = max(pos[i].cx, grazing[j].x)-min(pos[i].cx, grazing[j].x);
            double dy = max(pos[i].cy, grazing[j].y)-min(pos[i].cy, grazing[j].y);
            dis = sqrt(dx * dx + dy * dy);
            ll g = max(pos[i].ct,grazing[j].t)-min(pos[i].ct,grazing[j].t);
            if(g < dis){
                ans++;
                break;
            }
            else{
                continue;
            }
        }
    }
    cout << ans << endl;
    return 0;
}