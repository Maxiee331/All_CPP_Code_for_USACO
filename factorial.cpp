#include <bits/stdc++.h>
using namespace std;

int factorial(int n){
    if(n==1){
        return 1;
    }

    return n*factorial(n-1);
}

int multiplier(int x, int y){
    if (y == 1){
        return x;
    }

    return x + multiplier(x, y-1);
}

int main(){
    int x,y;
    cin>>x>>y;
    cout<<multiplier(x,y)<<endl;

    //int n
    //cin>>n;
    //cout<<factorial(n)<<endl;



    return 0;
}