#include <stdio.h>
#include <stdlib.h>

#define N 1100010

int parent[N], index[N], flag[N];
int n, m, cnt = 0;

int root(int x)
{
  int rt = x, tmp;
  while(rt != parent[rt] ) rt = parent[rt];
  while(x != rt)
  {
    tmp = x;
    x = parent[x];
    parent[tmp] = rt;
  }
  return rt;
}

int main()
{
  int test = 1;
  while(scanf("%d%d", &n, &m) != EOF)
  {
    if(n == 0 && m == 0) break;
    cnt = n;
    for(int i = 0; i < N; ++i)
    {
      parent[i] = index[i] = i;
      flag[i] = 0;
    }
    for(int i = 0; i < m; ++i)
    {
      char command[5];
      int x, y;
      scanf("%s", command);
      if(command[0] == 'M')
      {
        scanf("%d%d", &x, &y);
        int rx = root(index[x]), ry = root(index[y]);
        if(rx != ry)
        {
          parent[rx] = ry;
        }
      }
      else if(command[0] == 'S')
      {
        scanf("%d", &x);
        index[x] = ++cnt;
      }
    }
    int result = 0;
    for(int i = 0; i < n; ++i)
    {
      int rt = root(index[i]);
      if(!flag[rt])
      {
        result++;
        flag[rt] = 1;
      }
    }
    printf("Case #%d: %d\n", test++, result);
  }
  return 0;
}
