## 思想
```
　　分治法的本质还是递归思想，但与归纳法还是有一定区别。分治，利用递归的思想，将问题简而化之，分成多个问题求解，并且总问题的
解会由子问题的解构成，但每次分解问题都没有改变问题的本质，只是简化规模，直到能够轻易求解。这也就是“分而治之”的思想。
```
## 学习要点
在尝试理解经典算法的同时，要注意分治法计算复杂度的技巧，以及分治法算法优化的角度。
## MINMAX
输入：n个整数元素的数组A[1...n]。  
输出：(x,y)，A中的最大元素和最小元素。
```cpp
vector<int> minmax(int low, int high, vector<int> a)
{
    vector<int> out;
    if (high == low || high - low == 1)
    {
        out.push_back(max(a[low], a[high]));
        out.push_back(min(a[low], a[high]));
    }
    else
    {
        int mid = (low + high) / 2;
        vector<int> v1 = minmax(low, mid, a);
        vector<int> v2 = minmax(mid + 1, high, a);

        out.push_back(max(v1[0], v2[0]));
        out.push_back(min(v1[1], v2[1]));
    }
    return out;
}
```
## BINARYSEARCHREC
输入：按非降序排列的n个元素的数组A[1...n]和元素x。  
输出：如果 x = A[j]，则输出j；否则输出0。
```cpp
int binarysearch(int low, int high, vector<int> a, int target)
{
    if (low > high)
    {
        return -1;
    }
    else
    {
        int mid = (low + high) / 2;
        if (a[mid] == target)
        {
            return mid;
        }
        else if (a[mid] < target)
        {
            return binarysearch(mid + 1, high, a, target);
        }
        else
        {
            return binarysearch(low, mid - 1, a, target);
        }
    }
}
```
## MERGESORT
输入：n个元素的数组A[1...n]。  
输出：按非降序排列的数组A[1...n]。
```cpp
void mergesort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        a = merge(a, low, mid, high);
    }
}
```
## SELECT
用于寻找中项和第k小元素  
输入：n个元素的数组A[1...n]和整数k，1<=k<=n。  
输出：A中的第k小元素（找大的规则一样）。
过程：
```
思路：以5个元素为单位，将所有元素分为q=p/5组，多的但不足5个的不作考虑；
　　　求出每组的中位数，将所有中项形成集合，并找出中项的中项mm；
    　以mm为基准，将A按（<,=,>）分为三组;
     根据k判断需要保留的那组，如果相等则返回，不相等则在小分组中继续递归寻找；
```
## SPLIT
## 
