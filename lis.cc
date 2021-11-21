#include <iostream>
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

//寻找最后一个<x的数组的下标
int binary(vector<int> &v, int x)
{
  int l = 0, r = v.size() - 1;
  while (l < r)
  {
    int mid = (l + r + 1) / 2;
    if (v[mid] < x)
      l = mid;
    else
      r = mid - 1;
  }
  if (v[l] >= 0)
    return -1;
  else
    return l;
}

int main()
{
  vector<int> v{1, 2, 3, 4, 5, 6};
  cout << binary(v, 1);
  return 0;
}