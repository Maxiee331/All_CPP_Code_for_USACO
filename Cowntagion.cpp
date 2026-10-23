#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>&graph, vector<bool>&visited, int&countx, int tar){
    visited[node] = true;
    for(int next : graph[node]){
        if(!visited[next] && next != tar){
            countx++;
            dfs(next, graph, visited, countx, tar);
        }
    }
}
int main(){
    int N;
    cin >> N;
    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);
    vector<int> a;
    for(int i = 0; i < N; i++){
        a.push_back(i + 1);
    }
    for (int i = 0; i < N - 1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    
    
    int countx = 0, suma = 0;
    for (int i = 1; i < N; i++){
        int tar = a[i];
        dfs(1, graph, visited, countx, tar);
        for(bool a : visited){
            a = false;
        }
        suma += countx;
        countx = 0;
    }

    cout << suma << endl; 

    return 0;
}