# 03 排序 Sorting

## USACO 真题

### Field Reduction.cpp
- **比赛**：USACO **2016 年 US Open**
- **组别**：**Bronze 铜组**（Problem 3）
- **官方链接**：https://usaco.org/index.php?page=viewproblem2&cpid=641
- **算法**：排序 + 枚举去掉哪头牛

**注意区分两个版本**：
| 组别 | cpid | 允许去掉几头牛 |
|---|---|---|
| **Bronze 铜组** | 641 | **恰好 1 头** |
| Silver 银组 | 642 | 最多 **3** 头 |

你的代码是**去掉 1 头**的逻辑 → 对应 **Bronze 铜组**那版。

**思路**：把 `x` 和 `y` 分别排序，去掉一头牛只可能影响到
最小/最大的边界，所以只需比较"去掉最左"和"去掉最右"两种情况。

> ⚠️ **这里有个正确性陷阱**：你把 `x` 和 `y` **各自独立**排序后独立决策，
> 但"去掉哪头牛"对 x 和 y 必须是**同一头牛**。
> 分开选可能选出两头不同的牛，算出比真实答案更小的面积。
> **正解**：只有 4 个候选（x 最小、x 最大、y 最小、y 最大的牛），
> 枚举去掉这 4 头中的每一头，对剩下的牛算包围盒面积取最小值。

---

### Cow ID Cards.cpp
- **来源**：官网上没有找到叫这个名字的 USACO 真题，判断为**自出/改编练习题**
- **算法**：`multiset` 计数 + `set` 去重

**思路**：`multiset` 存全部 ID，再用 `count(x)==1` 挑出只出现一次的。
写法没问题，但 `multiset::count` 是 `O(log n + 出现次数)`，
对每个元素都调一次总共 `O(n log n)`。
更轻量的做法是用 `map<int,int>` 直接统计频次。

---

## 三大基础排序（手写练习）

| 文件 | 算法 | 复杂度 | 状态 |
|---|---|---|---|
| `bubble sort.cpp` | 冒泡排序 | `O(n²)` | ⚠️ **有越界 bug** |
| `insertion sort.cpp` | 插入排序 | `O(n²)` | ⚠️ **有越界 bug** |
| `selection sort.cpp` | 选择排序 | `O(n²)` | ⚠️ **逻辑错误** |

### 三个 bug 的具体位置

**`bubble sort.cpp`**：
- `asize = 7` 但数组实际有 **8** 个元素 → 最后一个没参与排序
- 内层 `arr[j+1]` 当 `j = asize-1` 时**读到数组外面**
- 输出循环 `i < asize+1` 又多读一个
- 正确写法：内层应该是 `for (int j = 0; j < asize-1-i; j++)`

**`insertion sort.cpp`**：
- `while(temp >= 0)` 里访问了 `arr[temp-1]`，`temp==0` 时 → **`arr[-1]` 越界**
- 条件应该是 `while (temp > 0 && arr[temp] < arr[temp-1])`

**`selection sort.cpp`**：
- `temp` 每轮都在循环体内被重置成 `0`，`temp++` 写在了外层循环末尾但下一轮又归零
  → 结果永远只往 `newarr[0]` 里写
- 而且内层没有"排除已选过的元素"，`currentmin` 每轮都会找到全局最小值
  → 输出会是同一个数重复

这三个建议**重写一遍**，手写排序是理解 `O(n²)` vs `O(n log n)` 的基础。

---

## 竞赛里实际怎么排

```cpp
// 1. 基础排序
sort(v.begin(), v.end());

// 2. 从大到小
sort(v.begin(), v.end(), greater<int>());

// 3. 结构体 / 自定义规则
struct Cow { int h, w; };
bool cmp(const Cow& a, const Cow& b) { return a.h < b.h; }
sort(v.begin(), v.end(), cmp);

// 4. pair 默认先比 first 再比 second —— 很好用
vector<pair<int,int>> v;
sort(v.begin(), v.end());
```

`std::sort` 是 `O(n log n)`，USACO 里**永远用它**，不要手写 `O(n²)`。
