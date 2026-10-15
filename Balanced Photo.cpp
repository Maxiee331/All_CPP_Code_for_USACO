#include <bits/stdc++.h>
using namespace std;

int N;
vector<long long> tree;

void update(int i, long long delta){

    while(i <= N){

        tree[i] += delta;

        i += i & -i;
    }
}

long long query(int i){

    long long sum = 0;

    while(i > 0){

        sum += tree[i];

        i -= i & -i;
    }

    return sum;
}
bool cmp(pair<int, int> a, pair<int ,int> b){
    return a.first > b.first;
}

int main(){

    cin >> N;
    
    tree.assign(N + 1, 0);
    vector<pair<int,int>> cows;

    vector<long long> a(N + 1);
    for(int i = 1; i <= N; i++){

        cin >> a[i];
        cows.push_back({a[i], i});

        //update(i, a[i]);
    }
    sort(cows.begin(), cows.end(),cmp);
    int ans = 0;

    // 已经处理了多少头牛
    int processed = 0;

    for(int i = 0; i < N; i++){

    int position = cows[i].second;

        // 左边比当前牛高的数量
    int left = query(position - 1);

        // 已经处理的牛全部比当前牛高
        // 剩下的就在右边
    int right = processed - left;
    if(max(left, right) >
        2 * min(left, right)){

        ans++;
    }

        // 当前牛加入BIT
    update(position, 1);

    processed++;
    }

    cout << ans << endl;


    return 0;
}
