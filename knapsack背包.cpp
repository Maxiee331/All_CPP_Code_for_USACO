#include <bits/stdc++.h>
using namespace std;
struct item{
    int weight;
    int value;
    item(int w, int v){
        v = value;
        w = weight;
    }
};



int main(){
    vector<int> dp(5);
    item*i1 = new item(1,3);
    item*i2 = new item(5,10);
    item*i3 = new item(2,1);
    item*i4 = new item(7,13);
    item*i5 = new item(3,8);
    item*i6 = new item(11,16);
    vector<item*> aa = {i1, i2, i3, i4, i5, i6};
    cout << aa[0]-> weight<< endl;
    for(auto item:aa){

        int w=item->weight;
        int v=item->value;


        for(int j=5;j>=w;j--){

            dp[j]=max(dp[j], dp[j-w]+v);

        }
    }

    cout << dp[5] << endl;

    return 0;
}




#include <bits/stdc++.h>
using namespace std;

int main(){

    int N, W;
    cin >> N >> W;

    vector<int> weight(N + 1);
    vector<int> value(N + 1);

    for(int i = 1; i <= N; i++){
        cin >> weight[i] >> value[i];
    }

    vector<vector<long long>> dp(
        N + 1,
        vector<long long>(W + 1, 0)
    );

    for(int i = 1; i <= N; i++){

        for(int j = 0; j <= W; j++){

            // 不选第 i 个
            dp[i][j] = dp[i - 1][j];

            // 选第 i 个
            if(j >= weight[i]){
                dp[i][j] = dp[i - 1][j - weight[i]] + value[i];
            }
        }
    }

    cout << dp[N][W] << endl;

    return 0;
}