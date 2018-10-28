## 算法说明

一般匹配字符串时，我们从目标字符串str（假设长度为n）的第一个下标选取和ptr长度（长度为m）一样的子字符串进行比较，如果一样，就返回开始处的下标值，不一样，选取str下一个下标，同样选取长度为n的字符串进行比较，直到str的末尾（实际比较时，下标移动到n-m）。这样的时间复杂度是O(n*m)。

KMP算法：可以实现复杂度为O(m+n)

为何简化了时间复杂度：
充分利用了目标字符串ptr的性质（比如里面部分字符串的重复性，即使不存在重复字段，在比较时，实现最大的移动量）。
上面理不理解无所谓，我说的其实也没有深刻剖析里面的内部原因。

考察目标字符串ptr：
ababaca
这里我们要计算一个长度为m的转移函数next。

next数组的含义就是一个固定字符串的最长前缀和最长后缀相同的长度。

比如：abcjkdabc，那么这个数组的最长前缀和最长后缀相同必然是abc。
cbcbc，最长前缀和最长后缀相同是cbc。
abcbc，最长前缀和最长后缀相同是不存在的。

注意最长前缀：是说以第一个字符开始，但是不包含最后一个字符。
比如aaaa相同的最长前缀和最长后缀是aaa。
对于目标字符串ptr，ababaca，长度是7，所以next[0]，next[1]，next[2]，next[3]，next[4]，next[5]，next[6]分别计算的是
a，ab，aba，abab，ababa，ababac，ababaca的相同的最长前缀和最长后缀的长度。由于a，ab，aba，abab，ababa，ababac，ababaca的相同的最长前缀和最长后缀是“”，“”，“a”，“ab”，“aba”，“”，“a”,所以next数组的值是[-1,-1,0,1,2,-1,0]，这里-1表示不存在，0表示存在长度为1，2表示存在长度为3。这是为了和代码相对应。

## 算法实现
```c
void cal_next(char *str, int *next, int len) { 
    next[0] = -1;//next[0]初始化为-1，-1表示不存在相同的最大前缀和最大后缀 
    int k = -1;//k初始化为-1 
    for (int q = 1; q <= len-1; q++) { 
        while (k > -1 && str[k + 1] != str[q])//如果下一个不同，那么k就变成next[k]，注意next[k]是小于k的，无论k取任何值。 
        {
            k = next[k];//往前回溯 
        } 
        if (str[k + 1] == str[q])//如果相同，k++ 
        { 
            k = k + 1; 
        } 
        next[q] = k;//这个是把算的k的值（就是相同的最大前缀和最大后缀长）赋给next[q] 
    } 
}
```
KMP
```
int KMP(char *str, int slen, char *ptr, int plen) { 
    int *next = new int[plen]; 
    cal_next(ptr, next, plen);//计算next数组 
    int k = -1; 
    for (int i = 0; i < slen; i++) { 
        while (k >-1&& ptr[k + 1] != str[i])//ptr和str不匹配，且k>-1（表示ptr和str有部分匹配） 
        {
            k = next[k];//往前回溯
        } 
        if (ptr[k + 1] == str[i]){
            k = k + 1; 
        }
        if (k == plen-1)//说明k移动到ptr的最末端 
        { 
            //cout << "在位置" << i-plen+1<< endl; 
            //k = -1;//重新初始化，寻找下一个 
            //i = i - plen + 1;//i定位到该位置，外层for循环i++可以继续找下一个（这里默认存在两个匹配字符串可以部分重叠）
            return i-plen+1;//返回相应的位置 
        } 
    } 
    return -1; 
}
```
[参考文献](https://blog.csdn.net/starstar1992/article/details/54913261/)
