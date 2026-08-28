#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K,A,B;
    cin>>N>>K;
    vector<int> stack(N, 0);
    for(int i=0; i<K; i++){
        cin>>A>>B;
        for(int j=A-1; j<=B-1; j++){
            stack[j]+=1;
        }
    }
    sort(stack.begin(), stack.end());
    cout<<stack[N/2]<<endl;
    return 0;
}