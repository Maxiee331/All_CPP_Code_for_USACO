#include <bits/stdc++.h>
using namespace std;

int main(){
    string stri;
    cin >> stri;
    int n = size(stri);
    int left = 0;
    set<char>temp;
    int ans = 0;
    for (int right = 0; right < n; right++){
        while (temp.count(stri[right])){
            temp.erase(stri[left]);
            left++;
        }
        temp.insert(stri[right]);
        ans = max(ans, (int) temp.size());
    }

    cout << ans << endl;
    return 0;
}



//((temp.size()-1) != right)||(left <= n)