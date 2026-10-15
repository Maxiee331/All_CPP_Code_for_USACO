#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> pos;
    for(int i = 0; i < N; i++){
        int apos;
        cin >> apos;
        pos.push_back(apos);
    }
    sort(pos.begin(), pos.end());
    int maxR = (pos[N-1] - pos[0]) / (K*2);
    int ans = maxR;
    
    for(int i = maxR - 1; i > 0; i--){
        int current = i * 2;
        int nowpos =0;

        for(int j = 1; j <= K; j++){
            nowpos += current;

            for(int a = 0; a < N; a++){
                
                if(pos[a] >= nowpos){
                    nowpos = pos[a];
                    break;
                }
            }
        }
        if (nowpos >= pos[N - 1]){
            ans = i;
            continue;
        }
        
    }
    cout << ans << endl;

    return 0;
}