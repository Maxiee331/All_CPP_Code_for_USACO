#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, amount, sum =0, average, total =0;
    cin>>N;
    vector <int> food;
    for (int i=0; i<N; i++){
        cin>>amount;
        food.push_back(amount);
        sum += amount;
    }
    average =sum/N;

    for(int element: food){

        if(element > average){
            total = total +(element-average);
        }
    }
    cout<<total<<endl;
    return 0;
}