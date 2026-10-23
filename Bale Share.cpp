#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> bales(N);
    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> bales[i];
        sum += bales[i];
    }
    vector<vector<bool>> dp(2500,vector<bool>(2500,false));
    sort(bales.begin(), bales.end());
    dp[0][0] = true;
    int sumx = 0;
    for(int i = 0; i < N; i++){
        int cur = bales[i];
        sumx += bales[i];
        dp[cur][0] = true;
        dp[sumx][0] = true;
        int sum2 = 0;
        for(int j = i + 1; j < N; j++){
            sum2 += bales[j];
            int bale = bales[j];
            dp[cur][bale] = true;
            dp[sumx][bale] = true;
            dp[cur][sum2] = true;
            dp[sumx][sum2] = true;
        }
    }
    int minx = 0, ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dp[i][j] == false){
                continue;
            }
            int temp = max(max(i, j), sum - i - j);
            if(minx <= temp){
                minx = temp;
                ans = i;
            }
        }
    }
    cout << ans << endl;

    return 0;
}