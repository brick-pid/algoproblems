#include <stdio.h>
#include <vector>

using namespace std;

//O(N^2) dp solution for lis problem
int lislen(vector<int> &v)
{
  vector<int> dp(v.size());
  int lislen = 1;
  for (int i = 0; i < v.size(); ++i)
  {
    int temp = 1;
    for (int k = 0; k < i; ++k)
    {
      if (v[i] > v[k])
      {
        temp = max(temp, dp[k] + 1);
      }
    }
    dp[i] = temp;
    lislen = max(temp, lislen);
  }
  return lislen;
}

int main()
{
  vector<int> v{5, 1, 2, 3, 6, 4, 0, 8};
  printf("%d\n", lislen(v));
  return 0;
}