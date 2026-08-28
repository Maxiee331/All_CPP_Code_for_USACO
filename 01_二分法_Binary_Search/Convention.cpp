#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, C;
    cin >> N >> M >> C;
    
    vector<int> cow(N);
    for (int i = 0; i < N; i++) {
        cin >> cow[i];
    }

    sort(cow.begin(), cow.end());

    int low = 0, high = cow[N - 1] - cow[0];
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        int buses = 1;                 
        int first_cow_time = cow[0]; 
        int count = 1;                 

        for (int i = 1; i < N; i++) {
            if (count == C || (cow[i] - first_cow_time > mid)) {
                buses += 1;               
                first_cow_time = cow[i]; 
                count = 1;             
            } else {
                count += 1;               
            }
        }

        if (buses <= M) {
            ans = mid;        
            high = mid - 1;
        } else {
            low = mid + 1;    
        }
    }

    cout << ans << endl;

    return 0;
}
