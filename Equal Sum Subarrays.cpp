#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Subarray{
    ll sum;
    int left, right;
};
int main(){
    int N;
    cin >> N;
    vector<ll> x(N);
    vector<ll> prex(N + 1,0);
    for(int i = 0; i < N; i++){
        ll s;
        cin >> s;
        x[i] = s;
        prex[i + 1] = s + prex[i];
    }
    vector<Subarray> sub;
    for(int i = 1; i < N + 1; i++){
        for(int j = i; j < N + 1; j++){
            sub.push_back({prex[j]-prex[i-1], i, j});
        }
    }
    sort(sub.begin(), sub.end(),
        [](const Subarray &a, const Subarray &b) {
            return a.sum < b.sum;
        });
    vector<ll> ans(N, 100000000000000000);
    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < sub.size(); j++){
            const auto &a = sub[j - 1];
            const auto &b = sub[j];
            bool ina = (a.left <= i && a.right >= i);
            bool inb = (b.left <= i && b.right >= i);
            if((ina && !inb) || (inb && !ina)){
                ans[i-1] = min(ans[i-1], (b.sum - a.sum));
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }
    return 0;
}