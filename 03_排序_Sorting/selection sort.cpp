#include<bits/stdc++.h>
using namespace std;

int main(){
    int asize;
    int arr []= {5, 4,12,123,266,176,12,23};
    asize = 8;
    int newarr[8];
    for(int i = 0; i < 8; i++){
        int temp = 0;
        int currentmin= 30000;
        for(int j = temp; j< asize; j++){
            if (arr[j] < currentmin){
                currentmin = arr[j];
                newarr[temp] = currentmin;
            }
        }
        temp++;
    }

    for(int i = 0; i < asize; i++){
        cout<<newarr[i]<<" ";
    }
    return 0;

}