#include<bits/stdc++.h>
using namespace std;

int main(){
    int asize;
    int arr []= {5, 4,12,123,266,176,12,23};
    asize = 7;
    for(int i = 0; i < asize; i++){
        for(int j = 0; j < asize; j++){
            if (arr[j] >= arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
            
        }
    }
    for(int i = 0; i < asize+1; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}