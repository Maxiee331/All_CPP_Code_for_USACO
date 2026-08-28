# 01 二分法 Binary Search

## 题目

### Convention.cpp
- **比赛**：USACO **2018 年 12 月** 比赛
- **组别**：**Silver 银组**（Problem 1）
- **官方链接**：https://usaco.org/index.php?page=viewproblem2&cpid=858
- **算法**：**二分答案（Binary Search on the Answer）** + 贪心检验

**思路**：答案（最长等待时间）具有单调性 —— 如果等待 `mid` 分钟够用 `M` 辆车，
那等待更久也一定够。所以在 `[0, cow[N-1]-cow[0]]` 上二分，
每次用**贪心**从左往右塞车（塞满 `C` 头或超时就开新车），
数出来的车数 `<= M` 就说明 `mid` 可行，往左收缩。

```
low=0, high=最大时间差
while (low <= high):
    mid = 中点
    buses = 贪心模拟(mid)
    if buses <= M:  ans = mid; high = mid-1   # 可行，试更小
    else:           low  = mid+1              # 不可行，必须放宽
```

**复杂度**：`O(N log N + N log(maxT))`

**代码点评**：写得很标准，`mid = low + (high-low)/2` 防溢出的写法也对。
这是二分答案的模板题，值得反复看。

---

## 这个类别的模板

```cpp
sort(a.begin(), a.end());
int low = 下界, high = 上界, ans = high;
while (low <= high) {
    int mid = low + (high - low) / 2;
    if (check(mid)) {        // check 通常是 O(N) 贪心
        ans = mid;
        high = mid - 1;      // 求最小可行值
    } else {
        low = mid + 1;
    }
}
```

**判断能不能用二分答案的信号**：题目问"最小化最大值"或"最大化最小值"，
并且给定一个答案后，能在 `O(N)` 或 `O(N log N)` 内验证它是否可行。

## 建议补充的题

银组二分答案高频题：
- **2019 Feb Silver** — Painting the Barn
- **2015 Dec Gold** — Fruit Feast
- 另外 **在有序数组里二分查值**（`lower_bound` / `upper_bound`）
  这个基础用法你还没有单独练过，建议补一下。
