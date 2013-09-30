#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**

从一个长字符串中查找包含给定字符集合的最短子串。例如，长串为“aaaaaaaaaacbebbbbbdddddddcccccc”，字符集为{abcd}，那么最短子串是“acbebbbbbd”。

*/

int pos[300];  // 记录子串中每个字符集的最大位置
char str[10000], chset[26];

int main()
{
  // 全部小写输入，第一个为目标串，第二个为字符集
  while(scanf("%s%s", str, chset)!= EOF)
  {
    memset(pos, 0, sizeof(pos));
    int allchset = 0;
    // 用一个整数判断是否包含所有字符集
    for(int i = 0; i < strlen(chset); ++i)
    {
      allchset |= (1 << (chset[i] - 'a'));
    }

    int begin = 0, end = 0, curr_chset = 0;
    int len = strlen(str);
    int result = 0, result_pos = 0;

    // 初始化子串, str[begin, end] 使得该子串包含字符集
    while((curr_chset & allchset) != allchset && end < len)
    {
      curr_chset |= (1 << (str[end] - 'a'));
      pos[str[end]-'a'] = end;
      end++;
    }
    end--;
    // 记录结果，长度和开始位置
    result = end - begin + 1, result_pos = begin;

    do 
    {
      pos[str[end] - 'a'] = end;
      // 如果该字符在子串中的最大位置不等于当前位置，说明这个字符是可以去掉的
      while(begin < end && begin < pos[str[begin] - 'a']) begin++;

      if(end - begin + 1 < result)
      {
        result = end - begin + 1;
        result_pos = begin;
      }
      end++;
    }
    while(begin <= end && end < len);

    printf("len is %d, begin pos is %d\n", result, result_pos);
  }
  return 0;
}


