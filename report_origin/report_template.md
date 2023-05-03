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

```C++
#include <iostream>
using namespace std;
int redBlackCount(int n){
    int B[n+1][n+1];//根节点为黑色
    int R[n+1][n+1];//根节点为红色
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            R[i][j]=0;
            B[i][j]=0;
        }
    }
    B[1][2]=1;B[2][2]=2;B[3][3]=1;B[3][2]=1;R[3][2]=1;//初始化一些数据便于计算
    for(int k=4;k<=n;k++){//总个数，最多n-1个
        for(int i=1;i<k-1;i++){//左子树个数，最多k-1个
            for(int j=0;j<=k;j++){//左右子树黑节点层数，最多i个
                R[k][j]+=B[i][j]*B[k-i-1][j];
                B[k][j+1]+=R[i][j]*B[k-i-1][j]+B[i][j]*R[k-i-1][j]+B[i][j]*B[k-i-1][j];
            }
        }
    }
    int num=0;
    for(int i=0;i<=n;i++){
        num+=B[n][i];
    }
    return num;
}
int main(){
    cout<<redBlackCount(6);
}
```

The algorithm works by using dynamic programming to build up the count of red-black trees for each number of nodes. It initializes two matrices, B and R, to keep track of the counts of black-rooted and red-rooted trees, respectively. It then iterates through each possible number of nodes, k, and for each k, iterates through each possible number of nodes in the left subtree, i. For each combination of k and i, it calculates the count of red-rooted trees with k nodes and j black nodes in the left subtree, as well as the count of black-rooted trees with k nodes and j+1 black nodes in the left subtree. It does this by using the counts of red- and black-rooted trees for the left and right subtrees of size i and k-i-1, respectively.

### Algorithm 2

Replace this sentence by zjf's work.

#### tips

NTT requires the module to have primary root. So we solve the problem with module 998244353, whose primary root is 3. For the same problem with module 1e9+7, we can use 3-module-NTT. But it's too complex for us, so we haven't tried that.

## Test Results

### Algorithm 1

![img](file:///D:\qq文件\766748001\Image\C2C\E57177E22CAAF5653A25BA35DEFE94C3.png)

### Algorithm 2

![](2023-05-03-12-16-25.png)

## Analysis

### Algorithm 1

The time complexity of this algorithm is O(n^3), since it involves three nested loops, each of which iterates up to n times. The space complexity is also O(n^2), since it uses two matrices of size n+1 by n+1.

### Algotithm 2

The optimal time complexity of this algorithm is O(n(logn)^2). The number of polynomial multiplication is O(logn), while using NTT method, we can make the time complexity of each multiplication as O(nlogn). The product of these 2 factors is O(n(logn)^2).

## Declaration

I hereby declare that all the work done in this project titled ”Maximum
Submatrix Sum” is of my independent effort.
