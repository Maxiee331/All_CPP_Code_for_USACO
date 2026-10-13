#include<bits/stdc++.h>
using namespace std;

int main() {

    freopen("248.in", "r", stdin);
    freopen("248.out", "w", stdout);

    int N;
    cin >> N;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    // dp[l][r]
    // 如果区间 l~r 可以完全合并成一个数字，
    // dp[l][r] = 最终数字
    // 否则 = -1
    vector<vector<int>> dp(
        N,
        vector<int>(N, -1)
    );

    int ans = 0;

    // Base case
    for (int i = 0; i < N; i++) {
        dp[i][i] = a[i];
        ans = max(ans, a[i]);
    }

    // 枚举区间长度
    for (int len = 2; len <= N; len++) {

        // 左端点
        for (int l = 0; l + len <= N; l++) {

            int r = l + len - 1;

            // 枚举最后一次合并的分割位置
            for (int k = l; k < r; k++) {

                // 左右两边都必须能合并
                // 并且最终数字必须相同
                if (dp[l][k] != -1 &&
                    dp[l][k] == dp[k + 1][r]) {

                    dp[l][r] = max(
                        dp[l][r],
                        dp[l][k] + 1
                    );
                }
            }

            // 更新全局最大值
            ans = max(ans, dp[l][r]);
        }
    }

    cout << ans << endl;

    return 0;
}


/*
interval DP template:

for (int len = 2; len <= N; len++) {

    for (int l = 0; l + len <= N; l++) {

        int r = l + len - 1;

        for (int k = l; k < r; k++) {

            // 用两个小区间
            // 更新一个大区间
        }
    }
}
*/