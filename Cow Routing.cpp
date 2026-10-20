#include<bits/stdc++.h>
using namespace std;
/*
int main(){
    int a, b, N;
    cin >> a >> b >> N;
    vector<long long> cost;
    vector<vector<int>> dest(N + 1);
    vector<int> edgec;
    int edgecount = 0;
    set<int> node;
    for(int i = 0; i < N; i++){
        int co;
        cin >> co;
        int numa;
        cin >> numa;
        cost.push_back(co);
        for(int j = 0; j < numa; j++){
            int x;
            cin >> x;
            dest[i].push_back(x);
            edgecount++;
            node.insert(x);
        }
        edgec.push_back(edgecount);
        edgecount = 0;
    }
    int c = node.size();
    vector<vector<pair<int, int>>> graph(c + 1);
    for(int i = 0; i < N; i++){
        for (int j = 0; j < edgec[i]; j++) {
            graph[dest[i][j]].push_back({dest[i][j+1], cost[i]});
        }
    }

    const long long INF = 4e18;

    vector<long long> dist(c + 1, INF);

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    int start = c;

    dist[start] = 0;
    pq.push({0, start});
    long long count = 0;
    while (!pq.empty()) {
        long long currentDist = pq.top().first;
        int current = pq.top().second;

        pq.pop();
        if (currentDist != dist[current]) {
            continue;
        }

        for (auto edge : graph[current]) {
            int next = edge.first;
            int weight = edge.second;

            if (dist[current] + weight < dist[next]) {
                dist[next] = dist[current] + weight;

                pq.push({dist[next], next});
            }
        }
    }

    cout << dist[b-1] <<" ";





    return 0;

}*/
