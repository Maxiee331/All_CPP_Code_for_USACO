#include<bits/stdc++.h>
using namespace std;

int main(){
    int asize;
    int arr []= {5, 4,12,123,266,176,12,23};
    asize = 8;
    for(int i = asize-1; i > 0; i--){
        int temp = i;
        while(temp >= 0){
            if(arr[temp]<arr[temp-1]){
                swap(arr[temp],arr[temp-1]);
            }
            temp--;
        }
    }
    for(int i = 0; i < asize; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}