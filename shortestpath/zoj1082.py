#!/usr/bin/env python
inf = 0x7fffffff
n = int(raw_input())
while(n != 0):
  ans = inf
  begin = 0
  mat = [[inf for col in range(n + 1)] for row in range(n + 1)]

  for i in range(1, n + 1):
    input = raw_input().split(' ')
    for j in range(1, int(input[0]) * 2, 2):
      mat[i][int(input[j])] = int(input[j+1])

  for k in range(1, n+1):
    for i in range(1, n+1):
      for j in range(1, n+1):
        if mat[i][k] + mat[k][j] < mat[i][j] :
          mat[i][j] = mat[i][k] + mat[k][j]

  for i in range(1, n+1):
    maxpath = 0
    for j in range(1, n+1):
      if mat[i][j] > maxpath and i != j:
        maxpath = mat[i][j];
    if maxpath < ans:
      ans = maxpath
      begin = i

  if ans == inf :
    print 'disjoint'
  else :
    print begin, ans
  n = int(raw_input())


