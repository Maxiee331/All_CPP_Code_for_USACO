
/*#include <bits/stdc++.h>
using namespace std;

struct Node{
    int u;
    int v;
};

vector<int> parent;
int findRoot(int index) {
    if (parent[index] == index) {
        return index;
    }

    return parent[index] = findRoot(parent[index]);
}
bool cmp(pair<int,pair<Node,Node>> a, pair<int,pair<Node,Node>> b){
    return a.first < b.first;
}

void unite(int a, int b) {

    int rootA = findRoot(a);
    int rootB = findRoot(b);

    parent[rootB] = rootA;
}

int main() {

    int N, C;
    cin >> N >> C;
    int edgeam = N * (N - 1) / 2;
    vector<Node> nodes;
    for(int i = 0; i < N; i++){
        int x, y;
        cin >> x >> y;
        nodes.push_back({x, y});
    }
    vector<pair<int,pair<Node,Node>>> edgeandis;
    for(int i = 1; i < N - 1; i++){
        for(int j = 2; j < N; j++){
            int fisx = nodes[i].u;
            int fisy = nodes[i].v;
            int secx = nodes[j].u;
            int secy = nodes[j].v;
            int dis = (fisx - secx)*(fisx - secx) + (fisy - secy) * (fisy - secy);
            if(dis >= C){
                edgeandis.push_back({dis,{{fisx,fisy}, {secx, secy}}});
            }
        }
    }
    sort(edgeandis.begin(),edgeandis.end(),cmp);
    parent.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    long long answer = 0;
    int edgeCount = 0;

    for (int i = 0; i < edgeam + 1; i++) {

        if (findRoot(edgeandis[i].second.first.u) != findRoot(edgeandis[i].second.second.u)&&findRoot(edgeandis[i].second.first.v) != findRoot(edgeandis[i].second.second.v)) {

            unite(,);

            answer += edgeandis[i].first;

            if(edgeandis[i].first != 0){
                edgeCount++;
            }

        }

        if (edgeCount == N - 1) {
            break;
        }
    }
    cout << answer << endl;

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u;
    int v;
    int weight;
};

vector<int> parent;

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

    parent[rootB] = rootA;
}

int main() {
    int N, C;
    cin >> N >> C;

    vector<int> x(N);
    vector<int> y(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    vector<Edge> edges;

    // Step 1: 建图
    for (int i = 0; i < N; i++) {

        for (int j = i + 1; j < N; j++) {

            int dx = x[i] - x[j];
            int dy = y[i] - y[j];

            int distance =
                dx * dx + dy * dy;

            // 只有distance >= C
            // 才允许建pipe
            if (true) {

                edges.push_back({
                    i,
                    j,
                    distance
                });
            }
        }
    }


// Step 2: 按weight排序

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.weight < b.weight;
         });


    // Step 3: 初始化DSU

    parent.resize(N);

    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }


    // Step 4: Kruskal

    long long answer = 0;

    int edgeCount = 0;

    for (Edge e : edges) {

        // 如果还不connected
        if (findRoot(e.u) != findRoot(e.v)) {

            unite(e.u, e.v);

            answer += e.weight;

            edgeCount++;

            // MST已经完成
            if (edgeCount == N - 1) {
                break;
            }
        }
    }


    // Step 5: Output

    if (edgeCount == N - 1) {
        cout << answer << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}