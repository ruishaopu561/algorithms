## EXPREC
```cpp
int power(int x, int n)
{
    int y = 1;
    if (n == 0)
    {
        return y;
    }
    else
    {
        y = power(x, n / 2);
        y = y * y;
        if (n & 1)
        {
            y = x * y;
        }
        return y;
    }
}
```
## EXP
```cpp
void toBinary(vector<int> &d, int n)
{
    while (n != 0)
    {
        d.push_back(n % 2);
        n /= 2;
    }
    d.push_back(n);
}

int power(int x, int n)
{
    int y = 1;
    vector<int> d;
    toBinary(d, n);

    for (int i = d.size() - 1; i >= 0; i--)
    {
        y = y * y;
        if (d[i] == 1)
        {
            y = x * y;
        }
    }
    return y;
}
```
## HORNER
即秦九韶算法，不再赘述。
## PERMUTATIONS1
print函数，无关紧要
```cpp
void print(vector<int> vec)
{
    int len = vec.size();
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
```
最常见的打印全排列的方式
```cpp
void perm(int m, int n, vector<int> vec)
{
    if (m == n)
    {
        print(vec);
        //count++;
    }
    else
    {
        for (int j = m - 1; j < n; j++)
        {
            int tem = vec[j];
            vec[j] = vec[m - 1];
            vec[m - 1] = tem;

            perm(m + 1, n, vec);

            tem = vec[j];
            vec[j] = vec[m - 1];
            vec[m - 1] = tem;
        }
    }
}

int main()
{
    int n = 3;
    vector<int> vec;
    for (int i = 1; i < n + 1; i++)
    {
        vec.push_back(i);
    }
    perm(1, n, vec);
    //cout << count << endl;
}
```
## PERMUTATIONS2
```cpp
void print(vector<int> vec)
{
    int len = vec.size();
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void perm(int m, vector<int> vec)
{
    int n = vec.size();
    if (m == 0)
    {
        print(vec);
        count++;
    }
    else
    {
        for (int j = 0; j < n; j++)
        {
            if (vec[j] == 0)
            {
                vec[j] = m;
                perm(m - 1, vec);
                vec[j] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        vec.push_back(0);
    }
    perm(n, vec);
    cout << count << endl;
}
```
## MAJORITY
```cpp
#include <iostream>
#include <vector>

using namespace std;

int majority(int n, vector<int> a)
{
    int c = candidate(1, a);
    int count = 0;
    for (int j = 0; j < n; j++)
    {
        if (a[j] == c)
        {
            count++;
        }
    }
    if (count > a.size() / 2)
    {
        return c;
    }
    else
    {
        return -1;
    }
}

int candidate(int m, vector<int> a)
{
    int j = m, c = a[m], count = 1, n = a.size();
    while (j < n && count > 0)
    {
        j++;
        if (a[j] == c)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    if (j == n)
    {
        return c;
    }
    return candidate(j + 1, a);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a = {1, 2, 1, 3, 3, 2, 1, 2, 3, 2, 2, 2, 1, 1, 2, 2, 2, 1, 1, 2};
    int out = majority(n, a);
    if (out > 0)
    {
        cout << out << endl;
    }
    else
    {
        cout << "none" << endl;
    }
}
```
