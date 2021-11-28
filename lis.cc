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

//二分寻找第一个 >=x 的数的下标
int binary(vector<int> &v, int x, int len)
{
  int l = 0, r = len - 1;
  while (l < r)
  {
    int mid = (l + r) / 2;
    if (v[mid] < x)
      l = mid + 1;
    else
      r = mid;
  }
  if (v[l] >= x)
    return l;
  else
    return -1; //dp中不存在>=x的数
}

//O(nlogn)的DP算法
int betterlislen(const vector<int> &v)
{
  int n = v.size();
  int dplen = 0; //dp数组的有效长度
  vector<int> dp(n);

  dp[0] = v[0];
  dplen++;
  for (int i = 1; i < n; i++)
  {
    int k = binary(dp, v[i], dplen);
    if (k == -1)
    {
      //dp中所有数字都小于k
      dp[dplen] = v[i];
      dplen++;
    }
    else
    {
      dp[k] = v[i];
    }
  }
  return dplen;
}

int main()
{
  vector<int> v{10, 9, 2, 5, 3, 7, 101, 18};
  cout << betterlislen(v) << endl;
  cout << lislen(v) << endl;
  return 0;
}