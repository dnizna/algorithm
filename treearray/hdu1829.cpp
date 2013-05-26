// http://acm.hdu.edu.cn/showproblem.php?pid=1892
#include <stdio.h>
#include <stdlib.h>

#define lowbit(x) -(x)&(x)
#define N 1005

int A[N][N] = {0}, S[N][N] = {0}, S_init[N][N] = {0} , n;

void add(int S[N][N], int x, int y, int delta)
{
  for(int i = x; i < N; i += lowbit(i))
  {
    for(int j = y; j < N; j += lowbit(j))
    {
      S[i][j] += delta;
    }
  }
}

int sum(int S[N][N], int x, int y)
{
  int s_ = 0;
  for(int i = x; i; i-= lowbit(i))
  {
    for(int j = y; j; j -= lowbit(j))
    {
      s_ += S[i][j];
    }
  }
  return s_;
}

void init()
{
  for(int i = 1; i < N; ++i)
  {
    for(int j = 1; j < N; ++j)
    {
      add(S_init, i, j, 1);
    }
  }
}
int main()
{
  int tests;
  init();
  scanf("%d", &tests);
  for(int test = 1; test <= tests; ++test)
  {
    scanf("%d", &n);
    for(int i = 1; i < N; ++i)
    {
      for(int j = 1; j < N; ++j)
      {
        A[i][j] = 1;
        S[i][j] = S_init[i][j];
      }
    }
    printf("Case %d:\n", test);
    for(int i = 0; i < n; ++i)
    {
      char command[5];
      int x, y, delta, x1, y1, x2, y2;
      scanf("%s", command);
      if(command[0] == 'S')
      {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1++, y1++, x2++, y2++;
        if(x1 > x2 ) x1 ^= x2 ^= x1 ^= x2;
        if(y1 > y2 ) y1 ^= y2 ^= y1 ^= y2;
        //printf("%d %d %d %d\n", sum(S, x2, y2), sum(S, x1 -1, y2), sum(S, x2, y1 -1), sum(S, x1 - 1, y1 - 1));
        printf("%d\n", sum(S, x2, y2) - sum(S, x1 - 1, y2) - sum(S, x2, y1 - 1) + sum(S, x1 - 1, y1 - 1));
      }
      else if(command[0] == 'A')
      {
        scanf("%d%d%d", &x, &y, &delta);
        x++, y++;
        A[x][y] += delta;
        add(S, x, y, delta);
      }
      else if(command[0] == 'D')
      {
        scanf("%d%d%d", &x, &y, &delta);
        x++, y++;
        if(A[x][y] < delta)
        {
          delta = A[x][y];
        }
        A[x][y] -= delta;
        add(S, x, y, -delta); 
      }
      else if(command[0] == 'M')
      {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &delta);
        x1++, y1++, x2++, y2++;
        if(A[x1][y1] < delta)
        {
          delta = A[x1][y1];
        }
        A[x1][y1] -= delta, A[x2][y2] += delta;
        add(S, x1, y1, -delta);
        add(S, x2, y2, delta);
      }
    }      
  }
  return 0;
}

