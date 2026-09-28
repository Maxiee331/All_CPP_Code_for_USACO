#include <bits/stdc++.h>
using namespace std;

int N;

vector<long long> a;
vector<long long> tree;


void build(int node, int left, int right){

    if(left == right){

        tree[node] = a[left];

        return;
    }

    int mid = (left + right) / 2;

    build(
        node * 2,
        left,
        mid
    );

    build(
        node * 2 + 1,
        mid + 1,
        right
    );

    tree[node] =
        tree[node * 2]
        +
        tree[node * 2 + 1];
    
    // 如果不是求区间和，而是求最大值
    // tree[node] = max( tree[node * 2],  tree[node * 2 + 1])

}


long long query(
    int node,
    int left,
    int right,
    int ql,
    int qr
){

    // no overlap
    if(right < ql || left > qr){
        return 0;
    }

    // complete overlap
    if(ql <= left && right <= qr){
        return tree[node];
    }

    // partial overlap
    int mid = (left + right) / 2;

    long long leftSum =
        query(
            node * 2,
            left,
            mid,
            ql,
            qr
        );

    long long rightSum =
        query(
            node * 2 + 1,
            mid + 1,
            right,
            ql,
            qr
        );

    return leftSum + rightSum;
}


void update(
    int node,
    int left,
    int right,
    int index,
    long long value
){

    if(left == right){

        tree[node] = value;

        return;
    }

    int mid = (left + right) / 2;

    if(index <= mid){

        update(
            node * 2,
            left,
            mid,
            index,
            value
        );
    }

    else{

        update(
            node * 2 + 1,
            mid + 1,
            right,
            index,
            value
        );
    }

    tree[node] =
        tree[node * 2]
        +
        tree[node * 2 + 1];
}


int main(){

    cin >> N;

    a.resize(N + 1);

    tree.resize(4 * N);

    for(int i = 1; i <= N; i++){
        cin >> a[i];
    }

build(1, 1, N);


    // 查询 [2,5]
    cout << query(1,1,N,2,5) << endl;

    // a[3] = 10
    update(
        1,
        1,
        N,
        3,
        10
    );


    // 再查询 [2,5]
    cout << query(
        1,
        1,
        N,
        2,
        5
    ) << endl;

    return 0;
}