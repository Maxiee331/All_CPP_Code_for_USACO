#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> cowpos;
    for(int i = 0; i < N; i++){
        int pos;
        cin >> pos;
        cowpos.push_back(pos);
    }
    vector<int> ans = cowpos;
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for(int a :cowpos){
        int indx = lower_bound(ans.begin(), ans.end(), a) - ans.begin();
        cout << a << " -> " << indx << endl;
    }
    return 0;
}