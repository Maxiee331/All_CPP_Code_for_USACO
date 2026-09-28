#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M,R;
    cin >> N >> M >> R;
    vector<int> milkamount;
    vector<pair<int,int>> store (M);
    vector<int> rentprice;
    vector<long long> milkProfit(N + 1, 0);
    vector<long long> rentprofit(N + 1, 0);
    for(int i = 0; i < N; i++){
        int amoun;
        cin >> amoun;
        milkamount.push_back(amoun);
    }
    for(int i = 0; i < M; i++){
        int c, q;
        cin >> c >> q;
        store[i] = {c, q};
    }
    for(int i = 0; i < R; i++){
        int rentfee;
        cin >> rentfee;
        rentprice.push_back(rentfee);
    }
    sort(rentprice.rbegin(), rentprice.rend());
    sort(milkamount.rbegin(), milkamount.rend());
    sort(store.rbegin(), store.rend());
    
    int storeIndex = 0;
    long long storeRemaining = 0;

    if (M > 0) {
        storeRemaining = store[0].second;
    }

    for (int i = 1; i <= N; i++) {
        long long milk = milkamount[i - 1];
        long long money = 0;
        while (milk > 0 && storeIndex < M) {

            long long amount = min(milk, storeRemaining);
            money += amount * store[storeIndex].first;

            milk -= amount;
            storeRemaining -= amount;

            if (storeRemaining == 0) {
                storeIndex++;

                if (storeIndex < M) {
                    storeRemaining = store[storeIndex].second;
                }
            }
        }

        milkProfit[i] = milkProfit[i - 1] + money;
    }
    for(int i = 1; i <= N; i++){

        rentprofit[i] = rentprofit[i - 1];

        if(i <= R){
            rentprofit[i] += rentprice[i - 1];
        }
    }

    long long ans = 0;
    long long temp = 0;

    for(int i = 0; i < N + 1; i ++){
        cout << milkProfit[i]<<endl;
    }
    for(int i = 0; i < R +1; i ++){
        cout << rentprice[i]<< endl;
    }
    
    for(int i = 0; i < N + 1; i++){
        if(i > M || N + 1 - i > R){
            continue;
        }
        temp = milkProfit[i] + rentprofit[N - i];
        if(temp >= ans){
            ans = temp;
            cout << ans << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
