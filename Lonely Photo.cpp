#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;
    string cows;
    cin >> cows;
    int ans = 0;
    for(long long i = 0; i < N - 2; i++){
        for(long long j = 3; j < N - i; j++){
            int countg = 0, counth = 0;
            string temp = cows.substr(i, j);
            for (char ch : temp) {
                if (ch == 'G') {
                    countg++;
                }
                if(ch == 'H'){
                    counth++;
                }
            }
            if(countg == 1||counth == 1){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}