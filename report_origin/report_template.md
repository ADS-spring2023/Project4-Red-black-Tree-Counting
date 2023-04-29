<div style="margin-top:30vh">
  <center><font face="黑体" size = 100>
    Project 4 
  </font></center>
  <center><font face="黑体" size = 4>
    Yue Hu, JieFu Zhang, YuYang Wu
  </font></center>
  <center><font face="黑体" size = 5>
    2023.3.14
  </font></center>
</div> 


<div STYLE="page-break-after: always;"></div>

## Introduction

## Algorithm Specification

### Algorithm 1

算法描述：

1. 初始化，令B[0] = 1, R[0] = 1。
2. 从i = 1到n，对于每个i，计算B[i]和R[i]的值：
   - B[i]的计算公式为：B[i] = ∑[B[j] * B[i-j-1]]，其中0 ≤ j ≤ i-1。
   - R[i]的计算公式为：R[i] = ∑[B[j-1] * R[i-j] + R[j-1] * B[i-j]]，其中1 ≤ j ≤ i。
3. 返回B[n] + R[n]，即含有n个节点的红黑树的数量。

```C++
int redBlackCount(int n) {
    int B[n+1]; // 包含n个节点的以黑色节点为根节点的红黑树的种数
    int R[n+1]; // 包含n个节点的以红色节点为根节点的红黑树的种数
    // 初始化
    B[0] = 1;
    R[0] = 1;
    // 从小到大计算每个节点的红黑树种数
    for (int i = 1; i <= n; i++) {
        B[i] = 0;
        R[i] = 0;
        // 根据公式计算B(i)
        for (int j = 0; j < i; j++) {
            B[i] += B[j] * B[i-j-1];
        // 根据公式计算R(i)
        for (int j = 1; j <= i; j++) {
            R[i] += B[j-1] * R[i-j] + R[j-1] * B[i-j];
        }
    }
    // 返回结果
    return B[n] + R[n];
}
```



## Test Results

## Analysis

### Algorithm 1

复杂度分析：

1. 时间复杂度：计算B[i]和R[i]的过程中，分别需要进行两个循环，所以时间复杂度为O(n^2)。
2. 空间复杂度：需要使用两个数组B和R，所以空间复杂度为O(n)。

## Declaration

I hereby declare that all the work done in this project titled ”Maximum
Submatrix Sum” is of my independent effort.