#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,K,front,back,i,j,count=0;
    cin >> N >> K;
    vector<int> gate;
    for(i=0; i < N; i++){
        gate.push_back(0);
    }
    
    for(int i=0; i<K; i++){
        cin>>front>>back;
        for(int j=front-1; j<=back-1; j++){
            if (gate[j]==0){
                gate[j]=1;
            }
            else{
                gate[j]=0;
            }
        }
    }
        
    for(int element:gate){
        if(element==1){
            count++;
        }
    
    }
    cout<<count<<endl;
    return 0;

}