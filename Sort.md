# 关于排序的一点记录
## Heap Sort
话不多说，直接上代码

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

以下是测试代码：

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

为了处理方便，我直接使用了c++里的vector.
