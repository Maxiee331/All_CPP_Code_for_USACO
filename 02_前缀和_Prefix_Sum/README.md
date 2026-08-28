# 02 前缀和 / 差分 Prefix Sum & Difference Array

## USACO 真题

### Breed Counting.cpp
- **比赛**：USACO **2015 年 12 月**
- **组别**：**Silver 银组**（Problem 3）
- **官方链接**：https://usaco.org/index.php?page=viewproblem2&cpid=572
- **算法**：**前缀和（三个品种各开一个数组）**

**思路**：对品种 1/2/3 各建一个前缀和数组 `br1/br2/br3`，
`br1[i]` = 前 `i` 头牛里品种 1 的数量。查询 `[a,b]` 就是 `br1[b]-br1[a-1]`。
下标从 1 开始、`br[0]=0`，这样 `a=1` 时不会越界 —— 你处理对了。

**复杂度**：`O(N + Q)`。如果每次查询都重新数一遍就是 `O(NQ)`，会超时。

---

### Haybale Stacking.cpp
- **比赛**：USACO **2012 年 1 月**
- **组别**：**Bronze 铜组**（Problem 2）
- **官方链接**：https://usaco.org/index.php?page=viewproblem2&cpid=104
- **算法**：**差分数组（Difference Array）** + 排序取中位数

**思路**：`K` 次区间 `+1`，最后问排序后的中位数。

> ⚠️ **你现在的写法是"暴力逐格加一"**，是 `O(N·K)`。
> 题目 `N ≤ 1,000,000`、`K ≤ 25,000`，最坏 `2.5 × 10^10` 次操作 → **一定超时**。
>
> **正解是差分**：区间 `[A,B]` 加 1 只需要
> `diff[A] += 1; diff[B+1] -= 1;`（`O(1)`），
> 全部读完后求一遍前缀和还原每个位置的高度（`O(N)`）。
> 总复杂度 `O(N + K + N log N)`。

差分模板：
```cpp
vector<int> diff(N + 2, 0);
for (每个区间 [A,B])  { diff[A]++; diff[B+1]--; }
vector<int> h(N + 1);
for (int i = 1; i <= N; i++) h[i] = h[i-1] + diff[i];
```

---

### broken gate.cpp
- **来源**：❓ **不确定 —— 很可能是自出/改编练习题，不是 USACO 真题**
- **算法**：区间 0/1 翻转（当前是暴力 `O(N·K)`）

**为什么不是 USACO 真题**：名字最接近的是
**USACO 2016 年 1 月 Silver 银组 Problem 3「Build Gates」**
（https://usaco.org/index.php?page=viewproblem2&cpid=596），
但那题是"从 (0,0) 出发按 N 步指令建栅栏，栅栏把农场分成若干区域，
问最少要开几道门才能让所有区域连通" —— **需要 Floodfill 数连通区域**，
和你这份"区间内 0/1 翻转，最后数 1 的个数"**完全是两回事**。

所以这份代码按**算法（区间修改 → 差分）** 归到这个文件夹。

**如果就按你的题意**：区间翻转同样可以用差分优化 ——
`diff[A]++; diff[B+1]--;`，最后看每个位置被翻转的**次数是奇数还是偶数**。

---

## 练习题

### range sum.cpp
朴素区间求和，每次查询都重新循环 → `O(NQ)`。
**这正是前缀和要解决的问题**，建议改写成前缀和版本对比一下：
```cpp
vector<int> pre(N+1, 0);
for (int i = 1; i <= N; i++) pre[i] = pre[i-1] + a[i-1];
// 查询 [l, r]（1-indexed）：pre[r] - pre[l-1]
```
另外变量名叫 `queue` 会和 `std::queue` 撞名，换个名字更安全。

---

## 核心模板

**一维前缀和**（静态数组，多次区间求和）：
```cpp
pre[0] = 0;
for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + a[i];
// 区间 [l, r] 的和 = pre[r] - pre[l-1]
```

**一维差分**（多次区间修改，最后统一查询）：
```cpp
for (每次修改 [l, r] 加 v) { d[l] += v; d[r+1] -= v; }
for (int i = 1; i <= n; i++) a[i] = a[i-1] + d[i];
```

记忆口诀：**"多次查询用前缀和，多次修改用差分。"**

## 建议补充的题
- **2019 Feb Silver** — Painting the Barn（**二维**前缀和，银组必考）
- **2016 Jan Silver** — Subsequences Summing to Sevens（前缀和 + 取模）
