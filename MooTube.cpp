#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u;
    int v;
    int weight;
};
struct Query {
    int k;
    int v;
};
vector<int> parent;
vector<int> sizes;
// 找root
int findRoot(int x) {

    if (parent[x] == x) {
        return x;
    }

    return parent[x] = findRoot(parent[x]);
}

// 合并两个component
void unite(int a, int b) {

    int rootA = findRoot(a);
    int rootB = findRoot(b);
    if(rootA == rootB){
        return;
    }
    else{
        parent[rootB] = rootA;
        sizes[rootA] += sizes[rootB];
    }
}

int main(){
    int N, Q;
    cin >> N >> Q;
    vector<Edge> edges;
    for(int i = 0; i < N -1; i++){
        int s, e, r;
        cin >> s >> e >> r;
        edges.push_back({s, e, r});
    }
    vector<Query> qureys;
    for(int i = 0; i < Q; i++){
        int K, V;
        cin >> K >> V;
        qureys.push_back({K, V});
    }
    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight > b.weight;
         });
    
    parent.resize(N + 1);
    sizes.resize(N + 1, 1);
    for (int i = 1; i < N + 1; i++) {
        parent[i] = i;
    }
    vector<int> ans;
    int j = 0;
    for(Query x : qureys) {

        for(; j < N - 1 && edges[j].weight >= x.k; j++) {

            unite(edges[j].u, edges[j].v);
        }

        int root = findRoot(x.v);

        ans.push_back(sizes[root] - 1);
    }
    for(int f : ans){
        cout << f << endl;
    }
}