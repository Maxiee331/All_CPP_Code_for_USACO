#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, Q;
    cin >> N >> Q;
    int breed;
    int beg, en;
    vector<int> cows;
    
    vector<int> br1(N+1);
    br1[0] = 0;
    vector<int> br2(N+1);
    br2[0] = 0;
    vector<int> br3(N+1);
    br3[0] = 0;
    
    
    for(int i = 0; i < N; i++){
        cin >> breed;
        cows.push_back(breed);
    }


    for(int i = 1; i < N + 1; i++){
        if (cows[i - 1] == 1){
            br1[i] = br1[i - 1] + 1;
            br2[i] = br2[i - 1];
            br3[i] = br3[i - 1];
        }
        if (cows[i - 1] == 2){
            br2[i] = br2[i - 1] + 1;;
            br1[i] = br1[i - 1];
            br3[i] = br3[i - 1];
        }
        if (cows[i - 1] == 3){
            br3[i] = br3[i - 1] + 1;;
            br2[i] = br2[i - 1];
            br1[i] = br1[i - 1];
        }
    }
    vector<int> ans;

    for(int i = 0; i < Q; i++){
        cin >> beg >>en;
        ans.push_back(br1[en]-br1[beg - 1]);
        ans.push_back(br2[en]-br2[beg - 1]);
        ans.push_back(br3[en]-br3[beg - 1]);
    }

    for(int i = 0; i < Q; i++){
        for(int j = 0; j < 3; j++){
            cout << ans[3 * i + j] <<" ";
        }
        cout << endl;
    }

    return 0;
}