#include <stdio.h>
#include <stdlib.h>

#define N 110
#define inf 0x7fffffff
int n, m, mat[N][N], dist[N][N];

int main()
{
  while(scanf("%d%d",&n,&m)!=EOF)
  {
    for(int i = 0; i <= n; ++i)
    {
      for(int j = 0; j <= n; ++j)
        mat[i][j] = dist[i][j] = mat[j][i] = dist[j][i] = inf;
    }
    for(int i = 0; i < m; ++i)
    {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      if(c > mat[a][b]) c = mat[a][b];
      mat[a][b] = mat[b][a] = dist[a][b] = dist[b][a] = c;
    }
    int ans = inf; 
    for(int k = 1; k <= n; ++k)
    {
      for(int i = 1; i <= n; ++i)
        for(int j = i + 1 ; j <= n; ++j)
        {
          if(dist[i][j] != inf  && mat[i][k] != inf && mat[k][j] != inf &&
              dist[i][j] + mat[i][k] + mat[k][j] < ans)
          {
            ans = dist[i][j] + mat[i][k] + mat[k][j];
          }
        }
      for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
        {
          if(dist[i][k] != inf && dist[k][j] != inf && 
              dist[i][k] + dist[k][j] < dist[i][j])
          {
            dist[i][j] = dist[i][k] + dist[k][j];
          }
        }
    }
    if(ans == inf) puts("It's impossible.");
    else printf("%d\n", ans);
  }
  return 0;
}
