#include <stdio.h>
#include <stdlib.h>

#define N 50010

int n, query;
int rel[N], parent[N];

int root(int x)
{
  int rt = x;
  if(x != parent[x])
  {
    rt = root(parent[x]); 
    // 修改与根节点的关系
    rel[x] = (rel[x] + rel[parent[x]]) % 3;
    // 路径压缩
    parent[x] = rt;
  }
  return rt;
}

int link(int x, int y, int dist)
{
  int rx = root(x), ry = root(y), ret = 0;
  if(rx == ry)
  {
    if((rel[x] - rel[y] + 3) % 3 != dist)
    {
      ret = 1;
    }
  }
  else
  {
    parent[rx] = ry;
    rel[rx] = (rel[y] - rel[x] + dist + 3) % 3;
    ret = 0;
  }
  return ret;
}

int main()
{
  scanf("%d%d", &n, &query);
  for(int i = 0; i <= n; ++i)
  {
    rel[i] = 0; 
    parent[i] = i;
  }
  int result = 0;
  for(int i = 0; i < query; ++i)
  {
    int d, x, y;
    scanf("%d%d%d", &d, &x, &y);
    if(x > n || y > n || x < 1 || y < 1)
    {
      result++;
      continue;
    }
    result += link(x, y, d - 1);
  }
  printf("%d\n", result);

  return 0;
}
