## Fibonacci
非动态规划实现：
```c++
int fibonacci(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
```
动态规划实现：
```c++
void f(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i < 2)
        {
            a.push_back(1);
        }
        else
        {
            a.push_back(a[i - 1] + a[i - 2]);
        }
    }
}
```
事实证明效率差距不是一般的大。
## 
