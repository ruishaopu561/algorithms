# 并查集的简单实现
```c++
#include <iostream>

using namespace std;

struct node
{
  int value;
  int rank;
  node *parent;

  node(int v) : value(v), rank(0), parent(NULL){};
};

node *Find(node *x) //return root
{
  while (x->parent != NULL)
  {
    x = x->parent;
  }
  return x;
};

void Union(node *x, node *y) //union two sets into one set
{
  node *xr = Find(x);
  node *yr = Find(y);
  if (xr->rank > yr->rank)
  {
    yr->parent = xr;
  }
  else
  {
    xr->parent = yr;
    if (yr->rank == xr->rank)
    {
      yr->rank++;
    }
  }
};
```
