#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<double> plant;
    for(int i = 0; i < N; i++){
        double p;
        cin >> p;
        plant.push_back(p);
    }
    double ans = N, sum = 0.0;
    for(int i = 0; i < N; i++){
        sum = plant[i];
        for(int j = i + 1; j < N; j++){
            sum += plant[j];
            double aveg = sum/(j-i+1);
            for(int k = i; k <= j; k++){
                if(plant[k] == aveg){
                    ans++;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}