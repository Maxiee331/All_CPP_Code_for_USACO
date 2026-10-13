#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>&graph, vector<bool>&visited){
    visited[node] = true;
    for(int next : graph[node]){
        if(!visited[next]){
            dfs(next, graph, visited);

        }
    }
}
int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    vector<bool> visited(N + 1, false);
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    int a, counta = 0;
    cin >> a;
    dfs(a, graph, visited);
    for (bool trth: visited){
        if (trth == true){
            counta += 1;
        }
    }
    cout << counta << endl; 
   
    return 0;
}








/* task 1
for (int i = 1; i < N + 1; i++){
        cout << (i) <<": ";
        for (int neigh : graph[i]){
            cout << neigh <<" ";
        }
        cout << endl;
    }












    int a;
    cin >> a;
    cout << "aaaaa"<< endl;
    dfs(a);
    cout << size(visited) << endl;
*/