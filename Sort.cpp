// Heap Sort
#include <iostream>
#include <vector>

using namespace std;

void makeUp(vector<int> &A, int index)  //index是理论下标，1为开始
{
    int value = 0, ind = 0, len = A.size();  
    if (2 * index + 1 <= len && value < A[2 * index])  //处理右儿子
    {
        ind = 2 * index;
        value = A[ind];
    }
    if (2 * index <= len && value < A[2 * index - 1])  //处理左儿子
    {
        ind = 2 * index - 1;
        value = A[ind];
    }
    if (value > A[index - 1])  //将最大值往上顶
    {
        A[ind] = A[index - 1];
        A[index - 1] = value;
        makeUp(A, ind + 1);  //若进行了替换，递归使的堆始终成立
    }
}

void initial(vector<int> &A)  //初始化函数
{
    int len = A.size() / 2;  //对前一半的元素进行上述判断与替换
    for (int i = len; i > 0; i--)
    {
        makeUp(A, i);
    }
}

int updateHeap(vector<int> &A)   //优先队列里弹出最大值函数的实现，删去并返回值。
{
    int i = A.size() - 1;
    int a = A[0];
    A[0] = A[i];
    A[i] = a;
    A.erase(A.begin() + i);
    makeUp(A, 1);
    return a;
}

// 以下是测试代码：

int main(int argc, char const *argv[])
{
    vector<int> A = {11, 12, 1, 5, 15, 3, 4, 10, 7, 2, 16, 9, 8, 14, 13, 6};
    initial(A);
    while(!A.empty())
    {
        cout << updateHeap(A) << endl;
    }
    system("pause");
    return 0;
}

//为了处理方便，我直接使用了c++里的vector.


// Fast Sort
// 快速排序的算法很好理解。但实现上还是有点小麻烦，有待改进。
#include <iostream>
#include <vector>

using namespace std;

void FastSort(int start, int end, vector<int> &A)
{
    if (end <= start + 1) //递归结束条件
    {
        return;
    }
    int low = start, high = end, counts = 1, target = A[start];
    A[start] = -1;
    while (low != high)
    {
        if (counts % 2 == 1)
        {
            while (A[high] > target)
            {
                high--;
            }
            if (A[high] != -1)
            {
                A[low] = A[high];
                A[high] = -1;
                low++;
            }
        }
        else 
        {
            while (A[low] != -1 && A[low] < target)
            {
                low++;
            }
            if (A[low] != -1){
                A[high] = A[low];
                A[low] = -1;
                high--;
            }
        }
        counts++;
    }
    A[low] = target;
    //开始递归
    FastSort(start, low - 1, A);
    FastSort(high + 1, end, A);
}

int main(int argc, char const *argv[])
{
    vector<int> A = {11, 12, 1, 5, 15, 3, 4, 10, 7, 2, 16, 9, 8, 14, 13, 6};
    FastSort(0, 15, A);
    for (int i = 0; i < A.size(); i++){
        cout << A[i] << endl;
    }
    system("pause");
    return 0;
}
