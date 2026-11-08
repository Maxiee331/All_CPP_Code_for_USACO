#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<string> a;
    for(int i = 0; i < N; i++){
        string x;
        cin >> x;
        a.push_back(x);
    }
    int wordcount = size(a[0]);
    cout << a[0];
    for(int i = 1; i < N; i++){
        int sizestr = size(a[i]);
        wordcount += sizestr;
        if(wordcount <= K){
            cout << " " << a[i];
        }
        else if(wordcount > K){
            cout << endl << a[i];
            wordcount = sizestr;
        }
    }
    return 0;
}