#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define lowbit(x) -(x)&(x)
#define N 500002

typedef long long LL;

int S[N] = {0};
int A[N], B[N], idx[N];
int n, cnt = 0;

void add(int x, int v)
{
  for(; x <= n; x += lowbit(x))
  {
    S[x]+= v;
  }
}

LL sum(int x)
{
  LL _s = 0;
  for(; x; x-= lowbit(x))
  {
    _s += S[x];
  }
  return _s;
}

int main()
{
  while(scanf("%d",&n),n)
  {
    for(int i = 0; i <= n; ++i)
    {
      S[i] = 0;
    }
    for(int i = 1; i <= n; ++i)
    {
      int v;
      scanf("%d", A + i);
      B[i] = A[i];
    }
    // 离散化
    cnt = 0;
    sort(A + 1, A + n + 1);
    idx[1] = ++cnt;
    for(int i = 2; i <= n; ++i)
    {
      if(A[i] != A[i-1])
      {
        idx[i] = ++cnt;
      }
      else
      {
        idx[i] = idx[i-1];
      }
    }
    // 计算逆序
    LL result = 0;
    for(int i = 1; i <= n; ++i)
    {
      int pos = lower_bound(A + 1, A + 1 + n, B[i]) - A;
      int data_map = idx[pos];
      //printf("xxxx %d %d %lld\n",  B[i], pos, sum(data_map));
      result += (i - 1 - sum(data_map));
      add(data_map, 1);
    }
    printf("%lld\n", result);
  }
}

