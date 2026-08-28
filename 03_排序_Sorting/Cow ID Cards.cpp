#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,every_ID;
    cin>>N;
    multiset<int> ID;
    set<int> monoID;
    for(int i=0; i<N; i++){
        cin>>every_ID;
        ID.insert(every_ID);
    }
    for(int element: ID){
        if (ID.count(element)==1){
            monoID.insert(element);
        }
    }
    cout<<monoID.size()<<endl;
    return 0;
}