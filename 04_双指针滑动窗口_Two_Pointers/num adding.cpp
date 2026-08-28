#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> vec = {2, 3, 1, 2, 4, 3};
    int S = 7, ans = 30000,left = 0;
    int suma = 0, maxsum = 0;

    
    
    for(int right = 0; right < (int)size(vec); right++){
        maxsum += vec[right];
    }
    if (maxsum < S){
        cout<< "no result"<< endl;
        return -1;
    }



    for (int right = 0; right < (int)size(vec); right++){
        suma += vec[right];
        while (suma >= 7){
            ans = min(ans, (right - left +1));
            suma -= vec[left];
            left++;
        }
        
    }
    cout<<ans<<endl;
    return 0;
}